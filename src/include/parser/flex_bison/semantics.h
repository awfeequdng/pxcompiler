#pragma once
#include "ast/ast.h"
#include "ast/name.h"
#include "ast/statement.h"

#define RESULT(x) do { \
    if (*ast == std::nullopt) { \
        *ast = std::make_shared<pxcompiler::AST>();    \
    }   \
    ast->value()->statements.push_back(x);   \
} while (0)

#define SYMBOL(x, l) pxcompiler::Name::make_Name(arena, l, x)

#define EXPR_01(e, l) pxcompiler::ExprStmt::make_ExprStmt(arena, l, e)