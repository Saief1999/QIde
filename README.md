# QIde

## Overview

This is a mini java compiler. Written in Flex (Lex) and Bison (Yacc). In addition to a GUI written in QT6 and Qt Widgets

## Technical Overview


### Core

The `QIde-core` represents the core functionalities of the compiler. It accepts text from a file, **analyzes** it and generates the appropriate **syntax** and **semantic** errors.

It's possible to run The Core application as a standalone. For more instructions check [The Core README](./QIde-core/README.md)

#### Components

- The analyzer is written in `flex`

- The syntax scanner is written in `bison`. Based on a minified version of the java Grammar

- The semantic analysis uses a `symbol table` : a `list` of `hashmap` ( each represeting a scope ). Check the source code for more info

### GUI

The `QIde-gui` represents the Gui application. The Gui is written entirely in Qt 6 and Qt Widgets. No Ui files have been used in the process ( meaning all the components are written as code, offering more flexibility). For more information check [The Gui README](./QIde-gui/README.md)

## TODO

> Errors are shown on terminal for now. We need to save them in a data structure ( that's also shared by the gui ) in order to make the gui display possible.