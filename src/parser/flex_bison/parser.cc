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
#line 254 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1054 "./parser.cc"
    break;

  case 3: // units: script_unit
#line 255 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1060 "./parser.cc"
    break;

  case 5: // script_unit: statement
#line 260 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1066 "./parser.cc"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 264 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1072 "./parser.cc"
    break;

  case 7: // sep_statements: sep statements
#line 268 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1078 "./parser.cc"
    break;

  case 8: // body_stmts: single_line_statements
#line 272 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1084 "./parser.cc"
    break;

  case 9: // body_stmts: sep_statements
#line 273 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1090 "./parser.cc"
    break;

  case 10: // statements1: statements1 statement
#line 277 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1096 "./parser.cc"
    break;

  case 11: // statements1: statement
#line 278 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1102 "./parser.cc"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 282 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1108 "./parser.cc"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 283 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1114 "./parser.cc"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 284 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1120 "./parser.cc"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 285 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1128 "./parser.cc"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 288 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1136 "./parser.cc"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 291 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1144 "./parser.cc"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 297 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1152 "./parser.cc"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 300 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1160 "./parser.cc"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 306 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1168 "./parser.cc"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 309 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1176 "./parser.cc"
    break;

  case 22: // statement: single_line_statement sep
#line 315 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1182 "./parser.cc"
    break;

  case 23: // statement: multi_line_statement
#line 316 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1188 "./parser.cc"
    break;

  case 24: // statement: multi_line_statement sep
#line 317 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1194 "./parser.cc"
    break;

  case 25: // single_line_statement: expression_statment
#line 321 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1200 "./parser.cc"
    break;

  case 26: // multi_line_statement: if_statement
#line 339 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1206 "./parser.cc"
    break;

  case 27: // multi_line_statement: function_def
#line 343 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1212 "./parser.cc"
    break;

  case 28: // decorators_opt: decorators
#line 352 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1218 "./parser.cc"
    break;

  case 29: // decorators_opt: %empty
#line 353 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1224 "./parser.cc"
    break;

  case 30: // decorators: decorators "@" expr sep
#line 357 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1230 "./parser.cc"
    break;

  case 31: // decorators: "@" expr sep
#line 358 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1236 "./parser.cc"
    break;

  case 32: // parameter: id
#line 362 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1242 "./parser.cc"
    break;

  case 33: // parameter: id ":" expr
#line 363 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1248 "./parser.cc"
    break;

  case 34: // parameter: id "=" expr
#line 364 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1254 "./parser.cc"
    break;

  case 35: // parameter: id ":" expr "=" expr
#line 365 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1260 "./parser.cc"
    break;

  case 36: // parameter_list: defparameter_list "," "/" comma_opt
#line 369 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1267 "./parser.cc"
    break;

  case 37: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 371 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1274 "./parser.cc"
    break;

  case 38: // parameter_list: parameter_list_no_posonly
#line 373 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1280 "./parser.cc"
    break;

  case 39: // parameter_list_no_posonly: defparameter_list comma_opt
#line 377 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1286 "./parser.cc"
    break;

  case 40: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 378 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1293 "./parser.cc"
    break;

  case 41: // parameter_list_no_posonly: parameter_list_starargs
#line 380 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1299 "./parser.cc"
    break;

  case 42: // defparameter_list: defparameter_list "," parameter
#line 384 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1305 "./parser.cc"
    break;

  case 43: // defparameter_list: parameter
#line 385 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1311 "./parser.cc"
    break;

  case 44: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 393 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1317 "./parser.cc"
    break;

  case 45: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 394 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1323 "./parser.cc"
    break;

  case 46: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 395 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1330 "./parser.cc"
    break;

  case 47: // parameter_list_starargs: "*" parameter comma_opt
#line 397 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1336 "./parser.cc"
    break;

  case 48: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 398 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1343 "./parser.cc"
    break;

  case 49: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 400 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1350 "./parser.cc"
    break;

  case 50: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 402 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1357 "./parser.cc"
    break;

  case 51: // parameter_list_starargs: "**" parameter comma_opt
#line 404 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1363 "./parser.cc"
    break;

  case 52: // parameter_list_opt: parameter_list
#line 408 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1369 "./parser.cc"
    break;

  case 53: // parameter_list_opt: %empty
#line 409 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1375 "./parser.cc"
    break;

  case 56: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 419 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1381 "./parser.cc"
    break;

  case 57: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 421 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1387 "./parser.cc"
    break;

  case 58: // if_statement: IF expr ":" body_stmts
#line 431 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1395 "./parser.cc"
    break;

  case 59: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 434 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1403 "./parser.cc"
    break;

  case 60: // expression_statment: expr
#line 442 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1409 "./parser.cc"
    break;

  case 61: // string: string string_literal
#line 446 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1415 "./parser.cc"
    break;

  case 62: // string: string_literal
#line 447 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1423 "./parser.cc"
    break;

  case 63: // string: id string_literal
#line 450 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1431 "./parser.cc"
    break;

  case 64: // string: string id string_literal
#line 453 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1439 "./parser.cc"
    break;

  case 65: // expr_list_opt: expr_list
#line 459 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1445 "./parser.cc"
    break;

  case 66: // expr_list_opt: %empty
#line 460 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1451 "./parser.cc"
    break;

  case 67: // expr_list: expr_list "," expr
#line 464 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1457 "./parser.cc"
    break;

  case 68: // expr_list: expr
#line 465 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1463 "./parser.cc"
    break;

  case 69: // dict: expr ":" expr
#line 475 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1469 "./parser.cc"
    break;

  case 70: // dict_list: dict_list "," dict
#line 479 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1475 "./parser.cc"
    break;

  case 71: // dict_list: dict
#line 480 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1481 "./parser.cc"
    break;

  case 72: // call_arguement_list: expr_list_opt
#line 484 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1487 "./parser.cc"
    break;

  case 73: // call_arguement_list: expr_list ","
#line 485 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1493 "./parser.cc"
    break;

  case 74: // keyword_item: id "=" expr
#line 490 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1499 "./parser.cc"
    break;

  case 75: // keyword_item: "**" expr
#line 491 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1505 "./parser.cc"
    break;

  case 76: // keyword_items: keyword_items "," keyword_item
#line 495 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1511 "./parser.cc"
    break;

  case 77: // keyword_items: keyword_item
#line 496 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1517 "./parser.cc"
    break;

  case 78: // primary: id
#line 501 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1523 "./parser.cc"
    break;

  case 79: // primary: string
#line 502 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1529 "./parser.cc"
    break;

  case 80: // primary: expr "." id
#line 503 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1535 "./parser.cc"
    break;

  case 81: // function_call: primary "(" call_arguement_list ")"
#line 507 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1541 "./parser.cc"
    break;

  case 82: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 508 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1548 "./parser.cc"
    break;

  case 83: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 510 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1555 "./parser.cc"
    break;

  case 84: // function_call: primary "(" keyword_items comma_opt ")"
#line 512 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1561 "./parser.cc"
    break;

  case 85: // function_call: function_call "(" call_arguement_list ")"
#line 513 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1567 "./parser.cc"
    break;

  case 86: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 514 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1574 "./parser.cc"
    break;

  case 87: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 516 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1581 "./parser.cc"
    break;

  case 88: // function_call: function_call "(" keyword_items comma_opt ")"
#line 518 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1587 "./parser.cc"
    break;

  case 89: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 525 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1593 "./parser.cc"
    break;

  case 90: // expr: id
#line 529 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1599 "./parser.cc"
    break;

  case 91: // expr: integer_literal
#line 530 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 1608 "./parser.cc"
    break;

  case 92: // expr: string
#line 534 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1614 "./parser.cc"
    break;

  case 93: // expr: real_literal
#line 535 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 1620 "./parser.cc"
    break;

  case 94: // expr: image_literal
#line 536 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 1629 "./parser.cc"
    break;

  case 95: // expr: TRUE
#line 540 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 1635 "./parser.cc"
    break;

  case 96: // expr: FALSE
#line 541 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 1641 "./parser.cc"
    break;

  case 97: // expr: NONE
#line 542 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 1647 "./parser.cc"
    break;

  case 98: // expr: "..."
#line 543 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 1653 "./parser.cc"
    break;

  case 99: // expr: "(" expr ")"
#line 544 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 1659 "./parser.cc"
    break;

  case 100: // expr: "(" ")"
#line 545 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 1665 "./parser.cc"
    break;

  case 101: // expr: function_call
#line 546 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1671 "./parser.cc"
    break;

  case 102: // expr: "[" expr_list_opt "]"
#line 548 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1677 "./parser.cc"
    break;

  case 103: // expr: "[" expr_list "," "]"
#line 549 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1683 "./parser.cc"
    break;

  case 104: // expr: "{" expr_list "}"
#line 550 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1689 "./parser.cc"
    break;

  case 105: // expr: "{" expr_list "," "}"
#line 551 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1695 "./parser.cc"
    break;

  case 106: // expr: expr "." id
#line 552 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1701 "./parser.cc"
    break;

  case 107: // expr: "{" "}"
#line 554 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 1707 "./parser.cc"
    break;

  case 108: // expr: "{" dict_list "}"
#line 555 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 1713 "./parser.cc"
    break;

  case 109: // expr: id ":=" expr
#line 559 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1719 "./parser.cc"
    break;

  case 110: // expr: "*" expr
#line 560 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1725 "./parser.cc"
    break;

  case 111: // expr: expr "+" expr
#line 562 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1731 "./parser.cc"
    break;

  case 112: // expr: expr "-" expr
#line 563 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1737 "./parser.cc"
    break;

  case 113: // expr: expr "*" expr
#line 564 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1743 "./parser.cc"
    break;

  case 114: // expr: expr "/" expr
#line 565 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1749 "./parser.cc"
    break;

  case 115: // expr: expr "%" expr
#line 566 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1755 "./parser.cc"
    break;

  case 116: // expr: "-" expr
#line 567 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 1761 "./parser.cc"
    break;

  case 117: // expr: "+" expr
#line 568 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 1767 "./parser.cc"
    break;

  case 118: // expr: "~" expr
#line 569 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 1773 "./parser.cc"
    break;

  case 119: // expr: expr "**" expr
#line 570 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1779 "./parser.cc"
    break;

  case 120: // expr: expr "//" expr
#line 571 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1785 "./parser.cc"
    break;

  case 121: // expr: expr "@" expr
#line 572 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1791 "./parser.cc"
    break;

  case 122: // expr: expr "&" expr
#line 574 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1797 "./parser.cc"
    break;

  case 123: // expr: expr "|" expr
#line 575 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1803 "./parser.cc"
    break;

  case 124: // expr: expr "^" expr
#line 576 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1809 "./parser.cc"
    break;

  case 125: // expr: expr "<<" expr
#line 577 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1815 "./parser.cc"
    break;

  case 126: // expr: expr ">>" expr
#line 578 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1821 "./parser.cc"
    break;

  case 127: // expr: expr "==" expr
#line 580 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1827 "./parser.cc"
    break;

  case 128: // expr: expr "!=" expr
#line 581 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1833 "./parser.cc"
    break;

  case 129: // expr: expr "<" expr
#line 582 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1839 "./parser.cc"
    break;

  case 130: // expr: expr "<=" expr
#line 583 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1845 "./parser.cc"
    break;

  case 131: // expr: expr ">" expr
#line 584 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1851 "./parser.cc"
    break;

  case 132: // expr: expr ">=" expr
#line 585 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1857 "./parser.cc"
    break;

  case 133: // expr: expr "is" expr
#line 586 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1863 "./parser.cc"
    break;

  case 134: // expr: expr "is not" expr
#line 587 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1869 "./parser.cc"
    break;

  case 135: // expr: expr "in" expr
#line 588 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1875 "./parser.cc"
    break;

  case 136: // expr: expr "not in" expr
#line 589 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1881 "./parser.cc"
    break;

  case 137: // expr: expr "and" expr
#line 591 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1887 "./parser.cc"
    break;

  case 138: // expr: expr "or" expr
#line 592 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1893 "./parser.cc"
    break;

  case 139: // expr: "not" expr
#line 593 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 1899 "./parser.cc"
    break;

  case 140: // id: identifier
#line 605 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1905 "./parser.cc"
    break;

  case 141: // sep: sep sep_one
#line 609 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 1911 "./parser.cc"
    break;

  case 142: // sep: sep_one
#line 610 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 1917 "./parser.cc"
    break;

  case 143: // sep_one: NEWLINE
#line 614 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 1923 "./parser.cc"
    break;

  case 144: // sep_one: COMMENT
#line 615 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 1929 "./parser.cc"
    break;

  case 145: // sep_one: ";"
#line 616 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 1935 "./parser.cc"
    break;


#line 1939 "./parser.cc"

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









  const short  Parser ::yypact_ninf_ = -160;

  const signed char  Parser ::yytable_ninf_ = -81;

  const short
   Parser ::yypact_[] =
  {
     269,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  1030,
    1030,   919,   860,  1030,  1030,  1030,  1030,  1030,  1030,  -160,
    -160,  -160,  -160,   818,  -160,  -160,   -52,   -52,    -1,   -11,
    -160,  -160,  -160,   125,    59,    72,   692,   121,   -52,  -160,
     462,  1061,  -160,   -25,  -160,   -24,   506,  -160,   550,    61,
      89,   692,    73,    73,    73,   418,    73,  -160,  -160,   -52,
     -52,   134,  1030,  -160,   133,  1015,  1015,  1030,  1030,  1030,
    1030,  1030,  1030,  1030,  1030,  1030,  1030,   134,  1030,  1030,
    1030,  1030,  1030,  1030,  1030,  1030,  1030,  1030,  1030,  1030,
    1030,  1030,  1030,  -160,  1030,  -160,   336,   941,  -160,  1030,
    -160,  1030,    86,  -160,   830,   -52,    88,   418,  -160,  1030,
    -160,   100,    75,  -160,   112,   113,   117,    87,   118,  1061,
     180,   180,   180,   180,   736,   227,   902,   180,   254,   114,
     254,    73,    73,    73,    73,    73,   303,   984,   984,   180,
     180,   180,   180,    73,   180,   692,  -160,   150,  -160,   -70,
    1030,   -50,   -62,  -160,   692,  -160,   506,   692,  1030,  -160,
      42,   -52,   692,  1015,  -160,  1015,   104,  1030,  1015,  -160,
    1015,   106,   135,  -160,    99,   108,   -48,  -160,   105,  1000,
    -160,   138,   116,   103,   134,  -160,  -160,  -160,   139,  -160,
     119,   -34,   144,   146,  -160,  -160,   692,   144,   146,  -160,
     336,  -160,    38,  -160,   115,  -160,   371,  -160,  1030,  -160,
      25,   151,   152,    36,  -160,   -36,  1030,  1030,    39,   127,
    1030,   128,   129,   130,  -160,  -160,  -160,  -160,   134,   159,
      43,  -160,  -160,  -160,   164,  -160,  -160,   336,  1030,   604,
     692,   163,  -160,  -160,  -160,  -160,   152,    90,  -160,   134,
     167,    42,  -160,  -160,   648,  1030,  -160,   134,   152,    93,
    -160,  -160,   169,   336,   692,   152,  -160,   134,    42,  -160,
    -160,   152,  -160
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
      29,    91,    93,    94,   140,    62,    96,    95,    97,     0,
       0,     0,     0,    66,     0,     0,     0,     0,     0,    98,
     145,   143,   144,    29,     3,     5,     0,    23,     0,    28,
      27,    26,    25,    92,     0,   101,    60,    90,     4,   142,
       0,   139,   107,     0,    71,     0,    68,   100,     0,     0,
      65,    68,   116,   117,   110,     0,   118,     1,     2,    22,
      24,     0,     0,    61,     0,    66,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,   141,     0,     0,   104,     0,
     108,     0,    99,   102,     0,    31,     0,     0,    64,     0,
      72,    65,     0,    77,    55,    90,    65,     0,    55,   137,
     135,   133,   134,   136,   138,   122,   124,   127,   112,   106,
     111,   113,   119,   121,   120,   115,   123,   125,   126,   129,
     130,   131,   132,   114,   128,   109,     9,    58,     8,     0,
       0,     0,     0,   105,    67,    70,     0,    69,    66,   103,
      53,    30,    75,    73,    81,    54,     0,     0,    73,    85,
      54,     0,     0,    12,     0,    18,    21,    14,     0,    29,
       7,    65,     0,     0,     0,    43,    52,    38,    55,    41,
       0,    32,    55,    55,    76,    84,    74,    55,    55,    88,
       0,    13,    20,    15,     0,    17,    29,    11,    73,    89,
       0,    55,    55,    54,    39,     0,     0,     0,    54,     0,
      54,     0,     0,     0,    59,    16,     6,    10,     0,    55,
      54,    47,    54,    51,    55,    42,    40,     0,     0,    33,
      34,     0,    82,    83,    86,    87,    55,    54,    44,     0,
      55,    54,    36,    56,     0,     0,    45,     0,    55,    54,
      48,    37,    55,     0,    35,    55,    49,     0,    54,    57,
      46,    55,    50
  };

  const short
   Parser ::yypgoto_[] =
  {
    -160,  -160,   201,  -160,  -160,  -146,  -160,  -160,  -160,  -160,
    -159,   -66,  -160,  -160,  -160,   -37,  -160,   -26,   -73,  -158,
    -160,   -86,  -160,  -160,  -160,  -160,   215,    28,   136,  -160,
     -56,   -43,   -55,  -160,  -160,    -9,    53,    13,   -16
  };

  const unsigned char
   Parser ::yydefgoto_[] =
  {
       0,    23,    24,   180,   146,   147,   206,   148,   149,   150,
      25,    26,    27,    28,    29,   185,   186,   187,   188,   189,
     190,   214,    30,    31,    32,    33,   110,    43,    44,    45,
     112,   113,   114,    34,    35,    36,    37,   152,    39
  };

  const short
   Parser ::yytable_[] =
  {
      40,    41,    46,    48,    51,    52,    53,    54,    55,    56,
     117,   118,   237,    38,   216,   173,   174,    20,   217,    61,
     207,   179,    95,    21,    22,    97,    99,    20,   166,   176,
     151,     4,   171,    21,    22,   177,   178,   203,   204,    59,
      60,    50,     4,    95,    95,     4,   238,   227,     4,     4,
      98,   100,    62,   107,   224,   236,    51,    51,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   105,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   175,   145,    64,   228,   154,    95,
     156,   253,   157,   111,   116,   154,     4,   183,   184,     4,
     162,   109,   182,   183,   184,   249,   219,   221,   192,     4,
     236,   222,   223,   197,   106,    65,   234,   269,   115,   115,
     161,    93,   194,   -19,   -19,   231,   233,   194,    66,    93,
     129,     4,    77,    63,   151,    80,    95,   229,   103,   104,
       4,   108,   158,   248,   160,    95,   211,   212,   252,    51,
     163,   164,   257,   210,   154,   267,    51,   250,   196,   154,
     256,    51,   165,   169,   260,   167,    94,   168,   170,   -78,
     -80,   151,   266,   172,    94,   194,   235,   -78,   262,   270,
     195,   -79,   199,   200,   201,   272,   181,   202,   208,   213,
     205,   246,   209,   193,   218,   215,   220,   151,   198,   154,
     225,   230,   232,   242,   243,   244,   245,   239,   240,   247,
     235,   154,   258,   191,   251,   167,   115,   259,   115,   268,
     265,   115,   235,   115,    58,   261,    73,    74,    49,   254,
     271,   235,     0,     0,     0,   155,   191,   191,    76,    77,
      78,    79,    80,    81,    82,    83,   264,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,   191,     0,     0,   191,     0,     0,     0,
       0,   241,     1,     2,     3,     4,     0,     5,     6,     7,
       8,   191,     0,   191,     0,    76,    77,    78,    79,    80,
      81,    82,    83,     0,     0,    85,    86,     0,     9,     0,
     191,     0,   191,     0,   191,     0,    10,    91,     0,     0,
     191,     0,   191,    77,     0,    79,    80,    81,    82,    83,
     191,   191,     0,     0,    11,    12,    13,    14,     0,    15,
      16,     0,    17,     0,    91,    18,     0,     0,     0,     1,
       2,     3,     4,    19,     5,     6,     7,     8,    20,    73,
      74,     0,     0,     0,    21,    22,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,    85,    86,    10,     1,     2,     3,     4,     0,     5,
       6,     7,     8,    91,     0,     0,     0,     0,     0,     0,
       0,    11,    12,    13,    14,     0,    15,    16,     0,     0,
       9,     0,    18,     0,     0,     0,     0,     0,    10,     0,
      19,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,    11,    12,    13,    14,
      67,    15,    16,     0,    17,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,    68,
      69,    70,    71,     0,     0,   226,    72,     0,     0,     0,
       0,     0,     0,     0,    73,    74,     0,     0,     0,     0,
       0,     0,    75,     0,    67,     0,    76,    77,    78,    79,
      80,    81,    82,    83,     0,    84,    85,    86,    87,    88,
      89,    90,     0,    68,    69,    70,    71,    20,    91,     0,
      72,     0,     0,    21,    22,     0,     0,    92,    73,    74,
      96,     0,     0,     0,     0,     0,    75,     0,    67,     0,
      76,    77,    78,    79,    80,    81,    82,    83,     0,    84,
      85,    86,    87,    88,    89,    90,     0,    68,    69,    70,
      71,     0,    91,     0,    72,     0,     0,     0,     0,     0,
       0,    92,    73,    74,   101,     0,     0,     0,     0,     0,
      75,     0,    67,     0,    76,    77,    78,    79,    80,    81,
      82,    83,     0,    84,    85,    86,    87,    88,    89,    90,
       0,    68,    69,    70,    71,     0,    91,     0,    72,     0,
       0,     0,     0,     0,     0,    92,    73,    74,     0,     0,
       0,     0,     0,     0,    75,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    67,    84,    85,    86,
      87,    88,    89,    90,     0,     0,   102,     0,     0,     0,
      91,     0,     0,     0,     0,    68,    69,    70,    71,    92,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
      73,    74,     0,     0,     0,     0,   255,     0,    75,     0,
      67,     0,    76,    77,    78,    79,    80,    81,    82,    83,
       0,    84,    85,    86,    87,    88,    89,    90,     0,    68,
      69,    70,    71,     0,    91,     0,    72,     0,     0,     0,
       0,     0,     0,    92,    73,    74,   263,     0,     0,     0,
       0,     0,    75,     0,    67,     0,    76,    77,    78,    79,
      80,    81,    82,    83,     0,    84,    85,    86,    87,    88,
      89,    90,     0,    68,    69,    70,    71,     0,    91,     0,
      72,     0,     0,     0,     0,     0,     0,    92,    73,    74,
       0,     0,     0,     0,     0,     0,    75,     0,    67,     0,
      76,    77,    78,    79,    80,    81,    82,    83,     0,    84,
      85,    86,    87,    88,    89,    90,     0,    68,    69,    70,
      71,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    73,    74,     0,     0,     0,     0,     0,     0,
      75,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,     0,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,     0,     0,     0,    91,     0,    57,     0,
       0,     1,     2,     3,     4,    92,     5,     6,     7,     8,
       0,     0,     0,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,    10,     5,     6,
       7,     8,     0,    11,    12,    13,    14,     0,    15,    16,
       0,    17,     0,     0,    18,    11,    12,    13,    14,     0,
      15,    16,    19,     0,     0,     0,    18,    10,     0,     0,
       0,     0,     0,     0,    19,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,    11,    12,    13,    14,     0,
      15,    16,     1,     2,     3,     4,    18,     5,     6,     7,
       8,     0,     0,     0,    19,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,    73,     5,
       6,     7,     8,     0,     0,     0,    10,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
      85,    86,     0,     0,    11,    12,    13,    14,    10,    15,
      16,     0,    91,     0,     0,    18,     0,     0,     0,     0,
       0,     0,     0,    19,    42,     0,    11,    12,    13,    14,
       0,    15,    16,     1,     2,     3,     4,    18,     5,     6,
       7,     8,     0,     0,     0,    19,   153,     0,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     9,
       0,     0,     0,     1,     2,     3,     4,    10,     5,     6,
       7,     8,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,    10,     0,     0,    11,    12,    13,    14,     0,
      15,    16,     0,    17,    91,     0,    18,    10,     0,     0,
      11,    12,    13,    14,    19,    15,    16,   109,     0,     0,
       0,    18,     0,     0,     0,    11,    12,    13,    14,    19,
      15,    16,    68,    69,    70,    71,    18,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,    73,    74,     0,
       0,     0,     0,     0,     0,    75,     0,     0,     0,    76,
      77,    78,    79,    80,    81,    82,    83,     0,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
      92
  };

  const short
   Parser ::yycheck_[] =
  {
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      66,    66,    48,     0,    48,    85,    86,    79,    52,    20,
     179,    83,    38,    85,    86,    50,    50,    79,   114,    79,
      96,     6,   118,    85,    86,    85,    86,    85,    86,    26,
      27,    13,     6,    59,    60,     6,    82,   206,     6,     6,
      75,    75,    63,    62,   200,   213,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    55,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   150,    94,    33,    62,    97,   105,
      99,   237,   101,    65,    66,   104,     6,    61,    62,     6,
     109,    62,   158,    61,    62,    62,   192,   193,   163,     6,
     268,   197,   198,   168,    61,    56,    80,   263,    65,    66,
     107,     8,   165,    85,    86,   211,   212,   170,    56,     8,
      77,     6,    59,     8,   200,    62,   152,   210,    77,    50,
       6,     8,    56,   229,    56,   161,   183,   184,   234,   158,
      50,    76,    62,    50,   163,    62,   165,   230,   167,   168,
     246,   170,    50,    76,   250,    52,    53,    50,    50,    56,
      56,   237,   258,    23,    53,   218,   213,    56,   251,   265,
      76,    56,    76,    48,    85,   271,   158,    79,    50,    50,
      85,   228,    76,   165,    50,    76,    50,   263,   170,   208,
      85,    50,    50,    76,    76,    76,    76,   216,   217,    50,
     247,   220,   249,   160,    50,    52,   163,    50,   165,    50,
     257,   168,   259,   170,    23,   251,    46,    47,    13,   238,
     267,   268,    -1,    -1,    -1,    99,   183,   184,    58,    59,
      60,    61,    62,    63,    64,    65,   255,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,   210,    -1,    -1,   213,    -1,    -1,    -1,
      -1,   218,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,   228,    -1,   230,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    -1,    68,    69,    -1,    29,    -1,
     247,    -1,   249,    -1,   251,    -1,    37,    80,    -1,    -1,
     257,    -1,   259,    59,    -1,    61,    62,    63,    64,    65,
     267,   268,    -1,    -1,    55,    56,    57,    58,    -1,    60,
      61,    -1,    63,    -1,    80,    66,    -1,    -1,    -1,     3,
       4,     5,     6,    74,     8,     9,    10,    11,    79,    46,
      47,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      -1,    68,    69,    37,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    60,    61,    -1,    -1,
      29,    -1,    66,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      74,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    -1,    -1,    55,    56,    57,    58,
      12,    60,    61,    -1,    63,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    31,
      32,    33,    34,    -1,    -1,    84,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    12,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    -1,    31,    32,    33,    34,    79,    80,    -1,
      38,    -1,    -1,    85,    86,    -1,    -1,    89,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    54,    -1,    12,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    -1,    31,    32,    33,
      34,    -1,    80,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    12,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      -1,    31,    32,    33,    34,    -1,    80,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    12,    67,    68,    69,
      70,    71,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    89,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,    -1,
      12,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    -1,    31,
      32,    33,    34,    -1,    80,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    12,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    -1,    31,    32,    33,    34,    -1,    80,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    89,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    12,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    -1,    31,    32,    33,
      34,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,     0,    -1,
      -1,     3,     4,     5,     6,    89,     8,     9,    10,    11,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    37,     8,     9,
      10,    11,    -1,    55,    56,    57,    58,    -1,    60,    61,
      -1,    63,    -1,    -1,    66,    55,    56,    57,    58,    -1,
      60,    61,    74,    -1,    -1,    -1,    66,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    61,     3,     4,     5,     6,    66,     8,     9,    10,
      11,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    46,     8,
       9,    10,    11,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    -1,
      68,    69,    -1,    -1,    55,    56,    57,    58,    37,    60,
      61,    -1,    80,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    55,    56,    57,    58,
      -1,    60,    61,     3,     4,     5,     6,    66,     8,     9,
      10,    11,    -1,    -1,    -1,    74,    75,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    29,
      -1,    -1,    -1,     3,     4,     5,     6,    37,     8,     9,
      10,    11,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    -1,    37,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    61,    -1,    63,    80,    -1,    66,    37,    -1,    -1,
      55,    56,    57,    58,    74,    60,    61,    62,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    55,    56,    57,    58,    74,
      60,    61,    31,    32,    33,    34,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    29,
      37,    55,    56,    57,    58,    60,    61,    63,    66,    74,
      79,    85,    86,    92,    93,   101,   102,   103,   104,   105,
     113,   114,   115,   116,   124,   125,   126,   127,   128,   129,
     126,   126,    75,   118,   119,   120,   126,    76,   126,   117,
     118,   126,   126,   126,   126,   126,   126,     0,    93,   128,
     128,    20,    63,     8,   127,    56,    56,    12,    31,    32,
      33,    34,    38,    46,    47,    54,    58,    59,    60,    61,
      62,    63,    64,    65,    67,    68,    69,    70,    71,    72,
      73,    80,    89,     8,    53,   129,    48,    50,    75,    50,
      75,    48,    76,    77,    50,   128,   127,   126,     8,    62,
     117,   118,   121,   122,   123,   127,   118,   121,   123,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   127,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,    95,    96,    98,    99,
     100,   102,   128,    75,   126,   119,   126,   126,    56,    77,
      56,   128,   126,    50,    76,    50,   112,    52,    50,    76,
      50,   112,    23,    85,    86,   102,    79,    85,    86,    83,
      94,   118,   121,    61,    62,   106,   107,   108,   109,   110,
     111,   127,   123,   118,   122,    76,   126,   123,   118,    76,
      48,    85,    79,    85,    86,    85,    97,   101,    50,    76,
      50,   106,   106,    50,   112,    76,    48,    52,    50,   112,
      50,   112,   112,   112,    96,    85,    84,   101,    62,   109,
      50,   112,    50,   112,    80,   106,   110,    48,    82,   126,
     126,   127,    76,    76,    76,    76,   106,    50,   112,    62,
     109,    50,   112,    96,   126,    52,   112,    62,   106,    50,
     112,   108,   109,    48,   126,   106,   112,    62,    50,    96,
     112,   106,   112
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    91,    92,    92,    92,    93,    94,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   106,   106,   107,   107,   107,   108,
     108,   108,   109,   109,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   116,   116,   116,   116,   117,   117,   118,   118,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     124,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     127,   128,   128,   129,   129,   129
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     3,     2,     1,     1,
       2,     1,     2,     3,     2,     3,     4,     3,     2,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     1,     0,
       4,     3,     1,     3,     3,     5,     4,     5,     1,     2,
       3,     1,     3,     1,     4,     5,     7,     3,     5,     6,
       8,     3,     1,     0,     1,     0,     8,    10,     4,     7,
       1,     2,     1,     2,     3,     1,     0,     3,     1,     3,
       3,     1,     1,     2,     3,     2,     3,     1,     1,     1,
       3,     4,     7,     7,     5,     4,     7,     7,     5,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     1,     3,     4,     3,     4,     3,     2,     3,     3,
       2,     3,     3,     3,     3,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     2,     1,     1,     1,     1
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
  "function_def", "if_statement", "expression_statment", "string",
  "expr_list_opt", "expr_list", "dict", "dict_list", "call_arguement_list",
  "keyword_item", "keyword_items", "primary", "function_call", "expr",
  "id", "sep", "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   254,   254,   255,   256,   260,   264,   268,   272,   273,
     277,   278,   282,   283,   284,   285,   288,   291,   297,   300,
     306,   309,   315,   316,   317,   321,   339,   343,   352,   353,
     357,   358,   362,   363,   364,   365,   369,   371,   373,   377,
     378,   380,   384,   385,   393,   394,   395,   397,   398,   400,
     402,   404,   408,   409,   413,   414,   418,   420,   431,   434,
     442,   446,   447,   450,   453,   459,   460,   464,   465,   475,
     479,   480,   484,   485,   490,   491,   495,   496,   501,   502,
     503,   507,   508,   510,   512,   513,   514,   516,   518,   525,
     529,   530,   534,   535,   536,   540,   541,   542,   543,   544,
     545,   546,   548,   549,   550,   551,   552,   554,   555,   559,
     560,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   574,   575,   576,   577,   578,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   591,   592,   593,
     605,   609,   610,   614,   615,   616
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
#line 2621 "./parser.cc"

#line 619 "parser.ypp"
