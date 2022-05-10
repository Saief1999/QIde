#ifndef ERROR_HANDLER_HH
#define ERROR_HANDLER_HH

#include "java_parser.hh"
#include <string>

namespace javacompiler {

    class ErrorHandler {
    public:
        virtual void syntax_error(const location& l, const std::string& msg)=0;
        virtual void error(const location& l, const std::string& msg)=0;
        virtual void warning(const location& l, const std::string& msg)=0;

        /**
         * @brief Used to highlight a certain identifier
         * 
         * @param identifier 
         * @return std::string 
         */
        virtual std::string highlight(const std::string& identifier)=0;
        virtual ~ErrorHandler()=default;
    };

} // namespace javacompiler

#endif // ERROR_HANDLER_HH
