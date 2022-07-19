#pragma once


#include "parser/ast.h"

namespace parser {

// todo: just for temporary use
enum temporary_token : int {
    tok_invalid = 1111,
    tok_def,     // def
    tok_identifier,
    tok_intLit,
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

} // namespace parser