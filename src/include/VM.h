#ifndef VM_DOT_H
#define VM_DOT_H
#include<stdint.h>
#include"include/program.h"
#include"include/instruction.h"

typedef struct VM
{
    int registers[32];
    unsigned int program_counter;
    vector* program;
    vector* heap;
    unsigned int remainder;
    uint8_t equal_flag;
} VM;

VM NewVM(unsigned int size);
uint8_t DecodeOpCode(VM *vm);
void RunVM(VM *vm);
uint8_t ExecuteInstruction(VM *vm);
void RunOnceVM(VM *vm);
uint8_t Next8bits(VM *vm);
uint16_t Next16bits(VM *vm);

#endif