#pragma once
#include "common/nonnull.h"
#include "common/arena.h"
#include "common/error.h"
#include "ast/ast.h"
#include <llvm/Support/raw_ostream.h>

namespace vm
{
auto RunAst(common::Nonnull<common::Arena*> arena, ast::AST ast,
            std::optional<common::Nonnull<llvm::raw_ostream*>> trace_stream)
    -> common::ErrorOr<int>;

} // namespace vm
