%union{
    char text[256];
    long long num;
    double real;
    char character;
}
%{
    #include <stdbool.h>
    #include <stdio.h>
%}
%locations
%define parse.trace
%define parse.error custom
%define parse.lac full
%token  ID CHARACTER STRING INCREMENT DECREMENT INTEGER REAL CLASS ARRAY RETURN INTERFACE
%token ABSTRACT STATIC EXTENDS IMPLEMENTS;
%token IF ELSE FOR WHILE DO SWITCH CASE DEFAULT
%token LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT
%token LEQ GEQ NEQ EQ
%right SELF_UNSIGNED_RIGHT_SHIFT SELF_LEFT_SHIFT SELF_RIGHT_SHIFT
%token INSTANCEOF MORE_ARGS NEW
%token LOGICAL_AND LOGICAL_OR TRUE FALSE
%token PACKAGE IMPORT
%right SELF_PLUS SELF_MINUS SELF_DIV SELF_MOD SELF_TIMES SELF_BITWISE_AND SELF_BITWISE_OR SELF_BITWISE_XOR
%left LOGICAL_AND LOGICAL_OR
%left '^' '|'
%left '&'
%left '<' '>' LEQ GEQ NEQ EQ
%left LEFT_SHIFT UNSIGNED_RIGHT_SHIFT RIGHT_SHIFT
%left '-' '+'
%left '*' '/' '%'
%right '='
%nonassoc LOWEST
%nonassoc ELSE
%nonassoc PUBLIC PRIVATE PROTECTED
%start start


%%
start : main_program {printf("GJ\n");}; 
/*
nested id is of the form of ID1.ID2.ID3...
*/
nested_id: ID '.' nested_id | ID;
/*
var denotes anything that can be a variable
*/
opt_var_access: '.' var |;
var : ID opt_array opt_var_access;
/*
type denotes anything that can be a type
*/
type : nested_id opt_array_type;
opt_array_type: ARRAY opt_array_type |;
opt_array: '[' expression ']' opt_array | ;


/*
Operators
*/
equality_operator : EQ | NEQ;
order_operator : '<' | '>' | LEQ | GEQ;
shift_operator: UNSIGNED_RIGHT_SHIFT | LEFT_SHIFT | RIGHT_SHIFT;
multiplicative_operator: '*' | '/' | '%';
additive_operator: '+' | '-'
logical_operator: LOGICAL_AND | LOGICAL_OR;
bitwise_operator: '&' | '^' | '|'
binary_operator: equality_operator |order_operator |
    shift_operator | logical_operator | bitwise_operator |
    additive_operator | multiplicative_operator;
unary_operator: '!' | '+' | '-' | '~';
opt_unary_operator: unary_operator |;
unary_special_operator: INCREMENT | DECREMENT;

/*
A function call
*/
fn_call: var '(' args ')' opt_array;
opt_var_fn_access: '.' var_fn |; 
/*
A variable or a function call
*/
var_fn : var | fn_call opt_var_fn_access;

/*
val denotes anything that can be a value
*/
val: var_fn | TRUE | FALSE | INTEGER | REAL | CHARACTER | STRING opt_string_access; /*TODO: upgrade it to the EBNF case*/
opt_string_access: '.' var_fn|;

/*Operator that assigns a value to its left side*/
assignment_operator: '=' | 
    SELF_UNSIGNED_RIGHT_SHIFT | SELF_RIGHT_SHIFT | SELF_LEFT_SHIFT |
    SELF_PLUS | SELF_MINUS|
    SELF_TIMES | SELF_DIV | SELF_MOD|
    SELF_BITWISE_AND | SELF_BITWISE_OR |SELF_BITWISE_XOR;

/*A general "enough" mathematical expression*/
expression: opt_unary_operator val binary_operator expression | 
    opt_unary_operator val | 
    opt_unary_operator '(' expression ')' opt_array |
    opt_unary_operator '(' expression ')' opt_array binary_operator expression;


/*boolean int
Low level definition of a 'normal' statement so that the grammar is guaranteed to be LALR(1)
A normal statement is any statement that is not one of the following:
- IF, FOR, WHILE, DO WHILE
*/
statement_s0: ID statement_s1 | '(' expression ')' opt_array | new_expression | unary_special_operator var;
statement_s1: var_declarations | '.' ID statement_s1 | '[' expression ']' opt_array statement_s2 | 
    ARRAY var_declarations | '(' args ')' opt_array statement_s2 |assignment | binary_operator expression | unary_special_operator|;
rhs: assignment | binary_operator expression; 
statement_s2: '.' val rhs | rhs|;

/*
New expression is an expression having the new operator
*/
new_expression: NEW nested_id new_initialisation;
new_initialisation: '(' args ')' | '['expression ']' opt_array opt_array_type  | ARRAY opt_array_type '{' args '}';

/*Expression that can be assigned to a variable, or returned*/
assignable_expression :  new_expression | expression

/*Arguments of a function*/
obligatory_args: assignable_expression | assignable_expression ',' obligatory_args;
args:  obligatory_args |;

/*
    Variadic method is a method having the special ellipsis
*/
opt_variadic: MORE_ARGS |;

/*
Formal arguments are the arguments defined during function declaration
*/
obligatory_formal_args: type ID opt_array_type ',' obligatory_formal_args | type ID opt_array_type opt_variadic;
formal_args: obligatory_formal_args |;

/*Optional assignment of a variable*/
opt_assignment: '=' assignable_expression |;

/*
Variable declaration, this special statement can be derived with the rule statement_s0. It is used mainly for the definition part of the for loop
*/
var_declarations: ID opt_array_type opt_assignment  ',' var_declarations| ID opt_array_type opt_assignment; 
statement_declarative: type var_declarations;

/*
    Assignment of a variable
*/
assignment: assignment_operator expression | '=' new_expression;
assignment_statement: var assignment;
statement_pm_1: unary_special_operator var | var unary_special_operator; /*Increment/Decrement by 1*/

/*
A more general form of a statement
This form can cover many statements
*/
statement:     
    /*expression ';' |
    assignment_statement ';' |
    statement_declarative ';' |
    statement_pm_1 ';' |*/
    statement_s0 ';'|
    for_statement |
    range_for_statement |
    if_statement |
    while_statement |
    do_while_statement | 
    switch_statement |
    return_statement ';'|
    ';' |
    error ';';

/*
    A sequence of statements.
*/
opt_statement_seq: statement_seq|;
statement_seq: statement opt_statement_seq | 
    '{' statement_seq '}' opt_statement_seq | 
    '{''}' opt_statement_seq;

/*
    A block of statements
*/
block: '{' opt_statement_seq '}' ;

/*
A condition, for now it is defined as any expression
*/
condition: expression
conditional_body: statement | block;

/*
Conditional statements (Special statements)
*/
opt_else_statement:ELSE conditional_body | %prec LOWEST;
if_statement: IF '(' condition ')' conditional_body opt_else_statement | IF '(' error ')' conditional_body opt_else_statement;
for_updating_statement: statement_pm_1 | assignment_statement
for_statement: FOR '(' statement_declarative ';' expression ';' for_updating_statement ')' conditional_body;
range_for_statement: FOR '(' type ID ':' val ')' conditional_body | FOR '(' error ')' conditional_body;
while_statement: WHILE '(' condition ')' conditional_body;
do_while_statement: DO '{' statement_seq '}' WHILE '(' condition ')' ';' | DO '{' statement_seq '}' WHILE '(' error ')' ';';
switch_statement: SWITCH '(' condition ')' '{' switch_body '}';
case_val: INTEGER | TRUE | FALSE | CHARACTER;
switch_label: CASE case_val | DEFAULT;
case_block: switch_label ':' opt_statement_seq;
switch_body: case_block switch_body |; 
opt_return_expression: new_expression | expression |;
return_statement: RETURN opt_return_expression;


/*
Class Grammar
1. Class attribute is a member variable or a member method
2. Its signature is what determines whether it is a member variable or a member method
3. Class info is simply the definition block of a class
*/
cls_modifier: PUBLIC |;
cls_attr_more: ',' ID opt_assignment cls_attr_more | ';' | error ';';
cls_attr_sign: opt_assignment cls_attr_more | '(' formal_args ')' block | '(' error ')' block;
fn_access_modifier: PRIVATE | PUBLIC | PROTECTED;
fn_static_modifier: STATIC;
fn_opt_static_modifier: fn_static_modifier|;
fn_opt_access_modifier: fn_access_modifier |;
fn_modifier: fn_access_modifier fn_opt_static_modifier | fn_static_modifier fn_opt_access_modifier|;
fn_declaration: fn_modifier type ID '(' formal_args ')' | fn_modifier type ID '(' error ')';
/*fn_definition:ABSTRACT fn_declaration ';' | fn_declaration block;*/
cls_declaration: cls_modifier CLASS ID | cls_modifier CLASS error;
cls_info_opt_more: cls_info|;
cls_info: ABSTRACT fn_declaration ';' cls_info_opt_more 
    | fn_modifier type ID cls_attr_sign cls_info_opt_more
    | ';' cls_info_opt_more;
opt_cls_info: cls_info|;
/*
Class inheritance and Intferace implementations
*/
opt_extends: EXTENDS nested_id|;
more_interface_list: ',' interface_list|;
interface_list: nested_id more_interface_list;
opt_implements: IMPLEMENTS interface_list|;
cls_definition: cls_declaration opt_extends opt_implements'{' opt_cls_info '}' | cls_declaration error '{' opt_cls_info '}';

/*
Interface Grammar
*/
opt_abstract: ABSTRACT|;
interface_info:  opt_abstract fn_declaration ';' interface_info | ';' | error ';' | error block;
opt_interface_info:interface_info|;
interface_declaration: cls_modifier INTERFACE ID | cls_modifier INTERFACE error;
opt_interface_extends: EXTENDS interface_list|;
interface_definition: interface_declaration opt_interface_extends '{' opt_interface_info '}' | interface_declaration error '{' opt_interface_info '}'; 

/*main_fn_modifier: PUBLIC STATIC | STATIC PUBLIC;
main_cls_info: main_fn_modifier;
main_cls: cls_declaration '{';*/

/*Main program Grammar*/
opt_pkg_declaration: PACKAGE nested_id ';'|;
pkg_import: IMPORT nested_id ';' pkg_import |;
type_definitions: interface_definition  type_definitions_more | cls_definition type_definitions_more; 
type_definitions_more: type_definitions|;
main_program: opt_pkg_declaration pkg_import type_definitions;
%%


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
