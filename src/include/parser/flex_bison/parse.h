#pragma once

#include <string>
#include <variant>

#include "ast/ast.h"
#include "common/arena.h"
#include "common/error.h"

namespace pxcompiler {

// Returns the AST representing the contents of the named file, or an error code
// if parsing fails. Allocations go into the provided arena.
auto Parse(pxcompiler::Nonnull<pxcompiler::Arena*> arena, std::string_view input_file_name,
           bool parser_debug) -> pxcompiler::ErrorOr<pxcompiler::ASTPtr>;

// Equivalent to `Parse`, but parses the contents of `file_contents`.
// `input_file_name` is used only for reporting source locations, and does
// not need to name a real file.
auto ParseFromString(pxcompiler::Nonnull<pxcompiler::Arena*> arena, std::string_view input_file_name,
                     std::string_view file_contents, bool parser_debug)
    -> pxcompiler::ErrorOr<pxcompiler::ASTPtr>;

}  // namespace parser::flex_bision

