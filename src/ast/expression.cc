
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
  // switch (kind()) {
  //   case ExpressionKind::Name:
  //     out << cast<Name>(this)->name();
  //     break;
  //   default:
  //     break;
  // }
  PrintID(out);
}

void Expression::PrintID(llvm::raw_ostream& out) const {
  switch (kind()) {
    case ExpressionKind::Name:
      out << "Name:" << cast<Name>(*this).name();
      break;
    case ExpressionKind::ConstantInt:
      out << cast<ConstantInt>(*this).value();
      break;
    case ExpressionKind::ConstantBool:
      out << (cast<ConstantBool>(*this).value() ? "True" : "False");
      break;
    case ExpressionKind::ConstantNone:
      out << "None";
      break;
    case ExpressionKind::ConstantEllipsis:
      out << "...";
      break;
    case ExpressionKind::ConstantFloat:
      out << cast<ConstantFloat>(*this).value();
      break;
    case ExpressionKind::ConstantComplex: {
      out << cast<ConstantComplex>(*this).real();
      auto image = cast<ConstantComplex>(*this).image();
      if (!(image < 0)) {
        out << "+";
      }
      out << image << "j";
      break;
    }
    case ExpressionKind::ConstantStr:
      out << "ConstStr(" << cast<ConstantStr>(*this).value() << ")";
      for (auto &expr : cast<ConstantStr>(*this).extend()) {
        out << *expr;
      }
      break;
    case ExpressionKind::JoinedStr: {
      const auto &values = cast<JoinedStr>(*this).values();
      for (auto &val : values) {
        out << *val;
      }
      break;
    }
    case ExpressionKind::ConstantBytes:
      out << cast<ConstantBytes>(*this).value();
      for (auto &expr : cast<ConstantStr>(*this).extend()) {
        out << *expr;
      }
      break;
    case ExpressionKind::FormattedValue:
      out << "{" << *(cast<FormattedValue>(*this).value()) << "}";
      break;
    case ExpressionKind::Tuple:
      out << "Tuple(";
      for (auto &elt: cast<Tuple>(*this).elements()) {
        out << *elt << ",";
      }
      out << ")";
      break;
    case ExpressionKind::List:
      out << "List[";
      for (auto &elt: cast<List>(*this).elements()) {
        out << *elt << ",";
      }
      out << "]";
      break;
    case ExpressionKind::Set:
      out << "Set{";
      for (auto &elt: cast<Set>(*this).elements()) {
        out << *elt << ",";
      }
      out << "}";
      break;
    case ExpressionKind::Attribute:
      out << "Attribute: " << *(cast<Attribute>(*this).value())
          << "." << *(cast<Attribute>(*this).attr());
      break;
    default:
      out << "...";
      break;
  }
}

}  // namespace pxcompiler
