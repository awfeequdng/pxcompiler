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

  void Print(llvm::raw_ostream& out) const override { PrintDepth(0, out); }
  void PrintID(llvm::raw_ostream& out) const override { PrintDepth(0, out); }
  void PrintDepth(int depth, llvm::raw_ostream& out) const;
  static llvm::raw_ostream& Space(int depth, llvm::raw_ostream& out);

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
                Nonnull<Expression*> name,
                Nonnull<Arguments*> args,
                std::vector<pxcompiler::Nonnull<Statement*>> body,
                std::vector<pxcompiler::Nonnull<Expression*>> decorator_list,
                std::optional<Nonnull<Expression*>> returns,
                std::optional<Nonnull<Expression*>> type_comment) {
        return arena->New<FunctionDef>(loc, name, args, body,
                                      decorator_list, returns, type_comment);
    }
    static auto classof(const AstNode* node) -> bool {
        return InheritsFromFunctionDef(node->kind());
    }

    FunctionDef(const pxcompiler::SourceLocation& loc,
                Nonnull<Expression*> name,
                Nonnull<Arguments*> args,
                std::vector<pxcompiler::Nonnull<Statement*>> body,
                std::vector<pxcompiler::Nonnull<Expression*>> decorator_list,
                std::optional<Nonnull<Expression*>> returns,
                std::optional<Nonnull<Expression*>> type_comment)
      : Statement(AstNodeKind::FunctionDef, loc),
        name_(name),
        args_(args),
        body_(std::move(body)),
        decorator_list_(std::move(decorator_list)),
        returns_(returns),
        type_comment_(type_comment) {}

// protected:
    Nonnull<Expression*> name_;
    Nonnull<Arguments*> args_;
    std::vector<Nonnull<Statement*>> body_;
    std::vector<Nonnull<Expression*>> decorator_list_;
    std::optional<Nonnull<Expression*>> returns_;
    std::optional<Nonnull<Expression*>> type_comment_;
};

class ExprStmt : public Statement {
public:
    static pxcompiler::Nonnull<ExprStmt*> make_ExprStmt(
                pxcompiler::Nonnull<pxcompiler::Arena*> arena,
                const pxcompiler::SourceLocation& loc,
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
    // auto expression() -> Expression& { return *expr_; }

protected:
    pxcompiler::Nonnull<Expression*> expr_;
};

class If : public Statement {
public:
    static Nonnull<If*> make_If (
                Nonnull<pxcompiler::Arena*> arena,
                const pxcompiler::SourceLocation& loc,
                pxcompiler::Nonnull<Expression*> test,
                std::vector<Nonnull<Statement*>> body,
                std::vector<Nonnull<Statement*>> orelse) {
        return arena->New<If>(loc, test, body, orelse);
    }

    static auto classof(const AstNode* node) -> bool {
        return InheritsFromIf(node->kind());
    }

    If(const pxcompiler::SourceLocation& loc,
       Nonnull<Expression*> test,
       std::vector<Nonnull<Statement*>> body,
       std::vector<Nonnull<Statement*>> orelse)
      : Statement(AstNodeKind::If, loc),
        test_(test),
        body_(body),
        orelse_(orelse) {}
    auto test() const -> const Expression& { return *test_; }

    auto body() const -> const std::vector<Nonnull<Statement*>>& {
        return body_;
    }

    auto orelse() const -> const std::vector<Nonnull<Statement*>>& {
        return orelse_;
    }

protected:
    Nonnull<Expression*> test_;
    std::vector<Nonnull<Statement*>> body_;
    std::vector<Nonnull<Statement*>> orelse_;
};

class NonLocal: public Statement {
public:
    static Nonnull<NonLocal*> make_NonLocal(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> names) {
        return arena->New<NonLocal>(loc, names);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromNonLocal(node->kind());
    }

    NonLocal(pxcompiler::SourceLocation loc,
            std::vector<Nonnull<Expression*>> names)
        : Statement(AstNodeKind::NonLocal, loc),
        names_(names) {}

    const std::vector<Nonnull<Expression*>> &names() const {
        return names_;
    }

private:
    std::vector<Nonnull<Expression*>> names_;
};


class Global: public Statement {
public:
    static Nonnull<Global*> make_Global(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> names) {
        return arena->New<Global>(loc, names);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromGlobal(node->kind());
    }

    Global(pxcompiler::SourceLocation loc,
            std::vector<Nonnull<Expression*>> names)
        : Statement(AstNodeKind::Global, loc),
        names_(names) {}

    const std::vector<Nonnull<Expression*>> &names() const {
        return names_;
    }

private:
    std::vector<Nonnull<Expression*>> names_;
};

class Import: public Statement {
public:
    static Nonnull<Import*> make_Import(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Alias*>> names) {
        return arena->New<Import>(loc, names);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromImport(node->kind());
    }

    Import(pxcompiler::SourceLocation loc,
            std::vector<Nonnull<Alias*>> names)
        : Statement(AstNodeKind::Import, loc),
        names_(names) {}

    const std::vector<Nonnull<Alias*>> &names() const {
        return names_;
    }

private:
    std::vector<Nonnull<Alias*>> names_;
};

class ImportFrom: public Statement {
public:
    static Nonnull<ImportFrom*> make_ImportFrom(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> module,
        std::vector<Nonnull<Alias*>> names,
        int level) {
        return arena->New<ImportFrom>(loc, module, names, level);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromImportFrom(node->kind());
    }

    ImportFrom(pxcompiler::SourceLocation loc,
            std::vector<Nonnull<Expression*>> module,
            std::vector<Nonnull<Alias*>> names,
            int level)
        : Statement(AstNodeKind::ImportFrom, loc),
        module_(module),
        names_(names),
        level_(level) {}

    const std::vector<Nonnull<Expression*>> &mod() const {
        return module_;
    }
    const std::vector<Nonnull<Alias*>> &names() const {
        return names_;
    }
    size_t level() const {
        return level_;
    }

private:
    std::vector<Nonnull<Expression*>> module_;
    std::vector<Nonnull<Alias*>> names_;
    size_t level_{};
};


class Break: public Statement {
public:
    static Nonnull<Break*> make_Break(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc) {
        return arena->New<Break>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromBreak(node->kind());
    }

    Break(pxcompiler::SourceLocation loc)
        : Statement(AstNodeKind::Break, loc) {}
};

class Continue: public Statement {
public:
    static Nonnull<Continue*> make_Continue(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc) {
        return arena->New<Continue>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromContinue(node->kind());
    }

    Continue(pxcompiler::SourceLocation loc)
        : Statement(AstNodeKind::Continue, loc) {}
};

class Pass: public Statement {
public:
    static Nonnull<Pass*> make_Pass(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc) {
        return arena->New<Pass>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromPass(node->kind());
    }

    Pass(pxcompiler::SourceLocation loc)
        : Statement(AstNodeKind::Pass, loc) {}
};

} // namespace pxcompiler
