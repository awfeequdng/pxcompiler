#pragma once
#include <string>
#include <iostream>

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
    uint64 flag;
    // SetFlag sets flag to the expression.
    // Flag indicates whether the expression contains
    // parameter marker, reference, aggregate function...
    virtual void SetFlag(uint64 flg) {
        this->flag = flg;
    }
    // GetFlag returns the flag of the expression.
    virtual uint64 GetFlag() {
        return flag;
    }

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
}
