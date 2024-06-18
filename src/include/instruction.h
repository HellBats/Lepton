#ifndef INSTRUCTION_DOT_H
#define INSTRUCTION_DOT_H
typedef enum Opcode
{
    HLT=0,
    LOAD=1,
    ADD=2,
    SUB=3,
    MUL=4,
    DIV=5,
    JMP=6,
    JMPF=7,
    JMPB=8,
    EQ=9,
    NEQ=10,
    GT=11,
    LT=12,
    GTQ=13,
    LTQ=14,
    JEQ=15,
}Opcode;

typedef struct Instruction
{
    Opcode opcode;

}Inst;

Inst NewInst();
#endif