//
// Created by ramizouari on 11/05/22.
//

#ifndef QIDE_OPCODE_H
#define QIDE_OPCODE_H

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
        EQUAL=EGAL,
        EQ=EQUAL,
        LESS=INF,
        LEQ=INFE,
        GREATER=SUP,
        GEQ=SUPE,
        NEQ=DIFF,
        RETURN=RETOUR,
        CALL=APPEL,
        ENTRY=ENTREE,
        END=SORTIE
    };
    std::string to_string(Opcode opcode);
}
#endif //QIDE_OPCODE_H
