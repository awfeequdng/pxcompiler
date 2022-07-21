#pragma once
#include <vector>

#include "parser/token.h"
#include <optional>
namespace parser
{
class Parser {
public:
    void parse(std::vector<Token> &tokens);

private:
    // std::optional<Token> expectIdentifier(const std::string &name);
    // std::vector<Token>::iterator curToken_;
    // std::vector<Token>::iterator endToken_;
};

} // namespace parser
