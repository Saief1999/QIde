//
// Created by ramizouari on 11/05/22.
//

#include <sstream>
#include "CodeGenerator.hh"

namespace javacompiler {
    CodeGenerator::CodeGenerator(JavaSemantics &semantics):semantics(&semantics) {
    }

    void CodeGenerator::setSemantics(JavaSemantics &semantics) {
        this->semantics=&semantics;
    }

    int CodeGenerator::addInstruction(Opcode opcode) {
            instructions.push_back(std::make_unique<Instruction>(opcode));
            return instructions.size();
    }

    int CodeGenerator::addInstruction(Opcode opcode, int op) {
        instructions.push_back(std::make_unique<UnaryInstruction>(opcode,op));
        return instructions.size();
    }

    int CodeGenerator::addInstruction(Opcode opcode, int op1, int op2) {
        instructions.push_back(std::make_unique<BinaryInstruction>(opcode,op1,op2));
        return instructions.size();
    }

    int CodeGenerator::getOffset(const std::string &name)
    {
        auto I=semantics->indexOf(name);
        if(I==-1)
            throw std::logic_error("Variable " + name + " is not found on the table");
        auto pos = semantics->symbol_table.at(I).symbols[name].pos;
        auto offset = semantics->symbol_table.at(I).symbolsAlignment[pos].offset;
        return offset;
    }

    int CodeGenerator::addInstruction(Opcode opcode, const std::string &name) {
        return addInstruction(opcode, getOffset(name));
    }

    int CodeGenerator::addInstruction(Opcode opcode, const std::string &name1, const std::string &name2) {
        return addInstruction(opcode, getOffset(name1), getOffset(name2));
    }

    std::string CodeGenerator::generateCode() const {
        std::stringstream  S;
        for(const auto &insPtr:instructions)
            S << to_string(*insPtr) << '\n';
        return S.str();
    }

    std::string CodeGenerator::make_tmp_symbol(const symbol_entry &entry) {
        return semantics->make_tmp_symbol(entry);
    }

    void CodeGenerator::setOperand(int k, int op) {
        dynamic_cast<UnaryInstruction&>(*instructions[k]).op=op;
    }

    void CodeGenerator::setOperand(int k, int op1, int op2) {
        auto binaryIns= dynamic_cast<BinaryInstruction&>(*instructions[k]);
        binaryIns.op1=op1;
        binaryIns.op2=op2;
    }

    int CodeGenerator::currentInstructionOffset()  const {
        return instructions.size();
    }

    int CodeGenerator::addFunctionEntry(const std::string &name)
    {
        auto offset=currentInstructionOffset();
        fn_offset.emplace(name,offset);
        return addInstruction(Opcode::ENTRY,offset);
    }

    int CodeGenerator::callFunction(const std::string &name) {
        return addInstruction(Opcode::CALL,fn_offset[name]);
    }


} // javacompiler