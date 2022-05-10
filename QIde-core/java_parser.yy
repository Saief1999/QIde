%{ /*** C/C++ Declarations ***/
#include <string>
#include <vector>
#include <ctype.h>
#include <any>
#include <cstring>

// extern bool build_success;
// extern int yylineno;
%}


/*** yacc/bison Declarations ***/

/* Require bison 3.2 or later */
%require "3.2"

/* start symbol is named "start" */
%start start

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%define api.prefix {javacompiler}

/* set the parser's class identifier */
%define api.parser.class {JavaParser}

/* keep track of the current position within the input */
%locations

%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
    // Save the current location pointer in the semantic analyzer ( to print errors )
    driver.semantics->current_location = &@$;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%define parse.error detailed

/*
 * Enable LAC (lookahead correction) to improve syntax error handling. 
 */
%define parse.lac full

/*
 * enable error tracing
 */
/* %define parse.trace */

/*** BEGIN TOKENS - Change the grammar's tokens below ***/

%union {
    char text[256];
    long long num;
    double real;
    char character;
}

/*
 * The following tokens are used in the grammar.
 * Notes : 
 *   - Name are used to make error handling more readable.
 *   - We can add a number to be used in the parser file for the token. Otherwise Bison will generate a number for us.   
 */

%token	END	        0	      "end of file"


%token  <text>      ID          "identifier" 
        CHARACTER   "character"
        STRING      "string"
        INCREMENT   "++"
        DECREMENT   "--"
        INTEGER     "integer"
        REAL        "real"
        CLASS       "class"
        ARRAY       "[]"
        RETURN      "return"
        INTERFACE   "interface"

%token  ABSTRACT    "abstract"
        STATIC      "static"
        EXTENDS     "extends"
        IMPLEMENTS  "implements"

%token  IF          "if"
        ELSE        "else"
        FOR         "for"
        WHILE       "while"
        DO          "do"
        SWITCH      "switch"
        CASE        "case"
        DEFAULT     "default"

%token  LEFT_SHIFT  "<<"
        RIGHT_SHIFT ">>"
        UNSIGNED_RIGHT_SHIFT    ">>>"

%token  LEQ         "<="
        GEQ         ">="
        NEQ         "!="
        EQ          "=="           

/*
    Right Associative tokens having the same priority (lowest priority is on top)
*/
%right  SELF_UNSIGNED_RIGHT_SHIFT
        SELF_LEFT_SHIFT 
        SELF_RIGHT_SHIFT

%token  INSTANCEOF  "instanceof"
        MORE_ARGS   ","
        NEW         "new"

%token  LOGICAL_AND  "&&"
        LOGICAL_OR   "||"
        TRUE         "true"
        FALSE        "false"

%token  PACKAGE      "package"
        IMPORT       "import"

%right  SELF_PLUS SELF_MINUS SELF_DIV SELF_MOD SELF_TIMES SELF_BITWISE_AND SELF_BITWISE_OR SELF_BITWISE_XOR

/*
    Left Associative tokens having the same priority 
*/
%left   LOGICAL_AND
        LOGICAL_OR
%left   '^' '|'
%left   '&'
%left   '<' '>' LEQ GEQ NEQ EQ
%left   LEFT_SHIFT UNSIGNED_RIGHT_SHIFT RIGHT_SHIFT
%left   '-' '+'
%left   '*' '/' '%'
%right  '='
%nonassoc LOWEST    
%nonassoc ELSE
%nonassoc PUBLIC    "public"
          PRIVATE   "private"
          PROTECTED "protected"

/*** END TOKENS - Change the grammar's tokens above ***/

/*** START NON TERMINALS ***/

%type <text> nested_id 
%type <text> opt_array_type
%type <text> opt_array
%type <text> type
%type <text> var
%type <text> opt_var_access
%{

#include "driver.hh"
#include "java_lexer.hh"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}


%% /*** Grammar Rules ***/

 /*** BEGIN GRAMMAR ***/


start : main_program {/*std::cout("program finished parsing\n");*/}; 
/*
nested id is of the form of ID1.ID2.ID3...
*/
nested_id: ID '.' nested_id {
    std::string res = std::string($1) + "." + std::string($3);
    strcpy($$,res.c_str());
} | ID { strcpy($$,$1); };
/*
var denotes anything that can be a variable (a local variable)
*/
opt_var_access: '.' var {
        strcpy($$, ("."+std::string($2)).c_str());
    }|
    { strcpy($$ ,(std::string("")).c_str()); };
var : ID {
        driver.semantics->check_definition($1);
    } 
    opt_array opt_var_access {
    // Midrule actions count as a rule too , they can even have a return value (that's why we jumped '$2')...
    /*God bless you for that comment*/
    strcpy($$, (std::string($1)+std::string($3) + std::string($4)).c_str());
};
/*
type denotes anything that can be a type
*/
type : nested_id opt_array_type { 
    strcpy($$ , (std::string($1)+std::string($2)).c_str());
};
opt_array_type: ARRAY opt_array_type { 
    // Array in declaration
    strcpy($$,("[]" + std::string($2)).c_str());
    } |
    { strcpy($$ ,(std::string("")).c_str()); }; 
opt_array: '[' expression ']' opt_array {
    // Array in call
    strcpy($$,("[]" + std::string($4)).c_str());
    }|
    { strcpy($$ ,(std::string("")).c_str()); }; 


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
var_fn : var { driver.semantics->use_symbol($1); } | fn_call opt_var_fn_access;

/*
val denotes anything that can be a value
*/
val: var_fn | TRUE | FALSE | INTEGER | REAL | CHARACTER | STRING opt_string_access; /*TODO: upgrade it to the EBNF case*/
opt_string_access: '.' var_fn|;

/*Operator that assigns a value to its left side*/
assignment_operator: '=' { driver.semantics->assign_value(driver.semantics->current_symbol); }| 
    SELF_UNSIGNED_RIGHT_SHIFT { driver.semantics->use_symbol(driver.semantics->current_symbol); } |
    SELF_RIGHT_SHIFT { driver.semantics->use_symbol(driver.semantics->current_symbol); } |
    SELF_LEFT_SHIFT { driver.semantics->use_symbol(driver.semantics->current_symbol); } |
    SELF_PLUS { driver.semantics->use_symbol(driver.semantics->current_symbol); } |
    SELF_MINUS { driver.semantics->use_symbol(driver.semantics->current_symbol); } |
    SELF_TIMES { driver.semantics->use_symbol(driver.semantics->current_symbol); } |
    SELF_DIV { driver.semantics->use_symbol(driver.semantics->current_symbol); } |
    SELF_MOD { driver.semantics->use_symbol(driver.semantics->current_symbol); } |
    SELF_BITWISE_AND { driver.semantics->use_symbol(driver.semantics->current_symbol); } |
    SELF_BITWISE_OR { driver.semantics->use_symbol(driver.semantics->current_symbol); } |
    SELF_BITWISE_XOR { driver.semantics->use_symbol(driver.semantics->current_symbol); } ;

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
statement_s0: ID {
    /* This represents either a variable, or a type of a variable ( if we added another ID after it ) */
        driver.semantics->current_symbol = std::string($1);
    } statement_s1 |
    '(' expression ')' opt_array |
    new_expression |
    unary_special_operator var;

statement_s1: var_declarations |
    '.' ID {
        driver.semantics->current_symbol = driver.semantics->current_symbol + "." + std::string($2); // used for types
    } statement_s1 |
    '[' expression ']' opt_array statement_s2 | 
    ARRAY var_declarations |
    '(' {
        driver.semantics->set_current_method_call(driver.semantics->current_symbol); 
    } args {
        driver.semantics->current_method_call.clear();
        driver.semantics->is_call_definition = false;
    } ')' opt_array statement_s2 |
    assignment|
    binary_operator expression { driver.semantics->use_symbol(driver.semantics->current_symbol); } |
    unary_special_operator { driver.semantics->use_symbol(driver.semantics->current_symbol); }|;

rhs: assignment |
    binary_operator expression; 

statement_s2: '.' val rhs |
    rhs|;

/*
New expression is an expression having the new operator
*/
new_expression: NEW nested_id new_initialisation;
new_initialisation: '(' args ')' | '['expression ']' opt_array opt_array_type  | ARRAY opt_array_type '{' args '}';


/*Expression that can be assigned to a variable, or returned*/
assignable_expression :  new_expression | expression

/*Arguments of a function*/
obligatory_args: assignable_expression {
    driver.semantics->args_number ++;
    } |
    assignable_expression {
        driver.semantics->args_number ++ ;
    } ',' obligatory_args;
args:  obligatory_args {
        driver.semantics->check_args_number();
    } |
    { 
        driver.semantics->check_args_number();
    };

/*
    Variadic method is a method having the special ellipsis
*/
opt_variadic: MORE_ARGS |;

/*
Formal arguments are the arguments defined during function declaration
*/
obligatory_formal_args: type ID opt_array_type {
        driver.semantics->add_arg_to_current($2,$1);
    }
    ',' obligatory_formal_args |
    type ID opt_array_type opt_variadic {
        driver.semantics->add_arg_to_current($2,$1);
    };
formal_args: obligatory_formal_args |;

/*Optional assignment of a variable*/
opt_assignment: '=' assignable_expression {
    // std::cout << "assigning a value to a variable" << std::endl;
    driver.semantics->current_symbol_entry.is_initialized = true;
}|;

/*
Variable declaration, this special statement can be derived with the rule statement_s0. It is used mainly for the definition part of the for loop
*/

var_declaration_body: ID {
        // a type is first detected as the "current_symbol" , if another identifier is found after it, it becomes the "current_type"
        if (driver.semantics->current_type.empty()) driver.semantics->current_type = driver.semantics->current_symbol;
        driver.semantics->current_symbol_entry.type = driver.semantics->current_type; // this is saved on 'statement_s0'
        driver.semantics->current_symbol = std::string($1);
        driver.semantics->current_symbol_entry.ident_type = identifier_type::VARIABLE;
        // std::cout << "setting type for " <<driver.semantics->current_symbol<< " as "<<driver.semantics->current_symbol_entry.type<<std::endl;

    } opt_array_type opt_assignment {

        driver.semantics->add_current_symbol();
        driver.semantics->reset_current_symbol();
        // driver.semantics->add_symbol($1, { identifier_type::VARIABLE, false });
    };

var_declarations: var_declaration_body  ',' var_declarations {
    driver.semantics->current_type.clear();
}
    | var_declaration_body; 
statement_declarative: type var_declarations;

/*
    Assignment of a variable
*/
assignment: assignment_operator expression |
    '=' new_expression {
        driver.semantics->assign_value(driver.semantics->current_symbol);
    };
assignment_statement: var assignment;
statement_pm_1: unary_special_operator var { driver.semantics->use_symbol($2); } |
    var unary_special_operator { driver.semantics->use_symbol($1); }; /*Increment/Decrement by 1*/

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
    block opt_statement_seq;

/*
    A block of statements
*/
block: opening_bracket opt_statement_seq closing_bracket;

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
do_while_statement: DO block WHILE '(' condition ')' ';' | DO block WHILE '(' error ')' ';';
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
cls_attr_more: ',' ID {
        driver.semantics->current_symbol = std::string($2);
        driver.semantics->add_current_symbol();

    } opt_assignment cls_attr_more | ';' | error ';';
cls_attr_sign: opt_assignment  {
        // GLOBAL VARIABLE DECLARATION
        driver.semantics->current_symbol_entry.ident_type = identifier_type::VARIABLE;
        driver.semantics->add_current_symbol();
    } cls_attr_more {
        driver.semantics->reset_current_symbol();
    }
    | '(' 
    {
        // GLOBAL METHOD DECLARATION
        driver.semantics->current_symbol_entry.ident_type = identifier_type::METHOD;
        driver.semantics->current_method = driver.semantics->current_symbol;
        driver.semantics->add_current_symbol();
        driver.semantics->reset_current_symbol();
    }
    formal_args ')' { driver.semantics->current_method.clear();}
    block
    | '(' error ')' block;
fn_access_modifier: PRIVATE | PUBLIC | PROTECTED;
fn_static_modifier: STATIC;
fn_opt_static_modifier: fn_static_modifier|;
fn_opt_access_modifier: fn_access_modifier |;
fn_modifier: fn_access_modifier fn_opt_static_modifier | fn_static_modifier fn_opt_access_modifier|;
fn_declaration: fn_modifier type ID '(' formal_args ')'| fn_modifier type ID '(' error ')';
/*fn_definition:ABSTRACT fn_declaration ';' | fn_declaration block;*/
cls_declaration: cls_modifier CLASS ID | cls_modifier CLASS error;
cls_info_opt_more: cls_info|;
cls_info: ABSTRACT fn_declaration ';' cls_info_opt_more 
    | fn_modifier type ID {
        // This can be either an attribute or a method (if we added "()")
        driver.semantics->current_symbol = std::string($3);
        // std::cout << "Setting type for "<<std::string($3)<<" as "<<std::string($2)<<std::endl;
        driver.semantics->current_symbol_entry.type = std::string($2);
        // std::cout << "setting new symbol " << std::string($3) <<"\n";
        } cls_attr_sign cls_info_opt_more 
    | ';' cls_info_opt_more;
opt_cls_info: cls_info|;
/*
Class inheritance and Intferace implementations
*/
opt_extends: EXTENDS nested_id|;
more_interface_list: ',' interface_list|;
interface_list: nested_id more_interface_list;
opt_implements: IMPLEMENTS interface_list|;

opening_bracket: '{' {
        // std::cout<<"Adding new scope"<<std::endl;
        driver.semantics->add_scope();
    };

closing_bracket: '}' {
        // std::cout<<"Removing new scope"<<std::endl;
        driver.semantics->free_scope();
    };

cls_definition: cls_declaration opt_extends opt_implements opening_bracket opt_cls_info closing_bracket
    | cls_declaration error '{' opt_cls_info '}';

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

 /*** END GRAMMAR ***/

%% /*** Additional Code ***/

// error handling is linked to the driver here
// if the parser fails, it will call the error handler

void javacompiler::JavaParser::error(const JavaParser::location_type& l, const std::string& m)
{
    /* printf("Error: %s\n", m.c_str()); */
    driver.error(l, m);
}
