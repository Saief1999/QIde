
#ifndef DRIVER_HH
# define DRIVER_HH

#include <string>
#include <vector>
#include "java_semantics.hh"

namespace javacompiler {
/**
 * @brief This class works as a "glue" between the parser and the scanner.
 * @note We should apply polymorphism here, so that the driver can be used with the GUI or with the console.   
 */
class Driver {
public:
    Driver(ErrorHandler& errorHandler);

    /// stream name (file or input stream) used for error messages.
    std::string streamname;
    
    ErrorHandler* errorHandler;
    
    /** Invoke the scanner and parser for a stream.
     * @param in	input stream
     * @param sname	stream name for error messages
     * @return		true if successfully parsed
     */
    bool parse_stream(std::istream& in,
		      const std::string& sname = "stream input");

    /** Invoke the scanner and parser on an input string.
     * @param input	input string
     * @param sname	stream name for error messages
     * @return		true if successfully parsed
     */
    bool parse_string(const std::string& input,
		      const std::string& sname = "string stream");

    
    /** Invoke the scanner and parser on a file. Use parse_stream with a
     * std::ifstream if detection of file reading errors is required.
     * @param filename	input file name
     * @return		true if successfully parsed
     */
    bool parse_file(const std::string& filename);

    /** Error handling with associated line number. This can be modified to
     * output the error e.g. to a dialog box. */
    void error(const class location& l, const std::string& m);

    /** General error handling. This can be modified to output the error
     * e.g. to a dialog box. */
    // void error(const std::string& m);

    class JavaLexer* lexer;
    class JavaSemantics *semantics;
};

} // namespace javacompiler

#endif // ! DRIVER_HH
