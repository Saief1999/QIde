#include "cli_error_handler.hh"

namespace javacompiler {
        void CliErrorHandler::syntax_error(const location& l, const std::string& msg) {
            std::cerr << BOLDWHITE << l << ": " << RESET << msg << std::endl;
        }


        void CliErrorHandler::error(const std::string& msg) {
            std::cerr<< BOLDRED << "error: "<<RESET;
            std::cerr<<msg<<std::endl;

            throw std::runtime_error("error");
        }

        void CliErrorHandler::error(const location& l, const std::string& msg) {
            std::cerr<< BOLDWHITE << l << ": " << RESET;
            std::cerr<< BOLDRED << "error: "<<RESET;
            std::cerr<<msg<<std::endl;

            throw std::runtime_error("error");
        }
        
        void CliErrorHandler::warning(const location& l, const std::string& msg) {
            std::cout<< BOLDWHITE << l << ": " << RESET;
            std::cout<< BOLDMAGENTA <<"warning: "<<RESET;
            std::cout<<msg<<std::endl;
        }

        std::string CliErrorHandler::highlight(const std::string& identifier) {
            return BOLDWHITE+std::string("'"+identifier+"'")+RESET;
        }


} // namespace javacompiler