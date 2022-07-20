#pragma once
#include <vector>

#include "parser/token.h"
namespace parser
{
class Parser {
public:
    void parse(std::vector<Token> &tokens);
};

} // namespace parser
