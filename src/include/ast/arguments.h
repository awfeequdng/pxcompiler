#pragma once

#include "common/source_location.h"
#include "common/nonnull.h"


namespace pxcompiler
{
class Expression;

struct Arg {
    // pxcompiler::SourceLocation loc;
    std::string arg;
};

struct Arguments {
    // pxcompiler::SourceLocation loc;
    std::vector<pxcompiler::Nonnull<Arg*>> posonlyargs;
    std::vector<pxcompiler::Nonnull<Arg*>> args;
    std::vector<pxcompiler::Nonnull<Arg*>> varargs;
    std::vector<pxcompiler::Nonnull<Arg*>> kwonlyargs;
    std::vector<pxcompiler::Nonnull<Arg*>> kw_defaults;
    std::vector<pxcompiler::Nonnull<Arg*>> kwarg;
    std::vector<pxcompiler::Nonnull<Arg*>> defaults;
};

struct Keyword {
    // pxcompiler::SourceLocation loc;
    std::string arg;
    pxcompiler::Nonnull<Expression*> value;
};

struct WithItem {
    // pxcompiler::SourceLocation loc;
    pxcompiler::Nonnull<Expression*> context_expr;
    pxcompiler::Nonnull<Expression*> optional_vars;
};

} // namespace pxcompiler
