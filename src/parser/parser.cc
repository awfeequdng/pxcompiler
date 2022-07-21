#include "parser/scanner.h"
#include "parser/parser.h"

namespace parser
{
// void Parser::parse(std::vector<Token> &tokens) {
//     curToken_ = tokens.begin();
//     endToken_ = tokens.end();
//     while (curToken_ != endToken_) {

//     }
// }

// std::optional<Token> Parser::expectIdentifier(const std::string &name) {
//     if (curToken_ == endToken_) return { std::nullopt; }
//     if (curToken_->tag != tok_identifier) { return std::nullopt; }
//     if (name.empty() || curToken_->lit != name) { return std::nullopt; }

//     return std::nullopt;
// }
} // namespace parser
