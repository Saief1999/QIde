//
// Created by ramizouari on 11/05/22.
//

#ifndef QIDE_INSTRUCTION_HH
#define QIDE_INSTRUCTION_HH

#include "opcode.hh"

namespace javacompiler {

    struct Instruction
    {
        Opcode opcode;
        virtual operator std::string() const;
        Instruction(Opcode opcode);
        virtual ~Instruction() = default;
    };

    struct UnaryInstruction : public Instruction
    {
        int op;
        UnaryInstruction(Opcode opcode, int op);
        operator std::string() const override;
        ~UnaryInstruction() override = default;

    };

    struct BinaryInstruction : public Instruction
    {
        int op1, op2;
        BinaryInstruction(Opcode opcode, int op1,int op2);

        operator std::string() const override;
    };

    std::string  to_string(const Instruction &instruction);
} // javacompiler

#endif //QIDE_INSTRUCTION_HH
