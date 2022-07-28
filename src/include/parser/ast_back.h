#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <vector>

#include "common/pos.h"
#include "parser/token.h"

using namespace std;

namespace parser {

typedef uint64_t uint64;
typedef int64_t int64;

struct Visitor;
struct Node;
using NodePtr = std::shared_ptr<Node>;

struct BlockStmt;
struct BranchStmt;
struct ExprStmt;
struct CommClause;

using BlockStmtPtr = std::shared_ptr<BlockStmt>;
using BranchStmtPtr = std::shared_ptr<BranchStmt>;
using ExprStmtPtr = std::shared_ptr<ExprStmt>;
using CommClausePtr = std::shared_ptr<CommClause>;

struct Ellipsis;
struct BasicLit;
struct Field;
struct ArrayType;
struct StructType;
struct FuncType;
struct MapType;
struct FuncLit;
struct CompositeLit;
struct DeclStmt;
struct EmptyStmt;
struct SwitchStmt;
struct RangeStmt;
struct SendStmt;
struct AssignStmt;
struct ReturnStmt;
struct IfStmt;
struct SelectStmt;
struct LabeledStmt;
struct DeferStmt;
struct ForStmt;
struct IncDecStmt;
struct CaseClause;
struct TypeSwitchStmt;
struct GoStmt;
using EllipsisPtr = std::shared_ptr<Ellipsis>;
using BasicLitPtr = std::shared_ptr<BasicLit>;
using FieldList = std::vector<Field>;
using ArrayTypePtr = std::shared_ptr<ArrayType>;
using StructTypePtr = std::shared_ptr<StructType>;
using FuncTypePtr = std::shared_ptr<FuncType>;
using MapTypePtr = std::shared_ptr<MapType>;
using FuncLitPtr = std::shared_ptr<FuncLit>;
using CompositeLitPtr = std::shared_ptr<CompositeLit>;
using DeclStmtPtr = std::shared_ptr<DeclStmt>;
using EmptyStmtPtr = std::shared_ptr<EmptyStmt>;
using SwitchStmtPtr = std::shared_ptr<SwitchStmt>;
using RangeStmtPtr = std::shared_ptr<RangeStmt>;
using SendStmtPtr = std::shared_ptr<SendStmt>;
using AssignStmtPtr = std::shared_ptr<AssignStmt>;
using ReturnStmtPtr = std::shared_ptr<ReturnStmt>;
using IfStmtPtr = std::shared_ptr<IfStmt>;
using SelectStmtPtr = std::shared_ptr<SelectStmt>;
using LabeledStmtPtr = std::shared_ptr<LabeledStmt>;
using DeferStmtPtr = std::shared_ptr<DeferStmt>;
using ForStmtPtr = std::shared_ptr<ForStmt>;
using IncDecStmtPtr = std::shared_ptr<IncDecStmt>;
using CaseClausePtr = std::shared_ptr<CaseClause>;
using TypeSwitchStmtPtr = std::shared_ptr<TypeSwitchStmt>;
using GoStmtPtr = std::shared_ptr<GoStmt>;


struct FuncNode;
struct Visitor;
struct Expr;
struct Stmt;
struct Decl;
struct Comment;
struct CommentGroup;
struct Ident;
struct Field;
using FuncNodePtr = std::shared_ptr<FuncNode>;
using VisitorPtr = std::shared_ptr<Visitor>;
using ExprPtr = std::shared_ptr<Expr>;
using StmtPtr = std::shared_ptr<Stmt>;
using DeclPtr = std::shared_ptr<Decl>;
using CommentPtr = std::shared_ptr<Comment>;
using CommentGroupPtr = std::shared_ptr<CommentGroup>;
using IdentPtr = std::shared_ptr<Ident>;
using FieldPtr = std::shared_ptr<Field>;

struct SliceExpr;
struct CallExpr;
struct KeyValueExpr;
struct KeyValueExpr;
struct StarExpr;
struct UnaryExpr;
struct BinaryExpr;
struct ParenExpr;
struct SelectorExpr;
struct IndexExpr;
struct TypeAssertExpr;
using SliceExprPtr = std::shared_ptr<SliceExpr>;
using CallExprPtr = std::shared_ptr<CallExpr>;
using KeyValueExprPtr = std::shared_ptr<KeyValueExpr>;
using StarExprPtr = std::shared_ptr<StarExpr>;
using UnaryExprPtr = std::shared_ptr<UnaryExpr>;
using BinaryExprPtr = std::shared_ptr<BinaryExpr>;
using ParenExprPtr = std::shared_ptr<ParenExpr>;
using SelectorExprPtr = std::shared_ptr<SelectorExpr>;
using IndexExprPtr = std::shared_ptr<IndexExpr>;
using TypeAssertExprPtr = std::shared_ptr<TypeAssertExpr>;
// Node is the basic element of the AST.
// Interfaces embed Node should have 'Node' name suffix.
struct Node : public std::enable_shared_from_this<Node> {
    std::string text;
    // Accept accepts Visitor to visit itself.
    // The returned node should replace original node.
    // ok returns false to stop visiting.
    //
    // Implementation of this method should first call visitor.Enter,
    // assign the returned node to its method receiver, if skipChildren returns true,
    // children should be skipped. Otherwise, call its children in particular order that
    // later elements depends on former elements. Finally, return visitor.Leave.
    virtual bool Accept(Visitor *v, Node *node) = 0;
    // Text returns the original text of the element.
    virtual std::string Text() { return text; }
    // SetText sets original text to the Node.
    virtual void SetText(std::string txt) { this->text = txt; };

    virtual ~Node() = default;
};

// Flags indicates whether an expression contains certain types of expression.

#define FlagConstant  0ul
#define FlagHasFunc   1ul << 0
#define FlagHasReference 1ul << 1
#define FlagHasAggregateFunc 1ul << 2
#define FlagHasVariable 1ul << 3
#define FlagHasDefault 1ul << 4

// ExprNode is a node that can be evaluated.
// Name of implementations should have 'Expr' suffix.
struct ExprNode : Node {
    // Format formats the AST into a writer.
    virtual void Format(std::iostream &writer) = 0;
};
using ExprNodePtr = std::shared_ptr<ExprNode>;

// OptBinary is used for parser.
struct OptBinary : Node {
    bool IsBinary;
    std::string Charset;
};

// FuncNode represents function call expression node.
struct FuncNode : public ExprNode {
    virtual void functionExpression() {};
};

// Visitor visits a Node.
struct Visitor {
    // Enter is called before children nodes are visited.
    // The returned node must be the same type as the input node n.
    // skipChildren returns true means children nodes should be skipped,
    // this is useful when work is done in Enter and there is no need to visit children.
    virtual bool Enter(NodePtr n, NodePtr node) = 0;
    // Leave is called after children nodes have been visited.
    // The returned node's type can be different from the input node if it is a ExprNode,
    // Non-expression node must be the same type as the input node n.
    // ok returns false to stop visiting.
    virtual bool Leave(NodePtr n, NodePtr node) = 0;
};

// All expression nodes implement the Expr interface.
class Expr : public Node {
public:
    virtual void exprNode() = 0;
};

// All statement nodes implement the Stmt interface.
class Stmt : public Node {
public:
    virtual void stmtNode() = 0;
};

// All declaration nodes implement the Decl interface.
class Decl : public Node {
public:
    virtual void declNode() = 0;
};

// ----------------------------------------------------------------------------
// Comments

// A Comment node represents a single //-style or /*-style comment.
//
// The Text field contains the comment text without carriage returns (\r) that
// may have been present in the source. Because a comment's end position is
// computed using len(Text), the position reported by End() does not match the
// true source end position for comments containing carriage returns.
class Comment : public Node {
public:
    inline common::Pos pos() { return slash; }

	common::Pos slash; // position of "/" starting the comment
	std::string text; // comment text (excluding '\n' for //-style comments)
};

// A CommentGroup represents a sequence of comments
// with no other tokens and no empty lines between.
//
class CommentGroup : public Node {
public:
    std::vector<CommentPtr> list; // list.size() > 0
};

// An Ident node represents an identifier.
class Ident : public Node {
public:
	common::Pos namePos;    // identifier position
	std::string name;       // identifier name
};

// An Ellipsis node stands for the "..." type in a
// parameter list or the "..." length in an array type.
//
class Ellipsis : public Node {
public:
    common::Pos ellipsis;   // position of "..."
    ExprPtr elt;               // ellipsis element type (parameter lists only); or nil
};

// A BasicLit node represents a literal of basic type.
//
// Note that for the CHAR and STRING kinds, the literal is stored
// with its quotes. For example, for a double-quoted STRING, the
// first and the last rune in the Value field will be ". The
// Unquote and UnquoteChar functions in the strconv package can be
// used to unquote STRING and CHAR values, respectively.
class BasicLit : public Node {
public:
	common::Pos valuePos;   // literal position
	Token       kind;       // Token.tok_intLit, Token.tok_floatLit, Token.IMAG, Token.tok_charLit, or Token.tok_stringLit
	std::string value;      // literal string; e.g. 42, 0x7f, 3.14, 1e-9, 2.4i, 'a', '\x7f', "foo" or `\m\n\o`
};

// ----------------------------------------------------------------------------
// Expressions and types
// A Field represents a Field declaration list in a struct type,
// a method list in an interface type, or a parameter/result declaration
// in a signature.
// Field.Names is nil for unnamed parameters (parameter lists which only contain types)
// and embedded struct fields. In the latter case, the field name is the type name.
//
class Field : public Node {
public:
	CommentGroupPtr Doc;            // associated documentation; or nil
	std::vector<IdentPtr> names;    // field/method/parameter names; or nil
	ExprPtr    Type;                   // field/method/parameter type
	BasicLitPtr Tag;               // field tag; or nil
	CommentGroupPtr Comment;         // line comments; or nil
};

// An ArrayType node represents an array or slice type.
class ArrayType : public Node {
public:
	common::Pos lbrackPos; // position of "["
	ExprPtr len;           // Ellipsis node for [...]T array types, nil for slice types
	ExprPtr elt;           // element type
};

// A StructType node represents a struct type.
class StructType : public Node {
public:
	common::Pos structPos;          // position of "struct" keyword
	FieldList fields;               // list of field declarations
	bool incomplete;                // true if (source) fields are missing in the Fields list
};

// Pointer types are represented via StarExpr nodes.

// A FuncType node represents a function type.
class FuncType : public Node {
public:
	common::Pos funcPos;   // position of "func" keyword (token.NoPos if there is no "func")
	FieldList params;   // (incoming) parameters; non-nil
	FieldList results;  // (outgoing) results; or nil
};

// A MapType node represents a map type.
class MapType : public Node {
public:
	common::Pos mapPos;   // position of "map" keyword
	ExprPtr key;
	ExprPtr value;
};

// A FuncLit node represents a function literal.
class FuncLit : public Node {
public:
    FuncTypePtr type;   // function type
    BlockStmtPtr body;  // function body
};

// A CompositeLit node represents a composite literal.
struct CompositeLit : public Node {
	ExprPtr type;              // literal type; or nil
	common::Pos lbrace;     // position of "{"
	std::vector<ExprPtr> elts; // list of composite elements; or nil
	common::Pos rbrace;     // position of "}"
	bool incomplete;        // true if (source) expressions are missing in the Elts list
};

struct IndexExpr : public Node {
    ExprPtr X;
    common::Pos Lbrack;
    ExprPtr Index;
    common::Pos Rbrack;
};
struct TypeAssertExpr : public Node {
    ExprPtr X;
    common::Pos Lparen;
    ExprPtr Type;
    common::Pos Rparen;
};

struct CallExpr : public Node {
    ExprPtr Fun;
    common::Pos Lparen;
    std::vector<ExprPtr> Args;
    common::Pos Ellipsis;
    common::Pos Rparen;
};

struct BinaryExpr : public Node {
    ExprPtr X;
    common::Pos OpPos;
    Token Op;
    ExprPtr Y;
};
struct KeyValueExpr : public Node {
    ExprPtr Key;
    common::Pos Colon;
    ExprPtr Value;
};

struct ParenExpr : public Node {
    common::Pos Lparen;
    ExprPtr X;
    common::Pos Rparen;
};
struct SliceExpr : public Node {
    ExprPtr X;
    common::Pos Lbrack;
    ExprPtr Low;
    ExprPtr High;
    ExprPtr Max;
    bool Slice3;
    common::Pos Rbrack;
};

struct StarExpr : public Node {
    common::Pos Star;
    ExprPtr X;
};

struct UnaryExpr : public Node {
    common::Pos OpPos;
    Token Op;
    ExprPtr X;
};

struct SelectorExpr : public Node {
    ExprPtr X;
    IdentPtr Sel;
};

// A DeclStmt node represents a declaration in a statement list.
struct DeclStmt : Node {
	DeclPtr decl; // *GenDecl with CONST, TYPE, or VAR token
};

// An EmptyStmt node represents an empty statement.
// The "position" of the empty statement is the position
// of the immediately following (explicit or implicit) semicolon.
//
struct EmptyStmt : public Node {
	common::Pos semicolon;      // position of following ";"
	bool Implicit;              // if set, ";" was omitted in the source
};

struct BlockStmt: public Node {
    common::Pos Lbrace;
    std::vector<StmtPtr> List;
    common::Pos Rbrace;
};

struct SwitchStmt : public Node {
    common::Pos Switch;
    StmtPtr Init;
    ExprPtr Tag;
    BlockStmtPtr Body;
};

struct RangeStmt: public Node {
    common::Pos For;
    ExprPtr Key;
    ExprPtr Value;
    common::Pos TokPos;
    Token Tok;
    ExprPtr X;
    BlockStmtPtr Body;
};

struct SendStmt : public Node {
    ExprPtr Chan;
    common::Pos Arrow;
    ExprPtr Value;
};

struct AssignStmt : public Node {
    std::vector<ExprPtr> Lhs;
    common::Pos TokPos;
    Token Tok;
    std::vector<ExprPtr> Rhs;
};

struct ReturnStmt: public Node {
    common::Pos Return;
    std::vector<ExprPtr> Results;
};

struct BranchStmt : public Node {
    common::Pos TokPos;
    Token Tok;
    Ident* Label;
};

struct IfStmt : public Node {
    common::Pos If;
    StmtPtr Init;
    ExprPtr Cond;
    BlockStmtPtr Body;
    StmtPtr Else;
};

struct SelectStmt : public Node {
    common::Pos Select;
    BlockStmtPtr Body;
};

struct LabeledStmt : public Node {
    IdentPtr Label;
    common::Pos Colon;
    StmtPtr Stmt;
};

struct ExprStmt : public Node {
    ExprPtr X;
};


struct DeferStmt : public Node {
    common::Pos Defer;
    CallExprPtr Call;
};

struct ForStmt : public Node {
    common::Pos For;
    StmtPtr Init;
    ExprPtr Cond;
    StmtPtr Post;
    BlockStmtPtr Body;
};

struct IncDecStmt : public Node {
    ExprPtr X;
    common::Pos TokPos;
    Token Tok;
};

struct GoStmt : public Node {
    common::Pos Go;
    CallExprPtr Call;
};

struct CaseClause : public Node {
    common::Pos Case;
    std::vector<ExprPtr> List;
    common::Pos Colon;
    std::vector<StmtPtr> Body;
};

struct TypeSwitchStmt : public Node {
    common::Pos Switch;
    StmtPtr Init;
    StmtPtr Assign;
    BlockStmtPtr Body;
};

struct CommClause : public Node {
    common::Pos Case;
    StmtPtr Comm;
    common::Pos Colon;
    std::vector<StmtPtr> Body;
};

} // namespace parser
