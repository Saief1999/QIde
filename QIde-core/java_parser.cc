// A Bison parser, made by GNU Bison 3.8.2.

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


// Take the name prefix into account.
#define yylex   javacompilerlex

// First part of user prologue.
#line 1 "java_parser.yy"
 /*** C/C++ Declarations ***/
#include <string>
#include <vector>
#include <ctype.h>
#include <any>
#include <cstring>

// extern bool build_success;
// extern int yylineno;

#line 54 "java_parser.cc"


#include "java_parser.hh"

// Second part of user prologue.
#line 165 "java_parser.yy"


#include "driver.hh"
#include "java_lexer.hh"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 73 "java_parser.cc"



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
#if JAVACOMPILERDEBUG

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

#else // !JAVACOMPILERDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !JAVACOMPILERDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace javacompiler {
#line 166 "java_parser.cc"

  /// Build a parser object.
  JavaParser::JavaParser (class Driver& driver_yyarg)
#if JAVACOMPILERDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      driver (driver_yyarg)
  {}

  JavaParser::~JavaParser ()
  {}

  JavaParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  JavaParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  JavaParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  JavaParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}


  template <typename Base>
  JavaParser::symbol_kind_type
  JavaParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  JavaParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  JavaParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  JavaParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  JavaParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  JavaParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  JavaParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  JavaParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  JavaParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  JavaParser::symbol_kind_type
  JavaParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  JavaParser::symbol_kind_type
  JavaParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  JavaParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  JavaParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  JavaParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  JavaParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  JavaParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  JavaParser::symbol_kind_type
  JavaParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  JavaParser::stack_symbol_type::stack_symbol_type ()
  {}

  JavaParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  JavaParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  JavaParser::stack_symbol_type&
  JavaParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  JavaParser::stack_symbol_type&
  JavaParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  JavaParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if JAVACOMPILERDEBUG
  template <typename Base>
  void
  JavaParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  JavaParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  JavaParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  JavaParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if JAVACOMPILERDEBUG
  std::ostream&
  JavaParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  JavaParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  JavaParser::debug_level_type
  JavaParser::debug_level () const
  {
    return yydebug_;
  }

  void
  JavaParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // JAVACOMPILERDEBUG

  JavaParser::state_type
  JavaParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  JavaParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  JavaParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  JavaParser::operator() ()
  {
    return parse ();
  }

  int
  JavaParser::parse ()
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

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 37 "java_parser.yy"
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
    // Save the current location pointer in the semantic analyzer ( to print errors )
    driver.semantics->current_location = &yyla.location;
}

#line 518 "java_parser.cc"


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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
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
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
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
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

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
  case 2: // start: main_program
#line 184 "java_parser.yy"
                     {/*std::cout("program finished parsing\n");*/}
#line 662 "java_parser.cc"
    break;

  case 3: // nested_id: "identifier" '.' nested_id
#line 188 "java_parser.yy"
                            {
    std::string res = std::string((yystack_[2].value.text)) + "." + std::string((yystack_[0].value.text));
    strcpy((yylhs.value.text),res.c_str());
}
#line 671 "java_parser.cc"
    break;

  case 4: // nested_id: "identifier"
#line 191 "java_parser.yy"
       { strcpy((yylhs.value.text),(yystack_[0].value.text)); }
#line 677 "java_parser.cc"
    break;

  case 5: // opt_var_access: '.' var
#line 195 "java_parser.yy"
                        {
        strcpy((yylhs.value.text), ("."+std::string((yystack_[0].value.text))).c_str());
    }
#line 685 "java_parser.cc"
    break;

  case 6: // opt_var_access: %empty
#line 198 "java_parser.yy"
    { strcpy((yylhs.value.text) ,(std::string("")).c_str()); }
#line 691 "java_parser.cc"
    break;

  case 7: // $@1: %empty
#line 199 "java_parser.yy"
         {
        driver.semantics->check_definition((yystack_[0].value.text));
    }
#line 699 "java_parser.cc"
    break;

  case 8: // var: "identifier" $@1 opt_array opt_var_access
#line 202 "java_parser.yy"
                             {
    // Midrule actions count as a rule too , they can even have a return value (that's why we jumped '$2')...
    strcpy((yylhs.value.text), (std::string((yystack_[3].value.text))+std::string((yystack_[1].value.text)) + std::string((yystack_[0].value.text))).c_str());
}
#line 708 "java_parser.cc"
    break;

  case 9: // type: nested_id opt_array_type
#line 209 "java_parser.yy"
                                { 
    strcpy((yylhs.value.text) , (std::string((yystack_[1].value.text))+std::string((yystack_[0].value.text))).c_str());
}
#line 716 "java_parser.cc"
    break;

  case 10: // opt_array_type: "[]" opt_array_type
#line 212 "java_parser.yy"
                                     { 
    // Array in declaration
    strcpy((yylhs.value.text),("[]" + std::string((yystack_[0].value.text))).c_str());
    }
#line 725 "java_parser.cc"
    break;

  case 11: // opt_array_type: %empty
#line 216 "java_parser.yy"
    { strcpy((yylhs.value.text) ,(std::string("")).c_str()); }
#line 731 "java_parser.cc"
    break;

  case 12: // opt_array: '[' expression ']' opt_array
#line 217 "java_parser.yy"
                                        {
    // Array in call
    strcpy((yylhs.value.text),("[]" + std::string((yystack_[0].value.text))).c_str());
    }
#line 740 "java_parser.cc"
    break;

  case 13: // opt_array: %empty
#line 221 "java_parser.yy"
    { strcpy((yylhs.value.text) ,(std::string("")).c_str()); }
#line 746 "java_parser.cc"
    break;

  case 51: // var_fn: var
#line 249 "java_parser.yy"
             { driver.semantics->use_symbol((yystack_[0].value.text)); }
#line 752 "java_parser.cc"
    break;

  case 62: // assignment_operator: '='
#line 258 "java_parser.yy"
                         { driver.semantics->assign_value(driver.semantics->current_symbol); }
#line 758 "java_parser.cc"
    break;

  case 63: // assignment_operator: SELF_UNSIGNED_RIGHT_SHIFT
#line 259 "java_parser.yy"
                              { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 764 "java_parser.cc"
    break;

  case 64: // assignment_operator: SELF_RIGHT_SHIFT
#line 260 "java_parser.yy"
                     { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 770 "java_parser.cc"
    break;

  case 65: // assignment_operator: SELF_LEFT_SHIFT
#line 261 "java_parser.yy"
                    { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 776 "java_parser.cc"
    break;

  case 66: // assignment_operator: SELF_PLUS
#line 262 "java_parser.yy"
              { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 782 "java_parser.cc"
    break;

  case 67: // assignment_operator: SELF_MINUS
#line 263 "java_parser.yy"
               { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 788 "java_parser.cc"
    break;

  case 68: // assignment_operator: SELF_TIMES
#line 264 "java_parser.yy"
               { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 794 "java_parser.cc"
    break;

  case 69: // assignment_operator: SELF_DIV
#line 265 "java_parser.yy"
             { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 800 "java_parser.cc"
    break;

  case 70: // assignment_operator: SELF_MOD
#line 266 "java_parser.yy"
             { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 806 "java_parser.cc"
    break;

  case 71: // assignment_operator: SELF_BITWISE_AND
#line 267 "java_parser.yy"
                     { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 812 "java_parser.cc"
    break;

  case 72: // assignment_operator: SELF_BITWISE_OR
#line 268 "java_parser.yy"
                    { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 818 "java_parser.cc"
    break;

  case 73: // assignment_operator: SELF_BITWISE_XOR
#line 269 "java_parser.yy"
                     { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 824 "java_parser.cc"
    break;

  case 78: // $@2: %empty
#line 283 "java_parser.yy"
                 {
    /* This represents either a variable, or a type of a variable ( if we added another ID after it ) */
        driver.semantics->current_symbol = std::string((yystack_[0].value.text));
    }
#line 833 "java_parser.cc"
    break;

  case 84: // $@3: %empty
#line 292 "java_parser.yy"
           {
        driver.semantics->current_symbol = driver.semantics->current_symbol + "." + std::string((yystack_[0].value.text)); // used for types
    }
#line 841 "java_parser.cc"
    break;

  case 88: // $@4: %empty
#line 297 "java_parser.yy"
        {
        driver.semantics->set_current_method_call(driver.semantics->current_symbol); 
    }
#line 849 "java_parser.cc"
    break;

  case 89: // $@5: %empty
#line 299 "java_parser.yy"
           {
        driver.semantics->current_method_call.clear();
        driver.semantics->is_call_definition = false;
    }
#line 858 "java_parser.cc"
    break;

  case 92: // statement_s1: binary_operator expression
#line 304 "java_parser.yy"
                               { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 864 "java_parser.cc"
    break;

  case 93: // statement_s1: unary_special_operator
#line 305 "java_parser.yy"
                           { driver.semantics->use_symbol(driver.semantics->current_symbol); }
#line 870 "java_parser.cc"
    break;

  case 106: // obligatory_args: assignable_expression
#line 324 "java_parser.yy"
                                       {
    driver.semantics->args_number ++;
    }
#line 878 "java_parser.cc"
    break;

  case 107: // $@6: %empty
#line 327 "java_parser.yy"
                          {
        driver.semantics->args_number ++ ;
    }
#line 886 "java_parser.cc"
    break;

  case 109: // args: obligatory_args
#line 330 "java_parser.yy"
                       {
        driver.semantics->check_args_number();
    }
#line 894 "java_parser.cc"
    break;

  case 110: // args: %empty
#line 333 "java_parser.yy"
    { 
        driver.semantics->check_args_number();
    }
#line 902 "java_parser.cc"
    break;

  case 113: // $@7: %empty
#line 345 "java_parser.yy"
                                               {
        driver.semantics->add_arg_to_current((yystack_[1].value.text),(yystack_[2].value.text));
    }
#line 910 "java_parser.cc"
    break;

  case 115: // obligatory_formal_args: type "identifier" opt_array_type opt_variadic
#line 349 "java_parser.yy"
                                        {
        driver.semantics->add_arg_to_current((yystack_[2].value.text),(yystack_[3].value.text));
    }
#line 918 "java_parser.cc"
    break;

  case 118: // opt_assignment: '=' assignable_expression
#line 355 "java_parser.yy"
                                          {
    // std::cout << "assigning a value to a variable" << std::endl;
    driver.semantics->current_symbol_entry.is_initialized = true;
}
#line 927 "java_parser.cc"
    break;

  case 120: // $@8: %empty
#line 364 "java_parser.yy"
                         {
        // a type is first detected as the "current_symbol" , if another identifier is found after it, it becomes the "current_type"
        if (driver.semantics->current_type.empty()) driver.semantics->current_type = driver.semantics->current_symbol;
        driver.semantics->current_symbol_entry.type = driver.semantics->current_type; // this is saved on 'statement_s0'
        driver.semantics->current_symbol = std::string((yystack_[0].value.text));
        driver.semantics->current_symbol_entry.ident_type = identifier_type::VARIABLE;
        // std::cout << "setting type for " <<driver.semantics->current_symbol<< " as "<<driver.semantics->current_symbol_entry.type<<std::endl;

    }
#line 941 "java_parser.cc"
    break;

  case 121: // var_declaration_body: "identifier" $@8 opt_array_type opt_assignment
#line 372 "java_parser.yy"
                                    {

        driver.semantics->add_current_symbol();
        driver.semantics->reset_current_symbol();
        // driver.semantics->add_symbol($1, { identifier_type::VARIABLE, false });
    }
#line 952 "java_parser.cc"
    break;

  case 122: // var_declarations: var_declaration_body ',' var_declarations
#line 379 "java_parser.yy"
                                                             {
    driver.semantics->current_type.clear();
}
#line 960 "java_parser.cc"
    break;

  case 126: // assignment: '=' new_expression
#line 389 "java_parser.yy"
                       {
        driver.semantics->assign_value(driver.semantics->current_symbol);
    }
#line 968 "java_parser.cc"
    break;

  case 128: // statement_pm_1: unary_special_operator var
#line 393 "java_parser.yy"
                                           { driver.semantics->use_symbol((yystack_[0].value.text)); }
#line 974 "java_parser.cc"
    break;

  case 129: // statement_pm_1: var unary_special_operator
#line 394 "java_parser.yy"
                               { driver.semantics->use_symbol((yystack_[1].value.text)); }
#line 980 "java_parser.cc"
    break;

  case 176: // $@9: %empty
#line 461 "java_parser.yy"
                      {
        driver.semantics->current_symbol = std::string((yystack_[0].value.text));
        driver.semantics->add_current_symbol();

    }
#line 990 "java_parser.cc"
    break;

  case 180: // $@10: %empty
#line 466 "java_parser.yy"
                               {
        // GLOBAL VARIABLE DECLARATION
        driver.semantics->current_symbol_entry.ident_type = identifier_type::VARIABLE;
        driver.semantics->add_current_symbol();
    }
#line 1000 "java_parser.cc"
    break;

  case 181: // cls_attr_sign: opt_assignment $@10 cls_attr_more
#line 470 "java_parser.yy"
                    {
        driver.semantics->reset_current_symbol();
    }
#line 1008 "java_parser.cc"
    break;

  case 182: // $@11: %empty
#line 474 "java_parser.yy"
    {
        // GLOBAL METHOD DECLARATION
        driver.semantics->current_symbol_entry.ident_type = identifier_type::METHOD;
        driver.semantics->current_method = driver.semantics->current_symbol;
        driver.semantics->add_current_symbol();
        driver.semantics->reset_current_symbol();
    }
#line 1020 "java_parser.cc"
    break;

  case 183: // $@12: %empty
#line 481 "java_parser.yy"
                    { driver.semantics->current_method.clear();}
#line 1026 "java_parser.cc"
    break;

  case 204: // $@13: %empty
#line 494 "java_parser.yy"
                          {
        // This can be either an attribute or a method (if we added "()")
        driver.semantics->current_symbol = std::string((yystack_[0].value.text));
        // std::cout << "Setting type for "<<std::string($3)<<" as "<<std::string($2)<<std::endl;
        driver.semantics->current_symbol_entry.type = std::string((yystack_[1].value.text));
        // std::cout << "setting new symbol " << std::string($3) <<"\n";
        }
#line 1038 "java_parser.cc"
    break;

  case 216: // opening_bracket: '{'
#line 511 "java_parser.yy"
                     {
        // std::cout<<"Adding new scope"<<std::endl;
        driver.semantics->add_scope();
    }
#line 1047 "java_parser.cc"
    break;

  case 217: // closing_bracket: '}'
#line 516 "java_parser.yy"
                     {
        // std::cout<<"Removing new scope"<<std::endl;
        driver.semantics->free_scope();
    }
#line 1056 "java_parser.cc"
    break;


#line 1060 "java_parser.cc"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
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
      yy_lac_discard_ ("error recovery");
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
  JavaParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  JavaParser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "identifier", "character",
  "string", "++", "--", "integer", "real", "class", "[]", "return",
  "interface", "abstract", "static", "extends", "implements", "if", "else",
  "for", "while", "do", "switch", "case", "default", "<<", ">>", ">>>",
  "<=", ">=", "!=", "==", "SELF_UNSIGNED_RIGHT_SHIFT", "SELF_LEFT_SHIFT",
  "SELF_RIGHT_SHIFT", "instanceof", ",", "new", "&&", "||", "true",
  "false", "package", "import", "SELF_PLUS", "SELF_MINUS", "SELF_DIV",
  "SELF_MOD", "SELF_TIMES", "SELF_BITWISE_AND", "SELF_BITWISE_OR",
  "SELF_BITWISE_XOR", "'^'", "'|'", "'&'", "'<'", "'>'", "'-'", "'+'",
  "'*'", "'/'", "'%'", "'='", "LOWEST", "PUBLIC", "public", "PRIVATE",
  "private", "PROTECTED", "protected", "'.'", "'['", "']'", "'!'", "'~'",
  "'('", "')'", "'{'", "'}'", "','", "';'", "':'", "$accept", "start",
  "nested_id", "opt_var_access", "var", "$@1", "type", "opt_array_type",
  "opt_array", "equality_operator", "order_operator", "shift_operator",
  "multiplicative_operator", "additive_operator", "logical_operator",
  "bitwise_operator", "binary_operator", "unary_operator",
  "opt_unary_operator", "unary_special_operator", "fn_call",
  "opt_var_fn_access", "var_fn", "val", "opt_string_access",
  "assignment_operator", "expression", "statement_s0", "$@2",
  "statement_s1", "$@3", "$@4", "$@5", "rhs", "statement_s2",
  "new_expression", "new_initialisation", "assignable_expression",
  "obligatory_args", "$@6", "args", "opt_variadic",
  "obligatory_formal_args", "$@7", "formal_args", "opt_assignment",
  "var_declaration_body", "$@8", "var_declarations",
  "statement_declarative", "assignment", "assignment_statement",
  "statement_pm_1", "statement", "opt_statement_seq", "statement_seq",
  "block", "condition", "conditional_body", "opt_else_statement",
  "if_statement", "for_updating_statement", "for_statement",
  "range_for_statement", "while_statement", "do_while_statement",
  "switch_statement", "case_val", "switch_label", "case_block",
  "switch_body", "opt_return_expression", "return_statement",
  "cls_modifier", "cls_attr_more", "$@9", "cls_attr_sign", "$@10", "$@11",
  "$@12", "fn_access_modifier", "fn_static_modifier",
  "fn_opt_static_modifier", "fn_opt_access_modifier", "fn_modifier",
  "fn_declaration", "cls_declaration", "cls_info_opt_more", "cls_info",
  "$@13", "opt_cls_info", "opt_extends", "more_interface_list",
  "interface_list", "opt_implements", "opening_bracket", "closing_bracket",
  "cls_definition", "opt_abstract", "interface_info", "opt_interface_info",
  "interface_declaration", "opt_interface_extends", "interface_definition",
  "opt_pkg_declaration", "pkg_import", "type_definitions",
  "type_definitions_more", "main_program", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // JavaParser::context.
  JavaParser::context::context (const JavaParser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  JavaParser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if JAVACOMPILERDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  JavaParser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if JAVACOMPILERDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  JavaParser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if JAVACOMPILERDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  JavaParser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  JavaParser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  JavaParser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short JavaParser::yypact_ninf_ = -278;

  const short JavaParser::yytable_ninf_ = -242;

  const short
  JavaParser::yypact_[] =
  {
       6,    61,    89,    28,  -278,    32,    36,  -278,    61,    60,
      61,  -278,    47,  -278,    87,    51,    48,    37,    48,  -278,
    -278,    28,    33,   154,    59,    61,   121,  -278,  -278,    66,
      61,    71,  -278,  -278,  -278,  -278,  -278,  -278,   171,  -278,
      61,    74,    55,    78,  -278,    55,   125,  -278,  -278,  -278,
    -278,   256,   163,   158,    61,  -278,   104,  -278,  -278,   171,
      38,  -278,  -278,   125,  -278,   110,    61,  -278,   112,    61,
     114,  -278,  -278,  -278,  -278,  -278,  -278,   186,   195,  -278,
     128,  -278,  -278,    72,   131,  -278,  -278,  -278,   197,   256,
     186,  -278,  -278,  -278,  -278,   134,  -278,  -278,  -278,   170,
     148,   156,   157,    74,   159,    61,   218,  -278,   213,   161,
    -278,   181,   128,  -278,   181,  -278,  -278,  -278,  -278,  -278,
    -278,   173,   153,   167,  -278,  -278,   -35,  -278,   343,  -278,
    -278,  -278,  -278,  -278,   310,  -278,  -278,  -278,   172,   162,
     218,   216,   218,     9,   187,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,    44,   258,    58,  -278,   256,  -278,   263,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
     229,   269,   218,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,   218,  -278,   218,  -278,   193,  -278,  -278,  -278,   204,
    -278,  -278,  -278,  -278,   218,   202,   208,  -278,   523,   220,
    -278,   221,   222,   278,   225,   224,   226,   230,   186,   218,
     433,  -278,   239,   239,   235,   317,  -278,   245,  -278,  -278,
    -278,   247,    61,    21,  -278,   186,  -278,  -278,  -278,   253,
     433,  -278,  -278,   263,   213,  -278,   252,   433,   213,  -278,
     218,   262,   262,   262,   248,  -278,   218,   262,   286,   261,
     270,   274,   251,  -278,   257,   218,  -278,   265,  -278,   186,
    -278,    74,   276,   275,   352,  -278,  -278,   294,   343,   239,
    -278,  -278,  -278,   239,   281,  -278,  -278,  -278,  -278,   340,
     340,  -278,   300,   282,  -278,   287,   288,   107,   411,   239,
     299,  -278,   293,   213,  -278,    -6,  -278,  -278,  -278,  -278,
    -278,  -278,   405,   290,   523,   239,   262,  -278,  -278,   291,
     140,   306,   326,   119,  -278,   298,   107,   302,   329,   186,
     258,   239,  -278,  -278,  -278,   330,    74,   294,   300,   218,
    -278,  -278,  -278,   239,   218,  -278,  -278,   262,   378,   213,
    -278,  -278,   332,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
     181,  -278,  -278,  -278,  -278,  -278,  -278,    61,  -278,    21,
     485,  -278,   405,  -278,  -278,  -278,  -278,  -278,   262,  -278,
    -278,  -278,  -278,  -278,  -278
  };

  const unsigned char
  JavaParser::yydefact_[] =
  {
     235,     0,     0,   237,     2,     4,     0,     1,     0,   175,
       0,   234,     0,   174,     0,     0,   175,     0,   175,   242,
       3,   237,     0,     0,     0,     0,   215,   240,   239,     0,
       0,     0,   238,   236,   200,   199,   229,   228,   196,   209,
       0,     0,     0,   212,   230,     0,   196,   189,   187,   186,
     188,   196,   191,   193,     0,   207,     0,   214,   216,   196,
       0,   220,   223,   196,   226,     0,     0,   213,     0,     0,
       0,   206,   201,   190,   194,   192,   195,    11,     0,   219,
       0,   224,   225,     0,     0,   233,   211,   232,     0,   196,
      11,     9,   204,   217,   218,     0,    78,    46,    47,    45,
       0,     0,     0,     0,     0,     0,    45,   138,     0,     0,
      81,     0,     0,   140,     0,   133,   131,   132,   134,   135,
     136,     0,     0,     0,   203,    10,   119,   139,    94,    42,
      41,    40,    43,    44,     0,   171,   170,   173,     0,     0,
      45,     0,    45,     0,     0,     7,    82,   130,   142,   144,
     143,   137,   222,     0,    45,     0,   180,   196,   120,     0,
      21,    22,    20,    18,    19,    15,    14,    63,    65,    64,
      28,    29,    66,    67,    69,    70,    68,    71,    72,    73,
      31,    32,    30,    16,    17,    27,    26,    23,    24,    25,
      62,     0,    45,    88,    33,    34,    35,    39,    38,    36,
      37,    45,    93,    45,    79,   123,    83,    91,    58,    61,
      56,    57,    54,    55,    45,    51,    50,    53,    75,     0,
     145,     0,     0,     0,     0,     0,     0,     0,    11,    45,
      45,   100,    13,    13,     0,     0,   116,     0,   105,   104,
     118,     0,   117,     0,   205,    11,    87,   126,    84,     0,
      45,    92,   125,     0,     0,    59,     0,    45,     0,    52,
      45,     0,     0,     0,   120,   124,    45,     0,     0,     0,
       0,     0,   106,   109,     0,    45,    80,     6,   198,    11,
     197,     0,     0,     0,     0,   178,   181,   119,    94,    13,
      89,   122,    60,    13,     0,    49,    74,   146,   147,   149,
     149,   156,     0,     0,   157,     0,     0,   169,    45,    13,
       0,   101,     0,     0,     8,   112,   185,   183,   179,   176,
     121,    85,    99,     0,    76,    13,     0,   151,   150,     0,
       0,     0,     0,     0,   166,     0,   169,     0,     0,    11,
      45,    13,     5,   111,   115,     0,     0,   119,     0,    45,
      98,    86,    95,    13,    45,    48,   148,     0,     0,     0,
     153,   152,     0,   159,   158,   164,   161,   162,   163,   165,
       0,   168,   160,   103,   102,   108,    12,     0,   184,     0,
       0,    96,    99,    77,   155,   129,   127,   128,     0,   167,
     114,   177,    97,    90,   154
  };

  const short
  JavaParser::yypgoto_[] =
  {
    -278,  -278,    25,  -278,  -104,  -278,   -30,   -83,  -227,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -114,  -278,  -278,  -119,
    -278,  -278,  -146,  -277,  -278,  -278,   -96,  -278,  -278,   129,
    -278,  -278,  -278,    40,    34,   -91,  -278,   264,    81,  -278,
    -220,  -278,    45,  -278,   200,  -260,  -278,  -278,  -147,  -278,
    -117,  -278,  -278,   -82,  -109,  -278,   -60,  -127,  -246,   143,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
     111,  -278,  -278,  -278,    67,  -278,  -278,  -278,  -278,  -278,
     395,   420,  -278,  -278,    14,   410,  -278,   -71,   -19,  -278,
     415,  -278,  -278,    17,  -278,   434,   365,  -278,  -278,   356,
     435,  -278,  -278,  -278,  -278,   458,   472,   464,  -278
  };

  const short
  JavaParser::yydefgoto_[] =
  {
       0,     2,    77,   314,   215,   233,   235,    91,   276,   194,
     195,   196,   197,   198,   199,   200,   349,   133,   134,   108,
     216,   259,   217,   218,   255,   203,   238,   109,   128,   204,
     288,   250,   323,   350,   351,   110,   231,   272,   273,   310,
     274,   344,   236,   345,   237,   156,   205,   245,   206,   224,
     352,   360,   361,   297,   112,   113,   298,   221,   299,   327,
     115,   362,   116,   117,   118,   119,   120,   369,   335,   336,
     337,   137,   121,    14,   286,   347,   157,   243,   242,   346,
      52,    53,    74,    76,    54,    70,    15,    71,    72,   126,
      56,    26,    67,    44,    41,    83,    94,    16,    63,    64,
      65,    17,    31,    18,     3,     9,    27,    28,     4
  };

  const short
  JavaParser::yytable_[] =
  {
      82,   111,   148,   135,   146,   150,   277,   125,   136,   202,
     144,   207,   246,   225,   201,   227,   300,   301,   124,    55,
     228,   304,   283,   114,    78,   329,     6,   320,   154,   111,
     290,   343,   111,    12,    34,    20,    35,   294,    29,    88,
      55,   155,   220,   141,   220,   234,   220,     5,  -241,     1,
      39,   114,    24,    30,   114,    43,    60,    57,  -221,   241,
      69,  -182,   322,   239,     5,    43,   324,    25,  -210,    61,
    -221,   380,     8,    95,  -113,    96,   265,    69,    97,    98,
     356,   229,   339,    86,    99,   230,   244,   379,   338,     7,
     100,    43,   101,   102,   103,   104,   249,    22,   355,   247,
      23,   284,   285,    10,   260,   251,   291,   252,   292,   223,
     105,   384,   295,    13,   376,  -231,    58,    11,   256,    81,
    -221,  -117,  -221,   365,  -221,    13,   382,   366,    21,  -210,
     143,   333,   334,   271,  -227,  -182,    62,    38,    40,   239,
      47,   306,   394,   145,    42,   270,    97,    98,   106,    45,
      58,  -141,    58,   107,    60,    36,  -221,    37,    66,   239,
     367,   368,   287,   222,   296,     5,   239,    61,  -221,   202,
     303,   207,   220,   219,   201,   -45,   -45,   -45,    47,   312,
     -45,   -45,    95,    79,    96,    46,    47,    97,    98,    85,
      48,    87,    49,    99,    50,    89,   315,    90,    92,   100,
     123,   101,   102,   103,   104,  -141,  -141,    93,   105,   342,
     354,   359,   122,   -45,   -45,   127,   145,   239,  -221,   105,
    -221,   316,  -221,    48,   138,    49,   358,    50,   129,   130,
     129,   130,   139,   140,    62,   142,    48,   226,    49,   385,
      50,   386,   147,   153,   131,   132,   131,   132,   -45,   239,
    -208,  -172,    51,   381,   151,   387,   374,   106,   383,    58,
    -141,   389,   107,    95,   232,    96,   158,   105,    97,    98,
      46,    47,   248,   253,    99,   254,   129,   130,   257,   258,
     100,   264,   101,   102,   103,   104,   378,   305,   111,   -45,
     -45,   -45,   131,   132,   -45,   -45,   105,   261,   262,   263,
     105,   267,   268,   145,   208,   209,   266,   269,   210,   211,
     114,   275,   278,   145,   208,   209,   129,   130,   210,   211,
     279,    48,   280,    49,   281,    50,   289,   -45,   -45,   293,
     302,  -107,   131,   132,   311,  -202,   313,    51,   106,   307,
      58,   212,   213,   107,   129,   130,   158,   309,   308,    97,
      98,   212,   213,   317,   159,   319,   318,   154,   325,   326,
     131,   132,   -45,   330,   331,   332,   341,   353,   357,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   340,
     370,   372,   170,   171,    97,    98,   214,   363,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   364,   373,   388,
     377,   167,   168,   169,   191,   192,   393,   321,   240,   193,
     392,   375,   390,   172,   173,   174,   175,   176,   177,   178,
     179,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   190,   282,   328,   170,   171,   391,   371,    75,   105,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   129,
     130,   105,    73,    84,    80,    59,   348,   149,   152,    33,
      68,    19,    32,     0,     0,   131,   132,     0,     0,     0,
    -110,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   132,     0,
    -110,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,     0,     0,   170,   171,     0,     0,     0,     0,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   160,
     161,   162,   163,   164,   165,   166,     0,     0,     0,     0,
       0,     0,   170,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189
  };

  const short
  JavaParser::yycheck_[] =
  {
      60,    83,   111,    99,   108,   114,   233,    90,    99,   128,
     106,   128,   159,   140,   128,   142,   262,   263,    89,    38,
      11,   267,     1,    83,    54,   302,     1,   287,    63,   111,
     250,    37,   114,     8,     1,    10,     3,   257,     1,    69,
      59,    76,   138,   103,   140,     1,   142,     3,     0,    43,
      25,   111,     1,    16,   114,    30,     1,    40,     3,     1,
      46,     3,   289,   154,     3,    40,   293,    16,    17,    14,
      15,   348,    44,     1,    80,     3,   223,    63,     6,     7,
     326,    72,   309,    66,    12,    76,   157,   347,   308,     0,
      18,    66,    20,    21,    22,    23,   192,    10,   325,   190,
      13,    80,    81,    71,   218,   201,   253,   203,   254,   139,
      38,   357,   258,    65,   341,    78,    78,    81,   214,    81,
      65,    77,    67,     4,    69,    65,   353,     8,    81,    78,
     105,    24,    25,   229,    79,    77,    81,    78,    17,   230,
      15,   268,   388,     3,    78,   228,     6,     7,    76,    78,
      78,    79,    78,    81,     1,     1,     3,     3,    80,   250,
      41,    42,   245,     1,   260,     3,   257,    14,    15,   288,
     266,   288,   268,     1,   288,     3,     4,     5,    15,   275,
       8,     9,     1,    79,     3,    14,    15,     6,     7,    79,
      65,    79,    67,    12,    69,    81,   279,    11,     3,    18,
       3,    20,    21,    22,    23,    24,    25,    79,    38,   313,
     324,   330,    81,    41,    42,    81,     3,   308,    65,    38,
      67,   281,    69,    65,    76,    67,   330,    69,    58,    59,
      58,    59,    76,    76,    81,    76,    65,    21,    67,   358,
      69,   358,    81,    76,    74,    75,    74,    75,    76,   340,
      79,    81,    81,   349,    81,   359,   339,    76,   354,    78,
      79,   370,    81,     1,    77,     3,     3,    38,     6,     7,
      14,    15,     3,    80,    12,    71,    58,    59,    76,    71,
      18,     3,    20,    21,    22,    23,   346,     1,   370,     3,
       4,     5,    74,    75,     8,     9,    38,    77,    77,    77,
      38,    77,    76,     3,     4,     5,    81,    77,     8,     9,
     370,    72,    77,     3,     4,     5,    58,    59,     8,     9,
       3,    65,    77,    67,    77,    69,    73,    41,    42,    77,
      82,    80,    74,    75,    77,    79,    71,    81,    76,    78,
      78,    41,    42,    81,    58,    59,     3,    73,    78,     6,
       7,    41,    42,    77,    11,     3,    81,    63,    77,    19,
      74,    75,    76,    81,    77,    77,    73,    77,    77,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    80,
      82,    79,    39,    40,     6,     7,    76,    81,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    81,    79,    77,
      80,    33,    34,    35,    71,    72,   382,   288,   154,    76,
     380,   340,   377,    45,    46,    47,    48,    49,    50,    51,
      52,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    63,   242,   300,    39,    40,   379,   336,    53,    38,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    58,
      59,    38,    52,    63,    59,    41,    71,   112,   122,    21,
      45,     9,    18,    -1,    -1,    74,    75,    -1,    -1,    -1,
      79,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,
      77,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62
  };

  const unsigned char
  JavaParser::yystos_[] =
  {
       0,    43,    84,   187,   191,     3,    85,     0,    44,   188,
      71,    81,    85,    65,   156,   169,   180,   184,   186,   189,
      85,    81,    10,    13,     1,    16,   174,   189,   190,     1,
      16,   185,   190,   188,     1,     3,     1,     3,    78,    85,
      17,   177,    78,    85,   176,    78,    14,    15,    65,    67,
      69,    81,   163,   164,   167,   171,   173,   176,    78,   178,
       1,    14,    81,   181,   182,   183,    80,   175,   183,   167,
     168,   170,   171,   164,   165,   163,   166,    85,    89,    79,
     173,    81,   139,   178,   168,    79,   176,    79,    89,    81,
      11,    90,     3,    79,   179,     1,     3,     6,     7,    12,
      18,    20,    21,    22,    23,    38,    76,    81,   102,   110,
     118,   136,   137,   138,   139,   143,   145,   146,   147,   148,
     149,   155,    81,     3,   170,    90,   172,    81,   111,    58,
      59,    74,    75,   100,   101,   109,   118,   154,    76,    76,
      76,   139,    76,    85,   109,     3,    87,    81,   137,   179,
     137,    81,   182,    76,    63,    76,   128,   159,     3,    11,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      39,    40,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    71,    72,    76,    92,    93,    94,    95,    96,    97,
      98,    99,   102,   108,   112,   129,   131,   133,     4,     5,
       8,     9,    41,    42,    76,    87,   103,   105,   106,     1,
     109,   140,     1,    89,   132,   140,    21,   140,    11,    72,
      76,   119,    77,    88,     1,    89,   125,   127,   109,   118,
     120,     1,   161,   160,   170,   130,   131,   118,     3,   109,
     114,   109,   109,    80,    71,   107,   109,    76,    71,   104,
      99,    77,    77,    77,     3,   131,    81,    77,    76,    77,
      90,   109,   120,   121,   123,    72,    91,    91,    77,     3,
      77,    77,   127,     1,    80,    81,   157,    90,   113,    73,
     123,   131,   105,    77,   123,   105,   109,   136,   139,   141,
     141,   141,    82,   109,   141,     1,   140,    78,    78,    73,
     122,    77,   109,    71,    86,    90,   139,    77,    81,     3,
     128,   112,    91,   115,    91,    77,    19,   142,   142,   106,
      81,    77,    77,    24,    25,   151,   152,   153,   123,    91,
      80,    73,    87,    37,   124,   126,   162,   158,    71,    99,
     116,   117,   133,    77,    99,    91,   141,    77,    87,   102,
     134,   135,   144,    81,    81,     4,     8,    41,    42,   150,
      82,   153,    79,    79,    90,   121,    91,    80,   139,   128,
     106,   109,    91,   109,   141,   102,   133,    87,    77,   137,
     125,   157,   116,   117,   141
  };

  const unsigned char
  JavaParser::yyr1_[] =
  {
       0,    83,    84,    85,    85,    86,    86,    88,    87,    89,
      90,    90,    91,    91,    92,    92,    93,    93,    93,    93,
      94,    94,    94,    95,    95,    95,    96,    96,    97,    97,
      98,    98,    98,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   100,   100,   101,   101,   102,   102,   103,   104,
     104,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   109,   109,   111,   110,
     110,   110,   110,   112,   113,   112,   112,   112,   114,   115,
     112,   112,   112,   112,   112,   116,   116,   117,   117,   117,
     118,   119,   119,   119,   120,   120,   121,   122,   121,   123,
     123,   124,   124,   126,   125,   125,   127,   127,   128,   128,
     130,   129,   131,   131,   132,   133,   133,   134,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   137,   138,   138,   139,   140,   141,   141,   142,   142,
     143,   143,   144,   144,   145,   146,   146,   147,   148,   148,
     149,   150,   150,   150,   150,   151,   151,   152,   153,   153,
     154,   154,   154,   155,   156,   156,   158,   157,   157,   157,
     160,   159,   161,   162,   159,   159,   163,   163,   163,   164,
     165,   165,   166,   166,   167,   167,   167,   168,   168,   169,
     169,   170,   170,   171,   172,   171,   171,   173,   173,   174,
     174,   175,   175,   176,   177,   177,   178,   179,   180,   180,
     181,   181,   182,   182,   182,   182,   183,   183,   184,   184,
     185,   185,   186,   186,   187,   187,   188,   188,   189,   189,
     190,   190,   191
  };

  const signed char
  JavaParser::yyr2_[] =
  {
       0,     2,     1,     3,     1,     2,     0,     0,     4,     2,
       2,     0,     4,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     5,     2,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     2,     5,     7,     0,     3,
       4,     1,     2,     1,     0,     4,     5,     2,     0,     0,
       7,     1,     2,     1,     0,     1,     2,     3,     1,     0,
       3,     3,     5,     5,     1,     1,     1,     0,     4,     1,
       0,     1,     0,     0,     6,     4,     1,     0,     2,     0,
       0,     4,     3,     1,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     0,     2,     2,     3,     1,     1,     1,     2,     0,
       6,     6,     1,     1,     9,     8,     5,     5,     7,     7,
       7,     1,     1,     1,     1,     2,     1,     3,     2,     0,
       1,     1,     0,     2,     1,     0,     0,     5,     1,     2,
       0,     3,     0,     0,     6,     4,     1,     1,     1,     1,
       1,     0,     1,     0,     2,     2,     0,     6,     6,     3,
       3,     1,     0,     4,     0,     6,     2,     1,     0,     2,
       0,     2,     0,     2,     2,     0,     1,     1,     6,     5,
       1,     0,     4,     1,     2,     2,     1,     0,     3,     3,
       2,     0,     5,     5,     3,     0,     4,     0,     2,     2,
       1,     0,     3
  };




#if JAVACOMPILERDEBUG
  const short
  JavaParser::yyrline_[] =
  {
       0,   184,   184,   188,   191,   195,   198,   199,   199,   209,
     212,   216,   217,   221,   227,   227,   228,   228,   228,   228,
     229,   229,   229,   230,   230,   230,   231,   231,   232,   232,
     233,   233,   233,   234,   234,   235,   235,   235,   236,   236,
     237,   237,   237,   237,   238,   238,   239,   239,   244,   245,
     245,   249,   249,   254,   254,   254,   254,   254,   254,   254,
     255,   255,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   272,   273,   274,   275,   283,   283,
     287,   288,   289,   291,   292,   292,   295,   296,   297,   299,
     297,   303,   304,   305,   305,   307,   308,   310,   311,   311,
     316,   317,   317,   317,   321,   321,   324,   327,   327,   330,
     333,   340,   340,   345,   345,   349,   352,   352,   355,   358,
     364,   364,   379,   382,   383,   388,   389,   392,   393,   394,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     419,   419,   420,   421,   426,   431,   432,   432,   437,   437,
     438,   438,   439,   439,   440,   441,   441,   442,   443,   443,
     444,   445,   445,   445,   445,   446,   446,   447,   448,   448,
     449,   449,   449,   450,   460,   460,   461,   461,   465,   465,
     466,   466,   474,   481,   473,   483,   484,   484,   484,   485,
     486,   486,   487,   487,   488,   488,   488,   489,   489,   491,
     491,   492,   492,   493,   494,   494,   501,   502,   502,   506,
     506,   507,   507,   508,   509,   509,   511,   516,   521,   522,
     527,   527,   528,   528,   528,   528,   529,   529,   530,   530,
     531,   531,   532,   532,   539,   539,   540,   540,   541,   541,
     542,   542,   543
  };

  void
  JavaParser::yy_stack_print_ () const
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
  JavaParser::yy_reduce_print_ (int yyrule) const
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
#endif // JAVACOMPILERDEBUG

  JavaParser::symbol_kind_type
  JavaParser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,     2,     2,    62,    55,     2,
      76,    77,    60,    59,    80,    58,    71,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,    81,
      56,    63,    57,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,    54,    79,    75,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    64,    65,
      66,    67,    68,    69,    70
    };
    // Last valid token kind.
    const int code_max = 314;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // javacompiler
#line 2027 "java_parser.cc"

#line 547 "java_parser.yy"
 /*** Additional Code ***/

// error handling is linked to the driver here
// if the parser fails, it will call the error handler

void javacompiler::JavaParser::error(const JavaParser::location_type& l, const std::string& m)
{
    /* printf("Error: %s\n", m.c_str()); */
    driver.error(l, m);
}
