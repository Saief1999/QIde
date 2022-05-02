## Overview

This directory contains the core functionalities of the **Java Compiler**. Written with `flex`( lexical scanner ) and `bison` ( syntax analyzer ). Look at the next section If you want to compile from source ( if you want to run the compiler without the UI )

## Usage (as a standalone application)

### Compiling sources

You can use one of the two methods listed below. Note that both will generate a `javacompiler` binary. That's your entry point to the application

Note that you'll only have access to the core compiler ( No GUI ). If you want to use the GUI run the entire project ( through `CMakeLists.txt` )

#### Using the makefile

To compile everything, run :

```bash
make
```

To clean object files, run : 

```bash
make clean
```


to clean generated files (by flex/bison) in addition to object files, run :

```bash
make cleanall
```

#### Using the script

You can also compile the project by running the script :

```bash
./analyze++
```

### Running the compiler

To run the compiler, simply run the generated binary while providing the **java file** on input

```bash
./javacompiler Test.java
```

Or You can also pipe the input

```bash
./javacompiler < Test.java # cat Test.java | ./javacompiler
```



> **Note:** No output will be given if no errors have been detected. Add errors to your source file and check the generated errors. 