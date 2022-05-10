#include "java_semantics.hh"

namespace javacompiler {

    JavaSemantics::JavaSemantics() {
        init_definitions();
        reset_current_symbol_entry();
        this->current_method = ""; 
        this->current_method_call = "";
        this->args_number = 0;
    }

    void JavaSemantics::init_definitions() {
        /*
        * Anything to make her happy
        */
        this->definitions.insert("System.out.println");
        this->definitions.insert("System.out.print");
        this->definitions.insert("System.err.println");
        this->definitions.insert("System.err.print");
        this->definitions.insert("System.out.flush");
        this->definitions.insert("System.err.flush");
        this->definitions.insert("System.out.close");
        this->definitions.insert("System.err.close");
        this->definitions.insert("System.out.wait");
        this->definitions.insert("System.err.wait");
    }

    void JavaSemantics::throw_error(std::string msg) {
        std::cerr<< BOLDWHITE << *current_location << ": " << RESET;
        std::cerr<< BOLDRED << "error: "<<RESET;
        std::cerr<<msg<<std::endl;

        throw std::runtime_error("error");
        // exit(0);
    }

    void JavaSemantics::warning(std::string msg) {
        std::cout<< BOLDWHITE << *current_location << ": " << RESET;
        std::cout<< BOLDMAGENTA <<"warning: "<<RESET;
        std::cout<<msg<<std::endl;
    } 


    /**
     * @brief Creates a new scope and pushes it to the symbol table
     * 
     * @param global 
     */
    void JavaSemantics::add_scope() {
        this->symbol_table.push_back(scope{});
    }
    

    /**
     * @brief Frees up the last scope in the symbol table
     * 
     */
    void JavaSemantics::free_scope() {

        // We don't check the global scope for usage
        if (this->symbol_table.size() > 1) {
            for (auto& it: this->symbol_table[this->symbol_table.size()-1].symbols) {
                if (!it.second.is_used) {
                    this->warning(highlight(it.first) + " is declared but its value is never used");
                }
            }
        }
        this->symbol_table.pop_back();
    }


    /**
     * @brief Searches for a symbol in the symbol table
     * 
     * @param search_global whether to search in the global scope or not
     * @param prioritize_local start by searching on the local scope first. If not found fallback to global scope
     * @return the scope where the symbol was found, -1 if not found
     */
    int JavaSemantics::find_symbol(std::string name, bool search_global, bool prioritize_local) {

/**
* @note Needs to be rewritten, finding the symbol needs to be from the current scope (most inner one) to the global scope.
**/

        int start = (prioritize_local)?1:(search_global?0:1);
        for (unsigned int i=start; i<symbol_table.size(); i++) {
            if ( symbol_table[i].symbols.count(name) != 0 ) {
                return i;
            }
        }
        
        if (prioritize_local && search_global) {
            if ( symbol_table[0].symbols.count(name) != 0 ) {
                return 0;
            }
        }

        return -1;
    }


    /**
     * @brief Add a new symbol to the current scope
     * 
     * @param name the name of the symbol (identifier)
     * @param symbol Information about the symbol
     */
    void JavaSemantics::add_symbol(std::string name, symbol_entry symbol) {

        // std::cout<< "Adding new symbol with name " << name << std::endl;

        // if we only have the global scope currently , then we need to check it for possible redefinition
        bool search_global = (this->symbol_table.size() == 1);
        if (this->find_symbol(name, search_global) != -1) {
            this->throw_error("symbol " + highlight(name) + " already defined");
            return;
        }

        this->symbol_table.back().symbols[name] = { symbol.type, symbol.ident_type, symbol.is_initialized, symbol.is_used, symbol.args };
    }


    /**
     * @brief Add the current symbol to the current scope
     * 
     */
    void JavaSemantics::add_current_symbol() {
        this->add_symbol(this->current_symbol, this->current_symbol_entry);
    }


    /**
     * @brief Resets the current symbol name and entry
     * 
     */
    void JavaSemantics::reset_current_symbol() {
        this->current_symbol.clear();
        this->reset_current_symbol_entry();
    }

    /**
     * @brief Resets the current symbol entry
     * 
     */
    void JavaSemantics::reset_current_symbol_entry() {
        this->current_symbol_entry.ident_type = identifier_type::UNDEF;
        this->current_symbol_entry.is_initialized = false;
        this->current_symbol_entry.is_used = false;
        this->current_symbol_entry.type.clear();
        this->current_symbol_entry.args = {};
    }

    /**
     * @brief Checks whether a symbol has been declared so it can be used
     * 
     */
    bool JavaSemantics::check_definition(std::string name) {
        // If we are within a function, check for params definition

        if (this->find_symbol(name, true) == -1) {
            this->throw_error("symbol " + highlight(name) + " not declared");
            return false;
        }
        return true;
    }


    /**
     * @brief Assigns a value to an already declared variable
     * 
     * @param name 
     */
    void JavaSemantics::assign_value(std::string name) {

        int scope = this->find_symbol(name, true, true); // start by searching local scope
        if ( scope == -1) {
                this->throw_error("symbol " + highlight(name) + " not declared");
            } 
        this->symbol_table[scope].symbols.at(name).is_initialized = true;
    }

    /**
     * @brief Uses the value in a symbol & mark it as used
     * 
     * @param name 
     */
    void JavaSemantics::use_symbol(std::string name) {
        int scope = this->find_symbol(name, true, true); // start by searching local scope
        if ( scope == -1) {
                this->throw_error("symbol " + highlight(name) + " not declared");
            }
        
        if (!this->symbol_table[scope].symbols.at(name).is_initialized) {
            this->throw_error("symbol " + highlight(name) + " not initialized yet");
        }

        this->symbol_table[scope].symbols.at(name).is_used = true;
    }


    void JavaSemantics::add_arg_to_current(std::string name, std::string type) {

        // std::cout<<"Adding new arg " << name <<" of type " << type <<std::endl;
        // std::cout << "current method is "<<current_method<<std::endl;
        scope current_scope = this->symbol_table.back();

        std::deque<argument> args = current_scope.symbols.at(current_method).args;
        // std::cout <<"current number of args is" << args.size()<<std::endl;
        for ( auto& it:args) {
            // std::cout << "Current iteration is on" << it.name<<std::endl;
            if (it.name.compare(name) == 0) {
                this->throw_error("argument with name " + highlight(name) + " already used");
            }
        }
        this->symbol_table.back().symbols.at(current_method).args.push_front({name, type}); // since we're ascending , the insertion needs to happen in reverse
    }

    void JavaSemantics::set_current_method_call(std::string name)  {
        

        if (this->definitions.count(name) != 0 ) {
            this->current_method_call = name;
            this->is_call_definition = true;
            return ;
        }
        // we will only check the global scope
        if (this->symbol_table.front().symbols.count(name) == 0 )
            this->throw_error("no method with name "+ highlight(name) + " declared");

        symbol_entry symbol = this->symbol_table.front().symbols.at(name);

        if (symbol.ident_type != identifier_type::METHOD)
            this->throw_error("symbol "+highlight(name)+ " is not a method");

        this->current_method_call = name;
        this->is_call_definition = false;
    }

    void JavaSemantics::check_args_number() {
        if (is_call_definition)
            return;
        
        int expected = this->symbol_table.front().symbols.at(current_method_call).args.size();

        if ( args_number != expected)
            this->throw_error("invalid number of arguments for "+highlight(current_method_call)+
            ", expected "+highlight(std::to_string(expected))+" got "+highlight(std::to_string(args_number)));

        args_number = 0;
    }

    /**
     * @brief Used to highlight a certain identifier
     * 
     * @param identifier 
     * @return std::string 
     */
    std::string JavaSemantics::highlight(std::string identifier) {

        return BOLDWHITE+std::string("'"+identifier+"'")+RESET;
    }

} // namespace javacompiler