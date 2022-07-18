#pragma once

#include <memory>
#include <sstream>
#include <tuple>

#include "common/utf8/reader.h"
#include "token.h"

namespace parser {

class Scanner;
using ScannerPtr = std::shared_ptr<Scanner>;

class Scanner : public std::enable_shared_from_this<Scanner> {
public:
    void reset(std::string text);
    // std::string stmtText();
    int getNextToken();
    std::tuple<int, common::utf8::Pos, std::string> scan();
    common::utf8::rune_t skipWhitespace();
    int isTokenIdentifier(std::string lit, int offset);
    std::shared_ptr<common::utf8::reader_t> reader() { return _reader; }

    std::tuple<int, common::utf8::Pos, std::string> scanString();

    // InheritScanner returns a new scanner object which inherits configurations from the parent scanner.
    ScannerPtr InheritScanner(std::string text) {
        auto scanner = std::make_shared<Scanner>();
        scanner->reset(text);
        return scanner;
    }

    std::stringbuf &buf() { return _buf; }

    void scanOct();
    void scanHex();
    void scanBit();
    std::tuple<int, common::utf8::Pos, std::string> scanFloat(const common::utf8::Pos &beg);
    std::string scanDigits();

    std::string stmtText();

    common::utf8::ReaderPtr _reader;

    std::stringbuf _buf;

    int _stmtStartPos;

    // Whether record the original text keyword position to the AST node.
    bool _skipPositionRecording;

    // lastScanOffset indicates last offset returned by scan().
    // It's used to substring sql in syntax error message.
    int _lastScanOffset;

    // lastKeyword records the previous keyword returned by scan().
    // determine whether an optimizer hint should be parsed or ignored.
    int _lastKeyword;
    // lastKeyword2 records the keyword before lastKeyword, it is used
    // to disambiguate hint after for update, which should be ignored.
    int _lastKeyword2;
    // lastKeyword3 records the keyword before lastKeyword2, it is used
    // to disambiguate hint after create binding for update, which should
    // be pertained.
    int _lastKeyword3;
};

ScannerPtr NewScanner(std::string);

}  // namespace parser