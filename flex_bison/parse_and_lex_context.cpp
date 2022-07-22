
#include "parse_and_lex_context.h"

#include <sstream>
namespace pxc {

auto ParseAndLexContext::RecordSyntaxError(const std::string& message,
                                           bool prefix_with_newline)
    -> Parser::symbol_type {
  // Optionally adds a newline in trace mode because trace prints an incomplete
  // line "Reading a token: " which can prevent LIT from finding expected
  // patterns.
  // TODO: support formatting of `SourceLocation` instances with formatv().
  std::string full_message;
  std::stringstream oss;
  oss << (prefix_with_newline && parser_debug() ? "\n" : "")
      << "COMPILATION ERROR: " << source_loc() << ": " << message;
  error_messages_.push_back(oss.str());

  // TODO: use `YYerror` token once bison is upgraded to at least 3.5.
  return Parser::make_END_OF_FILE(current_token_position);
}

}  // namespace pxc
