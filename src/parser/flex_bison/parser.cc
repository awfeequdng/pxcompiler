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
      case symbol_kind::S_single_line_statement: // single_line_statement
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

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Arg*>> > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_single_line_statement: // single_line_statement
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

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.move< std::vector<Nonnull<Arg*>> > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_single_line_statement: // single_line_statement
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

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.copy< std::vector<Nonnull<Arg*>> > (that.value);
        break;

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
      case symbol_kind::S_single_line_statement: // single_line_statement
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

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.move< std::vector<Nonnull<Arg*>> > (that.value);
        break;

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
      case symbol_kind::S_single_line_statement: // single_line_statement
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

      case symbol_kind::S_defparameter_list: // defparameter_list
        yylhs.value.emplace< std::vector<Nonnull<Arg*>> > ();
        break;

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
#line 258 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1069 "./parser.cc"
    break;

  case 3: // units: script_unit
#line 259 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1075 "./parser.cc"
    break;

  case 5: // script_unit: statement
#line 264 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1081 "./parser.cc"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 268 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1087 "./parser.cc"
    break;

  case 7: // sep_statements: sep statements
#line 272 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1093 "./parser.cc"
    break;

  case 8: // body_stmts: single_line_statements
#line 276 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1099 "./parser.cc"
    break;

  case 9: // body_stmts: sep_statements
#line 277 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1105 "./parser.cc"
    break;

  case 10: // statements1: statements1 statement
#line 281 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1111 "./parser.cc"
    break;

  case 11: // statements1: statement
#line 282 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1117 "./parser.cc"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 286 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1123 "./parser.cc"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 287 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1129 "./parser.cc"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 288 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1135 "./parser.cc"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 289 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1143 "./parser.cc"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 292 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1151 "./parser.cc"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 295 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1159 "./parser.cc"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 301 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1167 "./parser.cc"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 304 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1175 "./parser.cc"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 310 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1183 "./parser.cc"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 313 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1191 "./parser.cc"
    break;

  case 22: // statement: single_line_statement sep
#line 319 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1197 "./parser.cc"
    break;

  case 23: // statement: multi_line_statement
#line 320 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1203 "./parser.cc"
    break;

  case 24: // statement: multi_line_statement sep
#line 321 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1209 "./parser.cc"
    break;

  case 25: // single_line_statement: expression_statment
#line 325 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1215 "./parser.cc"
    break;

  case 26: // single_line_statement: global_statement
#line 337 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1221 "./parser.cc"
    break;

  case 27: // single_line_statement: nonlocal_statement
#line 339 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1227 "./parser.cc"
    break;

  case 28: // multi_line_statement: if_statement
#line 343 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1233 "./parser.cc"
    break;

  case 29: // multi_line_statement: function_def
#line 347 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1239 "./parser.cc"
    break;

  case 30: // decorators_opt: decorators
#line 356 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1245 "./parser.cc"
    break;

  case 31: // decorators_opt: %empty
#line 357 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1251 "./parser.cc"
    break;

  case 32: // decorators: decorators "@" expr sep
#line 361 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1257 "./parser.cc"
    break;

  case 33: // decorators: "@" expr sep
#line 362 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1263 "./parser.cc"
    break;

  case 34: // parameter: id
#line 366 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1269 "./parser.cc"
    break;

  case 35: // parameter: id ":" expr
#line 367 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1275 "./parser.cc"
    break;

  case 36: // parameter: id "=" expr
#line 368 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1281 "./parser.cc"
    break;

  case 37: // parameter: id ":" expr "=" expr
#line 369 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1287 "./parser.cc"
    break;

  case 38: // parameter_list: defparameter_list "," "/" comma_opt
#line 373 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1294 "./parser.cc"
    break;

  case 39: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 375 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1301 "./parser.cc"
    break;

  case 40: // parameter_list: parameter_list_no_posonly
#line 377 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1307 "./parser.cc"
    break;

  case 41: // parameter_list_no_posonly: defparameter_list comma_opt
#line 381 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1313 "./parser.cc"
    break;

  case 42: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 382 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1320 "./parser.cc"
    break;

  case 43: // parameter_list_no_posonly: parameter_list_starargs
#line 384 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1326 "./parser.cc"
    break;

  case 44: // defparameter_list: defparameter_list "," parameter
#line 388 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1332 "./parser.cc"
    break;

  case 45: // defparameter_list: parameter
#line 389 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1338 "./parser.cc"
    break;

  case 46: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 397 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1344 "./parser.cc"
    break;

  case 47: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 398 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1350 "./parser.cc"
    break;

  case 48: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 399 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1357 "./parser.cc"
    break;

  case 49: // parameter_list_starargs: "*" parameter comma_opt
#line 401 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1363 "./parser.cc"
    break;

  case 50: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 402 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1370 "./parser.cc"
    break;

  case 51: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 404 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1377 "./parser.cc"
    break;

  case 52: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 406 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1384 "./parser.cc"
    break;

  case 53: // parameter_list_starargs: "**" parameter comma_opt
#line 408 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1390 "./parser.cc"
    break;

  case 54: // parameter_list_opt: parameter_list
#line 412 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1396 "./parser.cc"
    break;

  case 55: // parameter_list_opt: %empty
#line 413 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1402 "./parser.cc"
    break;

  case 58: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 423 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1408 "./parser.cc"
    break;

  case 59: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 425 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1414 "./parser.cc"
    break;

  case 60: // global_statement: GLOBAL expr_list
#line 435 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1420 "./parser.cc"
    break;

  case 61: // ternary_if_statement: expr IF expr ELSE expr
#line 439 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1426 "./parser.cc"
    break;

  case 62: // nonlocal_statement: NONLOCAL expr_list
#line 443 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1432 "./parser.cc"
    break;

  case 63: // if_statement: IF expr ":" body_stmts
#line 447 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1440 "./parser.cc"
    break;

  case 64: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 450 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1448 "./parser.cc"
    break;

  case 65: // expression_statment: expr
#line 458 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1454 "./parser.cc"
    break;

  case 66: // string: string string_literal
#line 462 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1460 "./parser.cc"
    break;

  case 67: // string: string_literal
#line 463 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1468 "./parser.cc"
    break;

  case 68: // string: id string_literal
#line 466 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1476 "./parser.cc"
    break;

  case 69: // string: string id string_literal
#line 469 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1484 "./parser.cc"
    break;

  case 70: // expr_list_opt: expr_list
#line 475 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1490 "./parser.cc"
    break;

  case 71: // expr_list_opt: %empty
#line 476 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1496 "./parser.cc"
    break;

  case 72: // expr_list: expr_list "," expr
#line 480 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1502 "./parser.cc"
    break;

  case 73: // expr_list: expr
#line 481 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1508 "./parser.cc"
    break;

  case 74: // dict: expr ":" expr
#line 491 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1514 "./parser.cc"
    break;

  case 75: // dict_list: dict_list "," dict
#line 495 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1520 "./parser.cc"
    break;

  case 76: // dict_list: dict
#line 496 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1526 "./parser.cc"
    break;

  case 77: // call_arguement_list: expr_list_opt
#line 500 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1532 "./parser.cc"
    break;

  case 78: // call_arguement_list: expr_list ","
#line 501 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1538 "./parser.cc"
    break;

  case 79: // keyword_item: id "=" expr
#line 506 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1544 "./parser.cc"
    break;

  case 80: // keyword_item: "**" expr
#line 507 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1550 "./parser.cc"
    break;

  case 81: // keyword_items: keyword_items "," keyword_item
#line 511 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1556 "./parser.cc"
    break;

  case 82: // keyword_items: keyword_item
#line 512 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1562 "./parser.cc"
    break;

  case 83: // primary: id
#line 517 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1568 "./parser.cc"
    break;

  case 84: // primary: string
#line 518 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1574 "./parser.cc"
    break;

  case 85: // primary: expr "." id
#line 519 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1580 "./parser.cc"
    break;

  case 86: // function_call: primary "(" call_arguement_list ")"
#line 523 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1586 "./parser.cc"
    break;

  case 87: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 524 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1593 "./parser.cc"
    break;

  case 88: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 526 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1600 "./parser.cc"
    break;

  case 89: // function_call: primary "(" keyword_items comma_opt ")"
#line 528 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1606 "./parser.cc"
    break;

  case 90: // function_call: function_call "(" call_arguement_list ")"
#line 529 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1612 "./parser.cc"
    break;

  case 91: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 530 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1619 "./parser.cc"
    break;

  case 92: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 532 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1626 "./parser.cc"
    break;

  case 93: // function_call: function_call "(" keyword_items comma_opt ")"
#line 534 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1632 "./parser.cc"
    break;

  case 94: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 541 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1638 "./parser.cc"
    break;

  case 95: // expr: id
#line 545 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1644 "./parser.cc"
    break;

  case 96: // expr: integer_literal
#line 546 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 1653 "./parser.cc"
    break;

  case 97: // expr: string
#line 550 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1659 "./parser.cc"
    break;

  case 98: // expr: real_literal
#line 551 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 1665 "./parser.cc"
    break;

  case 99: // expr: image_literal
#line 552 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 1674 "./parser.cc"
    break;

  case 100: // expr: TRUE
#line 556 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 1680 "./parser.cc"
    break;

  case 101: // expr: FALSE
#line 557 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 1686 "./parser.cc"
    break;

  case 102: // expr: NONE
#line 558 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 1692 "./parser.cc"
    break;

  case 103: // expr: "..."
#line 559 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 1698 "./parser.cc"
    break;

  case 104: // expr: "(" expr ")"
#line 560 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 1704 "./parser.cc"
    break;

  case 105: // expr: "(" ")"
#line 561 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 1710 "./parser.cc"
    break;

  case 106: // expr: function_call
#line 562 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1716 "./parser.cc"
    break;

  case 107: // expr: "[" expr_list_opt "]"
#line 564 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1722 "./parser.cc"
    break;

  case 108: // expr: "[" expr_list "," "]"
#line 565 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1728 "./parser.cc"
    break;

  case 109: // expr: "{" expr_list "}"
#line 566 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1734 "./parser.cc"
    break;

  case 110: // expr: "{" expr_list "," "}"
#line 567 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1740 "./parser.cc"
    break;

  case 111: // expr: expr "." id
#line 568 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1746 "./parser.cc"
    break;

  case 112: // expr: "{" "}"
#line 570 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 1752 "./parser.cc"
    break;

  case 113: // expr: "{" dict_list "}"
#line 571 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 1758 "./parser.cc"
    break;

  case 114: // expr: id ":=" expr
#line 575 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1764 "./parser.cc"
    break;

  case 115: // expr: "*" expr
#line 576 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1770 "./parser.cc"
    break;

  case 116: // expr: expr "+" expr
#line 578 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1776 "./parser.cc"
    break;

  case 117: // expr: expr "-" expr
#line 579 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1782 "./parser.cc"
    break;

  case 118: // expr: expr "*" expr
#line 580 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1788 "./parser.cc"
    break;

  case 119: // expr: expr "/" expr
#line 581 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1794 "./parser.cc"
    break;

  case 120: // expr: expr "%" expr
#line 582 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1800 "./parser.cc"
    break;

  case 121: // expr: "-" expr
#line 583 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 1806 "./parser.cc"
    break;

  case 122: // expr: "+" expr
#line 584 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 1812 "./parser.cc"
    break;

  case 123: // expr: "~" expr
#line 585 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 1818 "./parser.cc"
    break;

  case 124: // expr: expr "**" expr
#line 586 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1824 "./parser.cc"
    break;

  case 125: // expr: expr "//" expr
#line 587 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1830 "./parser.cc"
    break;

  case 126: // expr: expr "@" expr
#line 588 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1836 "./parser.cc"
    break;

  case 127: // expr: expr "&" expr
#line 590 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1842 "./parser.cc"
    break;

  case 128: // expr: expr "|" expr
#line 591 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1848 "./parser.cc"
    break;

  case 129: // expr: expr "^" expr
#line 592 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1854 "./parser.cc"
    break;

  case 130: // expr: expr "<<" expr
#line 593 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1860 "./parser.cc"
    break;

  case 131: // expr: expr ">>" expr
#line 594 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1866 "./parser.cc"
    break;

  case 132: // expr: expr "==" expr
#line 596 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1872 "./parser.cc"
    break;

  case 133: // expr: expr "!=" expr
#line 597 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1878 "./parser.cc"
    break;

  case 134: // expr: expr "<" expr
#line 598 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1884 "./parser.cc"
    break;

  case 135: // expr: expr "<=" expr
#line 599 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1890 "./parser.cc"
    break;

  case 136: // expr: expr ">" expr
#line 600 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1896 "./parser.cc"
    break;

  case 137: // expr: expr ">=" expr
#line 601 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1902 "./parser.cc"
    break;

  case 138: // expr: expr "is" expr
#line 602 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1908 "./parser.cc"
    break;

  case 139: // expr: expr "is not" expr
#line 603 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1914 "./parser.cc"
    break;

  case 140: // expr: expr "in" expr
#line 604 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1920 "./parser.cc"
    break;

  case 141: // expr: expr "not in" expr
#line 605 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1926 "./parser.cc"
    break;

  case 142: // expr: expr "and" expr
#line 607 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1932 "./parser.cc"
    break;

  case 143: // expr: expr "or" expr
#line 608 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1938 "./parser.cc"
    break;

  case 144: // expr: "not" expr
#line 609 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 1944 "./parser.cc"
    break;

  case 145: // expr: ternary_if_statement
#line 616 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1950 "./parser.cc"
    break;

  case 146: // id: identifier
#line 621 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1956 "./parser.cc"
    break;

  case 147: // sep: sep sep_one
#line 625 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 1962 "./parser.cc"
    break;

  case 148: // sep: sep_one
#line 626 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 1968 "./parser.cc"
    break;

  case 149: // sep_one: NEWLINE
#line 630 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 1974 "./parser.cc"
    break;

  case 150: // sep_one: COMMENT
#line 631 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 1980 "./parser.cc"
    break;

  case 151: // sep_one: ";"
#line 632 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 1986 "./parser.cc"
    break;


#line 1990 "./parser.cc"

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









  const short  Parser ::yypact_ninf_ = -208;

  const signed char  Parser ::yytable_ninf_ = -86;

  const short
   Parser ::yypact_[] =
  {
     282,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  1213,
    1213,  1213,  1213,  1043,   984,  1213,  1213,  1213,  1213,  1213,
    1213,  -208,  -208,  -208,  -208,   942,  -208,  -208,   -53,   -53,
      -1,   -40,  -208,  -208,  -208,  -208,  -208,  -208,   125,   -20,
     -14,   772,    98,   -53,  -208,     4,   772,   493,     4,  1244,
    -208,   -29,  -208,   -28,   538,  -208,   583,    28,    73,   -25,
     -25,   -25,   431,   -25,  -208,  -208,   -53,   -53,   122,  1213,
    -208,   130,  1198,  1198,  1213,  1213,  1213,  1213,  1213,  1213,
    1213,  1213,  1213,  1213,  1213,   122,  1213,  1213,  1213,  1213,
    1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,
    1213,  -208,  1213,  -208,  1213,   349,  1065,  -208,  1213,  -208,
    1213,    84,  -208,   954,   -53,    88,   431,  -208,  1213,  -208,
     106,    70,  -208,   107,   133,   110,    72,   120,  1244,   637,
    1276,  1276,  1276,  1276,   860,   240,  1026,  1276,   267,   118,
     267,   -25,   -25,   -25,   -25,   -25,   209,   201,   201,  1276,
    1276,  1276,  1276,   -25,  1276,   816,   772,  -208,   154,  -208,
     -68,  1139,    57,   -55,  -208,  -208,   538,   772,  1213,  -208,
      49,   -53,   772,  1198,  -208,  1198,   102,  1213,  1198,  -208,
    1198,   103,  1213,   132,  -208,   105,   104,   -46,  -208,   108,
    1124,  -208,   137,   119,   115,   122,  -208,  -208,  -208,   141,
    -208,   121,   -23,   144,   149,  -208,  -208,   772,   144,   149,
    -208,   816,   349,  -208,    67,  -208,   116,  -208,   384,  -208,
    1213,  -208,    14,   150,   152,    52,  -208,   -34,  1213,  1213,
      53,   128,  1213,   138,   139,   140,  -208,  -208,  -208,  -208,
     122,   156,    56,  -208,  -208,  -208,   163,  -208,  -208,   349,
    1213,   682,   772,   165,  -208,  -208,  -208,  -208,   152,   113,
    -208,   122,   168,    49,  -208,  -208,   727,  1213,  -208,   122,
     152,   114,  -208,  -208,   171,   349,   772,   152,  -208,   122,
      49,  -208,  -208,   152,  -208
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
      31,    96,    98,    99,   146,    67,   101,   100,   102,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,     0,
       0,   103,   151,   149,   150,    31,     3,     5,     0,    23,
       0,    30,    29,    26,   145,    27,    28,    25,    97,     0,
     106,    65,    95,     4,   148,    60,    73,     0,    62,   144,
     112,     0,    76,     0,    73,   105,     0,     0,    70,   121,
     122,   115,     0,   123,     1,     2,    22,    24,     0,     0,
      66,     0,    71,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,     0,   147,     0,     0,     0,   109,     0,   113,
       0,   104,   107,     0,    33,     0,     0,    69,     0,    77,
      70,     0,    82,    57,    95,    70,     0,    57,   142,     0,
     140,   138,   139,   141,   143,   127,   129,   132,   117,   111,
     116,   118,   124,   126,   125,   120,   128,   130,   131,   134,
     135,   136,   137,   119,   133,   114,    72,     9,    63,     8,
       0,     0,     0,     0,   110,    75,     0,    74,    71,   108,
      55,    32,    80,    78,    86,    56,     0,     0,    78,    90,
      56,     0,     0,     0,    12,     0,    18,    21,    14,     0,
      31,     7,    70,     0,     0,     0,    45,    54,    40,    57,
      43,     0,    34,    57,    57,    81,    89,    79,    57,    57,
      93,    61,     0,    13,    20,    15,     0,    17,    31,    11,
      78,    94,     0,    57,    57,    56,    41,     0,     0,     0,
      56,     0,    56,     0,     0,     0,    64,    16,     6,    10,
       0,    57,    56,    49,    56,    53,    57,    44,    42,     0,
       0,    35,    36,     0,    87,    88,    91,    92,    57,    56,
      46,     0,    57,    56,    38,    58,     0,     0,    47,     0,
      57,    56,    50,    39,    57,     0,    37,    57,    51,     0,
      56,    59,    48,    57,    52
  };

  const short
   Parser ::yypgoto_[] =
  {
    -208,  -208,   197,  -208,  -208,  -112,  -208,  -208,  -208,  -208,
    -174,   -67,  -208,  -208,  -208,   -33,  -208,   -38,  -207,  -164,
    -208,   -74,  -208,  -208,  -208,  -208,  -208,  -208,  -208,   215,
      30,   123,  -208,   -60,  -123,   -61,  -208,  -208,    -9,    54,
      96,   -16
  };

  const unsigned char
   Parser ::yydefgoto_[] =
  {
       0,    25,    26,   191,   157,   158,   218,   159,   160,   161,
      27,    28,    29,    30,    31,   196,   197,   198,   199,   200,
     201,   226,    32,    33,    34,    35,    36,    37,    38,   119,
      45,    52,    53,   121,   122,   123,    39,    40,    41,    42,
     163,    44
  };

  const short
   Parser ::yytable_[] =
  {
      46,    47,    46,    49,    54,    56,    46,    59,    60,    61,
      62,    63,   127,   126,   249,   241,   219,   184,   185,    68,
       4,   106,   108,    69,    22,   228,    22,   103,   190,   229,
      23,    24,    23,    24,    85,   262,    72,    88,   162,   215,
     216,    48,    73,    51,   239,    58,   107,   109,   250,   176,
     103,   103,   205,   181,   104,     4,   274,   205,     4,     4,
     116,   248,     4,    46,    46,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   240,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    71,   155,   186,   156,    43,   156,   103,   166,
     236,   167,   120,   125,   156,   112,   101,   205,   193,   172,
     194,   195,   203,   194,   195,   118,   248,   208,   261,     4,
       4,     4,   115,   113,    66,    67,   124,   124,     4,   231,
     233,     4,   246,    70,   234,   235,   187,   265,   117,   139,
     168,   101,   188,   189,   170,   162,   174,   103,   179,   243,
     245,   102,   -19,   -19,   -83,   103,   173,   175,   114,    46,
     178,   223,   224,   281,   156,   222,    46,   260,   207,   156,
     180,    46,   264,   211,   -85,   269,   279,   183,   206,   210,
     212,   -84,   162,   214,   268,   177,   102,   220,   272,   -83,
     213,   225,   247,   217,   230,   221,   278,   227,   192,   232,
     242,   237,   244,   282,   254,   204,   259,   258,   162,   284,
     209,   156,   171,   263,   255,   256,   257,   177,   271,   251,
     252,   280,    65,   156,   202,   273,   247,   124,   270,   124,
      57,   165,   124,     0,   124,     0,   277,     0,   247,     0,
       0,   266,     0,     0,     0,     0,   283,   247,   202,   202,
       0,     0,     0,     0,     0,    81,    82,     0,   276,    84,
      85,    86,    87,    88,    89,    90,    91,    84,    85,    86,
      87,    88,    89,    90,    91,     0,   202,    93,    94,   202,
       0,    99,     0,     0,   253,     1,     2,     3,     4,    99,
       5,     6,     7,     8,   202,     0,   202,     0,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,    93,    94,
       9,    10,     0,   202,     0,   202,     0,   202,    11,    12,
      99,     0,     0,   202,     0,   202,    85,     0,    87,    88,
      89,    90,    91,   202,   202,     0,     0,    13,    14,    15,
      16,     0,    17,    18,     0,    19,     0,    99,    20,     0,
       0,     0,     1,     2,     3,     4,    21,     5,     6,     7,
       8,    22,     0,     0,     0,     0,     0,    23,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,    11,    12,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,    15,    16,     0,    17,
      18,     0,     9,    10,     0,    20,     0,     0,     0,     0,
      11,    12,     0,    21,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,    23,    24,     0,     0,     0,    13,
      14,    15,    16,    74,    17,    18,     0,    19,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    21,     0,
      75,     0,    76,    77,    78,    79,     0,     0,   238,    80,
       0,     0,     0,     0,     0,     0,     0,    81,    82,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,    84,
      85,    86,    87,    88,    89,    90,    91,     0,    92,    93,
      94,    95,    96,    97,    98,    74,     0,     0,     0,     0,
      22,    99,     0,     0,     0,     0,    23,    24,     0,     0,
     100,     0,    75,     0,    76,    77,    78,    79,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,    81,
      82,   105,     0,     0,     0,     0,     0,    83,     0,     0,
      74,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,    93,    94,    95,    96,    97,    98,    75,     0,    76,
      77,    78,    79,    99,     0,     0,    80,     0,     0,     0,
       0,     0,   100,     0,    81,    82,   110,     0,     0,     0,
       0,     0,    83,     0,     0,    74,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    92,    93,    94,    95,    96,
      97,    98,    75,     0,    76,    77,    78,    79,    99,     0,
       0,    80,     0,     0,     0,     0,     0,   100,     0,    81,
      82,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    74,
      92,    93,    94,    95,    96,    97,    98,     0,     0,   111,
     182,     0,     0,    99,     0,     0,    75,     0,    76,    77,
      78,    79,   100,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,    83,     0,     0,    74,    84,    85,    86,    87,    88,
      89,    90,    91,     0,    92,    93,    94,    95,    96,    97,
      98,    75,     0,    76,    77,    78,    79,    99,     0,     0,
      80,     0,     0,     0,     0,     0,   100,     0,    81,    82,
       0,     0,     0,     0,   267,     0,    83,     0,     0,    74,
      84,    85,    86,    87,    88,    89,    90,    91,     0,    92,
      93,    94,    95,    96,    97,    98,    75,     0,    76,    77,
      78,    79,    99,     0,     0,    80,     0,     0,     0,     0,
       0,   100,     0,    81,    82,   275,     0,     0,     0,     0,
       0,    83,     0,     0,    74,    84,    85,    86,    87,    88,
      89,    90,    91,     0,    92,    93,    94,    95,    96,    97,
      98,    75,     0,    76,    77,    78,    79,    99,     0,     0,
      80,     0,     0,     0,     0,     0,   100,     0,    81,    82,
       0,     0,     0,     0,     0,     0,    83,     0,    74,     0,
      84,    85,    86,    87,    88,    89,    90,    91,     0,    92,
      93,    94,    95,    96,    97,    98,     0,    76,    77,    78,
      79,     0,    99,     0,    80,     0,     0,     0,     0,     0,
       0,   100,    81,    82,     0,     0,     0,     0,     0,     0,
      83,     0,    74,     0,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
       0,    76,    77,    78,    79,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,   100,    81,    82,     0,     0,
       0,     0,     0,     0,    83,     0,     0,     0,    84,    85,
      86,    87,    88,    89,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,     0,    64,     0,     0,     1,     2,     3,     4,   100,
       5,     6,     7,     8,     0,     0,     0,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     0,     0,
       9,    10,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,    12,     5,     6,     7,     8,     0,    13,    14,    15,
      16,     0,    17,    18,     0,    19,     0,     0,    20,    13,
      14,    15,    16,     0,    17,    18,    21,     0,     0,     0,
      20,    12,     0,     0,     0,     0,     0,     0,    21,     0,
       0,   169,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    16,     0,    17,    18,     1,     2,     3,     4,
      20,     5,     6,     7,     8,     0,     0,     0,    21,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,    81,     5,     6,     7,     8,     0,     0,     0,
      12,     0,     0,     0,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,    93,    94,     0,     0,    13,    14,
      15,    16,    12,    17,    18,     0,    99,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,    21,    50,     0,
      13,    14,    15,    16,     0,    17,    18,     1,     2,     3,
       4,    20,     5,     6,     7,     8,     0,     0,     0,    21,
     164,     0,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     9,    10,     0,     0,     0,     0,     0,     0,
      11,    12,     0,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,    11,    12,     0,     0,    13,
      14,    15,    16,     0,    17,    18,     0,    19,     0,     0,
      20,     0,     0,     0,    13,    14,    15,    16,    21,    17,
      18,     1,     2,     3,     4,    20,     5,     6,     7,     8,
       0,     0,     0,    21,     0,     0,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,    13,    14,    15,    16,     0,    17,    18,
     118,     0,     0,     0,    20,     0,     0,     0,    13,    14,
      15,    16,    21,    17,    18,    76,    77,    78,    79,    20,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
      81,    82,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,    81,    82,    99,     0,     0,     0,     0,     0,
       0,     0,     0,   100,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99
  };

  const short
   Parser ::yycheck_[] =
  {
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    73,    73,    48,   222,   190,    85,    86,    20,
       6,    50,    50,    63,    79,    48,    79,    43,    83,    52,
      85,    86,    85,    86,    59,   242,    56,    62,   105,    85,
      86,    11,    56,    13,   218,    15,    75,    75,    82,   123,
      66,    67,   175,   127,    50,     6,   263,   180,     6,     6,
      69,   225,     6,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    62,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    38,   102,   161,   104,     0,   106,   114,   108,
     212,   110,    72,    73,   113,    77,     8,   230,   168,   118,
      61,    62,   173,    61,    62,    62,   280,   178,    62,     6,
       6,     6,    68,    50,    28,    29,    72,    73,     6,   203,
     204,     6,    80,     8,   208,   209,    79,   249,     8,    85,
      56,     8,    85,    86,    56,   212,    76,   163,    76,   223,
     224,    53,    85,    86,    56,   171,    50,    50,    62,   168,
      50,   194,   195,   275,   173,    50,   175,   241,   177,   178,
      50,   180,   246,   182,    56,    62,    62,    23,    76,    76,
      48,    56,   249,    79,   258,    52,    53,    50,   262,    56,
      85,    50,   225,    85,    50,    76,   270,    76,   168,    50,
      50,    85,    50,   277,    76,   175,    50,   240,   275,   283,
     180,   220,   116,    50,    76,    76,    76,    52,    50,   228,
     229,    50,    25,   232,   170,   263,   259,   173,   261,   175,
      15,   108,   178,    -1,   180,    -1,   269,    -1,   271,    -1,
      -1,   250,    -1,    -1,    -1,    -1,   279,   280,   194,   195,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,   267,    58,
      59,    60,    61,    62,    63,    64,    65,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,   222,    68,    69,   225,
      -1,    80,    -1,    -1,   230,     3,     4,     5,     6,    80,
       8,     9,    10,    11,   240,    -1,   242,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    -1,    68,    69,
      28,    29,    -1,   259,    -1,   261,    -1,   263,    36,    37,
      80,    -1,    -1,   269,    -1,   271,    59,    -1,    61,    62,
      63,    64,    65,   279,   280,    -1,    -1,    55,    56,    57,
      58,    -1,    60,    61,    -1,    63,    -1,    80,    66,    -1,
      -1,    -1,     3,     4,     5,     6,    74,     8,     9,    10,
      11,    79,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    60,
      61,    -1,    28,    29,    -1,    66,    -1,    -1,    -1,    -1,
      36,    37,    -1,    74,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    55,
      56,    57,    58,    12,    60,    61,    -1,    63,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      29,    -1,    31,    32,    33,    34,    -1,    -1,    84,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    12,    -1,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,
      89,    -1,    29,    -1,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      12,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    29,    -1,    31,
      32,    33,    34,    80,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    12,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    29,    -1,    31,    32,    33,    34,    80,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    89,    -1,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    12,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    76,
      23,    -1,    -1,    80,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    89,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    12,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    29,    -1,    31,    32,    33,    34,    80,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    89,    -1,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,    54,    -1,    -1,    12,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    29,    -1,    31,    32,
      33,    34,    80,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    12,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    29,    -1,    31,    32,    33,    34,    80,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    89,    -1,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    12,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    -1,    31,    32,    33,
      34,    -1,    80,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    12,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      -1,    31,    32,    33,    34,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,     0,    -1,    -1,     3,     4,     5,     6,    89,
       8,     9,    10,    11,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    37,     8,     9,    10,    11,    -1,    55,    56,    57,
      58,    -1,    60,    61,    -1,    63,    -1,    -1,    66,    55,
      56,    57,    58,    -1,    60,    61,    74,    -1,    -1,    -1,
      66,    37,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    60,    61,     3,     4,     5,     6,
      66,     8,     9,    10,    11,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    46,     8,     9,    10,    11,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    -1,    68,    69,    -1,    -1,    55,    56,
      57,    58,    37,    60,    61,    -1,    80,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,
      55,    56,    57,    58,    -1,    60,    61,     3,     4,     5,
       6,    66,     8,     9,    10,    11,    -1,    -1,    -1,    74,
      75,    -1,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    55,
      56,    57,    58,    -1,    60,    61,    -1,    63,    -1,    -1,
      66,    -1,    -1,    -1,    55,    56,    57,    58,    74,    60,
      61,     3,     4,     5,     6,    66,     8,     9,    10,    11,
      -1,    -1,    -1,    74,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    55,    56,    57,    58,    -1,    60,    61,
      62,    -1,    -1,    -1,    66,    -1,    -1,    -1,    55,    56,
      57,    58,    74,    60,    61,    31,    32,    33,    34,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    46,    47,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    28,
      29,    36,    37,    55,    56,    57,    58,    60,    61,    63,
      66,    74,    79,    85,    86,    92,    93,   101,   102,   103,
     104,   105,   113,   114,   115,   116,   117,   118,   119,   127,
     128,   129,   130,   131,   132,   121,   129,   129,   121,   129,
      75,   121,   122,   123,   129,    76,   129,   120,   121,   129,
     129,   129,   129,   129,     0,    93,   131,   131,    20,    63,
       8,   130,    56,    56,    12,    29,    31,    32,    33,    34,
      38,    46,    47,    54,    58,    59,    60,    61,    62,    63,
      64,    65,    67,    68,    69,    70,    71,    72,    73,    80,
      89,     8,    53,   132,    50,    48,    50,    75,    50,    75,
      48,    76,    77,    50,   131,   130,   129,     8,    62,   120,
     121,   124,   125,   126,   130,   121,   124,   126,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   130,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,    95,    96,    98,
      99,   100,   102,   131,    75,   122,   129,   129,    56,    77,
      56,   131,   129,    50,    76,    50,   112,    52,    50,    76,
      50,   112,    23,    23,    85,    86,   102,    79,    85,    86,
      83,    94,   121,   124,    61,    62,   106,   107,   108,   109,
     110,   111,   130,   126,   121,   125,    76,   129,   126,   121,
      76,   129,    48,    85,    79,    85,    86,    85,    97,   101,
      50,    76,    50,   106,   106,    50,   112,    76,    48,    52,
      50,   112,    50,   112,   112,   112,    96,    85,    84,   101,
      62,   109,    50,   112,    50,   112,    80,   106,   110,    48,
      82,   129,   129,   130,    76,    76,    76,    76,   106,    50,
     112,    62,   109,    50,   112,    96,   129,    52,   112,    62,
     106,    50,   112,   108,   109,    48,   129,   106,   112,    62,
      50,    96,   112,   106,   112
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    91,    92,    92,    92,    93,    94,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   102,   102,   102,   103,   103,
     104,   104,   105,   105,   106,   106,   106,   106,   107,   107,
     107,   108,   108,   108,   109,   109,   110,   110,   110,   110,
     110,   110,   110,   110,   111,   111,   112,   112,   113,   113,
     114,   115,   116,   117,   117,   118,   119,   119,   119,   119,
     120,   120,   121,   121,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   127,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   130,   131,   131,   132,
     132,   132
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     3,     2,     1,     1,
       2,     1,     2,     3,     2,     3,     4,     3,     2,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     0,     4,     3,     1,     3,     3,     5,     4,     5,
       1,     2,     3,     1,     3,     1,     4,     5,     7,     3,
       5,     6,     8,     3,     1,     0,     1,     0,     8,    10,
       2,     5,     2,     4,     7,     1,     2,     1,     2,     3,
       1,     0,     3,     1,     3,     3,     1,     1,     2,     3,
       2,     3,     1,     1,     1,     3,     4,     7,     7,     5,
       4,     7,     7,     5,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     3,     4,     3,
       4,     3,     2,     3,     3,     2,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     2,     1,     1,
       1,     1
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
  "single_line_multi_statements_opt", "statement", "single_line_statement",
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
       0,   258,   258,   259,   260,   264,   268,   272,   276,   277,
     281,   282,   286,   287,   288,   289,   292,   295,   301,   304,
     310,   313,   319,   320,   321,   325,   337,   339,   343,   347,
     356,   357,   361,   362,   366,   367,   368,   369,   373,   375,
     377,   381,   382,   384,   388,   389,   397,   398,   399,   401,
     402,   404,   406,   408,   412,   413,   417,   418,   422,   424,
     435,   439,   443,   447,   450,   458,   462,   463,   466,   469,
     475,   476,   480,   481,   491,   495,   496,   500,   501,   506,
     507,   511,   512,   517,   518,   519,   523,   524,   526,   528,
     529,   530,   532,   534,   541,   545,   546,   550,   551,   552,
     556,   557,   558,   559,   560,   561,   562,   564,   565,   566,
     567,   568,   570,   571,   575,   576,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   590,   591,   592,
     593,   594,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   607,   608,   609,   616,   621,   625,   626,   630,
     631,   632
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
#line 2721 "./parser.cc"

#line 635 "parser.ypp"
