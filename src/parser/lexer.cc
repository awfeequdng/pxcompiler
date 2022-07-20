#include "parser/lexer.h"

#include "parser/misc.h"
#include "parser/token.h"

namespace parser {

std::tuple<int, common::Pos, std::string> startWithAt(Scanner &s) {

    return {};
}

std::tuple<int, common::Pos, std::string> startWithSlash(Scanner &s) {
    auto pos = s.reader()->pos();
    s.reader()->next();
    if (s.reader()->peek() != '*' && s.reader()->peek() != '/') {
        auto tok = int('/');
        auto lit = "/";
        return {tok, pos, lit};
    }
    if (s.reader()->peek() == '/') {
        s.reader()->incAsLongAs([](common::utf8::rune_t ch) { return ch != '\n'; });
        return s.scan();
    }

    auto currentCharIsStar = false;
    s.reader()->next();  // we see '/*' so far.

    switch ((int)s.reader()->next()) {
        case '*':  // '/**' if the next char is '/' it would close the comment.
            currentCharIsStar = true;
        default:
            break;
    }

    // standard C-like comment. read until we see '*/' then drop it.
    while (true) {
        auto fn = [](common::utf8::rune_t ch) -> bool { return ch != '*'; };
        if (currentCharIsStar || s.reader()->incAsLongAs(fn) == '*') {
            switch ((int)s.reader()->next()) {
                case '/':
                    // Meets */, means comment end.
                    return s.scan();
                case '*':
                    currentCharIsStar = true;
                    continue;
                default:
                    currentCharIsStar = false;
                    continue;
            }
        }
        // unclosed comment or other errors.
        // todo: add some error information here
        return {};
    }
}

std::tuple<int, common::Pos, std::string> startWithStar(Scanner &s) {
    auto pos = s.reader()->pos();
    s.reader()->next();

    return {'*', pos, "*"};
}

std::tuple<int, common::Pos, std::string> startWithDash(Scanner &s) { return {}; }

std::tuple<int, common::Pos, std::string> startWithSharp(Scanner &s) {
    s.reader()->incAsLongAs([](common::utf8::rune_t ch) { return ch != '\n'; });
    return s.scan();
}

std::tuple<int, common::Pos, std::string> startWithXx(Scanner &s) {
    int tok;
    std::string lit;
    auto pos = s.reader()->pos();
    s.reader()->next();
    if (s.reader()->peek() == '\'') {
        s.reader()->next();
        s.scanHex();
        if (s.reader()->peek() == '\'') {
            s.reader()->next();
            tok = tok_hexLit;
            lit = s.reader()->data(pos);
        } else {
            tok = (int)common::utf8::rune_invalid;
        }
        return {tok, pos, lit};
    }
    s.reader()->updatePos(pos);
    return scanIdentifier(s);
}

std::tuple<int, common::Pos, std::string> startWithNn(Scanner &s) {
    auto [tok, pos, lit] = scanIdentifier(s);
    return {tok, pos, lit};
}

std::tuple<int, common::Pos, std::string> startWithBb(Scanner &s) {
    int tok;
    std::string lit;
    auto pos = s.reader()->pos();
    s.reader()->next();
    if (s.reader()->peek() == '\'') {
        s.reader()->next();
        s.scanBit();
        if (s.reader()->peek() == '\'') {
            s.reader()->next();
            tok = tok_bitLit;
            lit = s.reader()->data(pos);
        } else {
            tok = (int)common::utf8::rune_invalid;
        }
        return {tok, pos, lit};
    }
    s.reader()->updatePos(pos);
    return scanIdentifier(s);
}

std::tuple<int, common::Pos, std::string> startWithDot(Scanner &s) { return {}; }

std::tuple<int, common::Pos, std::string> scanIdentifier(Scanner &scanner) {
    auto pos = scanner.reader()->pos();
    scanner.reader()->incAsLongAs(isIdentChar);
    return {tok_identifier, pos, scanner.reader()->data(pos)};
}

std::tuple<int, common::Pos, std::string> scanQuotedIdent(Scanner &s) {
    int tok;
    std::string lit;
    auto pos = s.reader()->pos();
    s.reader()->next();
    // clear buffer
    s.buf().str(std::string());
    while (true) {
        auto ch = s.reader()->next();
        if (ch == common::utf8::rune_invalid && s.reader()->eof()) {
            tok = (int)common::utf8::rune_invalid;
            return {tok, pos, lit};
        }
        if (ch == '`') {
            if (s.reader()->peek() != '`') {
                // don't return identifier in case that it's interpreted as keyword token later.
                tok = tok_quotedIdentifier;
                lit = s.buf().str();
                return {tok, pos, lit};
            }
            s.reader()->next();
        }
        s.buf().sputc((int)ch);
    }
}

std::tuple<int, common::Pos, std::string> startWithNumber(Scanner &s) {
    auto pos = s.reader()->pos();
    auto tok = tok_intLit;
    auto ch0 = s.reader()->next();

    if (ch0 == '0') {
        tok = tok_intLit;
        auto ch1 = s.reader()->peek();
        if (ch1 >= '0' && ch1 <= '7') {
            s.reader()->next();
            s.scanOct();
        } else if (ch1 == 'x' || ch1 == 'X') {
            s.reader()->next();
            auto p1 = s.reader()->pos();
            s.scanHex();
            auto p2 = s.reader()->pos();
            // 0x, 0x7fz3 are identifier
            if (p1 == p2 || isDigit(s.reader()->peek())) {
                s.reader()->incAsLongAs(isIdentChar);
                return {tok_identifier, pos, s.reader()->data(pos)};
            }
            tok = tok_hexLit;
        } else if (ch1 == 'b') {
            s.reader()->next();
            auto p1 = s.reader()->pos();
            s.scanBit();
            auto p2 = s.reader()->pos();
            // 0b, 0b123, 0b1ab are identifier
            if (p1 == p2 || isDigit(s.reader()->peek())) {
                s.reader()->incAsLongAs(isIdentChar);
                return {tok_identifier, pos, s.reader()->data(pos)};
            }
            tok = tok_bitLit;
        } else if (ch1 == '.') {
            return s.scanFloat(pos);
        } else if (ch1 == 'B') {
            s.reader()->incAsLongAs(isIdentChar);
            return {tok_identifier, pos, s.reader()->data(pos)};
        }
    }

    s.scanDigits();
    ch0 = s.reader()->peek();
    if (ch0 == '.' || ch0 == 'e' || ch0 == 'E') {
        return s.scanFloat(pos);
    }

    // Identifiers may begin with a digit but unless quoted may not consist solely of digits.
    if (!s.reader()->eof() && isIdentChar(ch0)) {
        s.reader()->incAsLongAs(isIdentChar);
        return {tok_identifier, pos, s.reader()->data(pos)};
    }
    auto lit = s.reader()->data(pos);
    return {tok, pos, lit};
}

std::tuple<int, common::Pos, std::string> startString(Scanner &s) { return s.scanString(); }

std::pair<int, std::string> scanIdentifierOrString(Scanner &s) {
    //    ch1 := s.r.peek()
    auto ch1 = s.reader()->peek();
    int tok;
    std::string lit;
    common::Pos pos;

    switch ((int)ch1) {
        case '\'':
            [[fallthrough]];
        case '"':
            std::tie(tok, pos, lit) = startString(s);
            break;
        case '`':
            std::tie(tok, pos, lit) = scanQuotedIdent(s);
            break;
        default:
            if (isUserVarChar(ch1)) {
                pos = s.reader()->pos();
                s.reader()->incAsLongAs(isUserVarChar);
                tok = tok_identifier;
                lit = s.reader()->data(pos);
            } else {
                tok = int(ch1);
            }
            break;
    }
    return {tok, lit};
}
}  // namespace parser