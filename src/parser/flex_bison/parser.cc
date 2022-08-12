// A Bison parser, made by GNU Bison 3.8.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 44 "parser.ypp"

  #include <algorithm>
  #include <cstdarg>
  #include <cstdio>
  #include <cstdlib>
  #include <vector>
  #include <utility>

  #include "common/check.h"
  #include "parser/flex_bison/parser.h"
  #include "parser/flex_bison/parse_and_lex_context.h"
  #include "llvm/ADT/StringExtras.h"
  #include "llvm/Support/raw_ostream.h"

#line 54 "./parser.cc"




//#include "parser.h"


// Unqualified %code blocks.
#line 77 "parser.ypp"

  void pxcompiler::Parser::error(const location_type&, const std::string& message) {
    context.RecordSyntaxError(message);
  }

#line 69 "./parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 21 "parser.ypp"
namespace  pxcompiler  {
#line 162 "./parser.cc"

  /// Build a parser object.
   Parser :: Parser  (pxcompiler::Nonnull<pxcompiler::Arena*> arena_yyarg, yyscan_t yyscanner_yyarg, ParseAndLexContext& context_yyarg, std::optional<pxcompiler::ASTPtr>* ast_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      arena (arena_yyarg),
      yyscanner (yyscanner_yyarg),
      context (context_yyarg),
      ast (ast_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.YY_MOVE_OR_COPY< Nonnull<Alias*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.YY_MOVE_OR_COPY< Nonnull<Arg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.YY_MOVE_OR_COPY< Nonnull<Arguments*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< Nonnull<Expression*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.YY_MOVE_OR_COPY< Nonnull<FnArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.YY_MOVE_OR_COPY< Nonnull<Keyword*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
        value.YY_MOVE_OR_COPY< Nonnull<Name*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.YY_MOVE_OR_COPY< Nonnull<NoPosOnlyArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.YY_MOVE_OR_COPY< Nonnull<StarArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_script_unit: // script_unit
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_pass_statement: // pass_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_continue_statement: // continue_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
        value.YY_MOVE_OR_COPY< Nonnull<Statement*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dict: // dict
        value.YY_MOVE_OR_COPY< PairNonnullExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Alias*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Arg*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Expression*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Keyword*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_sep_statements: // sep_statements
      case symbol_kind::S_body_stmts: // body_stmts
      case symbol_kind::S_statements1: // statements1
      case symbol_kind::S_single_line_statements: // single_line_statements
      case symbol_kind::S_single_line_multi_statements: // single_line_multi_statements
      case symbol_kind::S_single_line_multi_statements_opt: // single_line_multi_statements_opt
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Statement*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.YY_MOVE_OR_COPY< std::vector<PairNonnullExpr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sep: // sep
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.move< Nonnull<Alias*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.move< Nonnull<Arg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.move< Nonnull<Arguments*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.move< Nonnull<Expression*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< Nonnull<FnArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.move< Nonnull<Keyword*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
        value.move< Nonnull<Name*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.move< Nonnull<NoPosOnlyArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.move< Nonnull<StarArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_script_unit: // script_unit
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_pass_statement: // pass_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_continue_statement: // continue_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
        value.move< Nonnull<Statement*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dict: // dict
        value.move< PairNonnullExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.move< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.move< std::vector<Nonnull<Alias*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.move< std::vector<Nonnull<Arg*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.move< std::vector<Nonnull<Expression*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.move< std::vector<Nonnull<Keyword*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_sep_statements: // sep_statements
      case symbol_kind::S_body_stmts: // body_stmts
      case symbol_kind::S_statements1: // statements1
      case symbol_kind::S_single_line_statements: // single_line_statements
      case symbol_kind::S_single_line_multi_statements: // single_line_multi_statements
      case symbol_kind::S_single_line_multi_statements_opt: // single_line_multi_statements_opt
        value.move< std::vector<Nonnull<Statement*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.move< std::vector<PairNonnullExpr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sep: // sep
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.copy< Nonnull<Alias*> > (that.value);
        break;

      case symbol_kind::S_parameter: // parameter
        value.copy< Nonnull<Arg*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.copy< Nonnull<Arguments*> > (that.value);
        break;

      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.copy< Nonnull<Expression*> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< Nonnull<FnArg*> > (that.value);
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.copy< Nonnull<Keyword*> > (that.value);
        break;

      case symbol_kind::S_id: // id
        value.copy< Nonnull<Name*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.copy< Nonnull<NoPosOnlyArg*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.copy< Nonnull<StarArg*> > (that.value);
        break;

      case symbol_kind::S_script_unit: // script_unit
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_pass_statement: // pass_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_continue_statement: // continue_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
        value.copy< Nonnull<Statement*> > (that.value);
        break;

      case symbol_kind::S_dict: // dict
        value.copy< PairNonnullExpr > (that.value);
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.copy< long long > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.copy< std::vector<Nonnull<Alias*>> > (that.value);
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.copy< std::vector<Nonnull<Arg*>> > (that.value);
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.copy< std::vector<Nonnull<Expression*>> > (that.value);
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.copy< std::vector<Nonnull<Keyword*>> > (that.value);
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_sep_statements: // sep_statements
      case symbol_kind::S_body_stmts: // body_stmts
      case symbol_kind::S_statements1: // statements1
      case symbol_kind::S_single_line_statements: // single_line_statements
      case symbol_kind::S_single_line_multi_statements: // single_line_multi_statements
      case symbol_kind::S_single_line_multi_statements_opt: // single_line_multi_statements_opt
        value.copy< std::vector<Nonnull<Statement*>> > (that.value);
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.copy< std::vector<PairNonnullExpr> > (that.value);
        break;

      case symbol_kind::S_sep: // sep
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.move< Nonnull<Alias*> > (that.value);
        break;

      case symbol_kind::S_parameter: // parameter
        value.move< Nonnull<Arg*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.move< Nonnull<Arguments*> > (that.value);
        break;

      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.move< Nonnull<Expression*> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< Nonnull<FnArg*> > (that.value);
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.move< Nonnull<Keyword*> > (that.value);
        break;

      case symbol_kind::S_id: // id
        value.move< Nonnull<Name*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.move< Nonnull<NoPosOnlyArg*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.move< Nonnull<StarArg*> > (that.value);
        break;

      case symbol_kind::S_script_unit: // script_unit
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_pass_statement: // pass_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_continue_statement: // continue_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
        value.move< Nonnull<Statement*> > (that.value);
        break;

      case symbol_kind::S_dict: // dict
        value.move< PairNonnullExpr > (that.value);
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.move< double > (that.value);
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.move< long long > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.move< std::vector<Nonnull<Alias*>> > (that.value);
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.move< std::vector<Nonnull<Arg*>> > (that.value);
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.move< std::vector<Nonnull<Expression*>> > (that.value);
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.move< std::vector<Nonnull<Keyword*>> > (that.value);
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_sep_statements: // sep_statements
      case symbol_kind::S_body_stmts: // body_stmts
      case symbol_kind::S_statements1: // statements1
      case symbol_kind::S_single_line_statements: // single_line_statements
      case symbol_kind::S_single_line_multi_statements: // single_line_multi_statements
      case symbol_kind::S_single_line_multi_statements_opt: // single_line_multi_statements_opt
        value.move< std::vector<Nonnull<Statement*>> > (that.value);
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.move< std::vector<PairNonnullExpr> > (that.value);
        break;

      case symbol_kind::S_sep: // sep
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (arena, yyscanner, context));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_module_as_id: // module_as_id
        yylhs.value.emplace< Nonnull<Alias*> > ();
        break;

      case symbol_kind::S_parameter: // parameter
        yylhs.value.emplace< Nonnull<Arg*> > ();
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        yylhs.value.emplace< Nonnull<Arguments*> > ();
        break;

      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< Nonnull<Expression*> > ();
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        yylhs.value.emplace< Nonnull<FnArg*> > ();
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        yylhs.value.emplace< Nonnull<Keyword*> > ();
        break;

      case symbol_kind::S_id: // id
        yylhs.value.emplace< Nonnull<Name*> > ();
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        yylhs.value.emplace< Nonnull<NoPosOnlyArg*> > ();
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        yylhs.value.emplace< Nonnull<StarArg*> > ();
        break;

      case symbol_kind::S_script_unit: // script_unit
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_pass_statement: // pass_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_continue_statement: // continue_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
        yylhs.value.emplace< Nonnull<Statement*> > ();
        break;

      case symbol_kind::S_dict: // dict
        yylhs.value.emplace< PairNonnullExpr > ();
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        yylhs.value.emplace< long long > ();
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        yylhs.value.emplace< std::vector<Nonnull<Alias*>> > ();
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        yylhs.value.emplace< std::vector<Nonnull<Arg*>> > ();
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        yylhs.value.emplace< std::vector<Nonnull<Expression*>> > ();
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        yylhs.value.emplace< std::vector<Nonnull<Keyword*>> > ();
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_sep_statements: // sep_statements
      case symbol_kind::S_body_stmts: // body_stmts
      case symbol_kind::S_statements1: // statements1
      case symbol_kind::S_single_line_statements: // single_line_statements
      case symbol_kind::S_single_line_multi_statements: // single_line_multi_statements
      case symbol_kind::S_single_line_multi_statements_opt: // single_line_multi_statements_opt
        yylhs.value.emplace< std::vector<Nonnull<Statement*>> > ();
        break;

      case symbol_kind::S_dict_list: // dict_list
        yylhs.value.emplace< std::vector<PairNonnullExpr> > ();
        break;

      case symbol_kind::S_sep: // sep
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // units: units script_unit
#line 265 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1134 "./parser.cc"
    break;

  case 3: // units: script_unit
#line 266 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1140 "./parser.cc"
    break;

  case 5: // script_unit: statement
#line 271 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1146 "./parser.cc"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 275 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1152 "./parser.cc"
    break;

  case 7: // sep_statements: sep statements
#line 279 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1158 "./parser.cc"
    break;

  case 8: // body_stmts: single_line_statements
#line 283 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1164 "./parser.cc"
    break;

  case 9: // body_stmts: sep_statements
#line 284 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1170 "./parser.cc"
    break;

  case 10: // statements1: statements1 statement
#line 288 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1176 "./parser.cc"
    break;

  case 11: // statements1: statement
#line 289 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1182 "./parser.cc"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 293 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1188 "./parser.cc"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 294 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1194 "./parser.cc"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 295 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1200 "./parser.cc"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 296 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1208 "./parser.cc"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 299 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1216 "./parser.cc"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 302 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1224 "./parser.cc"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 308 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1232 "./parser.cc"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 311 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1240 "./parser.cc"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 317 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1248 "./parser.cc"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 320 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1256 "./parser.cc"
    break;

  case 22: // statement: single_line_statement sep
#line 326 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1262 "./parser.cc"
    break;

  case 23: // statement: multi_line_statement
#line 327 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1268 "./parser.cc"
    break;

  case 24: // statement: multi_line_statement sep
#line 328 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1274 "./parser.cc"
    break;

  case 25: // pass_statement: PASS
#line 333 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1280 "./parser.cc"
    break;

  case 26: // break_statement: BREAK
#line 337 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1286 "./parser.cc"
    break;

  case 27: // continue_statement: CONTINUE
#line 341 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1292 "./parser.cc"
    break;

  case 28: // single_line_statement: expression_statment
#line 345 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1298 "./parser.cc"
    break;

  case 29: // single_line_statement: pass_statement
#line 350 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1304 "./parser.cc"
    break;

  case 30: // single_line_statement: break_statement
#line 354 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1310 "./parser.cc"
    break;

  case 31: // single_line_statement: continue_statement
#line 355 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1316 "./parser.cc"
    break;

  case 32: // single_line_statement: import_statement
#line 356 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1322 "./parser.cc"
    break;

  case 33: // single_line_statement: global_statement
#line 357 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1328 "./parser.cc"
    break;

  case 34: // single_line_statement: nonlocal_statement
#line 358 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1334 "./parser.cc"
    break;

  case 35: // module: module "." id
#line 363 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1340 "./parser.cc"
    break;

  case 36: // module: id
#line 364 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1346 "./parser.cc"
    break;

  case 37: // module_as_id: module
#line 368 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1352 "./parser.cc"
    break;

  case 38: // module_as_id: module AS id
#line 369 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1358 "./parser.cc"
    break;

  case 39: // module_as_id: "*"
#line 370 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1364 "./parser.cc"
    break;

  case 40: // module_item_list: module_item_list "," module_as_id
#line 374 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1370 "./parser.cc"
    break;

  case 41: // module_item_list: module_as_id
#line 375 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1376 "./parser.cc"
    break;

  case 42: // import_statement: IMPORT module_item_list
#line 379 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1382 "./parser.cc"
    break;

  case 43: // multi_line_statement: if_statement
#line 395 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1388 "./parser.cc"
    break;

  case 44: // multi_line_statement: function_def
#line 399 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1394 "./parser.cc"
    break;

  case 45: // decorators_opt: decorators
#line 408 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1400 "./parser.cc"
    break;

  case 46: // decorators_opt: %empty
#line 409 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1406 "./parser.cc"
    break;

  case 47: // decorators: decorators "@" expr sep
#line 413 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1412 "./parser.cc"
    break;

  case 48: // decorators: "@" expr sep
#line 414 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1418 "./parser.cc"
    break;

  case 49: // parameter: id
#line 418 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1424 "./parser.cc"
    break;

  case 50: // parameter: id ":" expr
#line 419 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1430 "./parser.cc"
    break;

  case 51: // parameter: id "=" expr
#line 420 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1436 "./parser.cc"
    break;

  case 52: // parameter: id ":" expr "=" expr
#line 421 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1442 "./parser.cc"
    break;

  case 53: // parameter_list: defparameter_list "," "/" comma_opt
#line 425 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1449 "./parser.cc"
    break;

  case 54: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 427 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1456 "./parser.cc"
    break;

  case 55: // parameter_list: parameter_list_no_posonly
#line 429 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1462 "./parser.cc"
    break;

  case 56: // parameter_list_no_posonly: defparameter_list comma_opt
#line 433 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1468 "./parser.cc"
    break;

  case 57: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 434 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1475 "./parser.cc"
    break;

  case 58: // parameter_list_no_posonly: parameter_list_starargs
#line 436 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1481 "./parser.cc"
    break;

  case 59: // defparameter_list: defparameter_list "," parameter
#line 440 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1487 "./parser.cc"
    break;

  case 60: // defparameter_list: parameter
#line 441 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1493 "./parser.cc"
    break;

  case 61: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 449 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1499 "./parser.cc"
    break;

  case 62: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 450 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1505 "./parser.cc"
    break;

  case 63: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 451 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1512 "./parser.cc"
    break;

  case 64: // parameter_list_starargs: "*" parameter comma_opt
#line 453 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1518 "./parser.cc"
    break;

  case 65: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 454 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1525 "./parser.cc"
    break;

  case 66: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 456 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1532 "./parser.cc"
    break;

  case 67: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 458 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1539 "./parser.cc"
    break;

  case 68: // parameter_list_starargs: "**" parameter comma_opt
#line 460 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1545 "./parser.cc"
    break;

  case 69: // parameter_list_opt: parameter_list
#line 464 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1551 "./parser.cc"
    break;

  case 70: // parameter_list_opt: %empty
#line 465 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1557 "./parser.cc"
    break;

  case 73: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 475 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1563 "./parser.cc"
    break;

  case 74: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 477 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1569 "./parser.cc"
    break;

  case 75: // global_statement: GLOBAL expr_list
#line 487 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1575 "./parser.cc"
    break;

  case 76: // ternary_if_statement: expr IF expr ELSE expr
#line 491 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1581 "./parser.cc"
    break;

  case 77: // nonlocal_statement: NONLOCAL expr_list
#line 495 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1587 "./parser.cc"
    break;

  case 78: // if_statement: IF expr ":" body_stmts
#line 499 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1595 "./parser.cc"
    break;

  case 79: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 502 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1603 "./parser.cc"
    break;

  case 80: // expression_statment: expr
#line 510 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1609 "./parser.cc"
    break;

  case 81: // string: string string_literal
#line 514 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1615 "./parser.cc"
    break;

  case 82: // string: string_literal
#line 515 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1623 "./parser.cc"
    break;

  case 83: // string: id string_literal
#line 518 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1631 "./parser.cc"
    break;

  case 84: // string: string id string_literal
#line 521 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1639 "./parser.cc"
    break;

  case 85: // expr_list_opt: expr_list
#line 527 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1645 "./parser.cc"
    break;

  case 86: // expr_list_opt: %empty
#line 528 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1651 "./parser.cc"
    break;

  case 87: // expr_list: expr_list "," expr
#line 532 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1657 "./parser.cc"
    break;

  case 88: // expr_list: expr
#line 533 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1663 "./parser.cc"
    break;

  case 89: // dict: expr ":" expr
#line 543 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1669 "./parser.cc"
    break;

  case 90: // dict_list: dict_list "," dict
#line 547 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1675 "./parser.cc"
    break;

  case 91: // dict_list: dict
#line 548 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1681 "./parser.cc"
    break;

  case 92: // call_arguement_list: expr_list_opt
#line 552 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1687 "./parser.cc"
    break;

  case 93: // call_arguement_list: expr_list ","
#line 553 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1693 "./parser.cc"
    break;

  case 94: // keyword_item: id "=" expr
#line 558 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1699 "./parser.cc"
    break;

  case 95: // keyword_item: "**" expr
#line 559 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1705 "./parser.cc"
    break;

  case 96: // keyword_items: keyword_items "," keyword_item
#line 563 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1711 "./parser.cc"
    break;

  case 97: // keyword_items: keyword_item
#line 564 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1717 "./parser.cc"
    break;

  case 98: // primary: id
#line 569 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1723 "./parser.cc"
    break;

  case 99: // primary: string
#line 570 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1729 "./parser.cc"
    break;

  case 100: // primary: expr "." id
#line 571 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1735 "./parser.cc"
    break;

  case 101: // function_call: primary "(" call_arguement_list ")"
#line 575 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1741 "./parser.cc"
    break;

  case 102: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 576 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1748 "./parser.cc"
    break;

  case 103: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 578 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1755 "./parser.cc"
    break;

  case 104: // function_call: primary "(" keyword_items comma_opt ")"
#line 580 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1761 "./parser.cc"
    break;

  case 105: // function_call: function_call "(" call_arguement_list ")"
#line 581 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1767 "./parser.cc"
    break;

  case 106: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 582 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1774 "./parser.cc"
    break;

  case 107: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 584 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1781 "./parser.cc"
    break;

  case 108: // function_call: function_call "(" keyword_items comma_opt ")"
#line 586 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1787 "./parser.cc"
    break;

  case 109: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 593 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1793 "./parser.cc"
    break;

  case 110: // expr: id
#line 597 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1799 "./parser.cc"
    break;

  case 111: // expr: integer_literal
#line 598 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 1808 "./parser.cc"
    break;

  case 112: // expr: string
#line 602 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1814 "./parser.cc"
    break;

  case 113: // expr: real_literal
#line 603 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 1820 "./parser.cc"
    break;

  case 114: // expr: image_literal
#line 604 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 1829 "./parser.cc"
    break;

  case 115: // expr: TRUE
#line 608 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 1835 "./parser.cc"
    break;

  case 116: // expr: FALSE
#line 609 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 1841 "./parser.cc"
    break;

  case 117: // expr: NONE
#line 610 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 1847 "./parser.cc"
    break;

  case 118: // expr: "..."
#line 611 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 1853 "./parser.cc"
    break;

  case 119: // expr: "(" expr ")"
#line 612 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 1859 "./parser.cc"
    break;

  case 120: // expr: "(" ")"
#line 613 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 1865 "./parser.cc"
    break;

  case 121: // expr: function_call
#line 614 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1871 "./parser.cc"
    break;

  case 122: // expr: "[" expr_list_opt "]"
#line 616 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1877 "./parser.cc"
    break;

  case 123: // expr: "[" expr_list "," "]"
#line 617 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1883 "./parser.cc"
    break;

  case 124: // expr: "{" expr_list "}"
#line 618 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1889 "./parser.cc"
    break;

  case 125: // expr: "{" expr_list "," "}"
#line 619 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1895 "./parser.cc"
    break;

  case 126: // expr: expr "." id
#line 620 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1901 "./parser.cc"
    break;

  case 127: // expr: "{" "}"
#line 622 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 1907 "./parser.cc"
    break;

  case 128: // expr: "{" dict_list "}"
#line 623 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 1913 "./parser.cc"
    break;

  case 129: // expr: id ":=" expr
#line 627 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1919 "./parser.cc"
    break;

  case 130: // expr: "*" expr
#line 628 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1925 "./parser.cc"
    break;

  case 131: // expr: expr "+" expr
#line 630 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1931 "./parser.cc"
    break;

  case 132: // expr: expr "-" expr
#line 631 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1937 "./parser.cc"
    break;

  case 133: // expr: expr "*" expr
#line 632 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1943 "./parser.cc"
    break;

  case 134: // expr: expr "/" expr
#line 633 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1949 "./parser.cc"
    break;

  case 135: // expr: expr "%" expr
#line 634 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1955 "./parser.cc"
    break;

  case 136: // expr: "-" expr
#line 635 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 1961 "./parser.cc"
    break;

  case 137: // expr: "+" expr
#line 636 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 1967 "./parser.cc"
    break;

  case 138: // expr: "~" expr
#line 637 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 1973 "./parser.cc"
    break;

  case 139: // expr: expr "**" expr
#line 638 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1979 "./parser.cc"
    break;

  case 140: // expr: expr "//" expr
#line 639 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1985 "./parser.cc"
    break;

  case 141: // expr: expr "@" expr
#line 640 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1991 "./parser.cc"
    break;

  case 142: // expr: expr "&" expr
#line 642 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1997 "./parser.cc"
    break;

  case 143: // expr: expr "|" expr
#line 643 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2003 "./parser.cc"
    break;

  case 144: // expr: expr "^" expr
#line 644 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2009 "./parser.cc"
    break;

  case 145: // expr: expr "<<" expr
#line 645 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2015 "./parser.cc"
    break;

  case 146: // expr: expr ">>" expr
#line 646 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2021 "./parser.cc"
    break;

  case 147: // expr: expr "==" expr
#line 648 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2027 "./parser.cc"
    break;

  case 148: // expr: expr "!=" expr
#line 649 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2033 "./parser.cc"
    break;

  case 149: // expr: expr "<" expr
#line 650 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2039 "./parser.cc"
    break;

  case 150: // expr: expr "<=" expr
#line 651 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2045 "./parser.cc"
    break;

  case 151: // expr: expr ">" expr
#line 652 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2051 "./parser.cc"
    break;

  case 152: // expr: expr ">=" expr
#line 653 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2057 "./parser.cc"
    break;

  case 153: // expr: expr "is" expr
#line 654 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2063 "./parser.cc"
    break;

  case 154: // expr: expr "is not" expr
#line 655 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2069 "./parser.cc"
    break;

  case 155: // expr: expr "in" expr
#line 656 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2075 "./parser.cc"
    break;

  case 156: // expr: expr "not in" expr
#line 657 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2081 "./parser.cc"
    break;

  case 157: // expr: expr "and" expr
#line 659 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2087 "./parser.cc"
    break;

  case 158: // expr: expr "or" expr
#line 660 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2093 "./parser.cc"
    break;

  case 159: // expr: "not" expr
#line 661 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2099 "./parser.cc"
    break;

  case 160: // expr: ternary_if_statement
#line 668 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2105 "./parser.cc"
    break;

  case 161: // id: identifier
#line 673 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2111 "./parser.cc"
    break;

  case 162: // sep: sep sep_one
#line 677 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2117 "./parser.cc"
    break;

  case 163: // sep: sep_one
#line 678 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2123 "./parser.cc"
    break;

  case 164: // sep_one: NEWLINE
#line 682 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2129 "./parser.cc"
    break;

  case 165: // sep_one: COMMENT
#line 683 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2135 "./parser.cc"
    break;

  case 166: // sep_one: ";"
#line 684 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2141 "./parser.cc"
    break;


#line 2145 "./parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const short  Parser ::yypact_ninf_ = -234;

  const signed char  Parser ::yytable_ninf_ = -101;

  const short
   Parser ::yypact_[] =
  {
     320,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  1348,  1348,     3,  1348,  1348,  -234,  1114,  1074,  1348,
    1348,  1348,  1348,  1348,  1348,  -234,  -234,  -234,  -234,  1001,
    -234,  -234,  -234,  -234,  -234,    10,  -234,    10,   -18,   -50,
    -234,  -234,  -234,  -234,  -234,  -234,    30,   -35,   -17,   831,
     108,    10,  -234,   -24,   831,   552,  -234,    97,  -234,    48,
    -234,   -24,  1365,  -234,   -33,  -234,   -32,   597,  -234,   642,
      14,    49,   -30,   -30,   -30,   490,   -30,  -234,  -234,    10,
      10,    96,  1348,  -234,   105,  1313,  1313,  1348,  1348,  1348,
    1348,  1348,  1348,  1348,  1348,  1348,  1348,  1348,    96,  1348,
    1348,  1348,  1348,  1348,  1348,  1348,  1348,  1348,  1348,  1348,
    1348,  1348,  1348,  1348,  -234,  1348,  -234,  1348,   392,    96,
      96,     3,  1149,  -234,  1348,  -234,  1348,    93,  -234,  1039,
      10,   107,   490,  -234,  1348,  -234,    55,    90,  -234,   118,
      41,   123,   104,   132,  1365,   696,   146,   146,   146,   146,
     919,  1190,   436,   146,   236,   127,   236,   -30,   -30,   -30,
     -30,   -30,   305,   180,   180,   146,   146,   146,   146,   -30,
     146,   875,   831,  -234,   166,  -234,   -51,  1275,    86,   112,
    -234,  -234,  -234,  -234,  -234,   597,   831,  1348,  -234,    13,
      10,   831,  1313,  -234,  1313,   120,  1348,  1313,  -234,  1313,
     126,  1348,   151,  -234,   109,   124,    68,  -234,   131,  1208,
    -234,   162,   141,    34,    96,  -234,  -234,  -234,   168,  -234,
     143,   -28,   171,   172,  -234,  -234,   831,   171,   172,  -234,
     875,   392,  -234,   102,  -234,   138,  -234,   451,  -234,  1348,
    -234,    16,   174,   183,     8,  -234,   -11,  1348,  1348,    17,
     159,  1348,   161,   173,   175,  -234,  -234,  -234,  -234,    96,
     197,    19,  -234,  -234,  -234,   200,  -234,  -234,   392,  1348,
     741,   831,   203,  -234,  -234,  -234,  -234,   183,    21,  -234,
      96,   202,    13,  -234,  -234,   786,  1348,  -234,    96,   183,
      25,  -234,  -234,   206,   392,   831,   183,  -234,    96,    13,
    -234,  -234,   183,  -234
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
      46,   111,   113,   114,   161,    82,   116,   115,   117,    26,
      27,     0,     0,     0,     0,     0,    25,     0,     0,    86,
       0,     0,     0,     0,     0,   118,   166,   164,   165,    46,
       3,     5,    29,    30,    31,     0,    32,    23,     0,    45,
      44,    33,   160,    34,    43,    28,   112,     0,   121,    80,
     110,     4,   163,    75,    88,     0,    39,    37,    41,    42,
      36,    77,   159,   127,     0,    91,     0,    88,   120,     0,
       0,    85,   136,   137,   130,     0,   138,     1,     2,    22,
      24,     0,     0,    81,     0,    86,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,   162,     0,     0,     0,
       0,     0,     0,   124,     0,   128,     0,   119,   122,     0,
      48,     0,     0,    84,     0,    92,    85,     0,    97,    72,
     110,    85,     0,    72,   157,     0,   155,   153,   154,   156,
     158,   142,   144,   147,   132,   126,   131,   133,   139,   141,
     140,   135,   143,   145,   146,   149,   150,   151,   152,   134,
     148,   129,    87,     9,    78,     8,     0,     0,     0,     0,
      38,    35,    40,   125,    90,     0,    89,    86,   123,    70,
      47,    95,    93,   101,    71,     0,     0,    93,   105,    71,
       0,     0,     0,    12,     0,    18,    21,    14,     0,    46,
       7,    85,     0,     0,     0,    60,    69,    55,    72,    58,
       0,    49,    72,    72,    96,   104,    94,    72,    72,   108,
      76,     0,    13,    20,    15,     0,    17,    46,    11,    93,
     109,     0,    72,    72,    71,    56,     0,     0,     0,    71,
       0,    71,     0,     0,     0,    79,    16,     6,    10,     0,
      72,    71,    64,    71,    68,    72,    59,    57,     0,     0,
      50,    51,     0,   102,   103,   106,   107,    72,    71,    61,
       0,    72,    71,    53,    73,     0,     0,    62,     0,    72,
      71,    65,    54,    72,     0,    52,    72,    66,     0,    71,
      74,    63,    72,    67
  };

  const short
   Parser ::yypgoto_[] =
  {
    -234,  -234,   228,  -234,  -234,  -227,  -234,  -234,  -234,  -234,
     -62,  -234,  -234,  -234,  -117,  -234,   140,  -234,  -234,  -234,
    -234,  -234,  -198,  -234,   -20,  -130,  -233,  -234,    31,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,   244,    -9,   142,  -234,
     -83,  -187,   -80,  -234,  -234,    33,   -13,    28,   -21
  };

  const unsigned char
   Parser ::yydefgoto_[] =
  {
       0,    29,    30,   210,   173,   174,   237,   175,   176,   177,
      31,    32,    33,    34,    35,    57,    58,    59,    36,    37,
      38,    39,   215,   216,   217,   218,   219,   220,   245,    40,
      41,    42,    43,    44,    45,    46,   135,    53,    65,    66,
     137,   138,   139,    47,    48,    49,    50,   179,    52
  };

  const short
   Parser ::yytable_[] =
  {
      60,   178,    81,   142,   255,    61,   143,   224,    64,     4,
      71,   267,   224,    82,     4,   242,   243,   122,   124,     4,
     247,    85,     4,     4,   248,     4,   117,     4,    51,    98,
     116,     4,   101,    84,   203,   204,     4,   268,    83,    86,
       4,   284,   123,   125,    54,    55,   266,    54,    62,   114,
      67,    69,    54,    72,    73,    74,    75,    76,   116,   116,
     205,   277,   224,    79,    56,    80,   267,   300,   131,   213,
     214,   269,   140,   140,   213,   214,   136,   141,   259,   134,
     266,   280,   289,   288,   241,   155,   -99,   298,   265,    26,
     296,   128,   266,   196,   115,    27,    28,   -98,   121,   129,
     302,   266,     4,   130,   212,   192,   180,   181,    60,   116,
     119,   260,   222,   133,   178,   132,   114,   227,    54,    54,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   281,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   238,   171,   187,
     172,   178,   293,   234,   235,   172,   120,   185,   116,   186,
     190,   115,   172,   189,   -98,   206,   193,   191,   194,   116,
     195,   207,   208,   197,   200,   258,   221,   178,   211,   140,
     198,   140,   199,  -100,   140,   223,   140,   -19,   -19,   202,
     228,    26,    94,    95,   232,   209,   225,    27,    28,   231,
     221,   221,   229,   233,    97,    98,    99,   100,   101,   102,
     103,   104,   239,   105,   106,   107,   236,   240,   244,   246,
      54,   249,   251,   256,   261,   172,   112,    54,   221,   226,
     172,   221,    54,   263,   230,   273,   272,   274,    97,    98,
      99,   100,   101,   102,   103,   104,   221,   278,   221,   275,
     282,   276,   290,   250,   252,   196,   299,    78,   253,   254,
     112,   182,   292,    70,     0,   221,   184,   221,     0,   221,
       0,     0,   172,   262,   264,   221,     0,   221,     0,     0,
     270,   271,     0,     0,   172,   221,   221,     0,     0,     0,
       0,   279,     0,     0,     0,    98,   283,   100,   101,   102,
     103,   104,   285,     0,     0,     0,     0,     0,   287,     0,
       0,     0,   291,     0,     0,     0,   112,     0,     0,   295,
     297,     0,     0,     1,     2,     3,     4,   301,     5,     6,
       7,     8,     0,   303,     0,     0,     0,     9,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
      13,    94,    95,     0,     0,     0,    14,    15,     0,    16,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,   106,   107,    17,    18,    19,    20,     0,
      21,    22,     0,    23,     0,   112,    24,     0,     0,     0,
       0,     0,     0,     0,    25,     1,     2,     3,     4,    26,
       5,     6,     7,     8,     0,    27,    28,     0,     0,     9,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,    13,     0,     0,     0,     0,     0,    14,    15,
       0,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,     0,    21,    22,     1,     2,     3,     4,    24,     5,
       6,     7,     8,     0,     0,     0,    25,     0,     9,     0,
      10,    26,     0,     0,     0,     0,     0,    27,    28,    11,
      12,    13,    94,     0,     0,     0,     0,    14,    15,     0,
      16,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,    87,     0,   106,   107,    17,    18,    19,    20,
       0,    21,    22,     0,    23,     0,   112,    24,     0,    88,
       0,    89,    90,    91,    92,    25,     0,     0,    93,     0,
       0,     0,     0,     0,     0,   257,    94,    95,     0,     0,
       0,     0,     0,     0,    96,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,   106,   107,
     108,   109,   110,   111,    87,     0,     0,     0,     0,    26,
     112,     0,     0,     0,     0,    27,    28,     0,     0,   113,
       0,    88,     0,    89,    90,    91,    92,     0,     0,     0,
      93,     0,     0,     0,     0,     0,     0,     0,    94,    95,
     118,     0,     0,     0,     0,     0,    96,     0,     0,    87,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
     106,   107,   108,   109,   110,   111,    88,     0,    89,    90,
      91,    92,   112,     0,     0,    93,     0,     0,     0,     0,
       0,   113,     0,    94,    95,   126,     0,     0,     0,     0,
       0,    96,     0,     0,    87,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,   106,   107,   108,   109,   110,
     111,    88,     0,    89,    90,    91,    92,   112,     0,     0,
      93,     0,     0,     0,     0,     0,   113,     0,    94,    95,
       0,     0,     0,     0,     0,     0,    96,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,    87,   105,
     106,   107,   108,   109,   110,   111,     0,     0,   127,   201,
       0,     0,   112,     0,     0,    88,     0,    89,    90,    91,
      92,   113,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
      96,     0,     0,    87,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,   106,   107,   108,   109,   110,   111,
      88,     0,    89,    90,    91,    92,   112,     0,     0,    93,
       0,     0,     0,     0,     0,   113,     0,    94,    95,     0,
       0,     0,     0,   286,     0,    96,     0,     0,    87,    97,
      98,    99,   100,   101,   102,   103,   104,     0,   105,   106,
     107,   108,   109,   110,   111,    88,     0,    89,    90,    91,
      92,   112,     0,     0,    93,     0,     0,     0,     0,     0,
     113,     0,    94,    95,   294,     0,     0,     0,     0,     0,
      96,     0,     0,    87,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,   106,   107,   108,   109,   110,   111,
      88,     0,    89,    90,    91,    92,   112,     0,     0,    93,
       0,     0,     0,     0,     0,   113,     0,    94,    95,     0,
       0,     0,     0,     0,     0,    96,     0,    87,     0,    97,
      98,    99,   100,   101,   102,   103,   104,     0,   105,   106,
     107,   108,   109,   110,   111,     0,    89,    90,    91,    92,
       0,   112,     0,    93,     0,     0,     0,     0,     0,     0,
     113,    94,    95,     0,     0,     0,     0,     0,     0,    96,
       0,    87,     0,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,   106,   107,   108,   109,   110,   111,     0,
      89,    90,    91,    92,     0,   112,     0,     0,     0,     0,
       0,     0,     0,     0,   113,    94,    95,     0,     0,     0,
       0,     0,     0,    96,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,   106,   107,   108,
     109,   110,   111,     0,     0,     0,     0,     0,     0,   112,
       0,    77,     0,     0,     1,     2,     3,     4,   113,     5,
       6,     7,     8,     0,     0,     0,     0,     0,     9,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,     0,    14,    15,     0,
      16,     0,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     0,     0,     0,    17,    18,    19,    20,
       0,    21,    22,     0,    23,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     0,    25,    15,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,     0,    21,
      22,     0,     0,     0,     0,    24,     0,     0,     0,     0,
       0,    15,     0,    25,     0,     0,   188,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     0,    17,
      18,    19,    20,     0,    21,    22,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,    25,     0,
      68,    15,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,     0,    21,    22,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,    15,     0,    25,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,     0,    21,
      22,     1,     2,     3,     4,    24,     5,     6,     7,     8,
       0,     0,     0,    25,   183,     9,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,    14,    15,     0,    16,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,   106,   107,
       0,     0,     0,    17,    18,    19,    20,     0,    21,    22,
     112,    23,     0,     0,    24,     0,     0,     0,     1,     2,
       3,     4,    25,     5,     6,     7,     8,     0,     0,     0,
       0,     0,     9,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,    13,     0,     0,     0,     0,
       0,    14,    15,     0,    16,     0,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,     0,     0,
      17,    18,    19,    20,     0,    21,    22,     0,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,    25,
      15,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,     0,    21,    22,   134,     0,     0,     0,    24,
       0,     0,     0,     0,     0,    15,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,     0,     0,    17,    18,    19,    20,     0,    21,    22,
       0,    94,    95,     0,    24,     0,     0,     0,     0,    96,
       0,     0,    25,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,   106,   107,   108,   109,   110,   111,     0,
       0,     0,     0,     0,     0,   112,     0,     0,     0,     0,
       0,     0,     0,     0,   113
  };

  const short
   Parser ::yycheck_[] =
  {
      13,   118,    20,    86,   231,    14,    86,   194,    17,     6,
      19,   244,   199,    63,     6,   213,   214,    50,    50,     6,
      48,    56,     6,     6,    52,     6,    50,     6,     0,    59,
      51,     6,    62,    46,    85,    86,     6,    48,     8,    56,
       6,   268,    75,    75,    11,    12,   244,    14,    15,     8,
      17,    18,    19,    20,    21,    22,    23,    24,    79,    80,
     177,   259,   249,    35,    61,    37,   299,   294,    81,    61,
      62,    82,    85,    86,    61,    62,    85,    86,    62,    62,
     278,    62,   280,    62,    50,    98,    56,    62,    80,    79,
     288,    77,   290,    52,    53,    85,    86,    56,    50,    50,
     298,   299,     6,    75,   187,    50,   119,   120,   121,   130,
      13,   241,   192,     8,   231,    82,     8,   197,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,   261,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   209,   115,    56,
     117,   268,   282,    85,    86,   122,    59,   124,   179,   126,
     132,    53,   129,    56,    56,    79,    76,   134,    50,   190,
     139,    85,    86,    50,   143,   237,   189,   294,   187,   192,
      76,   194,    50,    56,   197,   194,   199,    85,    86,    23,
     199,    79,    46,    47,    85,    83,    76,    85,    86,    48,
     213,   214,    76,    79,    58,    59,    60,    61,    62,    63,
      64,    65,    50,    67,    68,    69,    85,    76,    50,    76,
     187,    50,    50,    85,    50,   192,    80,   194,   241,   196,
     197,   244,   199,    50,   201,    76,   249,    76,    58,    59,
      60,    61,    62,    63,    64,    65,   259,    50,   261,    76,
      50,    76,    50,   222,   223,    52,    50,    29,   227,   228,
      80,   121,   282,    19,    -1,   278,   124,   280,    -1,   282,
      -1,    -1,   239,   242,   243,   288,    -1,   290,    -1,    -1,
     247,   248,    -1,    -1,   251,   298,   299,    -1,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    59,   265,    61,    62,    63,
      64,    65,   269,    -1,    -1,    -1,    -1,    -1,   277,    -1,
      -1,    -1,   281,    -1,    -1,    -1,    80,    -1,    -1,   286,
     289,    -1,    -1,     3,     4,     5,     6,   296,     8,     9,
      10,    11,    -1,   302,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    46,    47,    -1,    -1,    -1,    36,    37,    -1,    39,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    68,    69,    55,    56,    57,    58,    -1,
      60,    61,    -1,    63,    -1,    80,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,     3,     4,     5,     6,    79,
       8,     9,    10,    11,    -1,    85,    86,    -1,    -1,    17,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    60,    61,     3,     4,     5,     6,    66,     8,
       9,    10,    11,    -1,    -1,    -1,    74,    -1,    17,    -1,
      19,    79,    -1,    -1,    -1,    -1,    -1,    85,    86,    28,
      29,    30,    46,    -1,    -1,    -1,    -1,    36,    37,    -1,
      39,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    12,    -1,    68,    69,    55,    56,    57,    58,
      -1,    60,    61,    -1,    63,    -1,    80,    66,    -1,    29,
      -1,    31,    32,    33,    34,    74,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    12,    -1,    -1,    -1,    -1,    79,
      80,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    89,
      -1,    29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    12,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    29,    -1,    31,    32,
      33,    34,    80,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    12,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    29,    -1,    31,    32,    33,    34,    80,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    89,    -1,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    12,    67,
      68,    69,    70,    71,    72,    73,    -1,    -1,    76,    23,
      -1,    -1,    80,    -1,    -1,    29,    -1,    31,    32,    33,
      34,    89,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    12,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      29,    -1,    31,    32,    33,    34,    80,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    46,    47,    -1,
      -1,    -1,    -1,    52,    -1,    54,    -1,    -1,    12,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    29,    -1,    31,    32,    33,
      34,    80,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    12,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      29,    -1,    31,    32,    33,    34,    80,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    12,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    31,    32,    33,    34,
      -1,    80,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    12,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    -1,
      31,    32,    33,    34,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,     0,    -1,    -1,     3,     4,     5,     6,    89,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      39,    -1,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    60,    61,    -1,    63,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    37,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    74,    -1,    -1,    77,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      76,    37,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    37,    -1,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    60,
      61,     3,     4,     5,     6,    66,     8,     9,    10,    11,
      -1,    -1,    -1,    74,    75,    17,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    -1,    39,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    -1,    68,    69,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    60,    61,
      80,    63,    -1,    -1,    66,    -1,    -1,    -1,     3,     4,
       5,     6,    74,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    -1,    39,    -1,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    60,    61,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      37,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    60,    61,    62,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    60,    61,
      -1,    46,    47,    -1,    66,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    74,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    17,
      19,    28,    29,    30,    36,    37,    39,    55,    56,    57,
      58,    60,    61,    63,    66,    74,    79,    85,    86,    92,
      93,   101,   102,   103,   104,   105,   109,   110,   111,   112,
     120,   121,   122,   123,   124,   125,   126,   134,   135,   136,
     137,   138,   139,   128,   136,   136,    61,   106,   107,   108,
     137,   128,   136,    75,   128,   129,   130,   136,    76,   136,
     127,   128,   136,   136,   136,   136,   136,     0,    93,   138,
     138,    20,    63,     8,   137,    56,    56,    12,    29,    31,
      32,    33,    34,    38,    46,    47,    54,    58,    59,    60,
      61,    62,    63,    64,    65,    67,    68,    69,    70,    71,
      72,    73,    80,    89,     8,    53,   139,    50,    48,    13,
      59,    50,    50,    75,    50,    75,    48,    76,    77,    50,
     138,   137,   136,     8,    62,   127,   128,   131,   132,   133,
     137,   128,   131,   133,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   137,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,    95,    96,    98,    99,   100,   105,   138,
     137,   137,   107,    75,   129,   136,   136,    56,    77,    56,
     138,   136,    50,    76,    50,   119,    52,    50,    76,    50,
     119,    23,    23,    85,    86,   105,    79,    85,    86,    83,
      94,   128,   131,    61,    62,   113,   114,   115,   116,   117,
     118,   137,   133,   128,   132,    76,   136,   133,   128,    76,
     136,    48,    85,    79,    85,    86,    85,    97,   101,    50,
      76,    50,   113,   113,    50,   119,    76,    48,    52,    50,
     119,    50,   119,   119,   119,    96,    85,    84,   101,    62,
     116,    50,   119,    50,   119,    80,   113,   117,    48,    82,
     136,   136,   137,    76,    76,    76,    76,   113,    50,   119,
      62,   116,    50,   119,    96,   136,    52,   119,    62,   113,
      50,   119,   115,   116,    48,   136,   113,   119,    62,    50,
      96,   119,   113,   119
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    91,    92,    92,    92,    93,    94,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   102,   103,   104,   105,   105,
     105,   105,   105,   105,   105,   106,   106,   107,   107,   107,
     108,   108,   109,   110,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   114,   114,   114,   115,   115,   115,   116,
     116,   117,   117,   117,   117,   117,   117,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   122,   123,   124,   124,
     125,   126,   126,   126,   126,   127,   127,   128,   128,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     134,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   137,   138,   138,   139,   139,   139
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     3,     2,     1,     1,
       2,     1,     2,     3,     2,     3,     4,     3,     2,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     1,
       3,     1,     2,     1,     1,     1,     0,     4,     3,     1,
       3,     3,     5,     4,     5,     1,     2,     3,     1,     3,
       1,     4,     5,     7,     3,     5,     6,     8,     3,     1,
       0,     1,     0,     8,    10,     2,     5,     2,     4,     7,
       1,     2,     1,     2,     3,     1,     0,     3,     1,     3,
       3,     1,     1,     2,     3,     2,     3,     1,     1,     1,
       3,     4,     7,     7,     5,     4,     7,     7,     5,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     1,     3,     4,     3,     4,     3,     2,     3,     3,
       2,     3,     3,     3,     3,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     2,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "END_OF_FILE", "error", "\"invalid token\"", "integer_literal",
  "real_literal", "image_literal", "identifier", "sized_type_literal",
  "string_literal", "FALSE", "TRUE", "NONE", "\"and\"", "AS", "ASSERT",
  "ASYNC", "AWAIT", "BREAK", "CLASS", "CONTINUE", "DEF", "DEL", "ELIF",
  "ELSE", "EXCEPT", "FINALLY", "FOR", "FROM", "GLOBAL", "IF", "IMPORT",
  "\"in\"", "\"is\"", "\"is not\"", "\"not in\"", "LAMBDA", "NONLOCAL",
  "\"not\"", "\"or\"", "PASS", "RETURN", "TRY", "WHILE", "WITH", "YIELD",
  "ARROW", "\"&\"", "\"^\"", "\":\"", "\":!\"", "\",\"", "\"=>\"", "\"=\"",
  "\":=\"", "\"==\"", "\"{\"", "\"(\"", "\"[\"", "\"-\"", "\".\"", "\"+\"",
  "\"*\"", "\"**\"", "\"@\"", "\"//\"", "\"%\"", "\"~\"", "\"|\"",
  "\"<<\"", "\">>\"", "\"<\"", "\"<=\"", "\">\"", "\">=\"", "\"...\"",
  "\"}\"", "\")\"", "\"]\"", "\"self\"", "\";\"", "\"/\"", "\"_\"",
  "\"->\"", "INDENT", "DEDENT", "NEWLINE", "COMMENT", "EOLCOMMENT",
  "TYPE_COMMENT", "\"!=\"", "UNARY", "$accept", "units", "script_unit",
  "statements", "sep_statements", "body_stmts", "statements1",
  "single_line_statements", "single_line_multi_statements",
  "single_line_multi_statements_opt", "statement", "pass_statement",
  "break_statement", "continue_statement", "single_line_statement",
  "module", "module_as_id", "module_item_list", "import_statement",
  "multi_line_statement", "decorators_opt", "decorators", "parameter",
  "parameter_list", "parameter_list_no_posonly", "defparameter_list",
  "parameter_list_starargs", "parameter_list_opt", "comma_opt",
  "function_def", "global_statement", "ternary_if_statement",
  "nonlocal_statement", "if_statement", "expression_statment", "string",
  "expr_list_opt", "expr_list", "dict", "dict_list", "call_arguement_list",
  "keyword_item", "keyword_items", "primary", "function_call", "expr",
  "id", "sep", "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   265,   265,   266,   267,   271,   275,   279,   283,   284,
     288,   289,   293,   294,   295,   296,   299,   302,   308,   311,
     317,   320,   326,   327,   328,   333,   337,   341,   345,   350,
     354,   355,   356,   357,   358,   363,   364,   368,   369,   370,
     374,   375,   379,   395,   399,   408,   409,   413,   414,   418,
     419,   420,   421,   425,   427,   429,   433,   434,   436,   440,
     441,   449,   450,   451,   453,   454,   456,   458,   460,   464,
     465,   469,   470,   474,   476,   487,   491,   495,   499,   502,
     510,   514,   515,   518,   521,   527,   528,   532,   533,   543,
     547,   548,   552,   553,   558,   559,   563,   564,   569,   570,
     571,   575,   576,   578,   580,   581,   582,   584,   586,   593,
     597,   598,   602,   603,   604,   608,   609,   610,   611,   612,
     613,   614,   616,   617,   618,   619,   620,   622,   623,   627,
     628,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   642,   643,   644,   645,   646,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   659,   660,   661,
     668,   673,   677,   678,   682,   683,   684
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 21 "parser.ypp"
} //  pxcompiler 
#line 2907 "./parser.cc"

#line 687 "parser.ypp"
