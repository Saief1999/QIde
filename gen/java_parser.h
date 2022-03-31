/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GEN_JAVA_PARSER_H_INCLUDED
# define YY_YY_GEN_JAVA_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    CHARACTER = 259,               /* CHARACTER  */
    STRING = 260,                  /* STRING  */
    INCREMENT = 261,               /* INCREMENT  */
    DECREMENT = 262,               /* DECREMENT  */
    INTEGER = 263,                 /* INTEGER  */
    REAL = 264,                    /* REAL  */
    CLASS = 265,                   /* CLASS  */
    ARRAY = 266,                   /* ARRAY  */
    RETURN = 267,                  /* RETURN  */
    INTERFACE = 268,               /* INTERFACE  */
    ABSTRACT = 269,                /* ABSTRACT  */
    STATIC = 270,                  /* STATIC  */
    EXTENDS = 271,                 /* EXTENDS  */
    IMPLEMENTS = 272,              /* IMPLEMENTS  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    FOR = 275,                     /* FOR  */
    WHILE = 276,                   /* WHILE  */
    DO = 277,                      /* DO  */
    SWITCH = 278,                  /* SWITCH  */
    CASE = 279,                    /* CASE  */
    DEFAULT = 280,                 /* DEFAULT  */
    LEFT_SHIFT = 281,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 282,             /* RIGHT_SHIFT  */
    UNSIGNED_RIGHT_SHIFT = 283,    /* UNSIGNED_RIGHT_SHIFT  */
    LEQ = 284,                     /* LEQ  */
    GEQ = 285,                     /* GEQ  */
    NEQ = 286,                     /* NEQ  */
    EQ = 287,                      /* EQ  */
    SELF_UNSIGNED_RIGHT_SHIFT = 288, /* SELF_UNSIGNED_RIGHT_SHIFT  */
    SELF_LEFT_SHIFT = 289,         /* SELF_LEFT_SHIFT  */
    SELF_RIGHT_SHIFT = 290,        /* SELF_RIGHT_SHIFT  */
    INSTANCEOF = 291,              /* INSTANCEOF  */
    MORE_ARGS = 292,               /* MORE_ARGS  */
    NEW = 293,                     /* NEW  */
    LOGICAL_AND = 294,             /* LOGICAL_AND  */
    LOGICAL_OR = 295,              /* LOGICAL_OR  */
    TRUE = 296,                    /* TRUE  */
    FALSE = 297,                   /* FALSE  */
    PACKAGE = 298,                 /* PACKAGE  */
    IMPORT = 299,                  /* IMPORT  */
    SELF_PLUS = 300,               /* SELF_PLUS  */
    SELF_MINUS = 301,              /* SELF_MINUS  */
    SELF_DIV = 302,                /* SELF_DIV  */
    SELF_MOD = 303,                /* SELF_MOD  */
    SELF_TIMES = 304,              /* SELF_TIMES  */
    SELF_BITWISE_AND = 305,        /* SELF_BITWISE_AND  */
    SELF_BITWISE_OR = 306,         /* SELF_BITWISE_OR  */
    SELF_BITWISE_XOR = 307,        /* SELF_BITWISE_XOR  */
    LOWEST = 308,                  /* LOWEST  */
    PUBLIC = 309,                  /* PUBLIC  */
    PRIVATE = 310,                 /* PRIVATE  */
    PROTECTED = 311                /* PROTECTED  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 1 "java.y"

    char text[256];
    long long num;
    double real;
    char character;

#line 127 "gen/java_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_GEN_JAVA_PARSER_H_INCLUDED  */
