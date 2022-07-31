#pragma once
#include "common/nonnull.h"
#include <string>
#include <memory>

#include "ast/statement.h"

namespace pxcompiler {
struct AST {
    std::string filename;
    // The file's ordered statement.
    std::vector<pxcompiler::Nonnull<Statement*>> statements;
};
using ASTPtr = std::shared_ptr<AST>;
}