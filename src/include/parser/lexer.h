#pragma once
#include <tuple>
// #include "common/utf8/rune.h"
#include "parser/scanner.h"

namespace parser {
std::tuple<int, common::utf8::Pos, std::string> startWithAt(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> startWithSlash(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> startWithStar(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> startWithDash(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> startWithSharp(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> startWithXx(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> startWithNn(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> startWithBb(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> startWithDot(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> scanIdentifier(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> scanQuotedIdent(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> startWithNumber(Scanner &s);
std::tuple<int, common::utf8::Pos, std::string> startString(Scanner &s);

std::pair<int, std::string> scanIdentifierOrString(Scanner &s);
}  // namespace parser