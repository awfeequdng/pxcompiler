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

namespace ast {

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

  // The static type of this expression. Cannot be called before typechecking.
  // auto static_type() const -> const Value& {
  //   PXC_CHECK(static_type_.has_value());
  //   return **static_type_;
  // }

  // Sets the static type of this expression. Can only be called once, during
  // typechecking.
  // void set_static_type(Nonnull<const Value*> type) {
  //   PXC_CHECK(!static_type_.has_value());
  //   static_type_ = type;
  // }

  // The value category of this expression. Cannot be called before
  // typechecking.
  // auto value_category() const -> ValueCategory { return *value_category_; }

  // Sets the value category of this expression. Can be called multiple times,
  // but the argument must have the same value each time.
  // void set_value_category(ValueCategory value_category) {
  //   PXC_CHECK(!value_category_.has_value() ||
  //                value_category == *value_category_);
  //   value_category_ = value_category;
  // }

  // Determines whether the expression has already been type-checked. Should
  // only be used by type-checking.
  // auto is_type_checked() -> bool {
  //   return static_type_.has_value() && value_category_.has_value();
  // }

 protected:
  // Constructs an Expression representing syntax at the given line number.
  // `kind` must be the enumerator corresponding to the most-derived type being
  // constructed.
  Expression(AstNodeKind kind, common::SourceLocation source_loc)
      : AstNode(kind, source_loc) {}

 private:
  // std::optional<Nonnull<const Value*>> static_type_;
  // std::optional<ValueCategory> value_category_;
};


} // namespace ast
