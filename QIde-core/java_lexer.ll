%{ /*** C/C++ Declarations ***/

#include <string>
#include <stdio.h>
#include <stdbool.h>

#include "java_lexer.hh"

/*
* To store error message
*/
#define MAX_LEN 256
char err_msg[MAX_LEN];

/*
* Comprehensive list of build errors
*/
#define BUILD_ERR_MAX_LEN (1<<20)
char err_build_msg[BUILD_ERR_MAX_LEN];

/*
* Indicate whether the build is successful or not
*/
bool build_success=true;

/*
* To store the current line number (UNNECESSARY since we used locations)
*/
// int yylineno = 0;


/* import the parser's token type into a local typedef */
typedef javacompiler::JavaParser::token token;
typedef javacompiler::JavaParser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type.  --> WE CAN USE THIS TO TRACK EOF*/ 
#define yyterminate() return token::END

/* 
* Needed to match escape characters 
*/
token_type convert_escape_representation(char c)
{
    char converted_char;
    switch(c)
    {
        case 'a':
            converted_char = '\a'; break;
        case 'b':
            converted_char = '\b'; break;
        case 'e':
            converted_char = '\e'; break;
        case 'f':
            converted_char = '\f'; break;
        case 'n':
            converted_char = '\n'; break; 
        case 'r':
            converted_char = '\r'; break;
        case 't':
            converted_char = '\t'; break;
        case 'v':
            converted_char = '\v'; break;
        default:
            converted_char = c;
    }

    return static_cast<token_type>(converted_char);
}

int representation_as_string(char *A,char *B)
{
    int n=strlen(A),m=0;
    int i=0;
    while(i<=n)
    {
        if(A[i]=='\\')
            B[m]=convert_escape_representation(A[++i]);
        else
            B[m]=A[i];
        i++;
        m++;
    }
    return 1;
}

%}


/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "JavaFlexLexer" */
%option prefix="Java"

/* the manual says "somewhat more optimized" */
%option batch

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. 
 * Then when a pattern is matched, its width is added to the end
 * column. !!!Code run each time a pattern is matched!!!.
 */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}


/*** Start Conditions ***/
%x comment
%x array_comment
%x array

/***  Regular Expressions Part ***/

alpha [a-z]|[A-Z]
numeric [0-9]
alpha_num {alpha}|{numeric}
decimal [1-9][0-9]*[lL]?|0[lL]?
binary 0[bB][0-1]+[lL]?
octal 0[0-7]*[lL]?
hexadecimal 0[xX][0-9a-fA-F]+[lL]?
real {numeric}+(\.{numeric}*)?(e{numeric}+)?[dDfF]?|\.{numeric}+(e{numeric}+)?[dDfF]?|{numeric}+(e{numeric}+)?[dDfF]
/* integer {decimal}|{binary}|{octal}|{hexadecimal} */
common_alphabet [^"'\n]
string_alphabet {common_alphabet}|\\\"|\'
char_alphabet {common_alphabet}|\\\'|\"
/* spacing [ \t\n] */
id ({alpha}|_)({alpha_num}|_)*

line_comment \/\/.+
/* multi_line_comment \/\*([^*]*|\*[^/]+)*\*\/ */
/* array_type \[{spacing}*\] */


%% /*** Rules Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

"++"    return token::INCREMENT;
"--"    return token::DECREMENT;
if  return token::IF;
else return token::ELSE;
class return token::CLASS;
interface return token::INTERFACE;
instanceof return token::INSTANCEOF;
new return token::NEW;
for return token::FOR;
while return token::WHILE;
do return token::DO;
switch return token::SWITCH;
case return token::CASE;
default return token::DEFAULT;
public return token::PUBLIC;
private return token::PRIVATE;
protected return token::PROTECTED;
static return token::STATIC;
abstract return token::ABSTRACT;
package return token::PACKAGE;
import return token::IMPORT;
return return token::RETURN;
extends return token::EXTENDS;
implements return token::IMPLEMENTS;
true return token::TRUE;
false return token::FALSE;
{id} {
    // printf("%s", yylval->text);

    // std::cout << std::string(yytext) << std::endl;
    strcpy(yylval->text,yytext);
    return token::ID;
}
"==" return token::EQ;
"!=" return token::NEQ;
"<=" return token::LEQ;
">=" return token::GEQ;
">>>=" return token::SELF_UNSIGNED_RIGHT_SHIFT;
"<<=" return token::SELF_LEFT_SHIFT;
">>=" return token::SELF_RIGHT_SHIFT;
"<<" return token::LEFT_SHIFT;
">>" return token::RIGHT_SHIFT;
">>>" return token::UNSIGNED_RIGHT_SHIFT;
"&&" return token::LOGICAL_AND;
"||" return token::LOGICAL_OR;
"..." return token::MORE_ARGS;
"+=" return token::SELF_PLUS;
"-=" return token::SELF_MINUS;
"*=" return token::SELF_TIMES;
"/=" return token::SELF_DIV;
"%=" return token::SELF_MOD;
"&=" return token::SELF_BITWISE_AND;
"|=" return token::SELF_BITWISE_OR;
"^=" return token::SELF_BITWISE_XOR;

{decimal} yylval->num=strtol(yytext,NULL,10);return token::INTEGER;
{octal} yylval->num=strtol(yytext+1,NULL,8);return token::INTEGER;
{hexadecimal} yylval->num=strtol(yytext+2,NULL,16); return token::INTEGER;
{binary} yylval->num=strtol(yytext+2,NULL,2); return token::INTEGER;
{real} yylval->real=strtod(yytext,NULL); return token::REAL;

[0-9]+{id} {
    /*
        Note on syntax_error : 
            This class derives from ‘std::runtime_error’.  Throw instances of
            it from the scanner or from the actions to raise parse errors.
            This is equivalent with first invoking ‘error’ (or yyerror in C) to report the
            location and message of the syntax error, and then to invoke
            ‘YYERROR’ to enter the error-recovery mode.
     */
    std::string message = "invalid identifier '" + std::string(yytext) + "'";
    throw javacompiler::JavaParser::syntax_error(*yylloc, message);
}

\"{string_alphabet}*\"|\"\"\"({string_alphabet}|\n)*\"\"\" {
    strcpy(yylval->text,yytext+1);
    yylval->text[strlen(yylval->text)-1]=0;
    representation_as_string(yylval->text,yylval->text);
    int m=strlen(yylval->text);
    for(int i=0;i<m;i++)
        if(yylval->text[i]=='\n')
            // yylineno++;
            yylloc->lines(yyleng); yylloc->step();

            
    return token::STRING;   
}

\'{char_alphabet}\' {
    yylval->character = yytext[0];
    return token::CHARACTER;
}

\'\\{char_alphabet}\' {
    yylval->character=convert_escape_representation(yytext[1]);
    return token::CHARACTER;
}

{line_comment}

"/*"                            {   BEGIN(comment);  }
<comment,array_comment>[^*\n]                 /* skip everything that's not "*" */
<comment,array_comment>"*"+[^*/\n]*           /* eat up ’*’s not followed by ’/’s */
<comment,array_comment>"\n"     {   
                                    //yylineno++;      /* skip (we can use this to count the number of lines later) */
                                    yylloc->lines(yyleng); yylloc->step();
                                }
<comment>"*"+"/"                {
                                    /*return to the main routine*/
                                    BEGIN(INITIAL);
                                }
<comment,array_comment><<EOF>>  {   
                                    BEGIN(INITIAL);
                                    std::string message = "comment not closed properly";                                    
                                    throw javacompiler::JavaParser::syntax_error(*yylloc, message);
                                }
<array_comment>"*"+"/"          {   BEGIN(array);    }


\[                              {   BEGIN(array);    }
<array>\n                       {   
                                    // yylineno++;      
                                    yylloc->lines(yyleng); yylloc->step();
                                }
<array>[ \t]+
<array>\]                       {   
                                   BEGIN(INITIAL);
                                   return token::ARRAY; 
                                }
<array>\/\*                     {  BEGIN(array_comment);}
<array>{line_comment}
<array>.                        {
                                    BEGIN(INITIAL);
                                    unput(yytext[0]);
                                    return static_cast<token_type>('[');
                                }
<array><<EOF>>                  { 
                                    BEGIN(INITIAL);
                                    std::string message = "unexpected end of file";
                                    throw javacompiler::JavaParser::syntax_error(*yylloc, message);
                                }



[+\-*/%{}()\[\]<>|&~=;.,^:] {
                                // return yytext[0];
                                return static_cast<token_type>(*yytext);
                            }


 /* gobble up white-spaces, each time blanks are matched, the begin cursor is moved onto the end
  * cursor to effectively ignore the blanks preceding tokens. */
[ \t\r]+ {
    yylloc->step();
}

 /* gobble up end-of-lines */
\n {
    // yylineno++;
    yylloc->lines(yyleng); yylloc->step();
    //return token::EOL;
}


 /* pass all other characters up to bison */
. {
    // return static_cast<token_type>(*yytext);

    std::string message = "lexical error, illegal character '" + std::string(yytext) + "'";
    throw javacompiler::JavaParser::syntax_error(*yylloc, message);
}


%% /*** Additional Code ***/

namespace javacompiler {

JavaLexer::JavaLexer(std::istream* in, std::ostream* out) :JavaFlexLexer(in, out)
{}

JavaLexer::~JavaLexer()
{}

}


/* This implementation of JavaFlexLexer::yylex() is required to fill the
 * vtable of the class JavaFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int JavaFlexLexer::yylex()
{
    std::cerr << "in JavaFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int JavaFlexLexer::yywrap()
{
    return 1;
}
