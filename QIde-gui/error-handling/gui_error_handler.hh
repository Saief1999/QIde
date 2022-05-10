#ifndef GUI_ERROR_HANDLER_HH
#define GUI_ERROR_HANDLER_HH

#include "error_handler.hh"
#include "utils.hh"
#include <QTextEdit>
#include <QString>
#include "sstream"

namespace javacompiler {

    class GuiErrorHandler:public ErrorHandler {

    private:
        QTextEdit* textEdit;
    public:
        void syntax_error(const location& l, const std::string& msg);
        void error(const location& l, const std::string& msg);
        void warning(const location& l, const std::string& msg);
        std::string highlight(const std::string& identifier);


        void setTextEdit(QTextEdit& textEdit);
        ~GuiErrorHandler()=default;
    };

} // namespace javacompiler

#endif // GUI_ERROR_HANDLER_HH
