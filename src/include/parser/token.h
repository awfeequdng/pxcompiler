#pragma once

namespace parser {

enum TokenTag {
    tok_invalid = 1111,
    tok_def,     // def
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
    Token newToken(TokenTag tag, common::Pos pos, std::string lit) {
        return {tag, pos, lit};
    }
// private:
    Token(TokenTag t, common::Pos p, std::string l)
        : tag(t), pos(p), lit(l) {}

    TokenTag tag;
    common::Pos pos;
    std::string lit;
};

} // namespace parser