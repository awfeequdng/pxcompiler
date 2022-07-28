#pragma once

#include <optional>
#include <string>

#include "common/error.h"
#include "llvm/ADT/StringRef.h"

namespace common {

// Note llvm StringExtras has significant functionality which is intended to be
// complementary to this.

// Unescapes common escape sequences in the source string. Returns std::nullopt
// on bad input. `is_block_string` enables escaping unique to block string
// literals, such as \<newline>.
auto UnescapeStringLiteral(llvm::StringRef source, int hashtag_num = 0,
                           bool is_block_string = false)
    -> std::optional<std::string>;

// Parses a block string literal in `source`.
auto ParseBlockStringLiteral(llvm::StringRef source, int hashtag_num = 0)
    -> ErrorOr<std::string>;

// Returns true if the pointer is in the string ref (including equality with
// `ref.end()`). This should be used instead of `<=` comparisons for
// correctness.
auto StringRefContainsPointer(llvm::StringRef ref, const char* ptr) -> bool;

}  // namespace common

