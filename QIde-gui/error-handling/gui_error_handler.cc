#include "gui_error_handler.hh"

namespace javacompiler {
        void GuiErrorHandler::syntax_error(const location& l, const std::string& msg) {
            std::stringstream stream;

            stream  << "<b>" <<l<< ":</b> "<< msg  << "<br>";

            QString message = QString::fromStdString(stream.str());
            textEdit->insertHtml(message);
        }


        void GuiErrorHandler::error(const std::string& msg) {
            std::stringstream stream;

            stream << "<span style='color:darkred;'><b>error:</b></span> ";
            stream <<msg << "<br>";

            QString message = QString::fromStdString(stream.str());
            textEdit->insertHtml(message);

            throw std::runtime_error("error");
        }

        void GuiErrorHandler::error(const location& l, const std::string& msg) {
            std::stringstream stream;

            stream << "<b>" <<l<< ":</b> ";
            stream << "<span style='color:darkred;'><b>error:</b></span> ";
            stream <<msg << "<br>";

            QString message = QString::fromStdString(stream.str());
            textEdit->insertHtml(message);

            throw std::runtime_error("error");
        }
        
        void GuiErrorHandler::warning(const location& l, const std::string& msg) {
            std::stringstream stream;

            stream  << "<b>" <<l<<":</b> "; 
            stream << "<span style='color:#ff00ff;'><b>warning:</b></span> ";
            stream << msg << "<br>";

            QString message = QString::fromStdString(stream.str());
            textEdit->insertHtml(message);
        }

        std::string GuiErrorHandler::highlight(const std::string& identifier) {
            return "<b>'"+identifier+"'</b>";
        }

        void GuiErrorHandler::setTextEdit(QTextEdit& textEdit) {
            this->textEdit = &textEdit;
        }

} // namespace javacompiler