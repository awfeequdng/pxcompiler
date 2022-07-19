#pragma once
#include <string>
#include <iostream>

#include "common/pos.h"

using namespace std;

namespace ast {

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
	common::Pos slash; // position of "/" starting the comment
	std::string text; // comment text (excluding '\n' for //-style comments)
};

} // namespace ast
