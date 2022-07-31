
#include "ast/expression.h"

#include <map>
#include <optional>

#include "common/arena.h"
#include "common/error_builders.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"

#include "ast/name.h"

namespace pxcompiler {

using llvm::cast;
using llvm::isa;

Expression::~Expression() = default;

void Expression::Print(llvm::raw_ostream& out) const {
  switch (kind()) {
    case ExpressionKind::Name:
      out << cast<Name>(this)->name();
      break;
    default:
      break;
  }
}

void Expression::PrintID(llvm::raw_ostream& out) const {
  switch (kind()) {
    case ExpressionKind::Name:
      out << cast<Name>(this)->name();
      break;
    // case ExpressionKind::IntLiteral:
    //   out << cast<IntLiteral>(*this).value();
    //   break;
    // case ExpressionKind::BoolLiteral:
    //   out << (cast<BoolLiteral>(*this).value() ? "True" : "False");
    //   break;
    // case ExpressionKind::StringLiteral:
    //   out << "\"";
    //   out.write_escaped(cast<StringLiteral>(*this).value());
    //   out << "\"";
    //   break;

    // default:
    //   out << "...";
    //   break;
  }
}

}  // namespace pxcompiler
