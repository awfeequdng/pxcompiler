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

namespace ast {

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
  Statement(AstNodeKind kind, common::SourceLocation source_loc)
      : AstNode(kind, source_loc) {}
};

class FunctionDef : public Statement {
public:
  static common::Nonnull<AstNode*> make_FunctionDef(
              common::Nonnull<common::Arena*> arena,
              const common::SourceLocation& loc,
              std::string& name,
              Arguments& args,
              std::vector<common::Nonnull<Statement*>>& body,
              std::vector<common::Nonnull<Expression*>>& decorator_list,
              common::Nonnull<Expression*> returns) {
        return arena->New<FunctionDef>(loc, name, args, body,
                                       decorator_list, returns);
    }

  FunctionDef(const common::SourceLocation& loc,
              std::string& name,
              Arguments& args,
              std::vector<common::Nonnull<Statement*>>& body,
              std::vector<common::Nonnull<Expression*>>& decorator_list,
              common::Nonnull<Expression*>& returns)
    : Statement(AstNodeKind::FunctionDef, loc),
      name_(name),
      args_(args),
      body_(std::move(body)),
      decorator_list_(std::move(decorator_list)),
      returns_(returns) {}

protected:
  std::string name_;
  Arguments args_;
  std::vector<common::Nonnull<Statement*>> body_;
  std::vector<common::Nonnull<Expression*>> decorator_list_;
  common::Nonnull<Expression*> returns_;
};

} // namespace ast
