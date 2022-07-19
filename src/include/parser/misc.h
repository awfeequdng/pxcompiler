#pragma once

#include "common/utf8/rune.h"
#include "parser/scanner.h"

namespace parser {
inline bool isLetter(common::utf8::rune_t ch) { return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); }

inline bool isIdentExtend(common::utf8::rune_t ch) { return ch >= 0x80 && ch <= 0xffffu; }

inline bool isDigit(common::utf8::rune_t ch) { return ch >= '0' && ch <= '9'; }

inline bool isIdentChar(common::utf8::rune_t ch) {
    return isLetter(ch) || isDigit(ch) || ch == '_' || ch == '$' || isIdentExtend(ch);
}

inline bool isUserVarChar(common::utf8::rune_t ch) {
    return isLetter(ch) || isDigit(ch) || ch == '_' || ch == '$' || ch == '.' || isIdentExtend(ch);
}

inline bool isSpace(common::utf8::rune_t ch) { return ch.is_space(); }

typedef std::function<std::tuple<int, common::Pos, std::string>(parser::Scanner &)> trieFunc;
struct trieNode {
#define BYTE_MAX 255
    std::shared_ptr<trieNode> childs[BYTE_MAX + 1];
    int token;
    trieFunc fn;
};

std::shared_ptr<trieNode> getRuleTable();
std::unordered_map<std::string, int> getTokenMap();
std::string getTokenStr(int tok);
}  // namespace parser