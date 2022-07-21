#include "parser/scanner.h"

#include <iostream>
#include "fmt/format.h"

#include "parser/lexer.h"
#include "parser/misc.h"
#include "parser/token.h"
#include "parser/ast.h"

namespace parser {

// lazyBuf is used to avoid allocation if possible.
// it has a useBuf field indicates whether bytes.Buffer is necessary. if
// useBuf is false, we can avoid using _buf, which
// make a copy of data and cause allocation.
struct lazyBuf {
    bool _useBuf;
    std::shared_ptr<common::utf8::reader_t> _reader;
    std::stringbuf &_buf;
    const common::Pos &_pos;
    void setUseBuf(std::string str) {
        if (!_useBuf) {
            _useBuf = true;
            // clear buf
            _buf.str(str);
            _buf.pubseekoff(0, std::ios_base::end);
        }
    }
    void writeRune(common::utf8::rune_t rune, int w) {
        if (_useBuf) {
            if (w > 1) {
                std::string str = (std::string)rune;
                _buf.sputn(str.c_str(), str.length());
            } else {
                int b = static_cast<int>(rune);
                _buf.sputc(b);
            }
        }
    }
    std::string data() {
        std::string lit;
        if (_useBuf) {
            lit = _buf.str();
        } else {
            lit = _reader->data(_pos);
            lit = lit.substr(1, lit.length() - 2);
        }
        return lit;
    }
};

void Scanner::reset(std::string text) {
    _reader = std::make_shared<common::utf8::reader_t>(text);
    _stmtStartPos = 0;
    _lastKeyword = 0;
}

std::string Scanner::stmtText() {
    auto endIndex = _reader->index();
    if (_reader->is_newline(endIndex - 1)) {
        endIndex --;
    }
    if (_reader->is_newline(_stmtStartPos)) {
        _stmtStartPos++;
    }
    std::string text = _reader->make_slice(_stmtStartPos, endIndex - _stmtStartPos);

    _stmtStartPos = endIndex;
    return text;
}

int Scanner::isKeywordIdentifier(std::string lit) {
    auto keywordMap = Token::getKeywordMap();
    auto curKeyword = keywordMap.find(lit);
    auto endKeyword = keywordMap.end();
    if (curKeyword != endKeyword) {
        return curKeyword->second;
    }
    return 0;
}

Token Scanner::getNextToken() {
    auto [tok, pos, lit] = scan();
    if (tok == tok_identifier) {
        auto tok1 = isKeywordIdentifier(lit);
        if (tok1 != 0) {
            tok = tok1;
            _lastKeyword = tok1;
        }
    }
    return Token::newToken((TokenTag)tok, pos, lit);
}

std::tuple<int, common::Pos, std::string> Scanner::scan() {
    auto ch0 = _reader->peek();
    if (ch0.is_space()) {
        ch0 = skipWhitespace();
    }
    auto pos = _reader->pos();
    if (_reader->eof()) {
        // when scanner meets EOF, the returned token should be 0,
        // because 0 is a special token id to remind the parser that stream is end.
        return {0, pos, ""};
    }
    if (isIdentExtend(ch0)) {
        // start with extend identifier, so it must be a identifier
        return scanIdentifier(*this);
    }

    auto node = getRuleTable();
    while (ch0 >= 0 && ch0 <= 255) {
        int id = (int)ch0;
        if (node->childs[id] == nullptr || _reader->eof()) {
            break;
        }
        node = node->childs[id];
        if (node->fn != nullptr) {
            return node->fn(*this);
        }
        _reader->next();
        ch0 = _reader->peek();
    }

    return {node->token, pos, _reader->data(pos)};
}

common::utf8::rune_t Scanner::skipWhitespace() { return _reader->incAsLongAs(isSpace); }

// handleEscape handles the case in scanString when previous char is '\'.
common::utf8::rune_t handleEscape(Scanner &scanner) {
    scanner.reader()->next();
    common::utf8::rune_t ch0 = scanner.reader()->peek();

    /*
        \" \' \\ \n \0 \b \Z \r \t ==> escape to one char
        \% \_ ==> preserve both char
        other ==> remove \
    */
    switch ((int)ch0) {
        case 'n':
            ch0 = '\n';
            break;
        case '0':
            ch0 = 0;
            break;
        case 'b':
            ch0 = 8;
            break;
        case 'Z':
            ch0 = 26;
            break;
        case 'r':
            ch0 = '\r';
            break;
        case 't':
            ch0 = '\t';
            break;
        case '%':
            [[fallthrough]];
        case '_':
            scanner.buf().sputc('\\');
            break;
    }
    return ch0;
}

std::tuple<int, common::Pos, std::string> Scanner::scanString() {
    auto tok = tok_stringLit;
    auto pos = _reader->pos();
    auto ending = _reader->next();
    auto ch0 = _reader->peek();
    std::string lit;

    auto mb = lazyBuf{false, _reader, _buf, pos};

    while (!_reader->eof()) {
        if (ch0 == ending) {
            _reader->next();
            if (_reader->peek() != ending) {
                lit = mb.data();
                return {tok, pos, lit};
            }
            auto str = mb._reader->data(pos);
            mb.setUseBuf(str.substr(1, str.length() - 2));
        } else if (ch0 == '\\') {
            auto str = mb._reader->data(pos);
            mb.setUseBuf(str.substr(1));
            ch0 = handleEscape(*this);
        }
        auto w = _reader->last_width();
        mb.writeRune(ch0, w);
        if (!_reader->eof()) {
            _reader->next();
            ch0 = _reader->peek();
        }
    }

    return {(int)common::utf8::rune_invalid, pos, lit};
}

void Scanner::scanOct() {
    _reader->incAsLongAs([](common::utf8::rune_t ch) { return ch >= '0' && ch <= '7'; });
}

void Scanner::scanHex() {
    _reader->incAsLongAs([](common::utf8::rune_t ch) {
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
    });
}

void Scanner::scanBit() {
    _reader->incAsLongAs([](common::utf8::rune_t ch) { return ch == '0' || ch == '1'; });
}

std::tuple<int, common::Pos, std::string> Scanner::scanFloat(const common::Pos &beg) {
    _reader->updatePos(beg);
    // float = D1 . D2 e D3
    scanDigits();
    int tok = 0;
    auto ch0 = _reader->peek();
    if (ch0 == '.') {
        _reader->next();
        scanDigits();
        ch0 = _reader->peek();
    }

    if (ch0 == 'e' || ch0 == 'E') {
        _reader->next();
        ch0 = _reader->peek();
        if (ch0 == '-' || ch0 == '+') {
            _reader->next();
        }
        if (isDigit(_reader->peek())) {
            scanDigits();
            tok = tok_floatLit;
        } else {
            // D1 . D2 e XX when XX is not D3, parse the result to an identifier.
            // 9e9e = 9e9(float) + e(identifier)
            // 9est = 9est(identifier)
            _reader->updatePos(beg);
            _reader->incAsLongAs(isIdentChar);
            tok = tok_identifier;
        }
    } else {
        tok = tok_decLit;
    }
    auto pos = beg;
    auto lit = _reader->data(beg);
    return {tok, pos, lit};
}

std::string Scanner::scanDigits() {
    auto pos = _reader->pos();
    _reader->incAsLongAs(isDigit);
    return _reader->data(pos);
}

// NewScanner returns a new scanner object.
std::shared_ptr<Scanner> NewScanner(std::string str) {
    auto scanner = std::make_shared<Scanner>();
    scanner->reset(str);
    return scanner;
}

}  // namespace parser