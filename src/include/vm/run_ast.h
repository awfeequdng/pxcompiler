#pragma once
#include "common/nonnull.h"
#include "common/arena.h"
#include "common/error.h"
#include "ast/ast.h"
#include <llvm/Support/raw_ostream.h>

namespace vm
{
auto RunAst(pxcompiler::Nonnull<pxcompiler::Arena*> arena, pxcompiler::ASTPtr ast,
            std::optional<pxcompiler::Nonnull<llvm::raw_ostream*>> trace_stream)
    -> pxcompiler::ErrorOr<int>;

} // namespace vm
