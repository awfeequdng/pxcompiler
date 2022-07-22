// Part of the Carbon Language project, under the Apache License v2.0 with LLVM
// Exceptions. See /LICENSE for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef PXC_SYNTAX_PARSE_AND_LEX_CONTEXT_H_
#define PXC_SYNTAX_PARSE_AND_LEX_CONTEXT_H_

#include <variant>

#include "parser.h"  // from parser.ypp
#include "source_location.h"

namespace pxc {

// The state and functionality that is threaded "globally" through the
// lexing/parsing process.
class ParseAndLexContext {
 public:
  // Creates an instance analyzing the given input file.
  ParseAndLexContext(const std::string input_file_name, bool parser_debug)
      : input_file_name_(input_file_name), parser_debug_(parser_debug) {}

  // Formats ands records a lexer error. Returns an error token as a
  // convenience.
  auto RecordSyntaxError(const std::string& message,
                         bool prefix_with_newline = false)
      -> Parser::symbol_type;

  auto source_loc() const -> SourceLocation {
    return SourceLocation(input_file_name_,
                          static_cast<int>(current_token_position.begin.line));
  }

  auto parser_debug() const -> bool { return parser_debug_; }

  // The source range of the token being (or just) lex'd.
  location current_token_position;

  auto error_messages() const -> const std::vector<std::string> {
    return error_messages_;
  }

 private:
  // A path to the file processed, relative to the current working directory
  // when *this is called.
  const std::string input_file_name_;

  bool parser_debug_;

  std::vector<std::string> error_messages_;
};

}  // namespace pxc

// // Gives flex the yylex prototype we want.
// #define YY_DECL                                                         \
//   auto yylex(Carbon::Nonnull<Carbon::Arena*> arena, yyscan_t yyscanner, \
//              Carbon::ParseAndLexContext& context)                       \
//       ->Carbon::Parser::symbol_type

// // Declares yylex for the parser's sake.
// YY_DECL;

#endif  // PXC_SYNTAX_PARSE_AND_LEX_CONTEXT_H_