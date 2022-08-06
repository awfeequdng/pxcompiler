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

#define LIST_NEW(l) l.reserve(4)
#define LIST_ADD(l, x) l.push_back(x)

#define EXPR_01(e, l) pxcompiler::ExprStmt::make_ExprStmt(arena, l, e)

#define IF_STMT_01(e, stmt, l) pxcompiler::If::make_If(arena, l, \
        e, stmt, {})
#define IF_STMT_02(e, stmt, orelse, l) pxcompiler::If::make_If(arena, l, \
        e, stmt, orelse)
