// Part of the Carbon Language project, under the Apache License v2.0 with LLVM
// Exceptions. See /LICENSE for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception


#include "ast/statement.h"
#include "ast/name.h"
#include "ast/expression.h"
#include "common/check.h"
#include "common/arena.h"
#include "llvm/Support/Casting.h"

namespace pxcompiler {

using llvm::cast;

Statement::~Statement() = default;

void Statement::PrintDepth(int depth, llvm::raw_ostream& out) const {
    if (depth == 0) {
      out << " ... ";
      return;
    }
    switch (kind()) {
      case StatementKind::ExprStmt: {
          const auto &expr = cast<ExprStmt>(*this).expression();
          out << expr << "\n";
          break;
      }
      case StatementKind::If: {
          auto &if_stmt = cast<If>(*this);
          auto &test = if_stmt.test();
          auto &body = if_stmt.body();
          auto &orelse = if_stmt.orelse();
          out << "if " << test << ":\n";
          for (auto &b: body) {
            out << "\t" << *b << "\n";
          }
          if (orelse.size()) {
            out << "else:\n";
          }
          for (auto &o: orelse) {
            out << "\t" << *o << "\n";
          }
          break;
      }
      default:
        out << "unknown kind: ";
        break;
    }
}

}  // namespace pxcompiler
