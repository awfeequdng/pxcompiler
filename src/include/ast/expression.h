#pragma once

#include <map>
#include <optional>
#include <string>
#include <variant>
#include <vector>

#include "common/ostream.h"
#include "ast/ast_node.h"
#include "common/arena.h"
#include "common/source_location.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/Support/Compiler.h"

namespace pxcompiler {

class Expression : public AstNode {
 public:
  ~Expression() override = 0;

  void Print(llvm::raw_ostream& out) const override;
  void PrintID(llvm::raw_ostream& out) const override;

  static auto classof(const AstNode* node) {
    return InheritsFromExpression(node->kind());
  }

  // Returns the enumerator corresponding to the most-derived type of this
  // object.
  auto kind() const -> ExpressionKind {
    return static_cast<ExpressionKind>(root_kind());
  }

 protected:
  // Constructs an Expression representing syntax at the given line number.
  // `kind` must be the enumerator corresponding to the most-derived type being
  // constructed.
  Expression(AstNodeKind kind, pxcompiler::SourceLocation source_loc)
      : AstNode(kind, source_loc) {}

 private:
};

class ConstantInt : public Expression {
public:
    static Nonnull<ConstantInt*> make_ConstantInt(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        int64_t val) {
        return arena->New<ConstantInt>(loc, val);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantInt(node->kind());
    }

    ConstantInt(pxcompiler::SourceLocation loc, int64_t val)
        : Expression(AstNodeKind::ConstantInt, loc),
          val_(val) {}

    int64_t value() const {
        return val_;
    }
private:
    int64_t val_;
};

class ConstantBool : public Expression {
public:
    static Nonnull<ConstantBool*> make_ConstantBool(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        bool val) {
        return arena->New<ConstantBool>(loc, val);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantBool(node->kind());
    }

    ConstantBool(pxcompiler::SourceLocation loc, bool val)
        : Expression(AstNodeKind::ConstantBool, loc),
          val_(val) {}

    bool value() const {
        return val_;
    }
private:
    bool val_;
};

class ConstantNone : public Expression {
public:
    static Nonnull<ConstantNone*> make_ConstantNone(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc) {
        return arena->New<ConstantNone>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantNone(node->kind());
    }

    ConstantNone(pxcompiler::SourceLocation loc)
        : Expression(AstNodeKind::ConstantNone, loc) {}
};

class ConstantEllipsis : public Expression {
public:
    static Nonnull<ConstantEllipsis*> make_ConstantEllipsis(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc) {
        return arena->New<ConstantEllipsis>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantEllipsis(node->kind());
    }

    ConstantEllipsis(pxcompiler::SourceLocation loc)
        : Expression(AstNodeKind::ConstantEllipsis, loc) {}
};

class ConstantFloat : public Expression {
public:
    static Nonnull<ConstantFloat*> make_ConstantFloat(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        double val) {
        return arena->New<ConstantFloat>(loc, val);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantFloat(node->kind());
    }

    ConstantFloat(SourceLocation loc, double val)
        : Expression(AstNodeKind::ConstantFloat, loc),
          val_(val) {}

    double value() const {
        return val_;
    }
private:
    double val_;
};

class ConstantComplex : public Expression {
public:
    static Nonnull<ConstantComplex*> make_ConstantComplex(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        double real, double image) {
        return arena->New<ConstantComplex>(loc, real, image);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantComplex(node->kind());
    }

    ConstantComplex(SourceLocation loc, double real, double image)
        : Expression(AstNodeKind::ConstantComplex, loc),
          real_(real), image_(image) {}

    double real() const {
        return real_;
    }
    double image() const {
        return image_;
    }
private:
    double real_;
    double image_;
};

class ConstantStr : public Expression {
public:
    static Nonnull<ConstantStr*> make_ConstantStr(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        std::string val,
        std::string kind = std::string()) {
        return arena->New<ConstantStr>(loc, val, kind);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantStr(node->kind());
    }

    ConstantStr(SourceLocation loc, std::string val, std::string kind)
        : Expression(AstNodeKind::ConstantStr, loc),
          val_(val), kind_(kind) {}

    const std::string& value() const {
        return val_;
    }
    const std::vector<Nonnull<Expression*>> &extend() const {
        return extend_;
    }

    void concat(std::string str) {
        val_ += str;
    }
    void extend(Nonnull<Expression*> expr) {
        extend_.push_back(expr);
    }
private:
    std::string val_;
    std::string kind_;
    std::vector<Nonnull<Expression*>> extend_;
};

class ConstantBytes : public Expression {
public:
    static Nonnull<ConstantBytes*> make_ConstantBytes(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        std::string val,
        std::string kind = std::string()) {
        return arena->New<ConstantBytes>(loc, val, kind);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantBytes(node->kind());
    }

    ConstantBytes(SourceLocation loc, std::string val, std::string kind)
        : Expression(AstNodeKind::ConstantBytes, loc),
          val_(val), kind_(kind) {}

    const std::string& value() const {
        return val_;
    }
    const std::vector<Nonnull<Expression*>> &extend() const {
        return extend_;
    }
    void concat(std::string str) {
        val_ += str;
    }
    void extend(Nonnull<Expression*> expr) {
        extend_.push_back(expr);
    }
private:
    std::string val_;
    std::string kind_;
    std::vector<Nonnull<Expression*>> extend_;
};

class JoinedStr : public Expression {
public:
    static Nonnull<JoinedStr*> make_JoinedStr(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> values) {
        return arena->New<JoinedStr>(loc, values);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromJoinedStr(node->kind());
    }

    JoinedStr(SourceLocation loc, std::vector<Nonnull<Expression*>> values)
        : Expression(AstNodeKind::JoinedStr, loc),
          values_(std::move(values)) {}

    const std::vector<Nonnull<Expression*>>& values() const {
        return values_;
    }
    void join(Nonnull<Expression*> expr) {
        values_.push_back(expr);
    }
private:
    std::vector<Nonnull<Expression*>> values_;
};

class FormattedValue : public Expression {
public:
    static Nonnull<FormattedValue*> make_FormattedValue(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        Nonnull<Expression*> value,
        int64_t conversion) {
        return arena->New<FormattedValue>(loc, value, conversion);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromFormattedValue(node->kind());
    }

    FormattedValue(SourceLocation loc, Nonnull<Expression*> value,
                  int64_t conversion
                //   Nonnull<Expression*> format_spec
        )
        : Expression(AstNodeKind::FormattedValue, loc),
          value_(value), conversion_(conversion)
        //   format_spec_(format_spec)
          {}

    const Nonnull<Expression*>& value() const {
        return value_;
    }

private:
    Nonnull<Expression*> value_;
    int64_t conversion_;
};

class Tuple : public Expression {
public:
    static Nonnull<Tuple*> make_Tuple(
        Nonnull<pxcompiler::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> elts) {
        return arena->New<Tuple>(loc, elts);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromTuple(node->kind());
    }

    Tuple(pxcompiler::SourceLocation loc, std::vector<Nonnull<Expression*>> elts)
        : Expression(AstNodeKind::Tuple, loc), elts_(elts) {}

    const std::vector<Nonnull<Expression*>> &elements() const {
        return elts_;
    }

private:
    std::vector<Nonnull<Expression*>> elts_;
};

} // namespace pxcompiler
