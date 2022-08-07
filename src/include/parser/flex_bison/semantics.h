#pragma once

#include "ast/ast.h"
#include "ast/name.h"
#include "ast/statement.h"
#include "llvm/Support/Casting.h"

#include <iostream>
using NonnullExpr = pxcompiler::Nonnull<pxcompiler::Expression*>;
using NonnullArena = pxcompiler::Nonnull<pxcompiler::Arena*>;

#define RESULT(x) do { \
    if (*ast == std::nullopt) { \
        *ast = std::make_shared<pxcompiler::AST>();    \
    }   \
    ast->value()->statements.push_back(x);   \
} while (0)

#define SYMBOL(x, l) pxcompiler::Name::make_Name(arena, l, x)

#define LIST_NEW(l) l.reserve(4)
#define LIST_ADD(l, x) l.push_back(x)

#define EXPR_01(e, l) pxcompiler::ExprStmt::make_ExprStmt(arena, l, e)

#define IF_STMT_01(e, stmt, l) pxcompiler::If::make_If(arena, l, \
        e, stmt, {})
#define IF_STMT_02(e, stmt, orelse, l) pxcompiler::If::make_If(arena, l, \
        e, stmt, orelse)
#define INTEGER(x, l) pxcompiler::ConstantInt::make_ConstantInt(arena, l, x)
#define FLOAT(x, l) pxcompiler::ConstantFloat::make_ConstantFloat(arena, l, x)
#define COMPLEX(x, l) pxcompiler::ConstantComplex::make_ConstantComplex(arena, l, 0, x)
#define BOOL(x, l) pxcompiler::ConstantBool::make_ConstantBool(arena, l, x)

#define ELLIPSIS(l) pxcompiler::ConstantEllipsis::make_ConstantEllipsis(arena,l)
#define NONE(l) pxcompiler::ConstantNone::make_ConstantNone(arena, l)

#define STRING1(x, l) pxcompiler::ConstantStr::make_ConstantStr(arena, l, \
        unescape(x))
#define STRING2(x, y, l) concat_string(arena, l, x, y)
#define STRING3(id, x, l) PREFIX_STRING(arena, l, id->name(), x)
#define STRING4(x, id, y, l) concat_string(arena, l, x, STRING3(id, y, l))

static inline std::string unescape(const std::string &s) {
    // std::string x;
    // for (size_t idx=0; idx < s.size(); idx++) {
    //     if (s[idx] == '\\' && s[idx+1] == 'n') {
    //         x += "\n";
    //         idx++;
    //     } else {
    //         x += s[idx];
    //     }
    // }
    // return x;
    return s;
}

static inline pxcompiler::Nonnull<pxcompiler::Expression*> concat_string(
    pxcompiler::Nonnull<pxcompiler::Arena*> arena,
    const pxcompiler::SourceLocation &loc,
    pxcompiler::Nonnull<pxcompiler::Expression*> a,
    pxcompiler::Nonnull<pxcompiler::Expression*> b) {
    if (pxcompiler::JoinedStr::classof(a)) {
        // JoinedStr
        auto &joinedStr = llvm::cast<pxcompiler::JoinedStr>(*a);
        joinedStr.join(b);
        return a;
    } else if (pxcompiler::ConstantStr::classof(a) ||
               pxcompiler::ConstantBytes::classof(a)) {
        if (pxcompiler::ConstantStr::classof(b) ||
            pxcompiler::ConstantBytes::classof(b) ||
            pxcompiler::JoinedStr::classof(b)) {
            llvm::cast<pxcompiler::ConstantStr>(*a).extend(b);
        } else {
            std::cout << "Error: invalid expression kind" << std::endl;
            exit(0);
        }

        return a;
    } else {
        std::cout << "Error: invalid expression kind" << std::endl;
        exit(0);
    }
}

static inline pxcompiler::Nonnull<pxcompiler::Expression*> concat_string(
    pxcompiler::Nonnull<pxcompiler::Arena*> arena,
    const pxcompiler::SourceLocation &loc,
    pxcompiler::Nonnull<pxcompiler::Expression*> a,
    std::string b) {
    if (pxcompiler::JoinedStr::classof(a)) {
        // JoinedStr
        auto &joinedStr = llvm::cast<pxcompiler::JoinedStr>(*a);
        auto constantStr = STRING1(std::move(b), loc);
        joinedStr.join(constantStr);
        return a;
    } else if (pxcompiler::ConstantStr::classof(a)) {
        llvm::cast<pxcompiler::ConstantStr>(*a).concat(b);
        return a;
    } else {
        std::cout << "Error: invalid expression kind" << std::endl;
        exit(0);
    }
}

static inline NonnullExpr PREFIX_STRING(
    NonnullArena arena,
    const pxcompiler::SourceLocation &l,
    std::string prefix,
    std::string s) {

    std::vector<NonnullExpr> exprs;
    exprs.reserve(4);
    NonnullExpr tmp = nullptr;
    if (prefix == "U") {
        return pxcompiler::ConstantStr::make_ConstantStr(arena, l,  s);
    }
    for (size_t i = 0; i < prefix.size(); i++) {
        prefix[i] = tolower(prefix[i]);
    }
    if (prefix == "f" || prefix == "fr" || prefix == "rf") {
        std::string str = s;
        std::string s1 = "";
        std::string id;
        std::vector<std::string> strs;
        bool open_paren = false;
        for (size_t i = 0; i < str.length(); i++) {
            if(str[i] == '{') {
                if(s1 != "") {
                    strs.push_back(s1);
                    s1 = "";
                }
                open_paren = true;
            } else if (str[i] != '}' && open_paren) {
                id.push_back(s[i]);
            } else if (str[i] == '}') {
                if(id != "") {
                    strs.push_back("{" + id + "}");
                    id = "";
                }
                open_paren = false;
            } else if (!open_paren) {
                s1.push_back(str[i]);
            }
            if(i == str.length()-1 && s1 != "") {
                strs.push_back(s1);
            }
        }

        for (size_t i = 0; i < strs.size(); i++) {
            auto last_c = strs[i][strs[i].length()-1];
            if (strs[i][0] == '{' && last_c == '}') {
                strs[i] = strs[i].substr(1, strs[i].length() - 2);
                tmp = pxcompiler::Name::make_Name(arena, l, strs[i]);
                tmp = pxcompiler::FormattedValue::make_FormattedValue(arena,
                                                                      l,
                                                                      tmp,
                                                                      -1);
                exprs.push_back(tmp);
            } else {
                tmp = pxcompiler::ConstantStr::make_ConstantStr(arena,
                                                                l,
                                                                strs[i]);
                exprs.push_back(tmp);
            }
        }
        tmp = pxcompiler::JoinedStr::make_JoinedStr(arena, l, exprs);
    } else if (prefix == "b" || prefix == "br" || prefix == "rb") {
        std::string str = std::string(s);
        size_t start_pos = 0;
        while((start_pos = str.find("\n", start_pos)) != std::string::npos) {
                str.replace(start_pos, 1, "\\n");
                start_pos += 2;
        }
        str = "b'" + str + "'";
        tmp = pxcompiler::ConstantBytes::make_ConstantBytes(arena, l, str);
    } else if (prefix == "r") {
        tmp = pxcompiler::ConstantStr::make_ConstantStr(arena, l,  s);
    } else if (prefix == "u") {
        tmp = pxcompiler::ConstantStr::make_ConstantStr(
                arena, l, s, std::string("u"));
    } else {
        std::cout << ("The string is not recognized by the parser.") << std::endl;
        exit(0);
    }
    return tmp;
}

#define TUPLE_EMPTY(l) pxcompiler::Tuple::make_Tuple(arena, l, {})