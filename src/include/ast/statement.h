#pragma once

#include <map>
#include <optional>
#include <string>
#include <variant>
#include <vector>

#include "common/ostream.h"
#include "ast/ast_node.h"
#include "ast/expression.h"
#include "common/arena.h"
#include "common/source_location.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/Support/Compiler.h"

#include "ast/arguments.h"

namespace pxcompiler {

class Statement : public AstNode {
 public:
  ~Statement() override = 0;

  void Print(llvm::raw_ostream& out) const override { PrintDepth(-1, out); }
  void PrintID(llvm::raw_ostream& out) const override { PrintDepth(1, out); }
  void PrintDepth(int depth, llvm::raw_ostream& out) const;

  static auto classof(const AstNode* node) {
    return InheritsFromStatement(node->kind());
  }

  // Returns the enumerator corresponding to the most-derived type of this
  // object.
  auto kind() const -> StatementKind {
    return static_cast<StatementKind>(root_kind());
  }

 protected:
  Statement(AstNodeKind kind, pxcompiler::SourceLocation source_loc)
      : AstNode(kind, source_loc) {}
};

class FunctionDef : public Statement {
public:
    static pxcompiler::Nonnull<FunctionDef*> make_FunctionDef(
                pxcompiler::Nonnull<pxcompiler::Arena*> arena,
                const pxcompiler::SourceLocation& loc,
                std::string& name,
                Arguments& args,
                std::vector<pxcompiler::Nonnull<Statement*>>& body,
                std::vector<pxcompiler::Nonnull<Expression*>>& decorator_list,
                pxcompiler::Nonnull<Expression*> returns) {
        return arena->New<FunctionDef>(loc, name, args, body,
                                      decorator_list, returns);
    }
    static auto classof(const AstNode* node) -> bool {
        return InheritsFromFunctionDef(node->kind());
    }

    FunctionDef(const pxcompiler::SourceLocation& loc,
                std::string& name,
                Arguments& args,
                std::vector<pxcompiler::Nonnull<Statement*>>& body,
                std::vector<pxcompiler::Nonnull<Expression*>>& decorator_list,
                pxcompiler::Nonnull<Expression*>& returns)
      : Statement(AstNodeKind::FunctionDef, loc),
        name_(name),
        args_(args),
        body_(std::move(body)),
        decorator_list_(std::move(decorator_list)),
        returns_(returns) {}

protected:
  std::string name_;
  Arguments args_;
  std::vector<pxcompiler::Nonnull<Statement*>> body_;
  std::vector<pxcompiler::Nonnull<Expression*>> decorator_list_;
  pxcompiler::Nonnull<Expression*> returns_;
};
class ExprStmt : public Statement {
public:
    static pxcompiler::Nonnull<ExprStmt*> make_ExprStmt(
                pxcompiler::Nonnull<pxcompiler::Arena*> arena,
                const pxcompiler::SourceLocation loc,
                pxcompiler::Nonnull<Expression*> expr) {
        return arena->New<ExprStmt>(loc, expr);
    }

    static auto classof(const AstNode* node) -> bool {
        return InheritsFromExprStmt(node->kind());
    }

    ExprStmt(const pxcompiler::SourceLocation& loc,
                pxcompiler::Nonnull<Expression*>& expr)
      : Statement(AstNodeKind::ExprStmt, loc),
        expr_(expr) {}
    auto expression() const -> const Expression& { return *expr_; }
    auto expression() -> Expression& { return *expr_; }

protected:
    pxcompiler::Nonnull<Expression*> expr_;
};

} // namespace pxcompiler
