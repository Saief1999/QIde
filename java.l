
%x comment
%x array_comment
%x array
%{
#include "java_parser.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 256
/*
* To store erros message
*/
char err_msg[MAX_LEN];
#define BUILD_ERR_MAX_LEN (1<<20)

/*
* Comprehensive list of build errors
*/
char err_build_msg[BUILD_ERR_MAX_LEN];
/*
* Indicate whether the build is successful or not
*/
bool build_success=true;

#ifndef NULL
#define NULL 0
#endif


 void yyerror (char const *s) {
     build_success=false;
   fprintf (yyout, "%s\n", s);
 }

char convert_escape_representation(char c)
{
    switch(c)
    {
        case 'a':
            return '\a';
        case 'b':
            return '\b';
        case 'e':
            return '\e';
        case 'f':
            return '\f';
        case 'n':
            return '\n';
        case 'r':
            return '\r';
        case 't':
            return '\t';
        case 'v':
            return '\v';
        default:
            return c;
    }
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

void reset_all()
{
	yylineno=1;
	build_success=true;
}

%}

alpha [a-z]|[A-Z]
numeric [0-9]
alpha_num {alpha}|{numeric}
decimal [1-9][0-9]*[lL]?|0[lL]?
binary 0[bB][0-1]+[lL]?
octal 0[0-7]*[lL]?
hexadecimal 0[xX][0-9a-fA-F]+[lL]?
real {numeric}+(\.{numeric}*)?(e{numeric}+)?[dDfF]?|\.{numeric}+(e{numeric}+)?[dDfF]?|{numeric}+(e{numeric}+)?[dDfF]
integer {decimal}|{binary}|{octal}|{hexadecimal}
common_alphabet [^"'\n]
string_alphabet {common_alphabet}|\\\"|\'
char_alphabet {common_alphabet}|\\\'|\"
spacing [ \t\n]
id ({alpha}|_)({alpha_num}|_)*

line_comment \/\/.+
multi_line_comment \/\*([^*]*|\*[^/]+)*\*\/
array_type \[{spacing}*\]
%%


"++"    return INCREMENT;
"--"    return DECREMENT;
if  return IF;
else return ELSE;
class return CLASS;
interface return INTERFACE;
instanceof return INSTANCEOF;
new return NEW;
for return FOR;
while return WHILE;
do return DO;
switch return SWITCH;
case return CASE;
default return DEFAULT;
public return PUBLIC;
private return PRIVATE;
protected return PROTECTED;
static return STATIC;
abstract return ABSTRACT;
package return PACKAGE;
import return IMPORT;
return return RETURN;
extends return EXTENDS;
implements return IMPLEMENTS;
true return TRUE;
false return FALSE;
{id} {
    strcpy(yylval.text,yytext);
    return ID;
}
"==" return EQ;
"!=" return NEQ;
"<=" return LEQ;
">=" return GEQ;
">>>=" return SELF_UNSIGNED_RIGHT_SHIFT;
"<<=" return SELF_LEFT_SHIFT;
">>=" return SELF_RIGHT_SHIFT;
"<<" return LEFT_SHIFT;
">>" return RIGHT_SHIFT;
">>>" return UNSIGNED_RIGHT_SHIFT;
"&&" return LOGICAL_AND;
"||" return LOGICAL_OR;
"..." return MORE_ARGS;
"+=" return SELF_PLUS;
"-=" return SELF_MINUS;
"*=" return SELF_TIMES;
"/=" return SELF_DIV;
"%=" return SELF_MOD;
"&=" return SELF_BITWISE_AND;
"|=" return SELF_BITWISE_OR;
"^=" return SELF_BITWISE_XOR;




{decimal} yylval.num=strtol(yytext,NULL,10);return INTEGER;
{octal} yylval.num=strtol(yytext+1,NULL,8);return INTEGER;
{hexadecimal} yylval.num=strtol(yytext+2,NULL,16); return INTEGER;
{binary} yylval.num=strtol(yytext+2,NULL,2); return INTEGER;
{real} yylval.real=strtod(yytext,NULL); return REAL;
[0-9]+{id} {
    strcpy(err_msg,yytext);
    sprintf(err_msg,"Illegal identifier '%s' at line %d",yytext,yylineno);
    yyerror(err_msg);
    return YYerror;
}
\"{string_alphabet}*\"|\"\"\"({string_alphabet}|\n)*\"\"\" {
    strcpy(yylval.text,yytext+1);
    yylval.text[strlen(yylval.text)-1]=0;
    representation_as_string(yylval.text,yylval.text);
    int m=strlen(yylval.text);
    for(int i=0;i<m;i++)
        if(yylval.text[i]=='\n')
            yylineno++;
            
    return STRING;   
}
\'{char_alphabet}\' {
    yylval.character = yytext[0];
    return CHARACTER;
}
\'\\{char_alphabet}\' {
    yylval.character=convert_escape_representation(yytext[1]);
    return CHARACTER;
}

{line_comment}

"/*"                            {BEGIN(comment);}
<comment,array_comment>[^*\n]                 /* skip everything that's not "*" */
<comment,array_comment>"*"+[^*/\n]*           /* eat up ’*’s not followed by ’/’s */
<comment,array_comment>"\n"                   yylineno++; /* skip (we can use this to count the number of lines later) */
<comment>"*"+"/"                {BEGIN(INITIAL);/*return to the main routine*/}
<comment,array_comment><<EOF>>                {
                                    sprintf(err_msg,"Illegal comment on line %d\n",yylineno);
                                    yyerror(err_msg);
                                    return YYerror;
                                }
<array_comment>"*"+"/"          BEGIN(array);


\[                             {   BEGIN(array);}
<array>\n                     {   yylineno++;   }
<array>[ \t]+
<array>\]                      {   BEGIN(INITIAL); return ARRAY; }
<array>\/\*                     {   BEGIN(array_comment);}
<array>{line_comment}
<array>.                  {
                                    BEGIN(INITIAL);
                                    unput(yytext[0]);
                                    return '[';
                                }
<array><<EOF>>                  { 
                                    sprintf(err_msg,"unexpected end of file near line %d\n",yylineno);
                                    yyerror(err_msg);
                                    return YYerror;
                                }

[+\-*/%{}()\[\]<>|&~=;.,^:] return yytext[0];
[ \t]+
\n yylineno++;



. {
    sprintf(err_msg,"Illegal character %s at line %d",yytext,yylineno);
    yyerror(err_msg);
    return YYerror;
}
%% 


/*{line_comment}|{multi_line_comment} {
    int m=strlen(yytext);
    for(int i=0;i<m;i++)
        if(yytext[i]=='\n')
            yylineno++;
            
}
*/


int yywrap(){}
