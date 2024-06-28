#ifndef INSTRUCTION_DOT_H
#define INSTRUCTION_DOT_H
#include<stdint.h>
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
    ALOC=16,
}Opcode;

typedef struct Instruction
{
    Opcode opcode;
    uint8_t registers_no;
    uint8_t operands_no;
    uint8_t registers[3];
    uint16_t operands[2];
    char *LabelDeclaration;
    char *LabelUsage;
    char *Directives;
}Inst;

Inst NewInst();
int SetInst(Inst *instruct,char* []); 
Opcode SetOpcode(char* instructions[],int i);
uint8_t SetRegister(char* instructions[],int j);
uint16_t SetOperand(char* instructions[],int j);
int power(int a,int b);
#endif