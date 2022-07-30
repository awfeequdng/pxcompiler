#pragma once

#include "common/source_location.h"
#include "common/nonnull.h"


namespace ast
{
class Expression;

struct Arg {
    // common::SourceLocation loc;
    std::string arg;
};

struct Arguments {
    // common::SourceLocation loc;
    std::vector<common::Nonnull<Arg*>> posonlyargs;
    std::vector<common::Nonnull<Arg*>> args;
    std::vector<common::Nonnull<Arg*>> varargs;
    std::vector<common::Nonnull<Arg*>> kwonlyargs;
    std::vector<common::Nonnull<Arg*>> kw_defaults;
    std::vector<common::Nonnull<Arg*>> kwarg;
    std::vector<common::Nonnull<Arg*>> defaults;
};

struct Keyword {
    // common::SourceLocation loc;
    std::string arg;
    common::Nonnull<Expression*> value;
};

struct WithItem {
    // common::SourceLocation loc;
    common::Nonnull<Expression*> context_expr;
    common::Nonnull<Expression*> optional_vars;
};

} // namespace ast
