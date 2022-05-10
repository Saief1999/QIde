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
#include "error_handler.hh"

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

    JavaSemantics(ErrorHandler& errorHandler);

    ErrorHandler* errorHandler;

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


    void throw_error(const std::string& msg);

    void warning(const std::string& msg);

    /**
     * @brief Creates a new scope and pushes it to the symbol table
     * 
     */
    void add_scope();

    /**
     * @brief Frees up the last scope in the symbol table
     * 
     */
    void free_scope();
    
    /**
     * @brief Searches for a symbol in the symbol table
     * 
     * @param search_global whether to search in the global scope or not
     * @param prioritize_local start by searching on the local scope first. If not found fallback to global scope
     * @return the scope where the symbol was found, -1 if not found
     */
    int find_symbol(std::string name, bool search_global=true, bool prioritize_local=false);

    /**
     * @brief Add a new symbol to the current scope
     * 
     * @param name the name of the symbol (identifier)
     * @param symbol Information about the symbol
     */
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

};
} // namespace javacompiler
#endif // SEMANTICS_HH