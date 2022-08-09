
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

std::string operatorTypeStr(const operatorType &x) {
    switch (x) {
        case (operatorType::Add) : {
            return "+";
        }
        case (operatorType::Sub) : {
            return "-";
        }
        case (operatorType::Mult) : {
            return "*";
        }
        case (operatorType::MatMult) : {
            return "@";
        }
        case (operatorType::Div) : {
            return "/";
        }
        case (operatorType::Mod) : {
            return "%";
        }
        case (operatorType::Pow) : {
            return "**";
        }
        case (operatorType::LShift) : {
            return "LShift";
        }
        case (operatorType::RShift) : {
            return "RShift";
        }
        case (operatorType::BitOr) : {
            return "BitOr";
        }
        case (operatorType::BitXor) : {
            return "BitXor";
        }
        case (operatorType::BitAnd) : {
            return "BitAnd";
        }
        case (operatorType::FloorDiv) : {
            return "//";
        }
    }
    return "UnknowOperatorType";
}

std::string unaryopTypeStr(const unaryopType &x) {
    switch (x) {
        case (unaryopType::Invert) : {
            return "~ ";
        }
        case (unaryopType::Not) : {
            return "not ";
        }
        case (unaryopType::UAdd) : {
            return "+ ";
        }
        case (unaryopType::USub) : {
            return "- ";
        }
    }
    return "UnknowunaryopType";
}

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
      out << "Name(" << cast<Name>(*this).name() << ")";
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
      out << "Attribute(" << *(cast<Attribute>(*this).value())
          << "." << *(cast<Attribute>(*this).attr())
          << ")";
      break;
    case ExpressionKind::Dict: {
      out << "Dict{";
      size_t cnt = 0;
      size_t sz = cast<Dict>(*this).key_value().size();
      for (auto &key_val : cast<Dict>(*this).key_value()) {
        out << *(key_val.first) << ":" << *(key_val.second);
        cnt++;
        if (cnt < sz) out << ", ";
      }
      out << "}";
      break;
    }
    case ExpressionKind::NamedExpr:
      out << "NamedExpr(" << *(cast<NamedExpr>(*this).target())
          << ":=" << *(cast<NamedExpr>(*this).value())
          << ")";
      break;
    case ExpressionKind::BinOp:
      out << "BinOp(" << *(cast<BinOp>(*this).left())
          << operatorTypeStr(cast<BinOp>(*this).op())
          << *(cast<BinOp>(*this).right())
          << ")";
      break;
    case ExpressionKind::UnaryOp:
      out << "UnaryOp("
          << unaryopTypeStr(cast<UnaryOp>(*this).op())
          << *(cast<UnaryOp>(*this).operand())
          << ")";
      break;
    case ExpressionKind::Starred:
      out << "Starred(*" << *(cast<Starred>(*this).value()) << ")";
      break;
    default:
      out << "...";
      break;
  }
}

}  // namespace pxcompiler
