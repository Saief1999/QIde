/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





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

#include "java_parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_CHARACTER = 4,                  /* CHARACTER  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_INCREMENT = 6,                  /* INCREMENT  */
  YYSYMBOL_DECREMENT = 7,                  /* DECREMENT  */
  YYSYMBOL_INTEGER = 8,                    /* INTEGER  */
  YYSYMBOL_REAL = 9,                       /* REAL  */
  YYSYMBOL_CLASS = 10,                     /* CLASS  */
  YYSYMBOL_ARRAY = 11,                     /* ARRAY  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_INTERFACE = 13,                 /* INTERFACE  */
  YYSYMBOL_ABSTRACT = 14,                  /* ABSTRACT  */
  YYSYMBOL_STATIC = 15,                    /* STATIC  */
  YYSYMBOL_EXTENDS = 16,                   /* EXTENDS  */
  YYSYMBOL_IMPLEMENTS = 17,                /* IMPLEMENTS  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_SWITCH = 23,                    /* SWITCH  */
  YYSYMBOL_CASE = 24,                      /* CASE  */
  YYSYMBOL_DEFAULT = 25,                   /* DEFAULT  */
  YYSYMBOL_LEFT_SHIFT = 26,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 27,               /* RIGHT_SHIFT  */
  YYSYMBOL_UNSIGNED_RIGHT_SHIFT = 28,      /* UNSIGNED_RIGHT_SHIFT  */
  YYSYMBOL_LEQ = 29,                       /* LEQ  */
  YYSYMBOL_GEQ = 30,                       /* GEQ  */
  YYSYMBOL_NEQ = 31,                       /* NEQ  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_SELF_UNSIGNED_RIGHT_SHIFT = 33, /* SELF_UNSIGNED_RIGHT_SHIFT  */
  YYSYMBOL_SELF_LEFT_SHIFT = 34,           /* SELF_LEFT_SHIFT  */
  YYSYMBOL_SELF_RIGHT_SHIFT = 35,          /* SELF_RIGHT_SHIFT  */
  YYSYMBOL_INSTANCEOF = 36,                /* INSTANCEOF  */
  YYSYMBOL_MORE_ARGS = 37,                 /* MORE_ARGS  */
  YYSYMBOL_NEW = 38,                       /* NEW  */
  YYSYMBOL_LOGICAL_AND = 39,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 40,                /* LOGICAL_OR  */
  YYSYMBOL_TRUE = 41,                      /* TRUE  */
  YYSYMBOL_FALSE = 42,                     /* FALSE  */
  YYSYMBOL_PACKAGE = 43,                   /* PACKAGE  */
  YYSYMBOL_IMPORT = 44,                    /* IMPORT  */
  YYSYMBOL_SELF_PLUS = 45,                 /* SELF_PLUS  */
  YYSYMBOL_SELF_MINUS = 46,                /* SELF_MINUS  */
  YYSYMBOL_SELF_DIV = 47,                  /* SELF_DIV  */
  YYSYMBOL_SELF_MOD = 48,                  /* SELF_MOD  */
  YYSYMBOL_SELF_TIMES = 49,                /* SELF_TIMES  */
  YYSYMBOL_SELF_BITWISE_AND = 50,          /* SELF_BITWISE_AND  */
  YYSYMBOL_SELF_BITWISE_OR = 51,           /* SELF_BITWISE_OR  */
  YYSYMBOL_SELF_BITWISE_XOR = 52,          /* SELF_BITWISE_XOR  */
  YYSYMBOL_53_ = 53,                       /* '^'  */
  YYSYMBOL_54_ = 54,                       /* '|'  */
  YYSYMBOL_55_ = 55,                       /* '&'  */
  YYSYMBOL_56_ = 56,                       /* '<'  */
  YYSYMBOL_57_ = 57,                       /* '>'  */
  YYSYMBOL_58_ = 58,                       /* '-'  */
  YYSYMBOL_59_ = 59,                       /* '+'  */
  YYSYMBOL_60_ = 60,                       /* '*'  */
  YYSYMBOL_61_ = 61,                       /* '/'  */
  YYSYMBOL_62_ = 62,                       /* '%'  */
  YYSYMBOL_63_ = 63,                       /* '='  */
  YYSYMBOL_LOWEST = 64,                    /* LOWEST  */
  YYSYMBOL_PUBLIC = 65,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 66,                   /* PRIVATE  */
  YYSYMBOL_PROTECTED = 67,                 /* PROTECTED  */
  YYSYMBOL_68_ = 68,                       /* '.'  */
  YYSYMBOL_69_ = 69,                       /* '['  */
  YYSYMBOL_70_ = 70,                       /* ']'  */
  YYSYMBOL_71_ = 71,                       /* '!'  */
  YYSYMBOL_72_ = 72,                       /* '~'  */
  YYSYMBOL_73_ = 73,                       /* '('  */
  YYSYMBOL_74_ = 74,                       /* ')'  */
  YYSYMBOL_75_ = 75,                       /* '{'  */
  YYSYMBOL_76_ = 76,                       /* '}'  */
  YYSYMBOL_77_ = 77,                       /* ','  */
  YYSYMBOL_78_ = 78,                       /* ';'  */
  YYSYMBOL_79_ = 79,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 80,                  /* $accept  */
  YYSYMBOL_start = 81,                     /* start  */
  YYSYMBOL_nested_id = 82,                 /* nested_id  */
  YYSYMBOL_opt_var_access = 83,            /* opt_var_access  */
  YYSYMBOL_var = 84,                       /* var  */
  YYSYMBOL_type = 85,                      /* type  */
  YYSYMBOL_opt_array_type = 86,            /* opt_array_type  */
  YYSYMBOL_opt_array = 87,                 /* opt_array  */
  YYSYMBOL_equality_operator = 88,         /* equality_operator  */
  YYSYMBOL_order_operator = 89,            /* order_operator  */
  YYSYMBOL_shift_operator = 90,            /* shift_operator  */
  YYSYMBOL_multiplicative_operator = 91,   /* multiplicative_operator  */
  YYSYMBOL_additive_operator = 92,         /* additive_operator  */
  YYSYMBOL_logical_operator = 93,          /* logical_operator  */
  YYSYMBOL_bitwise_operator = 94,          /* bitwise_operator  */
  YYSYMBOL_binary_operator = 95,           /* binary_operator  */
  YYSYMBOL_unary_operator = 96,            /* unary_operator  */
  YYSYMBOL_opt_unary_operator = 97,        /* opt_unary_operator  */
  YYSYMBOL_unary_special_operator = 98,    /* unary_special_operator  */
  YYSYMBOL_fn_call = 99,                   /* fn_call  */
  YYSYMBOL_opt_var_fn_access = 100,        /* opt_var_fn_access  */
  YYSYMBOL_var_fn = 101,                   /* var_fn  */
  YYSYMBOL_val = 102,                      /* val  */
  YYSYMBOL_opt_string_access = 103,        /* opt_string_access  */
  YYSYMBOL_assignment_operator = 104,      /* assignment_operator  */
  YYSYMBOL_expression = 105,               /* expression  */
  YYSYMBOL_statement_s0 = 106,             /* statement_s0  */
  YYSYMBOL_statement_s1 = 107,             /* statement_s1  */
  YYSYMBOL_rhs = 108,                      /* rhs  */
  YYSYMBOL_statement_s2 = 109,             /* statement_s2  */
  YYSYMBOL_new_expression = 110,           /* new_expression  */
  YYSYMBOL_new_initialisation = 111,       /* new_initialisation  */
  YYSYMBOL_assignable_expression = 112,    /* assignable_expression  */
  YYSYMBOL_obligatory_args = 113,          /* obligatory_args  */
  YYSYMBOL_args = 114,                     /* args  */
  YYSYMBOL_opt_variadic = 115,             /* opt_variadic  */
  YYSYMBOL_obligatory_formal_args = 116,   /* obligatory_formal_args  */
  YYSYMBOL_formal_args = 117,              /* formal_args  */
  YYSYMBOL_opt_assignment = 118,           /* opt_assignment  */
  YYSYMBOL_var_declarations = 119,         /* var_declarations  */
  YYSYMBOL_statement_declarative = 120,    /* statement_declarative  */
  YYSYMBOL_assignment = 121,               /* assignment  */
  YYSYMBOL_assignment_statement = 122,     /* assignment_statement  */
  YYSYMBOL_statement_pm_1 = 123,           /* statement_pm_1  */
  YYSYMBOL_statement = 124,                /* statement  */
  YYSYMBOL_opt_statement_seq = 125,        /* opt_statement_seq  */
  YYSYMBOL_statement_seq = 126,            /* statement_seq  */
  YYSYMBOL_block = 127,                    /* block  */
  YYSYMBOL_condition = 128,                /* condition  */
  YYSYMBOL_conditional_body = 129,         /* conditional_body  */
  YYSYMBOL_opt_else_statement = 130,       /* opt_else_statement  */
  YYSYMBOL_if_statement = 131,             /* if_statement  */
  YYSYMBOL_for_updating_statement = 132,   /* for_updating_statement  */
  YYSYMBOL_for_statement = 133,            /* for_statement  */
  YYSYMBOL_range_for_statement = 134,      /* range_for_statement  */
  YYSYMBOL_while_statement = 135,          /* while_statement  */
  YYSYMBOL_do_while_statement = 136,       /* do_while_statement  */
  YYSYMBOL_switch_statement = 137,         /* switch_statement  */
  YYSYMBOL_case_val = 138,                 /* case_val  */
  YYSYMBOL_switch_label = 139,             /* switch_label  */
  YYSYMBOL_case_block = 140,               /* case_block  */
  YYSYMBOL_switch_body = 141,              /* switch_body  */
  YYSYMBOL_opt_return_expression = 142,    /* opt_return_expression  */
  YYSYMBOL_return_statement = 143,         /* return_statement  */
  YYSYMBOL_cls_modifier = 144,             /* cls_modifier  */
  YYSYMBOL_cls_attr_more = 145,            /* cls_attr_more  */
  YYSYMBOL_cls_attr_sign = 146,            /* cls_attr_sign  */
  YYSYMBOL_fn_access_modifier = 147,       /* fn_access_modifier  */
  YYSYMBOL_fn_static_modifier = 148,       /* fn_static_modifier  */
  YYSYMBOL_fn_opt_static_modifier = 149,   /* fn_opt_static_modifier  */
  YYSYMBOL_fn_opt_access_modifier = 150,   /* fn_opt_access_modifier  */
  YYSYMBOL_fn_modifier = 151,              /* fn_modifier  */
  YYSYMBOL_fn_declaration = 152,           /* fn_declaration  */
  YYSYMBOL_cls_declaration = 153,          /* cls_declaration  */
  YYSYMBOL_cls_info_opt_more = 154,        /* cls_info_opt_more  */
  YYSYMBOL_cls_info = 155,                 /* cls_info  */
  YYSYMBOL_opt_cls_info = 156,             /* opt_cls_info  */
  YYSYMBOL_opt_extends = 157,              /* opt_extends  */
  YYSYMBOL_more_interface_list = 158,      /* more_interface_list  */
  YYSYMBOL_interface_list = 159,           /* interface_list  */
  YYSYMBOL_opt_implements = 160,           /* opt_implements  */
  YYSYMBOL_cls_definition = 161,           /* cls_definition  */
  YYSYMBOL_opt_abstract = 162,             /* opt_abstract  */
  YYSYMBOL_interface_info = 163,           /* interface_info  */
  YYSYMBOL_opt_interface_info = 164,       /* opt_interface_info  */
  YYSYMBOL_interface_declaration = 165,    /* interface_declaration  */
  YYSYMBOL_opt_interface_extends = 166,    /* opt_interface_extends  */
  YYSYMBOL_interface_definition = 167,     /* interface_definition  */
  YYSYMBOL_opt_pkg_declaration = 168,      /* opt_pkg_declaration  */
  YYSYMBOL_pkg_import = 169,               /* pkg_import  */
  YYSYMBOL_type_definitions = 170,         /* type_definitions  */
  YYSYMBOL_type_definitions_more = 171,    /* type_definitions_more  */
  YYSYMBOL_main_program = 172              /* main_program  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 7 "java.y"

    #include <stdbool.h>
    #include <stdio.h>

#line 280 "gen/java_parser.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   614

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  385

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,     2,     2,    62,    55,     2,
      73,    74,    60,    59,    77,    58,    68,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    78,
      56,    63,    57,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,    54,    76,    72,     2,     2,     2,
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
      66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    40,    40,    44,    44,    48,    48,    49,    53,    54,
      54,    55,    55,    61,    61,    62,    62,    62,    62,    63,
      63,    63,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    68,    68,    69,    69,    69,    70,    70,    71,
      71,    71,    71,    72,    72,    73,    73,    78,    79,    79,
      83,    83,    88,    88,    88,    88,    88,    88,    88,    89,
      89,    92,    93,    93,    93,    94,    94,    95,    95,    95,
      96,    96,    96,    99,   100,   101,   102,   110,   110,   110,
     110,   111,   111,   111,   112,   112,   112,   112,   112,   112,
     113,   113,   114,   114,   114,   119,   120,   120,   120,   123,
     123,   126,   126,   127,   127,   132,   132,   137,   137,   138,
     138,   141,   141,   146,   146,   147,   152,   152,   153,   154,
     154,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   179,   179,   180,   181,   182,   187,   192,   193,   193,
     198,   198,   199,   199,   200,   200,   201,   202,   202,   203,
     204,   204,   205,   206,   206,   206,   206,   207,   207,   208,
     209,   209,   210,   210,   210,   211,   220,   220,   221,   221,
     221,   222,   222,   222,   223,   223,   223,   224,   225,   225,
     226,   226,   227,   227,   227,   228,   228,   230,   230,   231,
     231,   232,   233,   234,   235,   235,   239,   239,   240,   240,
     241,   242,   242,   243,   243,   248,   248,   249,   249,   249,
     249,   250,   250,   251,   251,   252,   252,   253,   253,   260,
     260,   261,   261,   262,   262,   263,   263,   264
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "ID", "CHARACTER", "STRING",
  "INCREMENT", "DECREMENT", "INTEGER", "REAL", "CLASS", "ARRAY", "RETURN",
  "INTERFACE", "ABSTRACT", "STATIC", "EXTENDS", "IMPLEMENTS", "IF", "ELSE",
  "FOR", "WHILE", "DO", "SWITCH", "CASE", "DEFAULT", "LEFT_SHIFT",
  "RIGHT_SHIFT", "UNSIGNED_RIGHT_SHIFT", "LEQ", "GEQ", "NEQ", "EQ",
  "SELF_UNSIGNED_RIGHT_SHIFT", "SELF_LEFT_SHIFT", "SELF_RIGHT_SHIFT",
  "INSTANCEOF", "MORE_ARGS", "NEW", "LOGICAL_AND", "LOGICAL_OR", "TRUE",
  "FALSE", "PACKAGE", "IMPORT", "SELF_PLUS", "SELF_MINUS", "SELF_DIV",
  "SELF_MOD", "SELF_TIMES", "SELF_BITWISE_AND", "SELF_BITWISE_OR",
  "SELF_BITWISE_XOR", "'^'", "'|'", "'&'", "'<'", "'>'", "'-'", "'+'",
  "'*'", "'/'", "'%'", "'='", "LOWEST", "PUBLIC", "PRIVATE", "PROTECTED",
  "'.'", "'['", "']'", "'!'", "'~'", "'('", "')'", "'{'", "'}'", "','",
  "';'", "':'", "$accept", "start", "nested_id", "opt_var_access", "var",
  "type", "opt_array_type", "opt_array", "equality_operator",
  "order_operator", "shift_operator", "multiplicative_operator",
  "additive_operator", "logical_operator", "bitwise_operator",
  "binary_operator", "unary_operator", "opt_unary_operator",
  "unary_special_operator", "fn_call", "opt_var_fn_access", "var_fn",
  "val", "opt_string_access", "assignment_operator", "expression",
  "statement_s0", "statement_s1", "rhs", "statement_s2", "new_expression",
  "new_initialisation", "assignable_expression", "obligatory_args", "args",
  "opt_variadic", "obligatory_formal_args", "formal_args",
  "opt_assignment", "var_declarations", "statement_declarative",
  "assignment", "assignment_statement", "statement_pm_1", "statement",
  "opt_statement_seq", "statement_seq", "block", "condition",
  "conditional_body", "opt_else_statement", "if_statement",
  "for_updating_statement", "for_statement", "range_for_statement",
  "while_statement", "do_while_statement", "switch_statement", "case_val",
  "switch_label", "case_block", "switch_body", "opt_return_expression",
  "return_statement", "cls_modifier", "cls_attr_more", "cls_attr_sign",
  "fn_access_modifier", "fn_static_modifier", "fn_opt_static_modifier",
  "fn_opt_access_modifier", "fn_modifier", "fn_declaration",
  "cls_declaration", "cls_info_opt_more", "cls_info", "opt_cls_info",
  "opt_extends", "more_interface_list", "interface_list", "opt_implements",
  "cls_definition", "opt_abstract", "interface_info", "opt_interface_info",
  "interface_declaration", "opt_interface_extends", "interface_definition",
  "opt_pkg_declaration", "pkg_import", "type_definitions",
  "type_definitions_more", "main_program", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    94,   124,    38,    60,    62,    45,    43,
      42,    47,    37,    61,   308,   309,   310,   311,    46,    91,
      93,    33,   126,    40,    41,   123,   125,    44,    59,    58
};
#endif

#define YYPACT_NINF (-259)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-227)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    45,    34,     9,  -259,     2,    13,  -259,    45,    -3,
      45,  -259,    55,  -259,   104,    35,    24,    40,    24,  -259,
    -259,     9,   163,   168,    37,    45,   124,  -259,  -259,    71,
      45,    93,  -259,  -259,  -259,  -259,  -259,  -259,   166,  -259,
      45,   110,    89,    81,  -259,    89,    83,  -259,  -259,  -259,
    -259,   181,   176,    86,    45,  -259,   112,  -259,   166,    50,
    -259,  -259,    83,  -259,   114,    45,  -259,   117,    45,   123,
    -259,  -259,  -259,  -259,  -259,  -259,   194,   199,  -259,   134,
     270,  -259,  -259,   139,  -259,  -259,  -259,   216,   181,   194,
    -259,    -6,  -259,   144,   407,  -259,  -259,   149,   153,   155,
     161,   165,   177,    45,    65,   277,  -259,   238,   187,  -259,
     191,   178,  -259,  -259,  -259,  -259,  -259,  -259,  -259,   190,
     158,   182,  -259,  -259,   258,    39,    31,   181,  -259,   194,
     255,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,   234,   271,    65,   298,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,    65,  -259,    65,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,   440,  -259,  -259,  -259,   323,   173,    65,
      43,    65,    66,   201,   191,   203,   212,  -259,  -259,  -259,
    -259,  -259,  -259,    57,  -259,  -259,  -259,   211,   283,  -259,
     213,   224,   291,  -259,  -259,  -259,   241,  -259,  -259,   407,
     235,   232,  -259,   237,  -259,  -259,  -259,   251,  -259,  -259,
    -259,  -259,    65,   252,   265,  -259,   552,   260,  -259,   261,
     263,   336,   262,   267,   266,   273,   194,    65,   298,  -259,
     212,  -259,   191,    65,   276,   275,   280,   285,   194,   285,
    -259,   241,   274,  -259,   212,   258,   212,   238,  -259,   284,
     298,   238,  -259,    65,   300,   300,   300,     4,  -259,    65,
     300,   347,   296,   299,   306,   303,  -259,  -259,   309,   238,
    -259,  -259,  -259,  -259,    -9,  -259,    31,   255,   471,  -259,
     471,  -259,   212,   312,  -259,  -259,  -259,  -259,   361,   361,
    -259,   380,   313,  -259,   314,   175,   180,   212,  -259,   212,
    -259,  -259,    45,  -259,  -259,  -259,   380,    65,  -259,  -259,
    -259,  -259,   552,   212,   300,  -259,  -259,   316,   307,   358,
     136,  -259,   318,   175,   317,   322,   194,  -259,  -259,   514,
    -259,    65,  -259,  -259,   300,   444,   238,  -259,  -259,   327,
     328,   329,  -259,  -259,  -259,  -259,  -259,   191,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,   300,   326,
     330,  -259,  -259,  -259,  -259
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     220,     0,     0,   222,     2,     4,     0,     1,     0,   167,
       0,   219,     0,   166,     0,     0,   167,     0,   167,   227,
       3,   222,     0,     0,     0,     0,   202,   225,   224,     0,
       0,     0,   223,   221,   188,   187,   214,   213,   184,   196,
       0,     0,     0,   199,   215,     0,   184,   177,   175,   174,
     176,   184,   179,   181,     0,   194,     0,   201,   184,     0,
     205,   208,   184,   211,     0,     0,   200,     0,     0,     0,
     193,   189,   178,   182,   180,   183,    10,     0,   204,     0,
       0,   209,   210,     0,   218,   198,   217,     0,   184,    10,
       8,   112,   203,     0,    89,    45,    46,    44,     0,     0,
       0,     0,     0,     0,    44,     0,   129,     0,     0,    79,
       0,     0,   131,   124,   122,   123,   125,   126,   127,     0,
       0,     0,   191,     9,    44,     0,     0,   184,   130,    10,
       0,    20,    21,    19,    17,    18,    14,    13,    62,    64,
      63,    27,    28,    65,    66,    68,    69,    67,    70,    71,
      72,    30,    31,    29,    15,    16,    26,    25,    22,    23,
      24,    61,     0,    44,    44,    32,    33,    34,    38,    37,
      35,    36,    44,    88,    44,    77,    81,    86,    41,    40,
      39,    42,    43,     0,   163,   162,   165,     0,     0,    44,
       0,    44,     0,     0,     0,     0,    12,    80,   121,   133,
     136,   128,   207,     0,   100,    99,   111,     0,     0,   109,
       0,     0,     0,   169,   171,   192,   112,    84,   117,    89,
       0,   101,   103,     0,    87,   116,    57,    60,    55,    56,
      53,    54,    44,    50,    49,    52,    74,     0,   137,     0,
       0,     0,     0,     0,     0,     0,    10,    44,    44,    95,
      12,   135,     0,    44,     6,     0,     0,     0,    10,     0,
     170,   112,   114,    82,    12,    44,    12,     0,    58,     0,
      44,     0,    51,    44,     0,     0,     0,    10,   115,    44,
       0,     0,     0,     0,     0,     0,    78,   134,     0,     0,
       7,   186,   185,   173,   106,   172,     0,     0,    94,   102,
      94,    59,    12,     0,    48,    73,   138,   139,   141,   141,
     148,     0,     0,   149,     0,   161,    44,    12,    96,    12,
       5,   105,     0,   108,   168,   113,     0,    44,    93,    83,
      90,    85,    75,    12,     0,   143,   142,     0,     0,     0,
       0,   158,     0,   161,     0,     0,    10,    11,   107,     0,
      91,    44,    47,   140,     0,     0,     0,   145,   144,     0,
       0,     0,   156,   153,   154,   155,   157,     0,   160,   152,
      98,    97,    92,    76,   147,   120,   118,   119,     0,     0,
       0,   159,   146,   151,   150
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -259,  -259,    29,  -259,  -103,   -45,   -76,  -231,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,   -89,  -259,  -259,   -93,  -259,
    -259,  -133,  -204,  -259,  -259,   -90,  -259,   186,    58,    92,
     -86,  -259,   282,   146,  -223,  -259,    87,   209,  -187,  -122,
    -259,   -92,  -259,  -259,  -258,  -107,   -84,   -53,  -179,  -249,
     106,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,    76,  -259,  -259,  -259,   127,  -259,   367,   372,  -259,
    -259,    33,   363,  -259,   -16,    42,   368,  -259,  -259,   -20,
    -259,  -259,  -259,   308,   382,  -259,  -259,  -259,  -259,   411,
     462,   454,  -259
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,    76,   290,   233,   208,   216,   254,   165,   166,
     167,   168,   169,   170,   171,   327,   182,   183,   107,   234,
     272,   235,   236,   268,   174,   204,   108,   175,   328,   329,
     109,   249,   221,   222,   223,   323,   209,   210,   126,   176,
     242,   330,   357,   358,   110,   111,   112,   307,   239,   308,
     335,   113,   359,   114,   115,   116,   117,   118,   366,   342,
     343,   344,   186,   119,    14,   214,   127,    52,    53,    73,
      75,    54,    69,    15,    70,    71,    56,    26,    66,    44,
      41,    16,    62,    63,    64,    17,    31,    18,     3,     9,
      27,    28,     4
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,   173,   177,   199,   197,   172,    82,   184,   217,    77,
     243,   185,   245,   123,   193,    89,   306,   306,   306,   286,
      57,   195,   306,    87,  -226,   285,   309,   310,   321,   262,
       6,   313,   211,   298,     7,   300,    24,    12,   205,    20,
     207,    29,     5,     1,    93,    85,    94,   303,     5,    95,
      96,    25,  -197,     8,    39,    97,    30,   124,   255,    43,
       5,    98,    13,    99,   100,   101,   102,   125,   322,    43,
      10,   332,   122,   220,   296,   218,   306,   246,   205,    68,
      55,   103,   224,   311,   225,   353,   346,   251,   347,    13,
      59,    11,  -206,   345,    43,    68,   306,   238,    47,   238,
      55,   238,   352,    60,  -206,   374,   244,   337,   212,   213,
    -197,   215,    38,  -110,    22,  -216,   104,    23,   105,   278,
     306,   106,   349,   178,   179,    80,   173,   177,    81,   382,
     172,  -110,   192,    21,   301,   247,   180,   181,   304,   248,
     362,    40,   269,   241,   363,   287,    42,   273,    48,    49,
      50,    48,    49,    50,  -206,  -206,  -206,   284,    65,    59,
     361,  -206,   205,   288,    34,  -212,    35,    61,    45,    36,
     283,    37,    60,  -206,   240,   325,     5,   364,   365,   205,
      46,    47,   294,   305,   205,    58,   320,   103,    78,   312,
      84,    47,    93,    86,    94,    46,    47,    95,    96,   340,
     341,    88,    91,    97,   293,    89,   295,   178,   179,    98,
      92,    99,   100,   101,   102,  -132,  -132,   120,   103,   121,
     180,   181,   128,  -206,  -206,  -206,   187,  -164,   188,   103,
     205,    48,    49,    50,   189,   355,    61,   350,   178,   179,
     190,   196,  -195,   351,    51,   356,    48,    49,    50,   238,
     191,   180,   181,   377,   200,   203,  -104,  -190,   129,    51,
     381,   373,   375,   376,   104,   198,   105,  -132,   201,   106,
     371,    93,   103,    94,   219,   250,    95,    96,    93,   252,
      94,   253,    97,    95,    96,   257,   258,   259,    98,    97,
      99,   100,   101,   102,   261,    98,   103,    99,   100,   101,
     102,    93,   260,    94,   124,   264,    95,    96,   103,   265,
     196,   266,    97,    95,    96,   103,   178,   179,    98,   267,
      99,   100,   101,   102,   237,   270,   -44,   -44,   -44,   180,
     181,   -44,   -44,   271,   274,   275,   103,   276,   103,   277,
     279,   280,   281,   104,   289,   105,  -132,   282,   106,   291,
     104,   297,   105,   194,   292,   106,   178,   179,   302,   360,
      80,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   314,   180,
     181,   315,  -104,   104,   316,    80,   317,   318,   106,   319,
     334,   178,   179,   196,   226,   227,   333,   339,   228,   229,
     354,   338,   331,   369,   180,   181,   -44,   367,   370,   -44,
     -44,   378,   379,   380,   383,   263,   206,   372,   384,   348,
     129,   299,   256,    95,    96,   336,   178,   179,   130,   368,
      74,   230,   231,   324,    72,    83,    79,    67,   202,   180,
     181,   -44,    33,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   196,   226,   227,   141,   142,   228,   229,
      95,    96,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    19,    32,     0,     0,   162,   163,   138,   139,   140,
     164,   230,   231,     0,     0,     0,     0,     0,     0,   143,
     144,   145,   146,   147,   148,   149,   150,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   161,     0,     0,
     141,   142,     0,   232,     0,     0,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,     0,     0,     0,     0,   326,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,   141,   142,     0,     0,     0,     0,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,     0,     0,
       0,   141,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160
};

static const yytype_int16 yycheck[] =
{
      76,    94,    94,   110,   107,    94,    59,    97,   130,    54,
     189,    97,   191,    89,   104,    11,   274,   275,   276,   250,
      40,   105,   280,    68,     0,   248,   275,   276,    37,   216,
       1,   280,     1,   264,     0,   266,     1,     8,   124,    10,
       1,     1,     3,    43,     1,    65,     3,   270,     3,     6,
       7,    16,    17,    44,    25,    12,    16,    63,     1,    30,
       3,    18,    65,    20,    21,    22,    23,    73,    77,    40,
      68,   302,    88,   163,   261,   161,   334,    11,   164,    46,
      38,    38,   172,    79,   174,   334,   317,   194,   319,    65,
       1,    78,     3,   316,    65,    62,   354,   187,    15,   189,
      58,   191,   333,    14,    15,   354,   190,   311,    77,    78,
      75,   127,    75,    74,    10,    75,    73,    13,    75,   241,
     378,    78,   326,    58,    59,    75,   219,   219,    78,   378,
     219,    74,   103,    78,   267,    69,    71,    72,   271,    73,
       4,    17,   232,   188,     8,   252,    75,   236,    65,    66,
      67,    65,    66,    67,    65,    66,    67,   247,    77,     1,
     339,     3,   248,   253,     1,    76,     3,    78,    75,     1,
     246,     3,    14,    15,     1,   297,     3,    41,    42,   265,
      14,    15,   258,   273,   270,    75,   289,    38,    76,   279,
      76,    15,     1,    76,     3,    14,    15,     6,     7,    24,
      25,    78,     3,    12,   257,    11,   259,    58,    59,    18,
      76,    20,    21,    22,    23,    24,    25,    78,    38,     3,
      71,    72,    78,    65,    66,    67,    73,    78,    73,    38,
     316,    65,    66,    67,    73,   338,    78,   327,    58,    59,
      75,     3,    76,   332,    78,   338,    65,    66,    67,   339,
      73,    71,    72,   356,    76,    73,    76,    76,     3,    78,
     367,   351,   355,   355,    73,    78,    75,    76,    78,    78,
     346,     1,    38,     3,     3,    74,     6,     7,     1,    76,
       3,    69,    12,     6,     7,    74,     3,    74,    18,    12,
      20,    21,    22,    23,     3,    18,    38,    20,    21,    22,
      23,     1,    78,     3,    63,    70,     6,     7,    38,    77,
       3,    74,    12,     6,     7,    38,    58,    59,    18,    68,
      20,    21,    22,    23,     1,    73,     3,     4,     5,    71,
      72,     8,     9,    68,    74,    74,    38,    74,    38,     3,
      78,    74,    76,    73,    68,    75,    76,    74,    78,    74,
      73,    77,    75,    76,    74,    78,    58,    59,    74,     1,
      75,     3,     4,     5,    41,    42,     8,     9,    21,    71,
      72,    75,    74,    73,    75,    75,    70,    74,    78,    70,
      19,    58,    59,     3,     4,     5,    74,    73,     8,     9,
      74,    78,   300,    76,    71,    72,    73,    79,    76,    41,
      42,    74,    74,    74,    78,   219,   124,   349,    78,   322,
       3,   265,   203,     6,     7,   309,    58,    59,    11,   343,
      53,    41,    42,   296,    52,    62,    58,    45,   120,    71,
      72,    73,    21,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     3,     4,     5,    39,    40,     8,     9,
       6,     7,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     9,    18,    -1,    -1,    68,    69,    33,    34,    35,
      73,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    63,    -1,    -1,
      39,    40,    -1,    73,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    81,   168,   172,     3,    82,     0,    44,   169,
      68,    78,    82,    65,   144,   153,   161,   165,   167,   170,
      82,    78,    10,    13,     1,    16,   157,   170,   171,     1,
      16,   166,   171,   169,     1,     3,     1,     3,    75,    82,
      17,   160,    75,    82,   159,    75,    14,    15,    65,    66,
      67,    78,   147,   148,   151,   155,   156,   159,    75,     1,
      14,    78,   162,   163,   164,    77,   158,   164,   151,   152,
     154,   155,   148,   149,   147,   150,    82,    85,    76,   156,
      75,    78,   127,   152,    76,   159,    76,    85,    78,    11,
      86,     3,    76,     1,     3,     6,     7,    12,    18,    20,
      21,    22,    23,    38,    73,    75,    78,    98,   106,   110,
     124,   125,   126,   131,   133,   134,   135,   136,   137,   143,
      78,     3,   154,    86,    63,    73,   118,   146,    78,     3,
      11,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    39,    40,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    68,    69,    73,    88,    89,    90,    91,    92,
      93,    94,    95,    98,   104,   107,   119,   121,    58,    59,
      71,    72,    96,    97,   105,   110,   142,    73,    73,    73,
      75,    73,    82,   105,    76,   126,     3,    84,    78,   125,
      76,    78,   163,    73,   105,   110,   112,     1,    85,   116,
     117,     1,    77,    78,   145,   154,    86,   119,   110,     3,
     105,   112,   113,   114,   105,   105,     4,     5,     8,     9,
      41,    42,    73,    84,    99,   101,   102,     1,   105,   128,
       1,    85,   120,   128,   126,   128,    11,    69,    73,   111,
      74,   125,    76,    69,    87,     1,   117,    74,     3,    74,
      78,     3,   118,   107,    70,    77,    74,    68,   103,   105,
      73,    68,   100,    95,    74,    74,    74,     3,   119,    78,
      74,    76,    74,    86,   105,   114,    87,   125,   105,    68,
      83,    74,    74,   127,    86,   127,   118,    77,    87,   113,
      87,   101,    74,   114,   101,   105,   124,   127,   129,   129,
     129,    79,   105,   129,    21,    75,    75,    70,    74,    70,
      84,    37,    77,   115,   145,   119,    68,    95,   108,   109,
     121,   109,    87,    74,    19,   130,   130,   102,    78,    73,
      24,    25,   139,   140,   141,   114,    87,    87,   116,   102,
     105,    95,    87,   129,    74,    84,    98,   122,   123,   132,
       1,   128,     4,     8,    41,    42,   138,    79,   141,    76,
      76,    86,   108,   105,   129,    98,   121,    84,    74,    74,
      74,   125,   129,    78,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    82,    82,    83,    83,    84,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    89,    89,    90,
      90,    90,    91,    91,    91,    92,    92,    93,    93,    94,
      94,    94,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    96,    97,    97,    98,    98,    99,   100,   100,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   106,   106,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     108,   108,   109,   109,   109,   110,   111,   111,   111,   112,
     112,   113,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   120,   121,   121,   122,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   125,   125,   126,   126,   126,   127,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   134,   134,   135,
     136,   136,   137,   138,   138,   138,   138,   139,   139,   140,
     141,   141,   142,   142,   142,   143,   144,   144,   145,   145,
     145,   146,   146,   146,   147,   147,   147,   148,   149,   149,
     150,   150,   151,   151,   151,   152,   152,   153,   153,   154,
     154,   155,   155,   155,   156,   156,   157,   157,   158,   158,
     159,   160,   160,   161,   161,   162,   162,   163,   163,   163,
     163,   164,   164,   165,   165,   166,   166,   167,   167,   168,
     168,   169,   169,   170,   170,   171,   171,   172
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     2,     0,     3,     2,     2,
       0,     4,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     5,     2,     0,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     5,     7,     2,     4,     1,
       2,     1,     3,     5,     2,     5,     1,     2,     1,     0,
       1,     2,     3,     1,     0,     3,     3,     5,     5,     1,
       1,     1,     3,     1,     0,     1,     0,     5,     4,     1,
       0,     2,     0,     5,     3,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     0,     2,     4,     3,     3,     1,     1,     1,
       2,     0,     6,     6,     1,     1,     9,     8,     5,     5,
       9,     9,     7,     1,     1,     1,     1,     2,     1,     3,
       2,     0,     1,     1,     0,     2,     1,     0,     4,     1,
       2,     2,     4,     4,     1,     1,     1,     1,     1,     0,
       1,     0,     2,     2,     0,     6,     6,     3,     3,     1,
       0,     4,     5,     2,     1,     0,     2,     0,     2,     0,
       2,     2,     0,     6,     5,     1,     0,     4,     1,     2,
       2,     1,     0,     3,     3,     2,     0,     5,     5,     3,
       0,     4,     0,     2,     2,     1,     0,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

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

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          goto yyexhaustedlab;                                          \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

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
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




/* The kind of the lookahead of this context.  */
static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;

static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx)
{
  return yyctx->yytoken;
}

/* The location of the lookahead of this context.  */
static YYLTYPE *
yypcontext_location (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;

static YYLTYPE *
yypcontext_location (const yypcontext_t *yyctx)
{
  return yyctx->yylloc;
}

/* User defined function to report a syntax error.  */
static int
yyreport_syntax_error (const yypcontext_t *yyctx);

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* start: main_program  */
#line 40 "java.y"
                     {printf("GJ\n");}
#line 1998 "gen/java_parser.c"
    break;


#line 2002 "gen/java_parser.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken, &yylloc};
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        if (yyreport_syntax_error (&yyctx) == 2)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);

  return yyresult;
}

#line 265 "java.y"



void format_err(char *dest,yysymbol_kind_t symbol,bool preserve_semantics)
    {
        if(symbol==YYSYMBOL_YYEMPTY)
            return;
        if(!preserve_semantics) switch(symbol)
        {
            case YYSYMBOL_INTEGER:
            strcpy(dest,"integer");
            break;
            case YYSYMBOL_REAL:
                strcpy(dest,"real");
                break;
            case YYSYMBOL_ARRAY:
                strcpy(dest,"'[]'");
                break;
            case YYSYMBOL_ID:
                sprintf(dest,"identifier");
                break;
            case YYSYMBOL_YYEOF:
                sprintf(dest,"end of file");
                break;
            default:
                sprintf(dest,"%s",yysymbol_name(symbol));
                {
                    int m=strlen(dest);
                    for(int i=0;i<m;i++)
                        dest[i]=tolower(dest[i]);
                }
                break;
        }
        else switch(symbol)
        {
            case YYSYMBOL_INTEGER:
            sprintf(dest,"integer %d",yylval.num);
            break;
            case YYSYMBOL_REAL:
                sprintf(dest,"float/double %f",yylval.real);
                break;
            case YYSYMBOL_ARRAY:
                strcpy(dest,"'[]'");
                break;
            case YYSYMBOL_ID:
                sprintf(dest,"identifier '%s'",yylval.text);
                break;
            case YYSYMBOL_YYEOF:
                sprintf(dest,"end of file");
                break;
            default:
                sprintf(dest,"symbol %s",yysymbol_name(symbol));
                {
                    int m=strlen(dest);
                    for(int i=0;i<m;i++)
                        dest[i]=tolower(dest[i]);
                }
                break;
        }
    }
extern int yylineno;
static int
yyreport_syntax_error (const yypcontext_t *ctx)
{
   build_success=false;
  int res = 0;
//  YYLOCATION_PRINT (stderr, *yypcontext_location (ctx));
//yypcontext_location(ctx)->first_column
    fprintf(yyout,"syntax error near line %d:", yylineno);
    //Variable used to store formatted messages
    enum {MAX_LENTGTH = 256};
    char flag[MAX_LENTGTH];
    int first_line_len=strlen(flag);
  // Report the unexpected token.
  {
    yysymbol_kind_t lookahead = yypcontext_token (ctx);
    if (lookahead != YYSYMBOL_YYEMPTY) format_err(flag,lookahead,true);
    fprintf (yyout, " unexpected %s", flag);
  }

    // Report the tokens expected at this point.
  {
    enum { TOKENMAX = 5 };
    yysymbol_kind_t expected[TOKENMAX];
    int n = yypcontext_expected_tokens (ctx, expected, TOKENMAX);
    if (n < 0)
      // Forward errors to yyparse.
      res = n;
    else
      {
        for (int i = 0; i < n; ++i)
        {
            format_err(flag,expected[i],false);
            if(i==0)
                fprintf (yyout, "\n%32s %s", "expecting" , flag);
            else fprintf(yyout, " or %s",flag);
        }
      }
  }
  fprintf (yyout, "\n");
  return res;
}
