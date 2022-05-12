//
// Created by ramizouari on 11/05/22.
//

#ifndef QIDE_CODEGENERATOR_HH
#define QIDE_CODEGENERATOR_HH

#include <memory>
#include "java_semantics.hh"
#include "opcode.hh"
#include "Instruction.hh"

namespace javacompiler
{

    class CodeGenerator {
        JavaSemantics * semantics;
        std::vector<std::unique_ptr<Instruction>> instructions;
    public:
        explicit CodeGenerator(JavaSemantics& semantics);
        void setSemantics(JavaSemantics& semantics);
        int addInstruction(Opcode opcode);
        int addInstruction(Opcode opcode, int op);
        int addInstruction(Opcode opcode,int op1,int op2);
        int addInstruction(Opcode opcode,const std::string &name);
        int addInstruction(Opcode opcode, const std::string &name1, const std::string &name2);
        int addFunctionEntry(const std::string &name);
        template<typename T0,typename ...T>
        int callFunction(const std::string &name,T0 param,T ...params)
        {
            addInstruction(name,param);
            return (callFunction(name,params),...);
        }
        int callFunction(const std::string &name);
        void setOperand(int k,int op);
        void setOperand(int k,int op1,int op2);
        int getOffset(const std::string &name);
        int currentInstructionOffset() const;
        std::string generateCode() const;
        std::string make_tmp_symbol(const symbol_entry& entry);
        std::unordered_set<std::string> ignore_list;
        std::unordered_map<std::string,int> fn_offset;
    };

} // javacompiler

#endif //QIDE_CODEGENERATOR_HH
