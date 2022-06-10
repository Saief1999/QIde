//
// Created by ramizouari on 11/05/22.
//

#ifndef QIDE_CODEGENERATOR_HH
#define QIDE_CODEGENERATOR_HH

#include <memory>
#include "java_semantics.hh"
#include "opcode.hh"
#include "instruction.hh"
#include <map>

namespace javacompiler
{

    /**
     * @brief Generator of the instructions list from the source code.
     * @details This class is used to generate the instructions list from the source code. It uses the JavaSemantics to get additional semantic information.
     * @param semantics The JavaSemantics used to get additional information.
     * */
    class CodeGenerator {
        JavaSemantics * semantics;
        /**
         * @brief The instructions map.
         * @details The instructions map is a vector of instructions vectors. Each vector element is a list of instructions.
         * It is used to generate independent instructions lists, and gives the ability to combine them into the final instructions list.
         * The final instructions list is the one that is used to generate the executable code, and is called the main. It is guaranteed to exists, and it is
         * the first element of the instructions map.
         * */
        std::vector<std::vector<std::unique_ptr<Instruction>>> instructionsMap;
        /**
         * @brief The current instructions vector.
         * @details The current instructions vector is the one that is used to generate the executable code.
         * It is the one that is modified to calls to the addInstruction method.
         * */
        std::reference_wrapper<std::vector<std::unique_ptr<Instruction>>> instructions;
        /**
         * @brief The name of each instruction list.
         * @details branchesNames keeps track of the name of each instructions list. It gives the ability to keep track of instructions given their name.
         * */
        std::unordered_map<std::string,int> branchesNames;
    public:
        explicit CodeGenerator(JavaSemantics& semantics);
        void setSemantics(JavaSemantics& semantics);
        /**
         * @brief Adds an instruction to the current instructions vector.
         * */
        int addInstruction(Opcode opcode);
        /**
         * @brief Adds an instruction to the current instructions vector, with a given  operand.
         * */
        int addInstruction(Opcode opcode, int op);
        /**
         * @brief Adds an instruction to the current instructions vector, with two given operands.
         * */
        int addInstruction(Opcode opcode,int op1,int op2);
        /**
         * @brief Adds an instruction to the current instructions vector, with a given variable name.
         * @details Internally, The variable name is used to get the offset of the variable in the symbol table.
         * Also, the operand of the given opcode will be that offset.
         * */
        int addInstruction(Opcode opcode,const std::string &name);
        /**
         * @brief Adds an instruction to the current instructions vector, with a given variable name.
         * @details Internally, The variable names are used to get the offsets of the variable in the symbol table.
         * Also, the operand of the given opcode will be that offsets.
         * */
        int addInstruction(Opcode opcode, const std::string &name1, const std::string &name2);
        /**
         * @brief Adds a function entry instruction, given the name of that function.
         * @details Internally, this function register the name of the function in the functional symbol table. And then, it adds an instruction to the current instructions vector.
        * */
        int addFunctionEntry(const std::string &name);
        template<typename T0,typename ...T>
        int callFunction(const std::string &name,T0 param,T ...params)
        {
            addInstruction(name,param);
            return (callFunction(name,params),...);
        }
        /**
         * @brief Calls a function, given the name of that function.
         * @details Internally, this function searches the function address from the functional symbol table.
         * And then, it adds a CALL instruction to the current instructions vector, with the found address.
         * */
        int callFunction(const std::string &name);
        /**
     * @brief Changes the value of an operand of an instruction.
     * @requires The instruction must exist in the current instructions vector. And it must be a unary instruction.
     * */
        void setOperand(int k,int op);
        /**
    * @brief Changes the value of an operand of an instruction.
    * @requires The instruction must exist in the current instructions vector. And it must be a binary instruction.
    * */
        void setOperand(int k,int op1,int op2);
        /**
         * @brief get the offset of a variable in the symbol table.
         * */
        int getOffset(const std::string &name);
        int currentInstructionOffset() const;
        std::string generateCode() const;
        std::string make_tmp_symbol(const symbol_entry& entry);
        std::unordered_set<std::string> ignore_list;
        std::unordered_map<std::string,int> fn_offset;
        std::string createBranch();
        void createBranch(const std::string &name);
        void setDefaultBranch(const std::string &name);
        void setDefaultBranch(int index);
        void combineBranches(const std::vector<std::string>&order);
        void combineBranches();
        std::vector<std::vector<std::string>> branchesStack;
        int main_offset=0;//offset of main function, always strictly greater than zero
    };

} // javacompiler

#endif //QIDE_CODEGENERATOR_HH
