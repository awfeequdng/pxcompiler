#pragma once

#define YY_USER_ACTION  \
    context.current_token_position.columns(yyleng);

#define PXC_TOKEN(name) \
    pxcompiler::Parser::make_##name(context.current_token_position);

#define PXC_ARG_TOKEN(name, arg) \
    pxcompiler::Parser::make_##name(arg, context.current_token_position);
