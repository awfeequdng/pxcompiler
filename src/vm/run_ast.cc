#include "vm/run_ast.h"

using namespace common;
namespace vm
{
auto RunAst(common::Nonnull<common::Arena*> arena, ast::AST ast,
            std::optional<common::Nonnull<llvm::raw_ostream*>> trace_stream)
    -> common::ErrorOr<int> {

    return 0;
}
} // namespace vm
