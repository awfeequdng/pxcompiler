#pragma once

#include "ast/expression.h"

namespace pxcompiler
{
class Name : public Expression {
public:
    static pxcompiler::Nonnull<Name*> make_Name(
        pxcompiler::Nonnull<pxcompiler::Arena*> arena,
        pxcompiler::SourceLocation loc,
        std::string &name) {
        return arena->New<Name>(loc, name);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromName(node->kind());
    }

    Name(pxcompiler::SourceLocation loc, std::string name)
        : Expression(AstNodeKind::Name, loc),
          name_(std::move(name)) {}

    std::string name() const {
        return name_;
    }
private:
    std::string name_;
};
} // namespace pxcompiler
