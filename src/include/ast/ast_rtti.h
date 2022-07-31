// Generated from ast_rtti.txt by gen_rtti.py

#ifndef AST_RTTI_TXT_
#define AST_RTTI_TXT_

#include <string_view>

namespace pxcompiler {

enum class AstNodeKind {
  Module = 0,
  Interactive = 1,
  ModExpression = 2,
  FunctionType = 3,
  FunctionDef = 4,
  AsyncFunctionDef = 5,
  ClassDef = 6,
  Return = 7,
  Delete = 8,
  Assign = 9,
  AugAssign = 10,
  AnnAssign = 11,
  For = 12,
  AsyncFor = 13,
  While = 14,
  If = 15,
  With = 16,
  AsyncWith = 17,
  Match = 18,
  Raise = 19,
  Try = 20,
  Assert = 21,
  Import = 22,
  ImportFrom = 23,
  Global = 24,
  Nolocal = 25,
  ExprStmt = 26,
  Pass = 27,
  Break = 28,
  Continue = 29,
  BoolOp = 30,
  NamedExpr = 31,
  BinOp = 32,
  UnaryOp = 33,
  Lambda = 34,
  IfExp = 35,
  Dict = 36,
  Set = 37,
  ListComp = 38,
  SetComp = 39,
  DictComp = 40,
  GeneratorExp = 41,
  Await = 42,
  Yield = 43,
  YieldFrom = 44,
  Compare = 45,
  Call = 46,
  FormattedValue = 47,
  JoinedStr = 48,
  ConstantStr = 49,
  ConstantFloat = 50,
  ConstantComplex = 51,
  ConstantEllipsis = 52,
  ConstantNone = 53,
  ConstantBytes = 54,
  Attribute = 55,
  Subscript = 56,
  Starred = 57,
  Name = 58,
  List = 59,
  Tuple = 60,
  Slice = 61,
  ExceptHandler = 62,
  MatchValue = 63,
  MatchSingleton = 64,
  MatchSequence = 65,
  MatchMapping = 66,
  MatchClass = 67,
  MatchStar = 68,
  MatchAs = 69,
  MatchOr = 70,
  TypeIgnore = 71,
};

std::string_view AstNodeKindName(AstNodeKind k);

enum class ModuleBaseKind {
  Module = 0,
  Interactive = 1,
  ModExpression = 2,
  FunctionType = 3,
};

std::string_view ModuleBaseKindName(ModuleBaseKind k);

inline bool InheritsFromModuleBase(AstNodeKind kind) {
  return kind >= AstNodeKind::Module
      && kind < AstNodeKind::FunctionDef
      ;
}

inline bool InheritsFromModule(AstNodeKind kind) {
    return kind == AstNodeKind::Module;
}

inline bool InheritsFromInteractive(AstNodeKind kind) {
    return kind == AstNodeKind::Interactive;
}

inline bool InheritsFromModExpression(AstNodeKind kind) {
    return kind == AstNodeKind::ModExpression;
}

inline bool InheritsFromFunctionType(AstNodeKind kind) {
    return kind == AstNodeKind::FunctionType;
}

enum class StatementKind {
  FunctionDef = 4,
  AsyncFunctionDef = 5,
  ClassDef = 6,
  Return = 7,
  Delete = 8,
  Assign = 9,
  AugAssign = 10,
  AnnAssign = 11,
  For = 12,
  AsyncFor = 13,
  While = 14,
  If = 15,
  With = 16,
  AsyncWith = 17,
  Match = 18,
  Raise = 19,
  Try = 20,
  Assert = 21,
  Import = 22,
  ImportFrom = 23,
  Global = 24,
  Nolocal = 25,
  ExprStmt = 26,
  Pass = 27,
  Break = 28,
  Continue = 29,
};

std::string_view StatementKindName(StatementKind k);

inline bool InheritsFromStatement(AstNodeKind kind) {
  return kind >= AstNodeKind::FunctionDef
      && kind < AstNodeKind::BoolOp
      ;
}

inline bool InheritsFromFunctionDef(AstNodeKind kind) {
    return kind == AstNodeKind::FunctionDef;
}

inline bool InheritsFromAsyncFunctionDef(AstNodeKind kind) {
    return kind == AstNodeKind::AsyncFunctionDef;
}

inline bool InheritsFromClassDef(AstNodeKind kind) {
    return kind == AstNodeKind::ClassDef;
}

inline bool InheritsFromReturn(AstNodeKind kind) {
    return kind == AstNodeKind::Return;
}

inline bool InheritsFromDelete(AstNodeKind kind) {
    return kind == AstNodeKind::Delete;
}

inline bool InheritsFromAssign(AstNodeKind kind) {
    return kind == AstNodeKind::Assign;
}

inline bool InheritsFromAugAssign(AstNodeKind kind) {
    return kind == AstNodeKind::AugAssign;
}

inline bool InheritsFromAnnAssign(AstNodeKind kind) {
    return kind == AstNodeKind::AnnAssign;
}

inline bool InheritsFromFor(AstNodeKind kind) {
    return kind == AstNodeKind::For;
}

inline bool InheritsFromAsyncFor(AstNodeKind kind) {
    return kind == AstNodeKind::AsyncFor;
}

inline bool InheritsFromWhile(AstNodeKind kind) {
    return kind == AstNodeKind::While;
}

inline bool InheritsFromIf(AstNodeKind kind) {
    return kind == AstNodeKind::If;
}

inline bool InheritsFromWith(AstNodeKind kind) {
    return kind == AstNodeKind::With;
}

inline bool InheritsFromAsyncWith(AstNodeKind kind) {
    return kind == AstNodeKind::AsyncWith;
}

inline bool InheritsFromMatch(AstNodeKind kind) {
    return kind == AstNodeKind::Match;
}

inline bool InheritsFromRaise(AstNodeKind kind) {
    return kind == AstNodeKind::Raise;
}

inline bool InheritsFromTry(AstNodeKind kind) {
    return kind == AstNodeKind::Try;
}

inline bool InheritsFromAssert(AstNodeKind kind) {
    return kind == AstNodeKind::Assert;
}

inline bool InheritsFromImport(AstNodeKind kind) {
    return kind == AstNodeKind::Import;
}

inline bool InheritsFromImportFrom(AstNodeKind kind) {
    return kind == AstNodeKind::ImportFrom;
}

inline bool InheritsFromGlobal(AstNodeKind kind) {
    return kind == AstNodeKind::Global;
}

inline bool InheritsFromNolocal(AstNodeKind kind) {
    return kind == AstNodeKind::Nolocal;
}

inline bool InheritsFromExprStmt(AstNodeKind kind) {
    return kind == AstNodeKind::ExprStmt;
}

inline bool InheritsFromPass(AstNodeKind kind) {
    return kind == AstNodeKind::Pass;
}

inline bool InheritsFromBreak(AstNodeKind kind) {
    return kind == AstNodeKind::Break;
}

inline bool InheritsFromContinue(AstNodeKind kind) {
    return kind == AstNodeKind::Continue;
}

enum class ExpressionKind {
  BoolOp = 30,
  NamedExpr = 31,
  BinOp = 32,
  UnaryOp = 33,
  Lambda = 34,
  IfExp = 35,
  Dict = 36,
  Set = 37,
  ListComp = 38,
  SetComp = 39,
  DictComp = 40,
  GeneratorExp = 41,
  Await = 42,
  Yield = 43,
  YieldFrom = 44,
  Compare = 45,
  Call = 46,
  FormattedValue = 47,
  JoinedStr = 48,
  ConstantStr = 49,
  ConstantFloat = 50,
  ConstantComplex = 51,
  ConstantEllipsis = 52,
  ConstantNone = 53,
  ConstantBytes = 54,
  Attribute = 55,
  Subscript = 56,
  Starred = 57,
  Name = 58,
  List = 59,
  Tuple = 60,
  Slice = 61,
};

std::string_view ExpressionKindName(ExpressionKind k);

inline bool InheritsFromExpression(AstNodeKind kind) {
  return kind >= AstNodeKind::BoolOp
      && kind < AstNodeKind::ExceptHandler
      ;
}

inline bool InheritsFromBoolOp(AstNodeKind kind) {
    return kind == AstNodeKind::BoolOp;
}

inline bool InheritsFromNamedExpr(AstNodeKind kind) {
    return kind == AstNodeKind::NamedExpr;
}

inline bool InheritsFromBinOp(AstNodeKind kind) {
    return kind == AstNodeKind::BinOp;
}

inline bool InheritsFromUnaryOp(AstNodeKind kind) {
    return kind == AstNodeKind::UnaryOp;
}

inline bool InheritsFromLambda(AstNodeKind kind) {
    return kind == AstNodeKind::Lambda;
}

inline bool InheritsFromIfExp(AstNodeKind kind) {
    return kind == AstNodeKind::IfExp;
}

inline bool InheritsFromDict(AstNodeKind kind) {
    return kind == AstNodeKind::Dict;
}

inline bool InheritsFromSet(AstNodeKind kind) {
    return kind == AstNodeKind::Set;
}

inline bool InheritsFromListComp(AstNodeKind kind) {
    return kind == AstNodeKind::ListComp;
}

inline bool InheritsFromSetComp(AstNodeKind kind) {
    return kind == AstNodeKind::SetComp;
}

inline bool InheritsFromDictComp(AstNodeKind kind) {
    return kind == AstNodeKind::DictComp;
}

inline bool InheritsFromGeneratorExp(AstNodeKind kind) {
    return kind == AstNodeKind::GeneratorExp;
}

inline bool InheritsFromAwait(AstNodeKind kind) {
    return kind == AstNodeKind::Await;
}

inline bool InheritsFromYield(AstNodeKind kind) {
    return kind == AstNodeKind::Yield;
}

inline bool InheritsFromYieldFrom(AstNodeKind kind) {
    return kind == AstNodeKind::YieldFrom;
}

inline bool InheritsFromCompare(AstNodeKind kind) {
    return kind == AstNodeKind::Compare;
}

inline bool InheritsFromCall(AstNodeKind kind) {
    return kind == AstNodeKind::Call;
}

inline bool InheritsFromFormattedValue(AstNodeKind kind) {
    return kind == AstNodeKind::FormattedValue;
}

inline bool InheritsFromJoinedStr(AstNodeKind kind) {
    return kind == AstNodeKind::JoinedStr;
}

inline bool InheritsFromConstantStr(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantStr;
}

inline bool InheritsFromConstantFloat(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantFloat;
}

inline bool InheritsFromConstantComplex(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantComplex;
}

inline bool InheritsFromConstantEllipsis(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantEllipsis;
}

inline bool InheritsFromConstantNone(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantNone;
}

inline bool InheritsFromConstantBytes(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantBytes;
}

inline bool InheritsFromAttribute(AstNodeKind kind) {
    return kind == AstNodeKind::Attribute;
}

inline bool InheritsFromSubscript(AstNodeKind kind) {
    return kind == AstNodeKind::Subscript;
}

inline bool InheritsFromStarred(AstNodeKind kind) {
    return kind == AstNodeKind::Starred;
}

inline bool InheritsFromName(AstNodeKind kind) {
    return kind == AstNodeKind::Name;
}

inline bool InheritsFromList(AstNodeKind kind) {
    return kind == AstNodeKind::List;
}

inline bool InheritsFromTuple(AstNodeKind kind) {
    return kind == AstNodeKind::Tuple;
}

inline bool InheritsFromSlice(AstNodeKind kind) {
    return kind == AstNodeKind::Slice;
}

inline bool InheritsFromExceptHandler(AstNodeKind kind) {
    return kind == AstNodeKind::ExceptHandler;
}

enum class PatternKind {
  MatchValue = 63,
  MatchSingleton = 64,
  MatchSequence = 65,
  MatchMapping = 66,
  MatchClass = 67,
  MatchStar = 68,
  MatchAs = 69,
  MatchOr = 70,
};

std::string_view PatternKindName(PatternKind k);

inline bool InheritsFromPattern(AstNodeKind kind) {
  return kind >= AstNodeKind::MatchValue
      && kind < AstNodeKind::TypeIgnore
      ;
}

inline bool InheritsFromMatchValue(AstNodeKind kind) {
    return kind == AstNodeKind::MatchValue;
}

inline bool InheritsFromMatchSingleton(AstNodeKind kind) {
    return kind == AstNodeKind::MatchSingleton;
}

inline bool InheritsFromMatchSequence(AstNodeKind kind) {
    return kind == AstNodeKind::MatchSequence;
}

inline bool InheritsFromMatchMapping(AstNodeKind kind) {
    return kind == AstNodeKind::MatchMapping;
}

inline bool InheritsFromMatchClass(AstNodeKind kind) {
    return kind == AstNodeKind::MatchClass;
}

inline bool InheritsFromMatchStar(AstNodeKind kind) {
    return kind == AstNodeKind::MatchStar;
}

inline bool InheritsFromMatchAs(AstNodeKind kind) {
    return kind == AstNodeKind::MatchAs;
}

inline bool InheritsFromMatchOr(AstNodeKind kind) {
    return kind == AstNodeKind::MatchOr;
}

inline bool InheritsFromTypeIgnore(AstNodeKind kind) {
    return kind == AstNodeKind::TypeIgnore;
}

}  // namespace pxcompiler

#endif  // AST_RTTI_TXT_
