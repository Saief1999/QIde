//
// Created by ramizouari on 11/05/22.
//

#ifndef QIDE_OPCODE_HH
#define QIDE_OPCODE_HH

#include <string>

namespace  javacompiler
{
    enum class Opcode
    {
        LDC,
        LDV,
        STORE,
        APPEL,
        ENTREE,
        SORTIE,
        RETOUR,
        ADD,
        MUL,
        SUB,
        DIV,
        MOD,
        INF,
        INFE,
        SUP,
        SUPE,
        DIFF,
        EGAL,
        INC,
        DEC,
        JMP,
        JMP_Z,
        JMP_NZ,
        POP,
        NOOP,
        LOGICAL_AND,
        LOGICAL_OR,
        LOGICAL_XOR,
        BITWISE_AND,
        BITWISE_OR,
        BITWISE_XOR,
        NEG,
        NOT,
        COMP,
        MAIN,
        RETURN=RETOUR,
        CALL=APPEL,
        ENTRY=ENTREE,
        END=SORTIE,
        EQUAL=EGAL,
        EQ=EQUAL,
        LESS=INF,
        LEQ=INFE,
        GREATER=SUP,
        GEQ=SUPE,
        NEQ=DIFF,
    };
    std::string to_string(Opcode opcode);
}
#endif //QIDE_OPCODE_HH
