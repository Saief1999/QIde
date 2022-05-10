#ifndef CLI_ERROR_HANDLER_HH
#define CLI_ERROR_HANDLER_HH

#include "error_handler.hh"
#include "utils.hh"

namespace javacompiler {

    class CliErrorHandler:public ErrorHandler {
    public:
        void syntax_error(const location& l, const std::string& msg);
        void error(const location& l, const std::string& msg);
        void warning(const location& l, const std::string& msg);
        std::string highlight(const std::string& identifier);

        ~CliErrorHandler()=default;
    };

} // namespace javacompiler

#endif // CLI_ERROR_HANDLER_HH
