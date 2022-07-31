#pragma once

#include <variant>

#include "common/nonnull.h"
#include "common/source_location.h"
#include "ast/ast.h"
#include "parser/flex_bison/parser.h"  // from parser.ypp

namespace pxcompiler {

// The state and functionality that is threaded "globally" through the
// lexing/parsing process.
class ParseAndLexContext {
 public:
  // Creates an instance analyzing the given input file.
  ParseAndLexContext(pxcompiler::Nonnull<const std::string*> input_file_name,
                     bool parser_debug)
      : input_file_name_(input_file_name), parser_debug_(parser_debug) {}

  // Formats ands records a lexer error. Returns an error token as a
  // convenience.
  auto RecordSyntaxError(const std::string& message,
                         bool prefix_with_newline = false)
      -> Parser::symbol_type;

  auto source_loc() const -> pxcompiler::SourceLocation {
    return pxcompiler::SourceLocation(input_file_name_,
                          static_cast<int>(current_token_position.begin.line),
                          static_cast<int>(current_token_position.begin.column)
                          );
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
  pxcompiler::Nonnull<const std::string*> input_file_name_;

  bool parser_debug_;

  std::vector<std::string> error_messages_;
};

}  // namespace pxcompiler

// Gives flex the yylex prototype we want.
#define YY_DECL                                                         \
  pxcompiler::Parser::symbol_type yylex(pxcompiler::Nonnull<pxcompiler::Arena*> arena, yyscan_t yyscanner, \
             pxcompiler::ParseAndLexContext& context)

// Declares yylex for the parser's sake.
YY_DECL;

