//
// Created by ramizouari on 11/05/22.
//

#ifndef QIDE_CODEGENERATOR_H
#define QIDE_CODEGENERATOR_H

#include <memory>
#include "java_semantics.hh"
#include "opcode.h"
#include "Instruction.h"

namespace javacompiler
{

    class CodeGenerator {
        JavaSemantics * semantics;
        std::vector<std::unique_ptr<Instruction>> instructions;
    public:
        explicit CodeGenerator(JavaSemantics& semantics);
        void setSemantics(JavaSemantics& semantics);
        void addInstruction(Opcode opcode);
        void addInstruction(Opcode opcode, int op);
        void addInstruction(Opcode opcode,int op1,int op2);
        int getOffset(const std::string &name);
    };

} // javacompiler

#endif //QIDE_CODEGENERATOR_H
