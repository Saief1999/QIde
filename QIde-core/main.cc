#include <iostream>
#include <fstream>
#include "driver.hh"

int main(int argc, char *argv[])
{
    javacompiler::Driver driver;

    bool result = false;

    if (argc == 1) { // no args passed
        result = driver.parse_stream(std::cin, "stdin");
    }
    else {
        std::fstream infile(argv[1]);

        if (!infile.good()) {
            std::cerr << "Could not open file: " << argv[1] << std::endl;
            return 0;
        }
        try {
            result = driver.parse_stream(infile, argv[1]);
        }
        catch(...) {
            return 0;
        }
    }
    return result;
}