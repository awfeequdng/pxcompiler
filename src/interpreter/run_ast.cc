#include "vm/run_ast.h"

using namespace pxcompiler;
namespace vm
{
auto RunAst(pxcompiler::Nonnull<pxcompiler::Arena*> arena, pxcompiler::ASTPtr ast,
            std::optional<pxcompiler::Nonnull<llvm::raw_ostream*>> trace_stream)
    -> pxcompiler::ErrorOr<int> {

    if (trace_stream) {
        **trace_stream << "********** source program **********\n";
        **trace_stream << "stmt cnt: " << ast->statements.size() << "\n";
        for (const auto stmt : ast->statements) {

            **trace_stream << *stmt;
        }
    }
    return 0;
}

} // namespace vm
