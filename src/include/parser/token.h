#pragma once

#include "common/pos.h"
#include <string>
#include <unordered_map>
namespace parser {

enum TokenTag : int {
    tok_invalid = 1111,
    // Keywords
    tok_False,
    tok_None,
    tok_True,
    tok_and,
    tok_as,
    tok_assert,
    tok_break,
    tok_class,
    tok_continue,
    tok_def,
    tok_del,
    tok_elif,
    tok_else,
    tok_except,
    tok_finally,
    tok_for,
    tok_from,
    tok_global,
    tok_if,
    tok_import,
    tok_in,
    tok_is,
    tok_lambda,
    tok_nonlocal,
    tok_not,
    tok_or,
    tok_pass,
    tok_raise,
    tok_return,
    tok_try,
    tok_while,
    tok_with,
    tok_yield,

    tok_identifier,
    tok_intLit,
    tok_charLit,
    tok_stringLit,
    tok_bitLit,
    tok_hexLit,
    tok_decLit,
    tok_floatLit,
    tok_quotedIdentifier,

    tok_paramMarker, // ?
    tok_eq,         // =
    tok_pipes,   // ||
    tok_andand,  // &&
    tok_andnot,  // &^
    tok_assignmentEq, // :=
    tok_nulleq, // <=>
    tok_ge,     // >=
    tok_le,     // <=
    tok_neq,    // !=
    tok_neqSynonym, // <>
    tok_lsh,    // <<
    tok_rsh,    // >>
    tok_null,   // \\N
};

class Token {
public:
    static Token newToken(TokenTag tag, pxcompiler::Pos pos, std::string lit) {
        return {tag, pos, lit};
    }
    static std::unordered_map<std::string, int> getKeywordMap();
    static std::unordered_map<std::string, int> keywordMap;
// private:
    Token(TokenTag t, pxcompiler::Pos p, std::string l)
        : tag(t), pos(p), lit(l) {}

    TokenTag tag;
    pxcompiler::Pos pos;
    std::string lit;
};


} // namespace parser