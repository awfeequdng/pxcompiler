#pragma once

#include "ast/ast.h"
#include "ast/name.h"
#include "ast/statement.h"
#include "llvm/Support/Casting.h"

#include <iostream>

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
        std::cout << ("The string is not recognized by the parser.")
                  << std::endl;
        exit(0);
    }
    return tmp;
}

#define TUPLE_EMPTY(l) pxcompiler::Tuple::make_Tuple(arena, l, {})
#define LIST(e, l) pxcompiler::List::make_List(arena, l, e)
#define SET(e, l) pxcompiler::Set::make_Set(arena, l, e)
#define ATTRIBUTE_REF(val, attr, l) \
    pxcompiler::Attribute::make_Attribute(arena, l, val, attr)

#define DICT_01(l) pxcompiler::Dict::make_Dict(arena, l, {})
#define DICT_02(dict_list, l) pxcompiler::Dict::make_Dict(arena, l, dict_list)

#define DICT_EXPR(key, value, l) std::make_pair(key, value)

#define NAMEDEXPR(x, y, l) pxcompiler::NamedExpr::make_NamedExpr(arena, l, x, y)
#define STARRED_ARG(e, l) pxcompiler::Starred::make_Starred(arena, l, e)

#define BINOP(x, op, y, l) pxcompiler::BinOp::make_BinOp(arena, l, \
        x, pxcompiler::operatorType::op, y)
#define UNARY(x, op, l) pxcompiler::UnaryOp::make_UnaryOp(arena, l, \
        pxcompiler::unaryopType::op, x)

#define COMPARE(x, op, y, l) pxcompiler::Compare::make_Compare(arena, l, \
        x, cmpopType::op, y)
#define BOOLOP(x, op, y, l) pxcompiler::BoolOp::make_BoolOp(arena, l, \
        x, boolopType::op, y)


static inline pxcompiler::Nonnull<pxcompiler::Arg*>
    FUNC_ARG(NonnullArena arena,
             pxcompiler::SourceLocation l,
             NonnullExpr arg,
             std::optional<NonnullExpr> annotation,
             std::optional<NonnullExpr> defaults) {
    auto r = pxcompiler::Arg::make_Arg(arena, l, arg);
    r->annotation_ = annotation;
    r->type_comment_ = std::nullopt;
    r->defaults_ = defaults;
    return r;
}

#define ARGS_01(arg, l) FUNC_ARG(arena, l, \
        arg, std::nullopt, std::nullopt)
#define ARGS_02(arg, annotation, l) FUNC_ARG(arena, l, \
        arg, annotation, std::nullopt)
#define ARGS_03(arg, defaults, l) FUNC_ARG(arena, l, \
        arg, std::nullopt, defaults)
#define ARGS_04(arg, ann, defaults, l) FUNC_ARG(arena, l, \
        arg, ann, defaults)

static inline pxcompiler::Nonnull<pxcompiler::FnArg*>
    FN_ARG(NonnullArena arena,
           std::vector<NonnullArg> posonlyargs,
           std::optional<pxcompiler::Nonnull<pxcompiler::NoPosOnlyArg*>> args) {
    auto r = pxcompiler::FnArg::make_FnArg(arena,
                pxcompiler::SourceLocation("invalid file", 0));
    r->posonlyargs_ = posonlyargs;
    r->args_ = args;
    return r;
}

#define PARAMETER_LIST_01(posonlyargs, args) \
        FN_ARG(arena, posonlyargs, args)

#define PARAMETER_LIST_02(args) FN_ARG(arena, {}, args)


static inline pxcompiler::Nonnull<pxcompiler::NoPosOnlyArg*>
    ARGS(NonnullArena arena, std::vector<NonnullArg> args,
    std::optional<pxcompiler::Nonnull<pxcompiler::StarArg*>> stararg) {
    auto r = pxcompiler::NoPosOnlyArg::make_NoPosOnlyArg(arena,
                pxcompiler::SourceLocation("ARGS", 0));
    r->args_ = args;
    r->stararg_ = stararg;
    return r;
}
#define PARAMETER_LIST_03(args, stararg) ARGS(arena, args, stararg)
#define PARAMETER_LIST_04(stararg) ARGS(arena, {}, stararg)

static inline pxcompiler::Nonnull<pxcompiler::StarArg*> STAR_ARG(
        NonnullArena arena,
        std::vector<NonnullArg> varargs,
        std::vector<NonnullArg> kwonlyargs,
        std::vector<NonnullArg> kwarg) {
    auto r = pxcompiler::StarArg::make_StarArg(arena,
                pxcompiler::SourceLocation("STAR_ARG", 0));
    r->varargs_ = varargs;
    r->kwonlyargs_ = kwonlyargs;
    r->kwarg_ = kwarg;
    return r;
}
#define PARAMETER_LIST_05(kwonlyargs) STAR_ARG(arena, {}, \
        kwonlyargs, {})
#define PARAMETER_LIST_06(kwarg) STAR_ARG(arena, {}, {}, {kwarg})

#define PARAMETER_LIST_07(kwonlyargs, kwarg) STAR_ARG(arena, {}, \
        kwonlyargs, {kwarg})

#define PARAMETER_LIST_08(vararg) STAR_ARG(arena, {vararg}, {}, {})
#define PARAMETER_LIST_09(vararg, kwonlyargs)  STAR_ARG(arena, {vararg}, \
        kwonlyargs, {})
#define PARAMETER_LIST_10(vararg, kwarg)  STAR_ARG(arena, {vararg}, {}, {kwarg})
#define PARAMETER_LIST_11(vararg, kwonlyargs, kwarg) STAR_ARG(arena, {vararg}, \
        kwonlyargs, {kwarg})
#define PARAMETER_LIST_12(l) FUNC_ARGS_01(arena, l, std::nullopt)

#define FUNC_ARGS_(x, kw) \
    for(auto exp : x) { \
        r->x##_.push_back(exp); \
        if(exp->defaults_.has_value() && !kw) { \
            defaults.push_back(*(exp->defaults_)); \
        } else if (exp->defaults_.has_value()){ \
            kw_defaults.push_back(*(exp->defaults_)); \
        } \
    }


static inline pxcompiler::Nonnull<pxcompiler::Arguments*>
        FUNC_ARGS_01(NonnullArena arena, pxcompiler::SourceLocation l,
        std::optional<pxcompiler::Nonnull<pxcompiler::FnArg*>> parameters) {
    auto r = pxcompiler::Arguments::make_Arguments(arena, l);
    std::vector<NonnullExpr> defaults;
    defaults.reserve(4);
    std::vector<NonnullExpr> kw_defaults;
    kw_defaults.reserve(4);

    if(parameters == std::nullopt) {
        return r;
    }

    auto &posonlyargs = (*parameters)->posonlyargs_;
    FUNC_ARGS_(posonlyargs, false);

    if (!parameters.has_value() || !(*parameters)->args_.has_value()) {
        r->kw_defaults_ = kw_defaults;
        r->defaults_ = defaults;
        return r;
    }

    auto &noposonlyargs = (*parameters)->args_;
    if (!noposonlyargs.has_value()) {
        r->kw_defaults_ = kw_defaults;
        r->defaults_ = defaults;
        return r;
    }
    auto &args = (*noposonlyargs)->args_;
    FUNC_ARGS_(args, false);

    auto &stararg = (*noposonlyargs)->stararg_;
    if (!stararg.has_value()) {
        r->kw_defaults_ = kw_defaults;
        r->defaults_ = defaults;
        return r;
    }

    auto& varargs = (*stararg)->varargs_;
    FUNC_ARGS_(varargs, false);

    auto &kwonlyargs = (*stararg)->kwonlyargs_;
    FUNC_ARGS_(kwonlyargs, true);

    auto &kwarg = (*stararg)->kwarg_;
    FUNC_ARGS_(kwarg, true);

    r->kw_defaults_ = kw_defaults;
    r->defaults_ = defaults;
    return r;
}


#define FUNCTION_01(decorator, id, args, stmts, l) \
    pxcompiler::FunctionDef::make_FunctionDef(arena, l, \
        id, args, stmts, decorator, std::nullopt, std::nullopt)
#define FUNCTION_02(decorator, id, args, returns, stmts, l) \
    pxcompiler::FunctionDef::make_FunctionDef(arena, l, \
        id, args, stmts, decorator, returns, std::nullopt)
#define FUNCTION_03(decorator, id, args, stmts, type_comment, l) \
    pxcompiler::FunctionDef::make_FunctionDef(arena, l, \
        id, args, stmts, decorator, std::nullopt, type_comment)

#define FUNCTION_04(decorator, id, args, returns, stmts, type_comment, l) \
    pxcompiler::FunctionDef::make_FunctionDef(arena, l, \
        id, args, stmts, decorator, returns, type_comment)
