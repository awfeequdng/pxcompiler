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
#line 262 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1119 "./parser.cc"
    break;

  case 3: // units: script_unit
#line 263 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1125 "./parser.cc"
    break;

  case 5: // script_unit: statement
#line 268 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1131 "./parser.cc"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 272 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1137 "./parser.cc"
    break;

  case 7: // sep_statements: sep statements
#line 276 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1143 "./parser.cc"
    break;

  case 8: // body_stmts: single_line_statements
#line 280 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1149 "./parser.cc"
    break;

  case 9: // body_stmts: sep_statements
#line 281 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1155 "./parser.cc"
    break;

  case 10: // statements1: statements1 statement
#line 285 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1161 "./parser.cc"
    break;

  case 11: // statements1: statement
#line 286 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1167 "./parser.cc"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 290 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1173 "./parser.cc"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 291 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1179 "./parser.cc"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 292 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1185 "./parser.cc"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 293 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1193 "./parser.cc"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 296 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1201 "./parser.cc"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 299 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1209 "./parser.cc"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 305 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1217 "./parser.cc"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 308 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1225 "./parser.cc"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 314 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1233 "./parser.cc"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 317 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1241 "./parser.cc"
    break;

  case 22: // statement: single_line_statement sep
#line 323 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1247 "./parser.cc"
    break;

  case 23: // statement: multi_line_statement
#line 324 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1253 "./parser.cc"
    break;

  case 24: // statement: multi_line_statement sep
#line 325 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1259 "./parser.cc"
    break;

  case 25: // single_line_statement: expression_statment
#line 329 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1265 "./parser.cc"
    break;

  case 26: // single_line_statement: import_statement
#line 340 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1271 "./parser.cc"
    break;

  case 27: // single_line_statement: global_statement
#line 341 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1277 "./parser.cc"
    break;

  case 28: // single_line_statement: nonlocal_statement
#line 342 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1283 "./parser.cc"
    break;

  case 29: // module: module "." id
#line 347 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1289 "./parser.cc"
    break;

  case 30: // module: id
#line 348 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1295 "./parser.cc"
    break;

  case 31: // module_as_id: module
#line 352 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1301 "./parser.cc"
    break;

  case 32: // module_as_id: module AS id
#line 353 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1307 "./parser.cc"
    break;

  case 33: // module_as_id: "*"
#line 354 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1313 "./parser.cc"
    break;

  case 34: // module_item_list: module_item_list "," module_as_id
#line 358 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1319 "./parser.cc"
    break;

  case 35: // module_item_list: module_as_id
#line 359 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1325 "./parser.cc"
    break;

  case 36: // import_statement: IMPORT module_item_list
#line 363 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1331 "./parser.cc"
    break;

  case 37: // multi_line_statement: if_statement
#line 379 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1337 "./parser.cc"
    break;

  case 38: // multi_line_statement: function_def
#line 383 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1343 "./parser.cc"
    break;

  case 39: // decorators_opt: decorators
#line 392 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1349 "./parser.cc"
    break;

  case 40: // decorators_opt: %empty
#line 393 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1355 "./parser.cc"
    break;

  case 41: // decorators: decorators "@" expr sep
#line 397 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1361 "./parser.cc"
    break;

  case 42: // decorators: "@" expr sep
#line 398 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1367 "./parser.cc"
    break;

  case 43: // parameter: id
#line 402 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1373 "./parser.cc"
    break;

  case 44: // parameter: id ":" expr
#line 403 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1379 "./parser.cc"
    break;

  case 45: // parameter: id "=" expr
#line 404 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1385 "./parser.cc"
    break;

  case 46: // parameter: id ":" expr "=" expr
#line 405 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1391 "./parser.cc"
    break;

  case 47: // parameter_list: defparameter_list "," "/" comma_opt
#line 409 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1398 "./parser.cc"
    break;

  case 48: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 411 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1405 "./parser.cc"
    break;

  case 49: // parameter_list: parameter_list_no_posonly
#line 413 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1411 "./parser.cc"
    break;

  case 50: // parameter_list_no_posonly: defparameter_list comma_opt
#line 417 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1417 "./parser.cc"
    break;

  case 51: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 418 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1424 "./parser.cc"
    break;

  case 52: // parameter_list_no_posonly: parameter_list_starargs
#line 420 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1430 "./parser.cc"
    break;

  case 53: // defparameter_list: defparameter_list "," parameter
#line 424 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1436 "./parser.cc"
    break;

  case 54: // defparameter_list: parameter
#line 425 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1442 "./parser.cc"
    break;

  case 55: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 433 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1448 "./parser.cc"
    break;

  case 56: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 434 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1454 "./parser.cc"
    break;

  case 57: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 435 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1461 "./parser.cc"
    break;

  case 58: // parameter_list_starargs: "*" parameter comma_opt
#line 437 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1467 "./parser.cc"
    break;

  case 59: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 438 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1474 "./parser.cc"
    break;

  case 60: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 440 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1481 "./parser.cc"
    break;

  case 61: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 442 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1488 "./parser.cc"
    break;

  case 62: // parameter_list_starargs: "**" parameter comma_opt
#line 444 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1494 "./parser.cc"
    break;

  case 63: // parameter_list_opt: parameter_list
#line 448 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1500 "./parser.cc"
    break;

  case 64: // parameter_list_opt: %empty
#line 449 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1506 "./parser.cc"
    break;

  case 67: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 459 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1512 "./parser.cc"
    break;

  case 68: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 461 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1518 "./parser.cc"
    break;

  case 69: // global_statement: GLOBAL expr_list
#line 471 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1524 "./parser.cc"
    break;

  case 70: // ternary_if_statement: expr IF expr ELSE expr
#line 475 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1530 "./parser.cc"
    break;

  case 71: // nonlocal_statement: NONLOCAL expr_list
#line 479 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1536 "./parser.cc"
    break;

  case 72: // if_statement: IF expr ":" body_stmts
#line 483 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1544 "./parser.cc"
    break;

  case 73: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 486 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1552 "./parser.cc"
    break;

  case 74: // expression_statment: expr
#line 494 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1558 "./parser.cc"
    break;

  case 75: // string: string string_literal
#line 498 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1564 "./parser.cc"
    break;

  case 76: // string: string_literal
#line 499 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1572 "./parser.cc"
    break;

  case 77: // string: id string_literal
#line 502 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1580 "./parser.cc"
    break;

  case 78: // string: string id string_literal
#line 505 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1588 "./parser.cc"
    break;

  case 79: // expr_list_opt: expr_list
#line 511 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1594 "./parser.cc"
    break;

  case 80: // expr_list_opt: %empty
#line 512 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1600 "./parser.cc"
    break;

  case 81: // expr_list: expr_list "," expr
#line 516 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1606 "./parser.cc"
    break;

  case 82: // expr_list: expr
#line 517 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1612 "./parser.cc"
    break;

  case 83: // dict: expr ":" expr
#line 527 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1618 "./parser.cc"
    break;

  case 84: // dict_list: dict_list "," dict
#line 531 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1624 "./parser.cc"
    break;

  case 85: // dict_list: dict
#line 532 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1630 "./parser.cc"
    break;

  case 86: // call_arguement_list: expr_list_opt
#line 536 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1636 "./parser.cc"
    break;

  case 87: // call_arguement_list: expr_list ","
#line 537 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1642 "./parser.cc"
    break;

  case 88: // keyword_item: id "=" expr
#line 542 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1648 "./parser.cc"
    break;

  case 89: // keyword_item: "**" expr
#line 543 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1654 "./parser.cc"
    break;

  case 90: // keyword_items: keyword_items "," keyword_item
#line 547 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1660 "./parser.cc"
    break;

  case 91: // keyword_items: keyword_item
#line 548 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1666 "./parser.cc"
    break;

  case 92: // primary: id
#line 553 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1672 "./parser.cc"
    break;

  case 93: // primary: string
#line 554 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1678 "./parser.cc"
    break;

  case 94: // primary: expr "." id
#line 555 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1684 "./parser.cc"
    break;

  case 95: // function_call: primary "(" call_arguement_list ")"
#line 559 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1690 "./parser.cc"
    break;

  case 96: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 560 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1697 "./parser.cc"
    break;

  case 97: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 562 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1704 "./parser.cc"
    break;

  case 98: // function_call: primary "(" keyword_items comma_opt ")"
#line 564 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1710 "./parser.cc"
    break;

  case 99: // function_call: function_call "(" call_arguement_list ")"
#line 565 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1716 "./parser.cc"
    break;

  case 100: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 566 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1723 "./parser.cc"
    break;

  case 101: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 568 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1730 "./parser.cc"
    break;

  case 102: // function_call: function_call "(" keyword_items comma_opt ")"
#line 570 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1736 "./parser.cc"
    break;

  case 103: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 577 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1742 "./parser.cc"
    break;

  case 104: // expr: id
#line 581 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1748 "./parser.cc"
    break;

  case 105: // expr: integer_literal
#line 582 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 1757 "./parser.cc"
    break;

  case 106: // expr: string
#line 586 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1763 "./parser.cc"
    break;

  case 107: // expr: real_literal
#line 587 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 1769 "./parser.cc"
    break;

  case 108: // expr: image_literal
#line 588 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 1778 "./parser.cc"
    break;

  case 109: // expr: TRUE
#line 592 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 1784 "./parser.cc"
    break;

  case 110: // expr: FALSE
#line 593 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 1790 "./parser.cc"
    break;

  case 111: // expr: NONE
#line 594 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 1796 "./parser.cc"
    break;

  case 112: // expr: "..."
#line 595 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 1802 "./parser.cc"
    break;

  case 113: // expr: "(" expr ")"
#line 596 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 1808 "./parser.cc"
    break;

  case 114: // expr: "(" ")"
#line 597 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 1814 "./parser.cc"
    break;

  case 115: // expr: function_call
#line 598 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1820 "./parser.cc"
    break;

  case 116: // expr: "[" expr_list_opt "]"
#line 600 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1826 "./parser.cc"
    break;

  case 117: // expr: "[" expr_list "," "]"
#line 601 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1832 "./parser.cc"
    break;

  case 118: // expr: "{" expr_list "}"
#line 602 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1838 "./parser.cc"
    break;

  case 119: // expr: "{" expr_list "," "}"
#line 603 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1844 "./parser.cc"
    break;

  case 120: // expr: expr "." id
#line 604 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1850 "./parser.cc"
    break;

  case 121: // expr: "{" "}"
#line 606 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 1856 "./parser.cc"
    break;

  case 122: // expr: "{" dict_list "}"
#line 607 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 1862 "./parser.cc"
    break;

  case 123: // expr: id ":=" expr
#line 611 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1868 "./parser.cc"
    break;

  case 124: // expr: "*" expr
#line 612 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1874 "./parser.cc"
    break;

  case 125: // expr: expr "+" expr
#line 614 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1880 "./parser.cc"
    break;

  case 126: // expr: expr "-" expr
#line 615 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1886 "./parser.cc"
    break;

  case 127: // expr: expr "*" expr
#line 616 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1892 "./parser.cc"
    break;

  case 128: // expr: expr "/" expr
#line 617 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1898 "./parser.cc"
    break;

  case 129: // expr: expr "%" expr
#line 618 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1904 "./parser.cc"
    break;

  case 130: // expr: "-" expr
#line 619 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 1910 "./parser.cc"
    break;

  case 131: // expr: "+" expr
#line 620 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 1916 "./parser.cc"
    break;

  case 132: // expr: "~" expr
#line 621 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 1922 "./parser.cc"
    break;

  case 133: // expr: expr "**" expr
#line 622 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1928 "./parser.cc"
    break;

  case 134: // expr: expr "//" expr
#line 623 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1934 "./parser.cc"
    break;

  case 135: // expr: expr "@" expr
#line 624 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1940 "./parser.cc"
    break;

  case 136: // expr: expr "&" expr
#line 626 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1946 "./parser.cc"
    break;

  case 137: // expr: expr "|" expr
#line 627 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1952 "./parser.cc"
    break;

  case 138: // expr: expr "^" expr
#line 628 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1958 "./parser.cc"
    break;

  case 139: // expr: expr "<<" expr
#line 629 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1964 "./parser.cc"
    break;

  case 140: // expr: expr ">>" expr
#line 630 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1970 "./parser.cc"
    break;

  case 141: // expr: expr "==" expr
#line 632 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1976 "./parser.cc"
    break;

  case 142: // expr: expr "!=" expr
#line 633 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1982 "./parser.cc"
    break;

  case 143: // expr: expr "<" expr
#line 634 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1988 "./parser.cc"
    break;

  case 144: // expr: expr "<=" expr
#line 635 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1994 "./parser.cc"
    break;

  case 145: // expr: expr ">" expr
#line 636 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2000 "./parser.cc"
    break;

  case 146: // expr: expr ">=" expr
#line 637 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2006 "./parser.cc"
    break;

  case 147: // expr: expr "is" expr
#line 638 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2012 "./parser.cc"
    break;

  case 148: // expr: expr "is not" expr
#line 639 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2018 "./parser.cc"
    break;

  case 149: // expr: expr "in" expr
#line 640 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2024 "./parser.cc"
    break;

  case 150: // expr: expr "not in" expr
#line 641 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2030 "./parser.cc"
    break;

  case 151: // expr: expr "and" expr
#line 643 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2036 "./parser.cc"
    break;

  case 152: // expr: expr "or" expr
#line 644 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2042 "./parser.cc"
    break;

  case 153: // expr: "not" expr
#line 645 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2048 "./parser.cc"
    break;

  case 154: // expr: ternary_if_statement
#line 652 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2054 "./parser.cc"
    break;

  case 155: // id: identifier
#line 657 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2060 "./parser.cc"
    break;

  case 156: // sep: sep sep_one
#line 661 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2066 "./parser.cc"
    break;

  case 157: // sep: sep_one
#line 662 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2072 "./parser.cc"
    break;

  case 158: // sep_one: NEWLINE
#line 666 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2078 "./parser.cc"
    break;

  case 159: // sep_one: COMMENT
#line 667 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2084 "./parser.cc"
    break;

  case 160: // sep_one: ";"
#line 668 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2090 "./parser.cc"
    break;


#line 2094 "./parser.cc"

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









  const short  Parser ::yypact_ninf_ = -224;

  const signed char  Parser ::yytable_ninf_ = -95;

  const short
   Parser ::yypact_[] =
  {
     291,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  1210,
    1210,    22,  1210,  1210,  1040,   981,  1210,  1210,  1210,  1210,
    1210,  1210,  -224,  -224,  -224,  -224,   939,  -224,  -224,    82,
    -224,    82,     5,   -32,  -224,  -224,  -224,  -224,  -224,  -224,
      93,   -36,   -23,   769,   142,    82,  -224,   -10,   769,   490,
    -224,     8,  -224,    -9,  -224,   -10,  1241,  -224,    34,  -224,
     112,   535,  -224,   580,   -34,    -4,   -45,   -45,   -45,   428,
     -45,  -224,  -224,    82,    82,    81,  1210,  -224,    90,  1195,
    1195,  1210,  1210,  1210,  1210,  1210,  1210,  1210,  1210,  1210,
    1210,  1210,    81,  1210,  1210,  1210,  1210,  1210,  1210,  1210,
    1210,  1210,  1210,  1210,  1210,  1210,  1210,  1210,  -224,  1210,
    -224,  1210,   330,    81,    81,    22,  1062,  -224,  1210,  -224,
    1210,    44,  -224,   951,    82,    50,   428,  -224,  1210,  -224,
      40,    31,  -224,    58,   104,    60,    37,   102,  1241,   634,
     374,   374,   374,   374,   857,  1264,  1023,   374,   349,   103,
     349,   -45,   -45,   -45,   -45,   -45,  1165,   176,   176,   374,
     374,   374,   374,   -45,   374,   813,   769,  -224,   141,  -224,
     -50,  1136,   114,     6,  -224,  -224,  -224,  -224,  -224,   535,
     769,  1210,  -224,     0,    82,   769,  1195,  -224,  1195,    95,
    1210,  1195,  -224,  1195,    97,  1210,   121,  -224,    91,    99,
     105,  -224,    94,  1121,  -224,   133,   113,    10,    81,  -224,
    -224,  -224,   153,  -224,   128,   -26,   157,   158,  -224,  -224,
     769,   157,   158,  -224,   813,   330,  -224,   116,  -224,   107,
    -224,   389,  -224,  1210,  -224,     9,   159,   161,    -3,  -224,
     106,  1210,  1210,    12,   136,  1210,   137,   138,   139,  -224,
    -224,  -224,  -224,    81,   167,    13,  -224,  -224,  -224,   168,
    -224,  -224,   330,  1210,   679,   769,   170,  -224,  -224,  -224,
    -224,   161,    17,  -224,    81,   169,     0,  -224,  -224,   724,
    1210,  -224,    81,   161,    18,  -224,  -224,   179,   330,   769,
     161,  -224,    81,     0,  -224,  -224,   161,  -224
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
      40,   105,   107,   108,   155,    76,   110,   109,   111,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,   112,   160,   158,   159,    40,     3,     5,     0,
      26,    23,     0,    39,    38,    27,   154,    28,    37,    25,
     106,     0,   115,    74,   104,     4,   157,    69,    82,     0,
      33,    31,    35,    36,    30,    71,   153,   121,     0,    85,
       0,    82,   114,     0,     0,    79,   130,   131,   124,     0,
     132,     1,     2,    22,    24,     0,     0,    75,     0,    80,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
     156,     0,     0,     0,     0,     0,     0,   118,     0,   122,
       0,   113,   116,     0,    42,     0,     0,    78,     0,    86,
      79,     0,    91,    66,   104,    79,     0,    66,   151,     0,
     149,   147,   148,   150,   152,   136,   138,   141,   126,   120,
     125,   127,   133,   135,   134,   129,   137,   139,   140,   143,
     144,   145,   146,   128,   142,   123,    81,     9,    72,     8,
       0,     0,     0,     0,    32,    29,    34,   119,    84,     0,
      83,    80,   117,    64,    41,    89,    87,    95,    65,     0,
       0,    87,    99,    65,     0,     0,     0,    12,     0,    18,
      21,    14,     0,    40,     7,    79,     0,     0,     0,    54,
      63,    49,    66,    52,     0,    43,    66,    66,    90,    98,
      88,    66,    66,   102,    70,     0,    13,    20,    15,     0,
      17,    40,    11,    87,   103,     0,    66,    66,    65,    50,
       0,     0,     0,    65,     0,    65,     0,     0,     0,    73,
      16,     6,    10,     0,    66,    65,    58,    65,    62,    66,
      53,    51,     0,     0,    44,    45,     0,    96,    97,   100,
     101,    66,    65,    55,     0,    66,    65,    47,    67,     0,
       0,    56,     0,    66,    65,    59,    48,    66,     0,    46,
      66,    60,     0,    65,    68,    57,    66,    61
  };

  const short
   Parser ::yypgoto_[] =
  {
    -224,  -224,   194,  -224,  -224,  -223,  -224,  -224,  -224,  -224,
    -193,   -78,  -224,   118,  -224,  -224,  -224,  -224,  -224,  -196,
    -224,   -33,   -70,  -211,  -224,    33,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,   215,    -7,   127,  -224,   -76,  -180,   -43,
    -224,  -224,    35,   -11,     1,    21
  };

  const unsigned char
   Parser ::yydefgoto_[] =
  {
       0,    26,    27,   204,   167,   168,   231,   169,   170,   171,
      28,    29,    51,    52,    53,    30,    31,    32,    33,   209,
     210,   211,   212,   213,   214,   239,    34,    35,    36,    37,
      38,    39,    40,   129,    47,    59,    60,   131,   132,   133,
      41,    42,    43,    44,   173,    46
  };

  const short
   Parser ::yytable_[] =
  {
      54,    45,   249,     4,   136,    55,     4,    58,   218,    65,
     232,   236,   237,   218,    92,     4,     4,    95,     4,     4,
      79,   113,   241,     4,     4,    75,   242,   261,     4,    78,
      73,    76,    74,    80,   172,   197,   198,   137,   252,   278,
     111,   115,   260,   122,    48,    49,   123,    48,    56,    61,
      63,    48,    66,    67,    68,    69,    70,   271,   207,   208,
     235,   207,   208,   218,   125,   294,   110,   114,   134,   134,
     124,   253,   130,   135,   128,   274,   260,   259,   283,   282,
     292,   149,   261,    50,   116,    23,   290,     4,   260,   203,
     186,    24,    25,   199,   110,   110,   296,   260,   127,     4,
     181,    77,   174,   175,    54,   206,   183,   187,   188,   117,
     191,   126,   108,   192,    48,    48,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   184,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   216,   165,   110,   166,   172,   221,   -93,
     108,   166,   193,   179,   262,   180,   190,   109,   166,   -94,
     -92,    23,   118,   185,   196,   254,   189,    24,    25,   225,
     194,   219,   215,   223,   205,   134,   226,   134,   227,   230,
     134,   217,   134,   233,   172,   275,   222,   119,   263,   234,
     228,   229,   250,   200,   110,   109,   215,   215,   -92,   201,
     202,   -19,   -19,   238,   240,   110,   287,   243,   245,   255,
     172,   257,   267,   268,   269,   270,    48,   272,   276,   284,
      72,   166,   190,    48,   215,   220,   166,   215,    48,   293,
     224,    64,   266,   176,    91,    92,    93,    94,    95,    96,
      97,    98,   215,   286,   215,   178,     0,     0,     0,   244,
     246,     0,     0,     0,   247,   248,   106,     0,     0,     0,
       0,   215,     0,   215,     0,   215,     0,     0,   166,   256,
     258,   215,     0,   215,     0,     0,   264,   265,     0,     0,
     166,   215,   215,     0,     0,     0,     0,   273,     0,     0,
       0,     0,   277,     0,     1,     2,     3,     4,   279,     5,
       6,     7,     8,     0,   281,     0,     0,     0,   285,     0,
       0,     0,     0,     0,     0,   289,   291,     0,     0,     9,
      10,    11,     0,   295,     0,     0,     0,    12,    13,   297,
       0,     0,     0,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     0,     0,    14,    15,    16,    17,
       0,    18,    19,     0,    20,     0,     0,    21,     9,     0,
      11,     0,     0,     0,     0,    22,    12,    13,     0,     0,
      23,     0,     0,     0,     0,     0,    24,    25,     0,     0,
       0,     0,     0,     0,     0,    14,    15,    16,    17,     0,
      18,    19,     1,     2,     3,     4,    21,     5,     6,     7,
       8,     0,     0,     0,    22,     0,     0,     0,    92,    23,
      94,    95,    96,    97,    98,    24,    25,     9,    10,    11,
      88,    89,     0,     0,     0,    12,    13,     0,     0,   106,
       0,     0,    91,    92,    93,    94,    95,    96,    97,    98,
      81,    99,   100,   101,    14,    15,    16,    17,     0,    18,
      19,     0,    20,     0,   106,    21,     0,    82,     0,    83,
      84,    85,    86,    22,     0,     0,    87,     0,     0,     0,
       0,     0,     0,   251,    88,    89,     0,     0,     0,     0,
       0,     0,    90,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    97,    98,     0,    99,   100,   101,   102,   103,
     104,   105,    81,     0,     0,     0,     0,    23,   106,     0,
       0,     0,     0,    24,    25,     0,     0,   107,     0,    82,
       0,    83,    84,    85,    86,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,    88,    89,   112,     0,
       0,     0,     0,     0,    90,     0,     0,    81,    91,    92,
      93,    94,    95,    96,    97,    98,     0,    99,   100,   101,
     102,   103,   104,   105,    82,     0,    83,    84,    85,    86,
     106,     0,     0,    87,     0,     0,     0,     0,     0,   107,
       0,    88,    89,   120,     0,     0,     0,     0,     0,    90,
       0,     0,    81,    91,    92,    93,    94,    95,    96,    97,
      98,     0,    99,   100,   101,   102,   103,   104,   105,    82,
       0,    83,    84,    85,    86,   106,     0,     0,    87,     0,
       0,     0,     0,     0,   107,     0,    88,    89,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    97,    98,    81,    99,   100,   101,
     102,   103,   104,   105,     0,     0,   121,   195,     0,     0,
     106,     0,     0,    82,     0,    83,    84,    85,    86,   107,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
      88,    89,     0,     0,     0,     0,     0,     0,    90,     0,
       0,    81,    91,    92,    93,    94,    95,    96,    97,    98,
       0,    99,   100,   101,   102,   103,   104,   105,    82,     0,
      83,    84,    85,    86,   106,     0,     0,    87,     0,     0,
       0,     0,     0,   107,     0,    88,    89,     0,     0,     0,
       0,   280,     0,    90,     0,     0,    81,    91,    92,    93,
      94,    95,    96,    97,    98,     0,    99,   100,   101,   102,
     103,   104,   105,    82,     0,    83,    84,    85,    86,   106,
       0,     0,    87,     0,     0,     0,     0,     0,   107,     0,
      88,    89,   288,     0,     0,     0,     0,     0,    90,     0,
       0,    81,    91,    92,    93,    94,    95,    96,    97,    98,
       0,    99,   100,   101,   102,   103,   104,   105,    82,     0,
      83,    84,    85,    86,   106,     0,     0,    87,     0,     0,
       0,     0,     0,   107,     0,    88,    89,     0,     0,     0,
       0,     0,     0,    90,     0,    81,     0,    91,    92,    93,
      94,    95,    96,    97,    98,     0,    99,   100,   101,   102,
     103,   104,   105,     0,    83,    84,    85,    86,     0,   106,
       0,    87,     0,     0,     0,     0,     0,     0,   107,    88,
      89,     0,     0,     0,     0,     0,     0,    90,     0,    81,
       0,    91,    92,    93,    94,    95,    96,    97,    98,     0,
      99,   100,   101,   102,   103,   104,   105,     0,    83,    84,
      85,    86,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,   107,    88,    89,     0,     0,     0,     0,     0,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
      96,    97,    98,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,     0,     0,     0,   106,     0,    71,
       0,     0,     1,     2,     3,     4,   107,     5,     6,     7,
       8,     0,     0,     0,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     0,     9,    10,    11,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,    13,     5,
       6,     7,     8,     0,    14,    15,    16,    17,     0,    18,
      19,     0,    20,     0,     0,    21,    14,    15,    16,    17,
       0,    18,    19,    22,     0,     0,     0,    21,    13,     0,
       0,     0,     0,     0,     0,    22,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,    14,    15,    16,    17,
       0,    18,    19,     1,     2,     3,     4,    21,     5,     6,
       7,     8,     0,     0,     0,    22,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,    88,
       5,     6,     7,     8,     0,     0,     0,    13,     0,     0,
       0,    91,    92,    93,    94,    95,    96,    97,    98,     0,
       0,   100,   101,     0,     0,    14,    15,    16,    17,    13,
      18,    19,     0,   106,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,    22,    57,     0,    14,    15,    16,
      17,     0,    18,    19,     1,     2,     3,     4,    21,     5,
       6,     7,     8,     0,     0,     0,    22,   177,     0,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     9,
      10,    11,     0,     0,     0,     0,     0,    12,    13,     0,
       0,     0,     0,     0,     9,     0,    11,     0,     0,     0,
       0,     0,    12,    13,     0,     0,    14,    15,    16,    17,
       0,    18,    19,     0,    20,     0,     0,    21,     0,     0,
       0,    14,    15,    16,    17,    22,    18,    19,     1,     2,
       3,     4,    21,     5,     6,     7,     8,     0,     0,     0,
      22,    88,    89,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,    91,    92,    93,    94,    95,    96,    97,
      98,     0,    13,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,    13,     0,     0,
      14,    15,    16,    17,     0,    18,    19,   128,     0,     0,
       0,    21,     0,     0,     0,    14,    15,    16,    17,    22,
      18,    19,    83,    84,    85,    86,    21,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,    88,    89,     0,
       0,     0,     0,     0,     0,    90,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    97,    98,     0,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,   106,    91,    92,    93,    94,    95,    96,    97,    98,
     107,     0,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106
  };

  const short
   Parser ::yycheck_[] =
  {
      11,     0,   225,     6,    80,    12,     6,    14,   188,    16,
     203,   207,   208,   193,    59,     6,     6,    62,     6,     6,
      56,    13,    48,     6,     6,    20,    52,   238,     6,    40,
      29,    63,    31,    56,   112,    85,    86,    80,   231,   262,
      50,    50,   238,    77,     9,    10,    50,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   253,    61,    62,
      50,    61,    62,   243,    75,   288,    45,    59,    79,    80,
      69,    62,    79,    80,    62,    62,   272,    80,   274,    62,
      62,    92,   293,    61,    50,    79,   282,     6,   284,    83,
      50,    85,    86,   171,    73,    74,   292,   293,     8,     6,
      56,     8,   113,   114,   115,   181,    56,    76,    50,    75,
      50,    76,     8,    76,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,   126,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   186,   109,   124,   111,   225,   191,    56,
       8,   116,    50,   118,    48,   120,    52,    53,   123,    56,
      56,    79,    50,   128,    23,   235,   133,    85,    86,    48,
     137,    76,   183,    76,   181,   186,    85,   188,    79,    85,
     191,   188,   193,    50,   262,   255,   193,    75,    82,    76,
      85,    86,    85,    79,   173,    53,   207,   208,    56,    85,
      86,    85,    86,    50,    76,   184,   276,    50,    50,    50,
     288,    50,    76,    76,    76,    76,   181,    50,    50,    50,
      26,   186,    52,   188,   235,   190,   191,   238,   193,    50,
     195,    16,   243,   115,    58,    59,    60,    61,    62,    63,
      64,    65,   253,   276,   255,   118,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,   222,    80,    -1,    -1,    -1,
      -1,   272,    -1,   274,    -1,   276,    -1,    -1,   233,   236,
     237,   282,    -1,   284,    -1,    -1,   241,   242,    -1,    -1,
     245,   292,   293,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,   259,    -1,     3,     4,     5,     6,   263,     8,
       9,    10,    11,    -1,   271,    -1,    -1,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,   280,   283,    -1,    -1,    28,
      29,    30,    -1,   290,    -1,    -1,    -1,    36,    37,   296,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    60,    61,    -1,    63,    -1,    -1,    66,    28,    -1,
      30,    -1,    -1,    -1,    -1,    74,    36,    37,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    61,     3,     4,     5,     6,    66,     8,     9,    10,
      11,    -1,    -1,    -1,    74,    -1,    -1,    -1,    59,    79,
      61,    62,    63,    64,    65,    85,    86,    28,    29,    30,
      46,    47,    -1,    -1,    -1,    36,    37,    -1,    -1,    80,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      12,    67,    68,    69,    55,    56,    57,    58,    -1,    60,
      61,    -1,    63,    -1,    80,    66,    -1,    29,    -1,    31,
      32,    33,    34,    74,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    12,    -1,    -1,    -1,    -1,    79,    80,    -1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    89,    -1,    29,
      -1,    31,    32,    33,    34,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    12,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    29,    -1,    31,    32,    33,    34,
      80,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    12,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    29,
      -1,    31,    32,    33,    34,    80,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    12,    67,    68,    69,
      70,    71,    72,    73,    -1,    -1,    76,    23,    -1,    -1,
      80,    -1,    -1,    29,    -1,    31,    32,    33,    34,    89,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    12,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    29,    -1,
      31,    32,    33,    34,    80,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    46,    47,    -1,    -1,    -1,
      -1,    52,    -1,    54,    -1,    -1,    12,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    29,    -1,    31,    32,    33,    34,    80,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    12,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    29,    -1,
      31,    32,    33,    34,    80,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    12,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    -1,    31,    32,    33,    34,    -1,    80,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    89,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    12,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    31,    32,
      33,    34,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,     0,
      -1,    -1,     3,     4,     5,     6,    89,     8,     9,    10,
      11,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    37,     8,
       9,    10,    11,    -1,    55,    56,    57,    58,    -1,    60,
      61,    -1,    63,    -1,    -1,    66,    55,    56,    57,    58,
      -1,    60,    61,    74,    -1,    -1,    -1,    66,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    60,    61,     3,     4,     5,     6,    66,     8,     9,
      10,    11,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    46,
       8,     9,    10,    11,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      -1,    68,    69,    -1,    -1,    55,    56,    57,    58,    37,
      60,    61,    -1,    80,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    55,    56,    57,
      58,    -1,    60,    61,     3,     4,     5,     6,    66,     8,
       9,    10,    11,    -1,    -1,    -1,    74,    75,    -1,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,    -1,    55,    56,    57,    58,
      -1,    60,    61,    -1,    63,    -1,    -1,    66,    -1,    -1,
      -1,    55,    56,    57,    58,    74,    60,    61,     3,     4,
       5,     6,    66,     8,     9,    10,    11,    -1,    -1,    -1,
      74,    46,    47,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    37,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    37,    -1,    -1,
      55,    56,    57,    58,    -1,    60,    61,    62,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    55,    56,    57,    58,    74,
      60,    61,    31,    32,    33,    34,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    58,    59,    60,    61,    62,    63,    64,    65,
      89,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    28,
      29,    30,    36,    37,    55,    56,    57,    58,    60,    61,
      63,    66,    74,    79,    85,    86,    92,    93,   101,   102,
     106,   107,   108,   109,   117,   118,   119,   120,   121,   122,
     123,   131,   132,   133,   134,   135,   136,   125,   133,   133,
      61,   103,   104,   105,   134,   125,   133,    75,   125,   126,
     127,   133,    76,   133,   124,   125,   133,   133,   133,   133,
     133,     0,    93,   135,   135,    20,    63,     8,   134,    56,
      56,    12,    29,    31,    32,    33,    34,    38,    46,    47,
      54,    58,    59,    60,    61,    62,    63,    64,    65,    67,
      68,    69,    70,    71,    72,    73,    80,    89,     8,    53,
     136,    50,    48,    13,    59,    50,    50,    75,    50,    75,
      48,    76,    77,    50,   135,   134,   133,     8,    62,   124,
     125,   128,   129,   130,   134,   125,   128,   130,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   134,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,    95,    96,    98,
      99,   100,   102,   135,   134,   134,   104,    75,   126,   133,
     133,    56,    77,    56,   135,   133,    50,    76,    50,   116,
      52,    50,    76,    50,   116,    23,    23,    85,    86,   102,
      79,    85,    86,    83,    94,   125,   128,    61,    62,   110,
     111,   112,   113,   114,   115,   134,   130,   125,   129,    76,
     133,   130,   125,    76,   133,    48,    85,    79,    85,    86,
      85,    97,   101,    50,    76,    50,   110,   110,    50,   116,
      76,    48,    52,    50,   116,    50,   116,   116,   116,    96,
      85,    84,   101,    62,   113,    50,   116,    50,   116,    80,
     110,   114,    48,    82,   133,   133,   134,    76,    76,    76,
      76,   110,    50,   116,    62,   113,    50,   116,    96,   133,
      52,   116,    62,   110,    50,   116,   112,   113,    48,   133,
     110,   116,    62,    50,    96,   116,   110,   116
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    91,    92,    92,    92,    93,    94,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   102,   102,   102,   102,   103,
     103,   104,   104,   104,   105,   105,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   110,   110,   111,   111,   111,
     112,   112,   112,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   115,   115,   116,   116,   117,   117,   118,
     119,   120,   121,   121,   122,   123,   123,   123,   123,   124,
     124,   125,   125,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   131,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   134,   135,   135,   136,   136,
     136
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     3,     2,     1,     1,
       2,     1,     2,     3,     2,     3,     4,     3,     2,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     1,     3,
       1,     1,     3,     1,     3,     1,     2,     1,     1,     1,
       0,     4,     3,     1,     3,     3,     5,     4,     5,     1,
       2,     3,     1,     3,     1,     4,     5,     7,     3,     5,
       6,     8,     3,     1,     0,     1,     0,     8,    10,     2,
       5,     2,     4,     7,     1,     2,     1,     2,     3,     1,
       0,     3,     1,     3,     3,     1,     1,     2,     3,     2,
       3,     1,     1,     1,     3,     4,     7,     7,     5,     4,
       7,     7,     5,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     3,     4,     3,     4,
       3,     2,     3,     3,     2,     3,     3,     3,     3,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     2,     1,     1,     1,
       1
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
       0,   262,   262,   263,   264,   268,   272,   276,   280,   281,
     285,   286,   290,   291,   292,   293,   296,   299,   305,   308,
     314,   317,   323,   324,   325,   329,   340,   341,   342,   347,
     348,   352,   353,   354,   358,   359,   363,   379,   383,   392,
     393,   397,   398,   402,   403,   404,   405,   409,   411,   413,
     417,   418,   420,   424,   425,   433,   434,   435,   437,   438,
     440,   442,   444,   448,   449,   453,   454,   458,   460,   471,
     475,   479,   483,   486,   494,   498,   499,   502,   505,   511,
     512,   516,   517,   527,   531,   532,   536,   537,   542,   543,
     547,   548,   553,   554,   555,   559,   560,   562,   564,   565,
     566,   568,   570,   577,   581,   582,   586,   587,   588,   592,
     593,   594,   595,   596,   597,   598,   600,   601,   602,   603,
     604,   606,   607,   611,   612,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   626,   627,   628,   629,
     630,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   643,   644,   645,   652,   657,   661,   662,   666,   667,
     668
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
#line 2830 "./parser.cc"

#line 671 "parser.ypp"
