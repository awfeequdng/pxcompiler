#pragma once

#define YY_USER_ACTION  \
    context.current_token_position.columns(yyleng); \
    if (YY_START == AFTER_WHITESPACE || YY_START == AFTER_OPERAND) { \
        BEGIN(INITIAL); \
    }

#define PXC_TOKEN(name) \
    parser::flex_bison::Parser::make_##name(context.current_token_position);

#define PXC_ARG_TOKEN(name, arg) \
    parser::flex_bison::Parser::make_##name(arg, context.current_token_position);