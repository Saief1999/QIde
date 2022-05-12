# a simple Makefile to build the compiler

CXX = g++
LEX = flex
YACC = bison

CXXFLAGS = -W -Wall -Wextra -ansi -g -std=c++17

# We need to add the header files to the list of files to be compiled
HEADERS = driver.hh java_parser.hh java_lexer.hh location.hh utils.hh java_semantics.hh error_handler.hh cli_error_handler.hh 
    

all: javacompiler

# Generate scanner and parser

# -d is not necessary since we added "%defines" to the .yy file
java_parser.cc: java_parser.yy
	$(YACC) -o java_parser.cc java_parser.yy 

java_lexer.cc: java_lexer.ll
	$(LEX) -o java_lexer.cc java_lexer.ll

# Implicit rule to compile c++ files
# $@ is the name of the target being generated, and $< the first prerequisite (usually a source file). 
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Link executable

javacompiler: java_parser.o java_lexer.o cli_error_handler.o main.o driver.o java_semantics.o CodeGenerator.o opcode.o Instruction.o
	$(CXX) -o $@ java_parser.o java_lexer.o cli_error_handler.o main.o driver.o java_semantics.o CodeGenerator.o opcode.o Instruction.o

clean:
	rm -f javacompiler *.o

cleanall: clean
	rm -f java_parser.cc java_parser.hh java_lexer.cc location.hh
