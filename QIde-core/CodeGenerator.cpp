//
// Created by ramizouari on 11/05/22.
//

#include <sstream>
#include "CodeGenerator.h"

namespace javacompiler {
    CodeGenerator::CodeGenerator(JavaSemantics &semantics):semantics(&semantics) {
    }

    void CodeGenerator::setSemantics(JavaSemantics &semantics) {
        this->semantics=&semantics;
    }

    void CodeGenerator::addInstruction(Opcode opcode) {
            instructions.push_back(std::make_unique<Instruction>(opcode));
    }

    void CodeGenerator::addInstruction(Opcode opcode, int op) {
        instructions.push_back(std::make_unique<UnaryInstruction>(opcode,op));
    }

    void CodeGenerator::addInstruction(Opcode opcode, int op1, int op2) {
        instructions.push_back(std::make_unique<BinaryInstruction>(opcode,op1,op2));
    }

    int CodeGenerator::getOffset(const std::string &name) {
    }


} // javacompiler