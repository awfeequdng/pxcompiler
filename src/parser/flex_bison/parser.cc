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
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< Nonnull<Expression*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.YY_MOVE_OR_COPY< Nonnull<FnArg*> > (YY_MOVE (that.value));
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
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Expression*>> > (YY_MOVE (that.value));
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
      case symbol_kind::S_expr: // expr
        value.move< Nonnull<Expression*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< Nonnull<FnArg*> > (YY_MOVE (that.value));
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
        value.move< std::vector<Nonnull<Expression*>> > (YY_MOVE (that.value));
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
      case symbol_kind::S_expr: // expr
        value.copy< Nonnull<Expression*> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< Nonnull<FnArg*> > (that.value);
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
        value.copy< std::vector<Nonnull<Expression*>> > (that.value);
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
      case symbol_kind::S_expr: // expr
        value.move< Nonnull<Expression*> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< Nonnull<FnArg*> > (that.value);
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
        value.move< std::vector<Nonnull<Expression*>> > (that.value);
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
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< Nonnull<Expression*> > ();
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        yylhs.value.emplace< Nonnull<FnArg*> > ();
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
        yylhs.value.emplace< std::vector<Nonnull<Expression*>> > ();
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
#line 249 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 999 "./parser.cc"
    break;

  case 3: // units: script_unit
#line 250 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1005 "./parser.cc"
    break;

  case 5: // script_unit: statement
#line 255 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1011 "./parser.cc"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 259 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1017 "./parser.cc"
    break;

  case 7: // sep_statements: sep statements
#line 263 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1023 "./parser.cc"
    break;

  case 8: // body_stmts: single_line_statements
#line 267 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1029 "./parser.cc"
    break;

  case 9: // body_stmts: sep_statements
#line 268 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1035 "./parser.cc"
    break;

  case 10: // statements1: statements1 statement
#line 272 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1041 "./parser.cc"
    break;

  case 11: // statements1: statement
#line 273 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1047 "./parser.cc"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 277 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1053 "./parser.cc"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 278 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1059 "./parser.cc"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 279 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1065 "./parser.cc"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 280 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1073 "./parser.cc"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 283 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1081 "./parser.cc"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 286 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1089 "./parser.cc"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 292 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1097 "./parser.cc"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 295 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1105 "./parser.cc"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 301 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1113 "./parser.cc"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 304 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1121 "./parser.cc"
    break;

  case 22: // statement: single_line_statement sep
#line 310 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1127 "./parser.cc"
    break;

  case 23: // statement: multi_line_statement
#line 311 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1133 "./parser.cc"
    break;

  case 24: // statement: multi_line_statement sep
#line 312 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1139 "./parser.cc"
    break;

  case 25: // single_line_statement: expression_statment
#line 316 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1145 "./parser.cc"
    break;

  case 26: // multi_line_statement: if_statement
#line 334 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1151 "./parser.cc"
    break;

  case 27: // multi_line_statement: function_def
#line 338 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1157 "./parser.cc"
    break;

  case 28: // decorators_opt: decorators
#line 347 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1163 "./parser.cc"
    break;

  case 29: // decorators_opt: %empty
#line 348 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1169 "./parser.cc"
    break;

  case 30: // decorators: decorators "@" expr sep
#line 352 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1175 "./parser.cc"
    break;

  case 31: // decorators: "@" expr sep
#line 353 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1181 "./parser.cc"
    break;

  case 32: // parameter: id
#line 357 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1187 "./parser.cc"
    break;

  case 33: // parameter: id ":" expr
#line 358 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1193 "./parser.cc"
    break;

  case 34: // parameter: id "=" expr
#line 359 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1199 "./parser.cc"
    break;

  case 35: // parameter: id ":" expr "=" expr
#line 360 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1205 "./parser.cc"
    break;

  case 36: // parameter_list: defparameter_list "," "/" comma_opt
#line 364 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1212 "./parser.cc"
    break;

  case 37: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 366 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1219 "./parser.cc"
    break;

  case 38: // parameter_list: parameter_list_no_posonly
#line 368 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1225 "./parser.cc"
    break;

  case 39: // parameter_list_no_posonly: defparameter_list comma_opt
#line 372 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1231 "./parser.cc"
    break;

  case 40: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 373 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1238 "./parser.cc"
    break;

  case 41: // parameter_list_no_posonly: parameter_list_starargs
#line 375 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1244 "./parser.cc"
    break;

  case 42: // defparameter_list: defparameter_list "," parameter
#line 379 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1250 "./parser.cc"
    break;

  case 43: // defparameter_list: parameter
#line 380 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1256 "./parser.cc"
    break;

  case 44: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 388 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1262 "./parser.cc"
    break;

  case 45: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 389 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1268 "./parser.cc"
    break;

  case 46: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 390 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1275 "./parser.cc"
    break;

  case 47: // parameter_list_starargs: "*" parameter comma_opt
#line 392 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1281 "./parser.cc"
    break;

  case 48: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 393 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1288 "./parser.cc"
    break;

  case 49: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 395 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1295 "./parser.cc"
    break;

  case 50: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 397 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1302 "./parser.cc"
    break;

  case 51: // parameter_list_starargs: "**" parameter comma_opt
#line 399 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1308 "./parser.cc"
    break;

  case 52: // parameter_list_opt: parameter_list
#line 403 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1314 "./parser.cc"
    break;

  case 53: // parameter_list_opt: %empty
#line 404 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1320 "./parser.cc"
    break;

  case 56: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 414 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1326 "./parser.cc"
    break;

  case 57: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 416 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1332 "./parser.cc"
    break;

  case 58: // if_statement: IF expr ":" body_stmts
#line 426 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1340 "./parser.cc"
    break;

  case 59: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 429 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1348 "./parser.cc"
    break;

  case 60: // expression_statment: expr
#line 437 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1354 "./parser.cc"
    break;

  case 61: // string: string string_literal
#line 441 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1360 "./parser.cc"
    break;

  case 62: // string: string_literal
#line 442 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1368 "./parser.cc"
    break;

  case 63: // string: id string_literal
#line 445 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1376 "./parser.cc"
    break;

  case 64: // string: string id string_literal
#line 448 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1384 "./parser.cc"
    break;

  case 65: // expr_list_opt: expr_list
#line 454 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1390 "./parser.cc"
    break;

  case 66: // expr_list_opt: %empty
#line 455 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1396 "./parser.cc"
    break;

  case 67: // expr_list: expr_list "," expr
#line 459 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1402 "./parser.cc"
    break;

  case 68: // expr_list: expr
#line 460 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1408 "./parser.cc"
    break;

  case 69: // dict: expr ":" expr
#line 470 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1414 "./parser.cc"
    break;

  case 70: // dict_list: dict_list "," dict
#line 474 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1420 "./parser.cc"
    break;

  case 71: // dict_list: dict
#line 475 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1426 "./parser.cc"
    break;

  case 72: // expr: id
#line 480 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1432 "./parser.cc"
    break;

  case 73: // expr: integer_literal
#line 481 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 1441 "./parser.cc"
    break;

  case 74: // expr: string
#line 485 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1447 "./parser.cc"
    break;

  case 75: // expr: real_literal
#line 486 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 1453 "./parser.cc"
    break;

  case 76: // expr: image_literal
#line 487 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 1462 "./parser.cc"
    break;

  case 77: // expr: TRUE
#line 491 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 1468 "./parser.cc"
    break;

  case 78: // expr: FALSE
#line 492 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 1474 "./parser.cc"
    break;

  case 79: // expr: NONE
#line 493 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 1480 "./parser.cc"
    break;

  case 80: // expr: "..."
#line 494 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 1486 "./parser.cc"
    break;

  case 81: // expr: "(" expr ")"
#line 495 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 1492 "./parser.cc"
    break;

  case 82: // expr: "(" ")"
#line 496 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 1498 "./parser.cc"
    break;

  case 83: // expr: "[" expr_list_opt "]"
#line 499 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1504 "./parser.cc"
    break;

  case 84: // expr: "[" expr_list "," "]"
#line 500 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1510 "./parser.cc"
    break;

  case 85: // expr: "{" expr_list "}"
#line 501 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1516 "./parser.cc"
    break;

  case 86: // expr: "{" expr_list "," "}"
#line 502 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1522 "./parser.cc"
    break;

  case 87: // expr: expr "." id
#line 503 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1528 "./parser.cc"
    break;

  case 88: // expr: "{" "}"
#line 505 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 1534 "./parser.cc"
    break;

  case 89: // expr: "{" dict_list "}"
#line 506 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 1540 "./parser.cc"
    break;

  case 90: // expr: id ":=" expr
#line 510 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1546 "./parser.cc"
    break;

  case 91: // expr: "*" expr
#line 511 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1552 "./parser.cc"
    break;

  case 92: // expr: expr "+" expr
#line 513 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1558 "./parser.cc"
    break;

  case 93: // expr: expr "-" expr
#line 514 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1564 "./parser.cc"
    break;

  case 94: // expr: expr "*" expr
#line 515 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1570 "./parser.cc"
    break;

  case 95: // expr: expr "/" expr
#line 516 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1576 "./parser.cc"
    break;

  case 96: // expr: expr "%" expr
#line 517 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1582 "./parser.cc"
    break;

  case 97: // expr: "-" expr
#line 518 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 1588 "./parser.cc"
    break;

  case 98: // expr: "+" expr
#line 519 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 1594 "./parser.cc"
    break;

  case 99: // expr: "~" expr
#line 520 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 1600 "./parser.cc"
    break;

  case 100: // expr: expr "**" expr
#line 521 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1606 "./parser.cc"
    break;

  case 101: // expr: expr "//" expr
#line 522 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1612 "./parser.cc"
    break;

  case 102: // expr: expr "@" expr
#line 523 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1618 "./parser.cc"
    break;

  case 103: // expr: expr "&" expr
#line 525 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1624 "./parser.cc"
    break;

  case 104: // expr: expr "|" expr
#line 526 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1630 "./parser.cc"
    break;

  case 105: // expr: expr "^" expr
#line 527 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1636 "./parser.cc"
    break;

  case 106: // expr: expr "<<" expr
#line 528 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1642 "./parser.cc"
    break;

  case 107: // expr: expr ">>" expr
#line 529 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1648 "./parser.cc"
    break;

  case 108: // expr: expr "==" expr
#line 531 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1654 "./parser.cc"
    break;

  case 109: // expr: expr "!=" expr
#line 532 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1660 "./parser.cc"
    break;

  case 110: // expr: expr "<" expr
#line 533 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1666 "./parser.cc"
    break;

  case 111: // expr: expr "<=" expr
#line 534 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1672 "./parser.cc"
    break;

  case 112: // expr: expr ">" expr
#line 535 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1678 "./parser.cc"
    break;

  case 113: // expr: expr ">=" expr
#line 536 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1684 "./parser.cc"
    break;

  case 114: // expr: expr "is" expr
#line 537 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1690 "./parser.cc"
    break;

  case 115: // expr: expr "is not" expr
#line 538 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1696 "./parser.cc"
    break;

  case 116: // expr: expr "in" expr
#line 539 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1702 "./parser.cc"
    break;

  case 117: // expr: expr "not in" expr
#line 540 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1708 "./parser.cc"
    break;

  case 118: // expr: expr "and" expr
#line 542 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1714 "./parser.cc"
    break;

  case 119: // expr: expr "or" expr
#line 543 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1720 "./parser.cc"
    break;

  case 120: // expr: "not" expr
#line 544 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 1726 "./parser.cc"
    break;

  case 121: // id: identifier
#line 556 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1732 "./parser.cc"
    break;

  case 122: // sep: sep sep_one
#line 560 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 1738 "./parser.cc"
    break;

  case 123: // sep: sep_one
#line 561 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 1744 "./parser.cc"
    break;

  case 124: // sep_one: NEWLINE
#line 565 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 1750 "./parser.cc"
    break;

  case 125: // sep_one: COMMENT
#line 566 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 1756 "./parser.cc"
    break;

  case 126: // sep_one: ";"
#line 567 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 1762 "./parser.cc"
    break;


#line 1766 "./parser.cc"

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









  const short  Parser ::yypact_ninf_ = -162;

  const signed char  Parser ::yytable_ninf_ = -20;

  const short
   Parser ::yypact_[] =
  {
     198,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,   860,
     860,   764,   705,   860,   860,   860,   860,   860,   860,  -162,
    -162,  -162,  -162,   663,  -162,  -162,    42,    42,    -3,   -35,
    -162,  -162,  -162,    17,   537,    41,    42,  -162,   307,   899,
    -162,   -40,  -162,   -34,   351,  -162,   395,   -47,    -2,   537,
     -41,   -41,   -41,   263,   -41,  -162,  -162,    42,    42,    44,
     860,  -162,    99,   860,   860,   860,   860,   860,   860,   860,
     860,   860,   860,    44,   860,   860,   860,   860,   860,   860,
     860,   860,   860,   860,   860,   860,   860,   860,   860,  -162,
     860,  -162,   213,   786,  -162,   860,  -162,   860,  -162,  -162,
     675,    42,    -4,   263,  -162,   899,   965,   965,   965,   965,
     581,   830,   747,   965,   131,  -162,   131,   -41,   -41,   -41,
     -41,   -41,   183,   977,   977,   965,   965,   965,   965,   -41,
     965,   537,  -162,    93,  -162,   -53,   860,    62,    27,  -162,
     537,  -162,   351,   537,  -162,    28,    42,    69,  -162,    33,
      40,   -48,  -162,    35,   845,  -162,    95,    44,  -162,  -162,
    -162,    76,  -162,    53,   -33,   213,  -162,   -39,  -162,    45,
    -162,    94,  -162,    18,    83,    84,    34,  -162,   -37,   860,
     860,  -162,  -162,  -162,  -162,    44,    88,    21,  -162,  -162,
    -162,    89,  -162,  -162,   213,   860,   449,   537,    84,    23,
    -162,    44,    92,    28,  -162,  -162,   493,   860,  -162,    44,
      84,    30,  -162,  -162,    96,   213,   537,    84,  -162,    44,
      28,  -162,  -162,    84,  -162
  };

  const signed char
   Parser ::yydefact_[] =
  {
      29,    73,    75,    76,   121,    62,    78,    77,    79,     0,
       0,     0,     0,    66,     0,     0,     0,     0,     0,    80,
     126,   124,   125,    29,     3,     5,     0,    23,     0,    28,
      27,    26,    25,    74,    60,    72,     4,   123,     0,   120,
      88,     0,    71,     0,    68,    82,     0,     0,    65,    68,
      97,    98,    91,     0,    99,     1,     2,    22,    24,     0,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,   122,     0,     0,    85,     0,    89,     0,    81,    83,
       0,    31,     0,     0,    64,   118,   116,   114,   115,   117,
     119,   103,   105,   108,    93,    87,    92,    94,   100,   102,
     101,    96,   104,   106,   107,   110,   111,   112,   113,    95,
     109,    90,     9,    58,     8,     0,     0,     0,     0,    86,
      67,    70,     0,    69,    84,    53,    30,     0,    12,     0,
      18,    21,    14,     0,    29,     7,     0,     0,    43,    52,
      38,    55,    41,     0,    32,     0,    13,    20,    15,     0,
      17,    29,    11,     0,    55,    55,    54,    39,     0,     0,
       0,    59,    16,     6,    10,     0,    55,    54,    47,    54,
      51,    55,    42,    40,     0,     0,    33,    34,    55,    54,
      44,     0,    55,    54,    36,    56,     0,     0,    45,     0,
      55,    54,    48,    37,    55,     0,    35,    55,    49,     0,
      54,    57,    46,    55,    50
  };

  const short
   Parser ::yypgoto_[] =
  {
    -162,  -162,   121,  -162,  -162,   -54,  -162,  -162,  -162,  -162,
    -140,   -72,  -162,  -162,  -162,   728,  -162,   -45,  -161,   -61,
    -162,   799,  -162,  -162,  -162,  -162,  -162,   149,    68,  -162,
      -9,   -20,    82,   -14
  };

  const unsigned char
   Parser ::yydefgoto_[] =
  {
       0,    23,    24,   155,   132,   133,   171,   134,   135,   136,
      25,    26,    27,    28,    29,   158,   159,   160,   161,   162,
     163,   177,    30,    31,    32,    33,    47,    41,    42,    43,
      34,    35,   138,    37
  };

  const short
   Parser ::yytable_[] =
  {
      38,    39,    44,    46,    49,    50,    51,    52,    53,    54,
      93,   194,   186,    62,   172,   179,    95,    59,    73,   180,
     137,    76,    91,     4,     4,    61,   202,     4,    60,     4,
      99,   184,   148,   149,     4,    94,     4,   168,   169,   102,
       4,    96,   214,    91,    91,   195,   -19,   -19,   100,    89,
       4,   103,   145,   115,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   150,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     185,   131,    36,   201,   140,   209,   142,    91,   143,   156,
     157,   140,   219,   137,    90,   156,   157,     1,     2,     3,
       4,     4,     5,     6,     7,     8,    20,   104,    57,    58,
     154,   181,    21,    22,   191,   193,   147,   165,   166,   167,
     170,    20,   137,     9,    91,   164,   176,    21,    22,   178,
     182,    10,    91,   187,   189,   101,   164,   164,   199,   203,
     205,   151,   211,   137,    56,   173,   220,   152,   153,    11,
      12,    13,    14,   164,    15,    16,   164,    17,   213,   193,
      18,   221,    48,   141,     0,   164,     0,   164,    19,     0,
     196,   197,     0,     0,     0,     0,     0,     0,   183,   164,
       0,   164,     0,   164,     0,   146,   206,     0,     0,   164,
      73,   164,    75,    76,    77,    78,    79,     0,   216,   164,
     164,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,    87,     0,     0,     0,     0,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     9,     0,    69,
      70,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    77,    78,    79,     0,
      10,    81,    82,    11,    12,    13,    14,     0,    15,    16,
       0,    17,     0,    87,    18,     0,     0,     0,    11,    12,
      13,    14,    19,    15,    16,    63,     0,    20,     0,    18,
       0,     0,     0,    21,    22,     0,     0,    19,     0,     0,
       0,     0,    20,     0,    64,    65,    66,    67,    21,    22,
       0,    68,     0,     0,     0,     0,     0,     0,     0,    69,
      70,     0,     0,     0,     0,     0,     0,    71,     0,    63,
       0,    72,    73,    74,    75,    76,    77,    78,    79,     0,
      80,    81,    82,    83,    84,    85,    86,     0,    64,    65,
      66,    67,    20,    87,     0,    68,     0,     0,    21,    22,
       0,     0,    88,    69,    70,    92,     0,     0,     0,     0,
       0,    71,     0,    63,     0,    72,    73,    74,    75,    76,
      77,    78,    79,     0,    80,    81,    82,    83,    84,    85,
      86,     0,    64,    65,    66,    67,     0,    87,     0,    68,
       0,     0,     0,     0,     0,     0,    88,    69,    70,    97,
       0,     0,     0,     0,     0,    71,     0,    63,     0,    72,
      73,    74,    75,    76,    77,    78,    79,     0,    80,    81,
      82,    83,    84,    85,    86,     0,    64,    65,    66,    67,
       0,    87,     0,    68,     0,     0,     0,     0,     0,     0,
      88,    69,    70,     0,     0,     0,     0,     0,     0,    71,
       0,     0,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    63,    80,    81,    82,    83,    84,    85,    86,     0,
       0,    98,     0,     0,     0,    87,     0,     0,     0,     0,
      64,    65,    66,    67,    88,     0,     0,    68,     0,     0,
       0,     0,     0,     0,     0,    69,    70,     0,     0,     0,
       0,   207,     0,    71,     0,    63,     0,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,    81,    82,    83,
      84,    85,    86,     0,    64,    65,    66,    67,     0,    87,
       0,    68,     0,     0,     0,     0,     0,     0,    88,    69,
      70,   215,     0,     0,     0,     0,     0,    71,     0,    63,
       0,    72,    73,    74,    75,    76,    77,    78,    79,     0,
      80,    81,    82,    83,    84,    85,    86,     0,    64,    65,
      66,    67,     0,    87,     0,    68,     0,     0,     0,     0,
       0,     0,    88,    69,    70,     0,     0,     0,     0,     0,
       0,    71,     0,    63,     0,    72,    73,    74,    75,    76,
      77,    78,    79,     0,    80,    81,    82,    83,    84,    85,
      86,     0,    64,    65,    66,    67,     0,    87,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    69,    70,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,     0,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,     0,
       0,    87,     0,    55,     0,     0,     1,     2,     3,     4,
      88,     5,     6,     7,     8,     0,     0,     0,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,    10,     5,     6,     7,     8,     0,    11,    12,
      13,    14,     0,    15,    16,     0,    17,     0,     0,    18,
      11,    12,    13,    14,     0,    15,    16,    19,     0,     0,
       0,    18,    10,     0,     0,     0,     0,     0,     0,    19,
       0,     0,   144,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,     0,    15,    16,     1,     2,     3,
       4,    18,     5,     6,     7,     8,     0,     0,     0,    19,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,    69,     5,     6,     7,     8,     0,     0,
       0,    10,     0,     0,     0,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    81,    82,     0,     0,    11,
      12,    13,    14,    10,    15,    16,     0,    87,     0,     0,
      18,     0,     0,     0,     0,     0,     0,     0,    19,    40,
       0,    11,    12,    13,    14,     0,    15,    16,     1,     2,
       3,     4,    18,     5,     6,     7,     8,     0,     0,     0,
      19,   139,     0,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     0,    10,     0,   174,   175,     0,     0,    72,    73,
      74,    75,    76,    77,    78,    79,     0,    10,    81,    82,
      11,    12,    13,    14,   192,    15,    16,     0,    17,     0,
      87,    18,     0,   198,     0,    11,    12,    13,    14,    19,
      15,    16,     0,     0,     0,     0,    18,   192,     0,   210,
      64,    65,    66,    67,    19,     0,     0,   217,     0,   192,
       0,     0,     0,     0,     0,    69,    70,   223,   192,     0,
       0,     0,     0,    71,     0,     0,     0,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    80,    81,    82,    83,
      84,    85,    86,   188,   190,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,   200,     0,     0,    88,     0,
     204,     0,     0,     0,     0,     0,     0,   208,     0,     0,
       0,   212,     0,     0,     0,     0,     0,     0,     0,   218,
       0,    69,    70,     0,     0,     0,   222,     0,     0,     0,
       0,     0,   224,    72,    73,    74,    75,    76,    77,    78,
      79,     0,    80,    81,    82,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87
  };

  const short
   Parser ::yycheck_[] =
  {
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      50,    48,   173,    33,   154,    48,    50,    20,    59,    52,
      92,    62,    36,     6,     6,     8,   187,     6,    63,     6,
      77,   171,    85,    86,     6,    75,     6,    85,    86,    59,
       6,    75,   203,    57,    58,    82,    85,    86,    50,     8,
       6,    60,    56,    73,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,   136,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      62,    90,     0,    62,    93,    62,    95,   101,    97,    61,
      62,   100,    62,   165,    53,    61,    62,     3,     4,     5,
       6,     6,     8,     9,    10,    11,    79,     8,    26,    27,
      83,   165,    85,    86,    80,   176,    23,    48,    85,    79,
      85,    79,   194,    29,   138,   145,    50,    85,    86,    76,
      85,    37,   146,    50,    50,    53,   156,   157,    50,    50,
     194,    79,    50,   215,    23,    50,    50,    85,    86,    55,
      56,    57,    58,   173,    60,    61,   176,    63,   203,   220,
      66,   215,    13,    95,    -1,   185,    -1,   187,    74,    -1,
     179,   180,    -1,    -1,    -1,    -1,    -1,    -1,    84,   199,
      -1,   201,    -1,   203,    -1,   103,   195,    -1,    -1,   209,
      59,   211,    61,    62,    63,    64,    65,    -1,   207,   219,
     220,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      -1,    80,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    29,    -1,    46,
      47,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      37,    68,    69,    55,    56,    57,    58,    -1,    60,    61,
      -1,    63,    -1,    80,    66,    -1,    -1,    -1,    55,    56,
      57,    58,    74,    60,    61,    12,    -1,    79,    -1,    66,
      -1,    -1,    -1,    85,    86,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    79,    -1,    31,    32,    33,    34,    85,    86,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    12,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    31,    32,
      33,    34,    79,    80,    -1,    38,    -1,    -1,    85,    86,
      -1,    -1,    89,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    12,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    -1,    31,    32,    33,    34,    -1,    80,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    12,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    31,    32,    33,    34,
      -1,    80,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    12,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    89,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    52,    -1,    54,    -1,    12,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    -1,    31,    32,    33,    34,    -1,    80,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    89,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,    12,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    31,    32,
      33,    34,    -1,    80,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    12,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    -1,    31,    32,    33,    34,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,     0,    -1,    -1,     3,     4,     5,     6,
      89,     8,     9,    10,    11,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    37,     8,     9,    10,    11,    -1,    55,    56,
      57,    58,    -1,    60,    61,    -1,    63,    -1,    -1,    66,
      55,    56,    57,    58,    -1,    60,    61,    74,    -1,    -1,
      -1,    66,    37,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    60,    61,     3,     4,     5,
       6,    66,     8,     9,    10,    11,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    46,     8,     9,    10,    11,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    -1,    68,    69,    -1,    -1,    55,
      56,    57,    58,    37,    60,    61,    -1,    80,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
      -1,    55,    56,    57,    58,    -1,    60,    61,     3,     4,
       5,     6,    66,     8,     9,    10,    11,    -1,    -1,    -1,
      74,    75,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,   156,   157,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    37,    68,    69,
      55,    56,    57,    58,   176,    60,    61,    -1,    63,    -1,
      80,    66,    -1,   185,    -1,    55,    56,    57,    58,    74,
      60,    61,    -1,    -1,    -1,    -1,    66,   199,    -1,   201,
      31,    32,    33,    34,    74,    -1,    -1,   209,    -1,   211,
      -1,    -1,    -1,    -1,    -1,    46,    47,   219,   220,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,   174,   175,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,    89,    -1,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
      -1,    46,    47,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,   223,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    29,
      37,    55,    56,    57,    58,    60,    61,    63,    66,    74,
      79,    85,    86,    92,    93,   101,   102,   103,   104,   105,
     113,   114,   115,   116,   121,   122,   123,   124,   121,   121,
      75,   118,   119,   120,   121,    76,   121,   117,   118,   121,
     121,   121,   121,   121,   121,     0,    93,   123,   123,    20,
      63,     8,   122,    12,    31,    32,    33,    34,    38,    46,
      47,    54,    58,    59,    60,    61,    62,    63,    64,    65,
      67,    68,    69,    70,    71,    72,    73,    80,    89,     8,
      53,   124,    48,    50,    75,    50,    75,    48,    76,    77,
      50,   123,   122,   121,     8,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   122,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,    95,    96,    98,    99,   100,   102,   123,    75,
     121,   119,   121,   121,    77,    56,   123,    23,    85,    86,
     102,    79,    85,    86,    83,    94,    61,    62,   106,   107,
     108,   109,   110,   111,   122,    48,    85,    79,    85,    86,
      85,    97,   101,    50,   106,   106,    50,   112,    76,    48,
      52,    96,    85,    84,   101,    62,   109,    50,   112,    50,
     112,    80,   106,   110,    48,    82,   121,   121,   106,    50,
     112,    62,   109,    50,   112,    96,   121,    52,   112,    62,
     106,    50,   112,   108,   109,    48,   121,   106,   112,    62,
      50,    96,   112,   106,   112
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    91,    92,    92,    92,    93,    94,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   106,   106,   107,   107,   107,   108,
     108,   108,   109,   109,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   116,   116,   116,   116,   117,   117,   118,   118,   119,
     120,   120,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   123,   123,   124,   124,   124
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
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     4,     3,     4,     3,     2,     3,
       3,     2,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     2,     1,     1,     1,     1
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
  "expr_list_opt", "expr_list", "dict", "dict_list", "expr", "id", "sep",
  "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   249,   249,   250,   251,   255,   259,   263,   267,   268,
     272,   273,   277,   278,   279,   280,   283,   286,   292,   295,
     301,   304,   310,   311,   312,   316,   334,   338,   347,   348,
     352,   353,   357,   358,   359,   360,   364,   366,   368,   372,
     373,   375,   379,   380,   388,   389,   390,   392,   393,   395,
     397,   399,   403,   404,   408,   409,   413,   415,   426,   429,
     437,   441,   442,   445,   448,   454,   455,   459,   460,   470,
     474,   475,   480,   481,   485,   486,   487,   491,   492,   493,
     494,   495,   496,   499,   500,   501,   502,   503,   505,   506,
     510,   511,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   525,   526,   527,   528,   529,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   542,   543,
     544,   556,   560,   561,   565,   566,   567
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
#line 2406 "./parser.cc"

#line 570 "parser.ypp"
