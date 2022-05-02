// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file java_parser.hh
 ** Define the javacompiler::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_JAVACOMPILER_JAVA_PARSER_HH_INCLUDED
# define YY_JAVACOMPILER_JAVA_PARSER_HH_INCLUDED


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef JAVACOMPILERDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define JAVACOMPILERDEBUG 1
#  else
#   define JAVACOMPILERDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define JAVACOMPILERDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined JAVACOMPILERDEBUG */

namespace javacompiler {
#line 190 "java_parser.hh"




  /// A Bison parser.
  class JavaParser
  {
  public:
#ifdef JAVACOMPILERSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define JAVACOMPILERSTYPE in C++, use %define api.value.type"
# endif
    typedef JAVACOMPILERSTYPE value_type;
#else
    /// Symbol semantic values.
    union value_type
    {
#line 64 "java_parser.yy"

    char text[256];
    long long num;
    double real;
    char character;

#line 215 "java_parser.hh"

    };
#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        JAVACOMPILEREMPTY = -2,
    END = 0,                       // "end of file"
    JAVACOMPILERerror = 256,       // error
    JAVACOMPILERUNDEF = 257,       // "invalid token"
    ID = 258,                      // "identifier"
    CHARACTER = 259,               // "character"
    STRING = 260,                  // "string"
    INCREMENT = 261,               // "++"
    DECREMENT = 262,               // "--"
    INTEGER = 263,                 // "integer"
    REAL = 264,                    // "real"
    CLASS = 265,                   // "class"
    ARRAY = 266,                   // "[]"
    RETURN = 267,                  // "return"
    INTERFACE = 268,               // "interface"
    ABSTRACT = 269,                // "abstract"
    STATIC = 270,                  // "static"
    EXTENDS = 271,                 // "extends"
    IMPLEMENTS = 272,              // "implements"
    IF = 273,                      // "if"
    ELSE = 274,                    // "else"
    FOR = 275,                     // "for"
    WHILE = 276,                   // "while"
    DO = 277,                      // "do"
    SWITCH = 278,                  // "switch"
    CASE = 279,                    // "case"
    DEFAULT = 280,                 // "default"
    LEFT_SHIFT = 281,              // "<<"
    RIGHT_SHIFT = 282,             // ">>"
    UNSIGNED_RIGHT_SHIFT = 283,    // ">>>"
    LEQ = 284,                     // "<="
    GEQ = 285,                     // ">="
    NEQ = 286,                     // "!="
    EQ = 287,                      // "=="
    SELF_UNSIGNED_RIGHT_SHIFT = 288, // SELF_UNSIGNED_RIGHT_SHIFT
    SELF_LEFT_SHIFT = 289,         // SELF_LEFT_SHIFT
    SELF_RIGHT_SHIFT = 290,        // SELF_RIGHT_SHIFT
    INSTANCEOF = 291,              // "instanceof"
    MORE_ARGS = 292,               // ","
    NEW = 293,                     // "new"
    LOGICAL_AND = 294,             // "&&"
    LOGICAL_OR = 295,              // "||"
    TRUE = 296,                    // "true"
    FALSE = 297,                   // "false"
    PACKAGE = 298,                 // "package"
    IMPORT = 299,                  // "import"
    SELF_PLUS = 300,               // SELF_PLUS
    SELF_MINUS = 301,              // SELF_MINUS
    SELF_DIV = 302,                // SELF_DIV
    SELF_MOD = 303,                // SELF_MOD
    SELF_TIMES = 304,              // SELF_TIMES
    SELF_BITWISE_AND = 305,        // SELF_BITWISE_AND
    SELF_BITWISE_OR = 306,         // SELF_BITWISE_OR
    SELF_BITWISE_XOR = 307,        // SELF_BITWISE_XOR
    LOWEST = 308,                  // LOWEST
    PUBLIC = 309,                  // PUBLIC
    PRIVATE = 311,                 // PRIVATE
    PROTECTED = 313                // PROTECTED
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 83, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_ID = 3,                                // "identifier"
        S_CHARACTER = 4,                         // "character"
        S_STRING = 5,                            // "string"
        S_INCREMENT = 6,                         // "++"
        S_DECREMENT = 7,                         // "--"
        S_INTEGER = 8,                           // "integer"
        S_REAL = 9,                              // "real"
        S_CLASS = 10,                            // "class"
        S_ARRAY = 11,                            // "[]"
        S_RETURN = 12,                           // "return"
        S_INTERFACE = 13,                        // "interface"
        S_ABSTRACT = 14,                         // "abstract"
        S_STATIC = 15,                           // "static"
        S_EXTENDS = 16,                          // "extends"
        S_IMPLEMENTS = 17,                       // "implements"
        S_IF = 18,                               // "if"
        S_ELSE = 19,                             // "else"
        S_FOR = 20,                              // "for"
        S_WHILE = 21,                            // "while"
        S_DO = 22,                               // "do"
        S_SWITCH = 23,                           // "switch"
        S_CASE = 24,                             // "case"
        S_DEFAULT = 25,                          // "default"
        S_LEFT_SHIFT = 26,                       // "<<"
        S_RIGHT_SHIFT = 27,                      // ">>"
        S_UNSIGNED_RIGHT_SHIFT = 28,             // ">>>"
        S_LEQ = 29,                              // "<="
        S_GEQ = 30,                              // ">="
        S_NEQ = 31,                              // "!="
        S_EQ = 32,                               // "=="
        S_SELF_UNSIGNED_RIGHT_SHIFT = 33,        // SELF_UNSIGNED_RIGHT_SHIFT
        S_SELF_LEFT_SHIFT = 34,                  // SELF_LEFT_SHIFT
        S_SELF_RIGHT_SHIFT = 35,                 // SELF_RIGHT_SHIFT
        S_INSTANCEOF = 36,                       // "instanceof"
        S_MORE_ARGS = 37,                        // ","
        S_NEW = 38,                              // "new"
        S_LOGICAL_AND = 39,                      // "&&"
        S_LOGICAL_OR = 40,                       // "||"
        S_TRUE = 41,                             // "true"
        S_FALSE = 42,                            // "false"
        S_PACKAGE = 43,                          // "package"
        S_IMPORT = 44,                           // "import"
        S_SELF_PLUS = 45,                        // SELF_PLUS
        S_SELF_MINUS = 46,                       // SELF_MINUS
        S_SELF_DIV = 47,                         // SELF_DIV
        S_SELF_MOD = 48,                         // SELF_MOD
        S_SELF_TIMES = 49,                       // SELF_TIMES
        S_SELF_BITWISE_AND = 50,                 // SELF_BITWISE_AND
        S_SELF_BITWISE_OR = 51,                  // SELF_BITWISE_OR
        S_SELF_BITWISE_XOR = 52,                 // SELF_BITWISE_XOR
        S_53_ = 53,                              // '^'
        S_54_ = 54,                              // '|'
        S_55_ = 55,                              // '&'
        S_56_ = 56,                              // '<'
        S_57_ = 57,                              // '>'
        S_58_ = 58,                              // '-'
        S_59_ = 59,                              // '+'
        S_60_ = 60,                              // '*'
        S_61_ = 61,                              // '/'
        S_62_ = 62,                              // '%'
        S_63_ = 63,                              // '='
        S_LOWEST = 64,                           // LOWEST
        S_PUBLIC = 65,                           // PUBLIC
        S_66_public_ = 66,                       // "public"
        S_PRIVATE = 67,                          // PRIVATE
        S_68_private_ = 68,                      // "private"
        S_PROTECTED = 69,                        // PROTECTED
        S_70_protected_ = 70,                    // "protected"
        S_71_ = 71,                              // '.'
        S_72_ = 72,                              // '['
        S_73_ = 73,                              // ']'
        S_74_ = 74,                              // '!'
        S_75_ = 75,                              // '~'
        S_76_ = 76,                              // '('
        S_77_ = 77,                              // ')'
        S_78_ = 78,                              // '{'
        S_79_ = 79,                              // '}'
        S_80_ = 80,                              // ','
        S_81_ = 81,                              // ';'
        S_82_ = 82,                              // ':'
        S_YYACCEPT = 83,                         // $accept
        S_start = 84,                            // start
        S_nested_id = 85,                        // nested_id
        S_opt_var_access = 86,                   // opt_var_access
        S_var = 87,                              // var
        S_88_1 = 88,                             // $@1
        S_type = 89,                             // type
        S_opt_array_type = 90,                   // opt_array_type
        S_opt_array = 91,                        // opt_array
        S_equality_operator = 92,                // equality_operator
        S_order_operator = 93,                   // order_operator
        S_shift_operator = 94,                   // shift_operator
        S_multiplicative_operator = 95,          // multiplicative_operator
        S_additive_operator = 96,                // additive_operator
        S_logical_operator = 97,                 // logical_operator
        S_bitwise_operator = 98,                 // bitwise_operator
        S_binary_operator = 99,                  // binary_operator
        S_unary_operator = 100,                  // unary_operator
        S_opt_unary_operator = 101,              // opt_unary_operator
        S_unary_special_operator = 102,          // unary_special_operator
        S_fn_call = 103,                         // fn_call
        S_opt_var_fn_access = 104,               // opt_var_fn_access
        S_var_fn = 105,                          // var_fn
        S_val = 106,                             // val
        S_opt_string_access = 107,               // opt_string_access
        S_assignment_operator = 108,             // assignment_operator
        S_expression = 109,                      // expression
        S_statement_s0 = 110,                    // statement_s0
        S_111_2 = 111,                           // $@2
        S_statement_s1 = 112,                    // statement_s1
        S_113_3 = 113,                           // $@3
        S_114_4 = 114,                           // $@4
        S_115_5 = 115,                           // $@5
        S_rhs = 116,                             // rhs
        S_statement_s2 = 117,                    // statement_s2
        S_new_expression = 118,                  // new_expression
        S_new_initialisation = 119,              // new_initialisation
        S_assignable_expression = 120,           // assignable_expression
        S_obligatory_args = 121,                 // obligatory_args
        S_122_6 = 122,                           // $@6
        S_args = 123,                            // args
        S_opt_variadic = 124,                    // opt_variadic
        S_obligatory_formal_args = 125,          // obligatory_formal_args
        S_126_7 = 126,                           // $@7
        S_formal_args = 127,                     // formal_args
        S_opt_assignment = 128,                  // opt_assignment
        S_var_declaration_body = 129,            // var_declaration_body
        S_130_8 = 130,                           // $@8
        S_var_declarations = 131,                // var_declarations
        S_statement_declarative = 132,           // statement_declarative
        S_assignment = 133,                      // assignment
        S_assignment_statement = 134,            // assignment_statement
        S_statement_pm_1 = 135,                  // statement_pm_1
        S_statement = 136,                       // statement
        S_opt_statement_seq = 137,               // opt_statement_seq
        S_statement_seq = 138,                   // statement_seq
        S_block = 139,                           // block
        S_condition = 140,                       // condition
        S_conditional_body = 141,                // conditional_body
        S_opt_else_statement = 142,              // opt_else_statement
        S_if_statement = 143,                    // if_statement
        S_for_updating_statement = 144,          // for_updating_statement
        S_for_statement = 145,                   // for_statement
        S_range_for_statement = 146,             // range_for_statement
        S_while_statement = 147,                 // while_statement
        S_do_while_statement = 148,              // do_while_statement
        S_switch_statement = 149,                // switch_statement
        S_case_val = 150,                        // case_val
        S_switch_label = 151,                    // switch_label
        S_case_block = 152,                      // case_block
        S_switch_body = 153,                     // switch_body
        S_opt_return_expression = 154,           // opt_return_expression
        S_return_statement = 155,                // return_statement
        S_cls_modifier = 156,                    // cls_modifier
        S_cls_attr_more = 157,                   // cls_attr_more
        S_158_9 = 158,                           // $@9
        S_cls_attr_sign = 159,                   // cls_attr_sign
        S_160_10 = 160,                          // $@10
        S_161_11 = 161,                          // $@11
        S_162_12 = 162,                          // $@12
        S_fn_access_modifier = 163,              // fn_access_modifier
        S_fn_static_modifier = 164,              // fn_static_modifier
        S_fn_opt_static_modifier = 165,          // fn_opt_static_modifier
        S_fn_opt_access_modifier = 166,          // fn_opt_access_modifier
        S_fn_modifier = 167,                     // fn_modifier
        S_fn_declaration = 168,                  // fn_declaration
        S_cls_declaration = 169,                 // cls_declaration
        S_cls_info_opt_more = 170,               // cls_info_opt_more
        S_cls_info = 171,                        // cls_info
        S_172_13 = 172,                          // $@13
        S_opt_cls_info = 173,                    // opt_cls_info
        S_opt_extends = 174,                     // opt_extends
        S_more_interface_list = 175,             // more_interface_list
        S_interface_list = 176,                  // interface_list
        S_opt_implements = 177,                  // opt_implements
        S_opening_bracket = 178,                 // opening_bracket
        S_closing_bracket = 179,                 // closing_bracket
        S_cls_definition = 180,                  // cls_definition
        S_opt_abstract = 181,                    // opt_abstract
        S_interface_info = 182,                  // interface_info
        S_opt_interface_info = 183,              // opt_interface_info
        S_interface_declaration = 184,           // interface_declaration
        S_opt_interface_extends = 185,           // opt_interface_extends
        S_interface_definition = 186,            // interface_definition
        S_opt_pkg_declaration = 187,             // opt_pkg_declaration
        S_pkg_import = 188,                      // pkg_import
        S_type_definitions = 189,                // type_definitions
        S_type_definitions_more = 190,           // type_definitions_more
        S_main_program = 191                     // main_program
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value (std::move (that.value))
        , location (std::move (that.location))
      {}
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);
      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t,
                    YY_MOVE_REF (location_type) l);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    YY_RVREF (value_type) v,
                    YY_RVREF (location_type) l);

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return JavaParser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {};

    /// Build a parser object.
    JavaParser (class Driver& driver_yyarg);
    virtual ~JavaParser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    JavaParser (const JavaParser&) = delete;
    /// Non copyable.
    JavaParser& operator= (const JavaParser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if JAVACOMPILERDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);



    class context
    {
    public:
      context (const JavaParser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const JavaParser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    JavaParser (const JavaParser&);
    /// Non copyable.
    JavaParser& operator= (const JavaParser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const unsigned char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if JAVACOMPILERDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 585,     ///< Last index in yytable_.
      yynnts_ = 109,  ///< Number of nonterminal symbols.
      yyfinal_ = 7 ///< Termination state number.
    };


    // User arguments.
    class Driver& driver;

  };


} // javacompiler
#line 1054 "java_parser.hh"




#endif // !YY_JAVACOMPILER_JAVA_PARSER_HH_INCLUDED
