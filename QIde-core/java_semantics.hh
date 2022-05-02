#ifndef SEMANTICS_HH
#define SEMANTICS_HH

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include "java_parser.hh"
#include "utils.hh"
#include <deque>

namespace javacompiler {

enum identifier_type {
    CLASS,
    INTERFACE,
    METHOD,
    VARIABLE,
    UNDEF
};

struct argument {
    std::string name;
    std::string type;
};

struct symbol_entry {
    std::string type;
    identifier_type ident_type;
    bool is_initialized ; // whether we gave it a value
    bool is_used;
    std::deque<argument> args;
};



// - For now we won't support nested global scopes, We will consider the first scope in the symbol table to be our global scope
struct scope {
    // bool global; // global scope for a class ( can be nested ) 
    std::unordered_map<std::string, symbol_entry> symbols;
};

class JavaSemantics {
public:

    JavaSemantics();

    /// Current Location , used to print errors
    location* current_location;

    /// Our main Symbol Table
    std::vector<scope> symbol_table;

    /// Predefined functions
    std::unordered_set<std::string> definitions;
    
    symbol_entry current_symbol_entry;
    std::string current_symbol;
    std::string current_type;

    std::string current_method;
    std::string current_method_call;
    int args_number;
    /// Whether the currently called function is predefined (ie. imported)
    bool is_call_definition;
    // void addImport(std::string import);


    void throw_error(std::string msg);
    void warning(std::string msg);

    void add_scope();
    void free_scope();
    

    int find_symbol(std::string name, bool search_global=true, bool prioritize_local=false);
    void add_symbol(std::string name, symbol_entry symbol);

    void add_current_symbol();
    void reset_current_symbol();
    void reset_current_symbol_entry();

    bool check_definition(std::string name);

    void assign_value(std::string name);

    void use_symbol(std::string name);

    void add_arg_to_current(std::string name, std::string type);

    void set_current_method_call(std::string name);

    void init_definitions();

    void check_args_number();

    std::string highlight(std::string identifier);
};
} // namespace javacompiler
#endif // SEMANTICS_HH