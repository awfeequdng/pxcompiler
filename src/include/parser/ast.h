#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <vector>

#include "common/pos.h"
#include "parser/token.h"

using namespace std;

namespace   {

typedef uint64_t uint64;
typedef int64_t int64;

struct Visitor;
struct Node;

using NodePtr = std::shared_ptr<Node>;
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
    virtual bool Accept(Visitor *v, Node *node) {};
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
struct OptBinary {
    bool IsBinary;
    std::string Charset;
};

// FuncNode represents function call expression node.
struct FuncNode : ExprNode {
    virtual void functionExpression() {};
};
using FuncNodePtr = std::shared_ptr<FuncNode>;

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
using VisitorPtr = std::shared_ptr<Visitor>;

// All expression nodes implement the Expr interface.
class Expr : public Node {
public:
    virtual void exprNode() {};
};

// All statement nodes implement the Stmt interface.
class Stmt : public Node {
public:
    virtual void stmtNode() {};
};

// All declaration nodes implement the Decl interface.
class Decl : public Node {
public:
    virtual void declNode() {};
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

using CommentPtr = std::shared_ptr<Comment>;

// A CommentGroup represents a sequence of comments
// with no other tokens and no empty lines between.
//
class CommentGroup : public Node {
public:
    std::vector<CommentPtr> list; // list.size() > 0
};
using CommentGroupPtr = std::shared_ptr<CommentGroup>;

// An Ident node represents an identifier.
class Ident : public Node {
public:
	common::Pos namePos;    // identifier position
	std::string name;       // identifier name
};
using IdentPtr = std::shared_ptr<Ident>;


// An Ellipsis node stands for the "..." type in a
// parameter list or the "..." length in an array type.
//
class Ellipsis {
public:
    common::Pos ellipsis;   // position of "..."
    Expr elt;               // ellipsis element type (parameter lists only); or nil
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
using BasicLitPtr = std::shared_ptr<BasicLit>;

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
	Expr    Type;                   // field/method/parameter type
	BasicLitPtr Tag;               // field tag; or nil
	CommentGroupPtr Comment;         // line comments; or nil
};
using FieldPtr = std::shared_ptr<Field>;
using FieldList = std::vector<Field>;

// An ArrayType node represents an array or slice type.
class ArrayType {
public:
	common::Pos lbrackPos; // position of "["
	Expr len;           // Ellipsis node for [...]T array types, nil for slice types
	Expr elt;           // element type
};

// A StructType node represents a struct type.
class StructType {
public:
	common::Pos structPos;          // position of "struct" keyword
	FieldList fields;               // list of field declarations
	bool incomplete;                // true if (source) fields are missing in the Fields list
};

// Pointer types are represented via StarExpr nodes.

// A FuncType node represents a function type.
class FuncType {
public:
	common::Pos funcPos;   // position of "func" keyword (token.NoPos if there is no "func")
	FieldList params;   // (incoming) parameters; non-nil
	FieldList results;  // (outgoing) results; or nil
};

// A MapType node represents a map type.
class MapType {
public:
	common::Pos mapPos;   // position of "map" keyword
	Expr key;
	Expr value;
};


} // namespace parser
