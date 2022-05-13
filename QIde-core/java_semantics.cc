#include <functional>
#include <sstream>
#include "java_semantics.hh"

namespace javacompiler {

    JavaSemantics::JavaSemantics(ErrorHandler& errorHandler) {
        init_definitions();
        reset_current_symbol_entry();
        this->current_method = ""; 
        this->current_method_call = "";
        this->args_number = 0;
        this->errorHandler = &errorHandler;
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

    void JavaSemantics::throw_error(const std::string& msg) {
        // std::cerr<< BOLDWHITE << *current_location << ": " << RESET;
        // std::cerr<< BOLDRED << "error: "<<RESET;
        // std::cerr<<msg<<std::endl;

        // throw std::runtime_error("error");
        this->errorHandler->error(*this->current_location, msg);
    }

    void JavaSemantics::warning(const std::string& msg) {
        // std::cout<< BOLDWHITE << *current_location << ": " << RESET;
        // std::cout<< BOLDMAGENTA <<"warning: "<<RESET;
        // std::cout<<msg<<std::endl;
        this->errorHandler->warning(*this->current_location, msg);
    } 



    void JavaSemantics::add_scope() {
        if(symbol_table.empty())
            symbol_table.emplace_back();
        else {
            int offset=scopeType==scope_type::ANONYMOUS;
            symbol_table.emplace_back(offset?symbol_table.back().symbolsAlignment.back().offset:0);
        }
        scopeType=scope_type::ANONYMOUS;
    }
    

    void JavaSemantics::free_scope() {

        // We don't check the global scope for usage
        if (this->symbol_table.size() > 1) {
            for (auto& it: this->symbol_table[this->symbol_table.size()-1].symbols) {
                if (!it.second.is_used) {
                    this->warning(errorHandler->highlight(it.first) + " is declared but its value is never used");
                }
            }
        }
        this->symbol_table.pop_back();
    }



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


    void JavaSemantics::add_symbol(std::string name, symbol_entry symbol) {

        // std::cout<< "Adding new symbol with name " << name << std::endl;

        // if we only have the global scope currently , then we need to check it for possible redefinition
        bool search_global = (this->symbol_table.size() == 1);
        if (this->find_symbol(name, search_global) != -1) {
            this->throw_error("symbol " + errorHandler->highlight(name) + " already defined");
            return;
        }
        symbol.pos=symbol_table.back().symbols.size();
        this->symbol_table.back().push_back(name,symbol);
        //std::cout << symbol_table.back().getAlignment(name).second << ' ' << std::flush;
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
        current_symbol_entry.pos=0;
    }

    /**
     * @brief Checks whether a symbol has been declared so it can be used
     * 
     */
    bool JavaSemantics::check_definition(std::string name) {
        // If we are within a function, check for params definition

        if (this->find_symbol(name, true) == -1) {
            this->throw_error("symbol " + errorHandler->highlight(name) + " not declared");
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
                this->throw_error("symbol " + errorHandler->highlight(name) + " not declared");
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
                this->throw_error("symbol " + errorHandler->highlight(name) + " not declared");
            }
        
        if (!this->symbol_table[scope].symbols.at(name).is_initialized) {
            this->throw_error("symbol " + errorHandler->highlight(name) + " not initialized yet");
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
                this->throw_error("argument with name " + errorHandler->highlight(name) + " already used");
            }
        }
        this->symbol_table.back().symbols.at(current_method).args.push_front({name, type}); // since in the grammar we're parsing in reverse , the insertion needs to happen this way
    }

    void JavaSemantics::set_current_method_call(std::string name)  {
        

        if (this->definitions.count(name) != 0 ) {
            this->current_method_call = name;
            this->is_call_definition = true;
            return ;
        }
        // we will only check the global scope
        if (this->symbol_table.front().symbols.count(name) == 0 )
            this->throw_error("no method with name "+ errorHandler->highlight(name) + " declared");

        symbol_entry symbol = this->symbol_table.front().symbols.at(name);

        if (symbol.ident_type != identifier_type::METHOD)
            this->throw_error("symbol "+ errorHandler->highlight(name) + " is not a method");

        this->current_method_call = name;
        this->is_call_definition = false;
    }

    void JavaSemantics::check_args_number() {
        if (is_call_definition)
            return;
        
        int expected = this->symbol_table.front().symbols.at(current_method_call).args.size();

        if ( args_number != expected)
            this->throw_error("invalid number of arguments for "+errorHandler->highlight(current_method_call)+
            ", expected "+errorHandler->highlight(std::to_string(expected))+" got "+errorHandler->highlight(std::to_string(args_number)));

        args_number = 0;
    }

    int JavaSemantics::indexOf(const std::string &name) const {
        return symbol_table.size()-1-std::distance(symbol_table.rbegin(),std::find_if(symbol_table.rbegin(),symbol_table.rend(),
                            [&name](const scope &U)
                            {
                                return U.symbols.count(name);
                            }));
    }

    std::string JavaSemantics::make_tmp_symbol(const symbol_entry &entry) {
        std::stringstream stream;
        stream << "@" << std::hex << tmp_counter++;
        auto name=stream.str();
        add_symbol(name,entry);
        return name;
    }

    void JavaSemantics::setInitialized(const std::string &name) {
        getEntry(name).is_initialized=true;
    }

    symbol_entry &JavaSemantics::getEntry(const std::string &name) {
       auto& entry= std::find_if(symbol_table.rbegin(),symbol_table.rend(),
                     [&name](const scope &U)
                     {
                         return U.symbols.count(name);
                     })->symbols[name];
        return entry;
    }


    void scope::push_back(const std::string &name,const symbol_entry& symbol)
    {
        symbols.emplace(name,symbol);
        symbolsAlignment.push_back({name,symbols[name],symbolsAlignment.empty()?offset:symbolsAlignment.back().offset+1});

    }

    scope::scope(int O) :offset(O){

    }

    void scope::pop_back() {
        auto &&[name,symbol,offset]=symbolsAlignment.back();
        symbols.erase(name);
        symbolsAlignment.pop_back();
    }

    std::pair<std::reference_wrapper<symbol_entry>,int> scope::getAlignment(const std::string &name) {
        auto & R=symbols.at(name);
        return std::make_pair(std::ref(R),symbolsAlignment[R.pos].offset);
    }
} // namespace javacompiler