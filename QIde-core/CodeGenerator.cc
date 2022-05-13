//
// Created by ramizouari on 11/05/22.
//

#include <sstream>
#include "CodeGenerator.hh"

namespace javacompiler {
    CodeGenerator::CodeGenerator(JavaSemantics &semantics):semantics(&semantics),instructionsMap(1),instructions(instructionsMap.front()) {
        for(const auto &fn:semantics.definitions)
            fn_offset.emplace(fn,-1-fn_offset.size());
        addInstruction(Opcode::MAIN,0);
    }

    void CodeGenerator::setSemantics(JavaSemantics &semantics) {
        this->semantics=&semantics;
    }

    int CodeGenerator::addInstruction(Opcode opcode) {
        auto address=instructions.get().size();
        instructions.get().push_back(std::make_unique<Instruction>(opcode));
        return address;
    }

    int CodeGenerator::addInstruction(Opcode opcode, int op) {
        auto address=instructions.get().size();
        instructions.get().push_back(std::make_unique<UnaryInstruction>(opcode,op));
        return address;
    }

    int CodeGenerator::addInstruction(Opcode opcode, int op1, int op2) {
        auto address=instructions.get().size();
        instructions.get().push_back(std::make_unique<BinaryInstruction>(opcode,op1,op2));
        return address;
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
        if(main_offset==0)
            throw std::logic_error("Main function is not defined");
        std::stringstream  S;
        for(const auto &insPtr:instructionsMap.front())
            S << to_string(*insPtr) << '\n';
        return S.str();
    }

    std::string CodeGenerator::make_tmp_symbol(const symbol_entry &entry) {
        return semantics->make_tmp_symbol(entry);
    }

    void CodeGenerator::setOperand(int k, int op) {
        dynamic_cast<UnaryInstruction&>(*instructions.get()[k]).op=op;
    }

    void CodeGenerator::setOperand(int k, int op1, int op2) {
        auto binaryIns= dynamic_cast<BinaryInstruction&>(*instructions.get()[k]);
        binaryIns.op1=op1;
        binaryIns.op2=op2;
    }

    int CodeGenerator::currentInstructionOffset()  const {
        return instructions.get().size();
    }

    int CodeGenerator::addFunctionEntry(const std::string &name)
    {
        auto offset=currentInstructionOffset();
        if(name=="main") {
            main_offset = offset;
            setOperand(0,main_offset);
        }
        fn_offset.emplace(name,offset);
        return addInstruction(Opcode::ENTRY,offset);
    }

    int CodeGenerator::callFunction(const std::string &name) {
        return addInstruction(Opcode::CALL,fn_offset[name]);
    }

    void CodeGenerator::createBranch(const std::string &name)
    {
        branchesNames.emplace(name,instructionsMap.size());
        instructionsMap.emplace_back();
        instructions=instructionsMap.back();
    }

    void CodeGenerator::combineBranches(const std::vector<std::string> &order) {
        instructions=instructionsMap.front();
        for(const auto &O:order)
        {
            auto I=branchesNames[O];
            std::move(instructionsMap[I].begin(),instructionsMap[I].end(),std::back_inserter(instructions.get()));
            branchesNames.erase(O);
        }
    }

    void CodeGenerator::setDefaultBranch(const std::string &name) {
        instructions=instructionsMap[branchesNames[name]];
    }

    std::string CodeGenerator::createBranch() {
        std::string name="@"+std::to_string(instructionsMap.size());
        createBranch(name);
        return name;
    }

    void CodeGenerator::combineBranches() {
        instructions=instructionsMap.front();
        for(int i=1;i<instructionsMap.size();i++)
            std::move(instructionsMap[i].begin(),instructionsMap[i].end(),std::back_inserter(instructions.get()));
        std::vector<std::string> delete_list;
        for(const auto &[name,i]:branchesNames)
            if(i)
                delete_list.emplace_back(name);
        for(const auto &name:delete_list)
            branchesNames.erase(name);
    }

    void CodeGenerator::setDefaultBranch(int index) {
        instructions=instructionsMap[index];
    }


} // javacompiler