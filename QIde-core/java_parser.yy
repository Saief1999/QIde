%{ /*** C/C++ Declarations ***/
#include <string>
#include <vector>
#include <ctype.h>
#include <any>
#include <cstring>
// extern bool build_success;
// extern int yylineno;
%}
%code requires {
    #include "opcode.hh"
}


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
    bool boolean;
    Opcode opcode;
}

/*
 * The following tokens are used in the grammar.
 * Notes : 
 *   - Name are used to make error handling more readable.
 *   - We can add a number to be used in the parser file for the token. Otherwise Bison will generate a number for us.   
 */

%token	END	        0	      "end of file"


%token  <text>      ID          "identifier" 
        <character> CHARACTER
        <text> STRING      "string"
        <num> INTEGER
        <real> REAL
%token
        INCREMENT   "++"
        DECREMENT   "--"

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
%type <num> unary_special_operator
//%type <text> expression
%type <text> val
%type <text> var_load
%type <text> var_store
%type <text> fn_call
%type <opcode> logical_operator
%type <opcode> bitwise_operator
%type <opcode> additive_operator
%type <opcode> multiplicative_operator
%type <opcode> order_operator
%type <opcode> equality_operator
%type <opcode> unary_operator
%type <opcode> opt_unary_operator
%type <opcode> assignment_operator
//%type <text> additive_expression
//%type <text> multiplicative_expression
//%type <text> disjunctive_expression
//%type <text> conjunctive_expression
//%type <text> unary_expression
%{

#include "driver.hh"
#include "java_lexer.hh"
#include "CodeGenerator.hh"
#include "opcode.hh"

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
var_load is a variable with a load instruction
*/
var_load : var{
    driver.codeGenerator->addInstruction(javacompiler::Opcode::LDV, std::string($1));
    strcpy($$, $1);
};


/*
var_store is a variable with a store instruction
*/
var_store : var{
    driver.codeGenerator->addInstruction(javacompiler::Opcode::STV, std::string($1));
    strcpy($$, $1);
};


/*
type denotes anything that can be a type
*/
type : nested_id opt_array_type { 
    strcpy($$ , (std::string($1)+std::string($2)).c_str());
};

type_save : type {
    driver.codeGenerator->addInstruction(javacompiler::Opcode::STT, std::string($1));
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
equality_operator : EQ {$$=Opcode::EQ;}| NEQ {$$=Opcode::NEQ;};
order_operator : '<' {$$=Opcode::LESS;} | '>'{$$=Opcode::GREATER;} | LEQ {$$=Opcode::LEQ;} | GEQ {$$=Opcode::GEQ;};
shift_operator: UNSIGNED_RIGHT_SHIFT | LEFT_SHIFT | RIGHT_SHIFT;
multiplicative_operator: '*' {$$=Opcode::MUL;} | '/' {$$=Opcode::DIV;} | '%' {$$=Opcode::MOD;};
additive_operator: '+' {$$=Opcode::ADD;}| '-' {$$=Opcode::SUB;};
logical_operator: LOGICAL_AND {$$=Opcode::LOGICAL_AND;}  | LOGICAL_OR { $$=Opcode::LOGICAL_OR;};
bitwise_operator: '&' {$$=Opcode::BITWISE_AND;}| '^' {$$=Opcode::BITWISE_XOR;}| '|' {$$=Opcode::BITWISE_OR;};
binary_operator: equality_operator |order_operator |
    shift_operator | logical_operator | bitwise_operator |
    additive_operator | multiplicative_operator;
unary_operator: '!' {$$=Opcode::NOT;}| '+' {$$=Opcode::NOOP;}| '-' {$$=Opcode::NEG;} | '~' {$$=Opcode::COMP;};
opt_unary_operator: unary_operator {$$=$1;} | {$$=Opcode::NOOP;};
unary_special_operator: INCREMENT {$$=1;}| DECREMENT{$$=-1;};

/*
A function call
*/
fn_call: var {driver.semantics->current_method_call=$1;}'(' args ')'  {
    driver.codeGenerator->callFunction($1);
} opt_array {
        strcpy($$, $1);
};
opt_var_fn_access: '.' var_fn |; 
/*
A variable or a function call
*/
var_fn : var_load { driver.semantics->use_symbol($1); } | fn_call opt_var_fn_access;

/*
val denotes anything that can be a value
*/
val: var_fn | TRUE {
            strcpy($$,"true");
            driver.codeGenerator->addInstruction(javacompiler::Opcode::LDC, 1);
        }| FALSE{
            strcpy($$,"false");
            driver.codeGenerator->addInstruction(javacompiler::Opcode::LDC, 0);
        } | INTEGER {
            driver.codeGenerator->addInstruction(javacompiler::Opcode::LDC,$1);
            auto i = std::to_string($1);
            strcpy($$,i.c_str());
        } | REAL {
            driver.codeGenerator->addInstruction(javacompiler::Opcode::LDC, $1);
            auto i = std::to_string($1);
            strcpy($$,i.c_str());
        }| CHARACTER {
            driver.codeGenerator->addInstruction(javacompiler::Opcode::LDC, $1);
            strncpy($$,&$1,1);
        } | STRING opt_string_access {
            strcpy($$,$1);
        }; /*TODO: upgrade it to the EBNF case*/
opt_string_access: '.' var_fn|;

/*Operator that assigns a value to its left side*/
assignment_operator: '=' { driver.semantics->assign_value(driver.semantics->current_symbol); 
        $$=Opcode::NOOP;
    }| 
    SELF_UNSIGNED_RIGHT_SHIFT { driver.semantics->use_symbol(driver.semantics->current_symbol); 
        $$=Opcode::NOOP;
    } |
    SELF_RIGHT_SHIFT { driver.semantics->use_symbol(driver.semantics->current_symbol); 
        $$=Opcode::NOOP;
    } |
    SELF_LEFT_SHIFT { driver.semantics->use_symbol(driver.semantics->current_symbol); 
        $$=Opcode::NOOP;
    } |
    SELF_PLUS { driver.semantics->use_symbol(driver.semantics->current_symbol); 
        $$=Opcode::ADD;
    } |
    SELF_MINUS { driver.semantics->use_symbol(driver.semantics->current_symbol); 
        $$=Opcode::SUB;
    } |
    SELF_TIMES { driver.semantics->use_symbol(driver.semantics->current_symbol); 
        $$=Opcode::MUL;
    } |
    SELF_DIV { driver.semantics->use_symbol(driver.semantics->current_symbol); 
        $$=Opcode::DIV;
    } |
    SELF_MOD { driver.semantics->use_symbol(driver.semantics->current_symbol); 
        $$=Opcode::MOD;
    } |
    SELF_BITWISE_AND { driver.semantics->use_symbol(driver.semantics->current_symbol); 
        $$=Opcode::BITWISE_AND;
    } |
    SELF_BITWISE_OR { driver.semantics->use_symbol(driver.semantics->current_symbol); 
    $$=Opcode::BITWISE_OR;
    } |
    SELF_BITWISE_XOR { driver.semantics->use_symbol(driver.semantics->current_symbol); 
        $$=Opcode::BITWISE_XOR;
    } ;

/*A general "enough" mathematical expression*/
/*expression: expression binary_operator opt_unary_operator val   {
        std::string rhsName($4), lhsName($1);
        symbol_entry entry;
        entry.type="int";
        auto tmp=driver.codeGenerator->make_tmp_symbol(entry);
        driver.codeGenerator->addInstruction(javacompiler::Opcode::LDV,rhsName);
        driver.codeGenerator->addInstruction(javacompiler::Opcode::ADD);
        strcpy($$,tmp.c_str());
} | 
    opt_unary_operator val {
        strcpy($$,$2);
    }| 
    opt_unary_operator '(' expression ')' opt_array {
    }|
     expression binary_operator opt_unary_operator '(' expression ')' opt_array  {

    };*/
expression : disjunctive_expression;

unary_expression: opt_unary_operator val {
    if($1!=Opcode::NOOP)
        driver.codeGenerator->addInstruction($1);
}
    | opt_unary_operator '(' disjunctive_expression ')' opt_array {
        if($1!=Opcode::NOOP)
            driver.codeGenerator->addInstruction($1);
    };

multiplicative_expression: multiplicative_expression multiplicative_operator  unary_expression  {
    driver.codeGenerator->addInstruction($2);
}
    | unary_expression;

additive_expression: additive_expression additive_operator multiplicative_expression {
    driver.codeGenerator->addInstruction($2);
}
    | multiplicative_expression;

relational_expression: relational_expression order_operator additive_expression {
    driver.codeGenerator->addInstruction($2);
}
    | additive_expression;

equality_expression: equality_expression equality_operator relational_expression {
    driver.codeGenerator->addInstruction($2);
}
    | relational_expression;

conjunctive_expression: conjunctive_expression LOGICAL_AND equality_expression{
    driver.codeGenerator->addInstruction(javacompiler::Opcode::LOGICAL_AND);
}
        | equality_expression;
disjunctive_expression : disjunctive_expression LOGICAL_OR conjunctive_expression {
    driver.codeGenerator->addInstruction(javacompiler::Opcode::LOGICAL_OR);
}
        | conjunctive_expression;




/*boolean int
Low level definition of a 'normal' statement so that the grammar is guaranteed to be LALR(1)
A normal statement is any statement that is not one of the following:
- IF, FOR, WHILE, DO WHILE
*/
statement_s0: ID {
    /* This represents either a variable, or a type of a variable ( if we added another ID after it ) */
        driver.semantics->current_symbol = std::string($1);
    } statement_s1 |
    '(' expression ')' opt_array {
        driver.codeGenerator->addInstruction(Opcode::POP);
    }|
    new_expression |
    unary_special_operator var{
        driver.codeGenerator->addInstruction($1==1?javacompiler::Opcode::INC:javacompiler::Opcode::DEC, $2);
    };

statement_s1: var_declarations |
    '.' ID {
        driver.semantics->current_symbol = driver.semantics->current_symbol + "." + std::string($2); // used for types
    } statement_s1 |
    '[' expression ']' opt_array statement_s2 | 
    ARRAY var_declarations |
    '(' {
        driver.semantics->set_current_method_call(driver.semantics->current_symbol); 
    } args {
        driver.codeGenerator->callFunction(driver.semantics->current_method_call);
        driver.semantics->current_method_call.clear();
        driver.semantics->is_call_definition = false;
        driver.codeGenerator->addInstruction(Opcode::POP);
    } ')' opt_array statement_s2 |
    assignment {
        driver.codeGenerator->addInstruction(javacompiler::Opcode::STORE, driver.semantics->current_symbol);
    } | binary_operator expression { driver.semantics->use_symbol(driver.semantics->current_symbol); } 
    | unary_special_operator { 
        driver.semantics->use_symbol(driver.semantics->current_symbol); 
        driver.codeGenerator->addInstruction($1==1?javacompiler::Opcode::INC:javacompiler::Opcode::DEC, driver.semantics->current_symbol);
        }|;

rhs: assignment |
    binary_operator expression; 

statement_s2: '.' val rhs |
    rhs{
        
    }|;

/*
New expression is an expression having the new operator
*/
new_expression: NEW nested_id new_initialisation;
new_initialisation: '(' args ')' | '['expression ']' opt_array opt_array_type  | ARRAY opt_array_type '{' args '}';


/*Expression that can be assigned to a variable, or returned*/
assignable_expression :  new_expression | expression

/*Arguments of a function*/
obligatory_args: assignable_expression {
    driver.semantics->args_number=1;
    } |
    assignable_expression {
        driver.semantics->args_number ++ ;
    } ',' obligatory_args;
args:  obligatory_args {
        driver.semantics->check_args_number();
    } |
    { 
        driver.semantics->args_number = 0;
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
    driver.semantics->setInitialized(driver.semantics->current_symbol);
    driver.codeGenerator->addInstruction(javacompiler::Opcode::STORE, driver.semantics->current_symbol);
}|;

/*
Variable declaration, this special statement can be derived with the rule statement_s0. It is used mainly for the definition part of the for loop
*/

var_declaration_body: ID {
        // a type is first detected as the "current_symbol" , if another identifier is found after it, it becomes the "current_type"
        if (driver.semantics->current_type.empty()) 
            driver.semantics->current_type = driver.semantics->current_symbol;
        driver.semantics->current_symbol_entry.type = driver.semantics->current_type; // this is saved on 'statement_s0'
        driver.semantics->current_symbol = std::string($1);
        driver.semantics->current_symbol_entry.ident_type = identifier_type::VARIABLE;
        // std::cout << "setting type for " <<driver.semantics->current_symbol<< " as "<<driver.semantics->current_symbol_entry.type<<std::endl;

    } opt_array_type {
        driver.semantics->add_current_symbol();
        } opt_assignment {

        driver.semantics->reset_current_symbol();
        // driver.semantics->add_symbol($1, { identifier_type::VARIABLE, false });
    };

var_declarations: var_declarations  ',' var_declaration_body {
    driver.semantics->current_type.clear();
}
    | var_declaration_body {
    driver.semantics->current_type.clear();
}; 
statement_declarative: type {
    driver.semantics->current_type = $1;
} var_declarations {
    driver.semantics->current_type.clear();
};

/*
    Assignment of a variable
*/
assignment: assignment_operator {
    if($1!=Opcode::NOOP)
        driver.codeGenerator->addInstruction(Opcode::LDV, driver.semantics->current_symbol);
        
} expression {
        driver.semantics->assign_value(driver.semantics->current_symbol);
        if($1!=Opcode::NOOP)
            driver.codeGenerator->addInstruction($1);
    }| '=' new_expression {
        driver.semantics->assign_value(driver.semantics->current_symbol);
    };
assignment_statement: var assignment {
    //driver.codeGenerator->isLeftSide=true;
    driver.codeGenerator->addInstruction(javacompiler::Opcode::STORE, $1);
};
statement_pm_1: unary_special_operator var { 
    driver.semantics->use_symbol($2); 
    driver.codeGenerator->addInstruction($1==1?javacompiler::Opcode::INC:javacompiler::Opcode::DEC, $2);
    } |
    var unary_special_operator {

         driver.semantics->use_symbol($1);
        driver.codeGenerator->addInstruction($2==1?javacompiler::Opcode::INC:javacompiler::Opcode::DEC, $1);
 }; /*Increment/Decrement by 1*/

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
//   range_for_statement |
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
if_statement: IF '(' condition ')' {
    driver.semantics->current_address.push_back(driver.codeGenerator->addInstruction(javacompiler::Opcode::JMP_Z, 0));
    //driver.codeGenerator.addInstruction(w)
} conditional_body {
    driver.codeGenerator->addInstruction(javacompiler::Opcode::JMP, 0);
    driver.semantics->current_address.push_back(driver.codeGenerator->currentInstructionOffset());
} opt_else_statement {
    auto alt_address=driver.semantics->current_address.back();
    driver.semantics->current_address.pop_back();
    auto src_address=driver.semantics->current_address.back();
    driver.semantics->current_address.pop_back();
    driver.codeGenerator->setOperand(src_address,alt_address);
    driver.codeGenerator->setOperand(alt_address-1,driver.codeGenerator->currentInstructionOffset());
} | IF '(' error ')' conditional_body opt_else_statement;
for_updating_statement: statement_pm_1 | assignment_statement
for_statement: FOR '(' statement_declarative ';'{
    driver.semantics->current_address.push_back(driver.codeGenerator->currentInstructionOffset());
} condition ';' {
    driver.semantics->current_address.push_back(driver.codeGenerator->addInstruction(javacompiler::Opcode::JMP_Z, 0));
    auto branch= driver.codeGenerator->createBranch();
    driver.codeGenerator->branchesStack.push_back({branch});
    driver.codeGenerator->setDefaultBranch(branch);
}for_updating_statement ')' {driver.codeGenerator->setDefaultBranch("main");} conditional_body {
    const auto& branchList=driver.codeGenerator->branchesStack.back();
    driver.codeGenerator->combineBranches(branchList);
    int jmp_address=driver.semantics->current_address.back();
    driver.semantics->current_address.pop_back();
    driver.codeGenerator->addInstruction(Opcode::JMP, driver.semantics->current_address.back());
    driver.codeGenerator->setOperand(jmp_address,driver.codeGenerator->currentInstructionOffset());
    driver.semantics->current_address.pop_back();
    driver.codeGenerator->branchesStack.pop_back();

};
range_for_statement: FOR '(' type ID ':' val ')' conditional_body | FOR '(' error ')' conditional_body;
while_statement: WHILE {
    driver.semantics->current_address.push_back(driver.codeGenerator->currentInstructionOffset());
    }'(' condition ')' {
        driver.semantics->current_address.push_back(driver.codeGenerator->addInstruction(javacompiler::Opcode::JMP_Z, 0));
    } conditional_body {
        auto src_address=driver.semantics->current_address.back();
        driver.semantics->current_address.pop_back();
        driver.codeGenerator->addInstruction(javacompiler::Opcode::JMP, driver.semantics->current_address.back());
        driver.codeGenerator->setOperand(src_address,driver.codeGenerator->currentInstructionOffset());
        driver.semantics->current_address.pop_back();
    };
do_while_statement: DO {
    driver.semantics->current_address.push_back(driver.codeGenerator->currentInstructionOffset());
} block WHILE '(' condition ')' ';' {
    auto src_address=driver.semantics->current_address.back();
    driver.semantics->current_address.pop_back();
    driver.codeGenerator->addInstruction(javacompiler::Opcode::JMP_Z, src_address);
} ;//| DO block WHILE '(' error ')' ';';
switch_statement: SWITCH '(' condition ')' '{' switch_body '}';
case_val: INTEGER | TRUE | FALSE | CHARACTER;
switch_label: CASE case_val | DEFAULT;
case_block: switch_label ':' opt_statement_seq;
switch_body: case_block switch_body |; 
opt_return_expression: new_expression | expression |;
return_statement: RETURN opt_return_expression {
    driver.codeGenerator->addInstruction(Opcode::RETURN);
};


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
        driver.codeGenerator->addFunctionEntry(driver.semantics->current_symbol);
        driver.semantics->reset_current_symbol();
    }
    formal_args ')' { driver.semantics->current_method.clear();
        driver.semantics->scopeType = scope_type::FUNCTION;
    }
    block {
        driver.codeGenerator->addInstruction(javacompiler::Opcode::END);
    }
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
