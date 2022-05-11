#include <fstream>
#include <sstream>

#include "driver.hh"
#include "java_lexer.hh"
#include "utils.hh"
#include "CodeGenerator.h"

/** The javacompiler namespace is used to encapsulate the three parser classes
 * javacompiler::Parser, javacompiler::Scanner and javacompiler::Driver */
namespace javacompiler {
Driver::Driver(ErrorHandler& errorHandler) {
    this->errorHandler = &errorHandler;
}


bool Driver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

    JavaLexer lexer(&in);

    this->lexer = &lexer;

    JavaParser parser(*this);

    JavaSemantics semantics(*this->errorHandler);
    this->semantics = &semantics;
    CodeGenerator codeGenerator(semantics);
    this->codeGenerator = &codeGenerator;

    return (parser.parse() == 0);
}


bool Driver::parse_file(const std::string &filename)
{
    std::ifstream in(filename.c_str());
    if (!in.good()) return false;
    return parse_stream(in, filename);
}

bool Driver::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
}

void Driver::error(const class location& l,
		   const std::string& m)
{
    this->errorHandler->syntax_error(l,m);
}

// void Driver::error(const std::string& m)
// {
//     std::cerr << m << std::endl;
// }

} // namespace javacompiler