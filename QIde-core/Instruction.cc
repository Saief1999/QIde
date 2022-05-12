//
// Created by ramizouari on 11/05/22.
//

#include <string>
#include <sstream>
#include "Instruction.h"

namespace javacompiler
{
    Instruction::operator std::string() const {
        return to_string(opcode);
    }

    Instruction::Instruction(Opcode opcode) :opcode(opcode){

    }

    UnaryInstruction::operator std::string() const {
        auto str=Instruction::operator std::string();
        return str+" "+std::to_string(op) ;
    }

    UnaryInstruction::UnaryInstruction(Opcode opcode,int op) : Instruction(opcode), op(op){

    }


    BinaryInstruction::operator std::string() const {
        auto str=Instruction::operator std::string();
        return str + " " +std::to_string(op1) + " " + std::to_string(op2);
    }

    BinaryInstruction::BinaryInstruction(Opcode opcode, int op1,int op2): Instruction(opcode),op1(op1),op2(op2) {}

    std::string to_string(Instruction &instruction);
} // javacompiler