#pragma once

#include "common/source_location.h"
#include "common/nonnull.h"


namespace pxcompiler
{
class Expression;

struct WithItem {
    // pxcompiler::SourceLocation loc;
    pxcompiler::Nonnull<Expression*> context_expr;
    pxcompiler::Nonnull<Expression*> optional_vars;
};

} // namespace pxcompiler
