#ifndef SCANNER_HH
#define SCANNER_HH


// Flex expects the signature of yylex to be defined in the macro YY_DECL, and
// the C++ parser expects it to be declared. We can factor both as follows.

#ifndef YY_DECL

#define	YY_DECL						\
    javacompiler::JavaParser::token_type				\
    javacompiler::JavaLexer::lex(				\
	javacompiler::JavaParser::semantic_type* yylval,		\
	javacompiler::JavaParser::location_type* yylloc		\
    )
#endif

#ifndef __FLEX_LEXER_H
#define yyFlexLexer JavaFlexLexer
#include <FlexLexer.h>
#undef yyFlexLexer
#endif

#include "java_parser.hh"

namespace javacompiler {
/** JavaLexer is a derived class to add some extra function to the scanner
 * class. Flex itself creates a class named yyFlexLexer, which is renamed using
 * macros to JavaFlexLexer. However we change the context of the generated
 * yylex() function to be contained within the Scanner class. This is required
 * because the yylex() defined in JavaFlexLexer has no parameters. */
class JavaLexer : public JavaFlexLexer
{
public:
    /** Create a new scanner object. The streams arg_yyin and arg_yyout default
     * to cin and cout, but that assignment is only made when initializing in
     * yylex(). */
    JavaLexer(std::istream* arg_yyin = 0,
	    std::ostream* arg_yyout = 0);

    /** Required for virtual functions */
    virtual ~JavaLexer();

    /** This is the main lexing function. It is generated by flex according to
     * the macro declaration YY_DECL above. The generated bison parser then
     * calls this virtual function to fetch new tokens. */
    virtual JavaParser::token_type lex(
	JavaParser::semantic_type* yylval,
	JavaParser::location_type* yylloc
	);

};
} // namespace javacompiler

#endif // SCANNER_HH
