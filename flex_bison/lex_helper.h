#ifndef PXC_SYNTAX_LEX_HELPER_H_
#define PXC_SYNTAX_LEX_HELPER_H_

// Flex expands this macro immediately before each action.
//
// Advances the current token position by yyleng columns without changing
// the line number, and takes us out of the after-whitespace / after-operand
// state.
#define YY_USER_ACTION                                             \
  context.current_token_position.columns(yyleng);                  \
  if (YY_START == AFTER_WHITESPACE || YY_START == AFTER_OPERAND) { \
    BEGIN(INITIAL);                                                \
  }

#define PXC_SIMPLE_TOKEN(name) \
  pxc::Parser::make_##name(context.current_token_position);

#define PXC_ARG_TOKEN(name, arg) \
  pxc::Parser::make_##name(arg, context.current_token_position);

#endif  // PXC_SYNTAX_LEX_HELPER_H_
