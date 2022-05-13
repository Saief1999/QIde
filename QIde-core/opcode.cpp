//
// Created by ramizouari on 11/05/22.
//
#include "opcode.hh"
#include <stdexcept>

std::string javacompiler::to_string(Opcode opcode)
{
    switch (opcode)
    {

        case Opcode::LDC:
            return "LDC";
        case Opcode::LDV:
            return "LDV";
        case Opcode::STORE:
            return "STORE";
        case Opcode::APPEL:
            return "CALL";
        case Opcode::ENTREE:
            return "ENTRY";
        case Opcode::SORTIE:
            return "END";
        case Opcode::RETOUR:
            return "RETURN";
        case Opcode::ADD:
            return "ADD";
        case Opcode::MUL:
            return "MUL";
        case Opcode::SUB:
            return "SUB";
        case Opcode::DIV:
            return "DIV";
        case Opcode::MOD:
            return "MOD";
        case Opcode::INF:
            return "LESS";
        case Opcode::INFE:
            return "LEQ";
        case Opcode::SUP:
            return "GREATER";
        case Opcode::SUPE:
            return "GEQ";
        case Opcode::DIFF:
            return "NEQ";
        case Opcode::EGAL:
            return "EQUAL";
        case Opcode::INC:
            return "INC";
        case Opcode::DEC:
            return "DEC";
        case Opcode::NEG:
            return "NEG";
        case Opcode::NOT:
            return "NOT";
        case Opcode::COMP:
            return "COMP";
        case Opcode::JMP:
            return "JMP";
        case Opcode::JMP_Z:
            return "JMP_Z";
        case Opcode::JMP_NZ:
            return "JMP_NZ";
        case Opcode::NOOP:
            return "NOOP";
        case Opcode::POP:
            return "POP";
        case Opcode::MAIN:
            return "MAIN";
        default:
            throw std::runtime_error("Unknown opcode");
    }
}