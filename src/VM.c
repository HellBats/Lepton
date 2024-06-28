#include<stdint.h>
#include<stdio.h>
#include"include/VM.h"
#include"include/program.h"
#include"include/instruction.h"
VM NewVM(unsigned int size)
{
    VM vm;
    for(int i=0;i<32;i++)
    {
        vm.registers[i] = 0;
    }
    vector *prog = NewVec(size);
    vm.program = prog;
    vector *heap = NewVec(size);
    vm.heap = heap;
    vm.program_counter = 0;
    return vm;
}

uint8_t DecodeOpCode(VM *vm)
{
    uint8_t opcode = vecget(vm->program,vm->program_counter);
    vm->program_counter += 1;
    return opcode; 
}


uint8_t Next8bits(VM *vm)
{
    uint8_t result = vecget((vm->program),vm->program_counter);
    vm->program_counter+=1;
    return result;
}

uint16_t Next16bits(VM *vm)
{
    uint16_t result = (uint16_t)vecget(vm->program,vm->program_counter) << 8 | 
    (uint16_t)vecget(vm->program,vm->program_counter+1);
    vm->program_counter+=2;
    return result;
}


void RunVM(VM *vm)
{
   uint8_t flag = 0;
   while(!flag)
   {
        flag = ExecuteInstruction(vm);
   } 
}

void RunOnceVM(VM *vm)
{
    ExecuteInstruction(vm);
}

uint8_t ExecuteInstruction(VM *vm)
{
    if(vm->program_counter>=vm->program->size)
    {
        return 1;
    }
    switch (DecodeOpCode(vm))
    {
        uint8_t register_no;
        uint8_t register1;
        uint8_t register2;
        uint8_t register3;
        case HLT:
            printf("Halted\n");
            Next8bits(vm);
            Next16bits(vm);
            return 1;
        case LOAD:
            register_no = Next8bits(vm);
            vm->registers[register_no] = (int)Next16bits(vm);
            break;
        case ADD:
            register1 = Next8bits(vm);
            register2 = Next8bits(vm);
            register3 = Next8bits(vm);
            vm->registers[register1] = vm->registers[register2] + vm->registers[register3];
            break;
        case SUB:
            register1 = Next8bits(vm);
            register2 = Next8bits(vm);
            register3 = Next8bits(vm);
            vm->registers[register1] = vm->registers[register2] - vm->registers[register3];
            break;
        case MUL:
            register1 = Next8bits(vm);
            register2 = Next8bits(vm);
            register3 = Next8bits(vm);
            vm->registers[register1] = vm->registers[register2] * vm->registers[register3];
            break;
        case DIV:
            register1 = Next8bits(vm);
            register2 = Next8bits(vm);
            register3 = Next8bits(vm);
            vm->registers[register1] = vm->registers[register2] / vm->registers[register3];
            vm->remainder = vm->registers[register2] % vm->registers[register3];
            break;
        case JMP:
            register_no = Next8bits(vm);
            vm->program_counter = vm->registers[register_no];
            break;
        case JMPF:
            register_no = Next8bits(vm);
            vm->program_counter+=vm->registers[register_no];
            break;
        case JMPB:
            register_no = Next8bits(vm);
            vm->program_counter-=vm->registers[register_no];
            break;
        case EQ:
            register1 = Next8bits(vm);
            register2 = Next8bits(vm);
            Next8bits(vm);
            if(vm->registers[register1]==vm->registers[register2]){vm->equal_flag=1;}
            else{vm->equal_flag=0;}
            break;
        case NEQ:
            register1 = Next8bits(vm);
            register2 = Next8bits(vm);
            Next8bits(vm);
            if(vm->registers[register1]!=vm->registers[register2]){vm->equal_flag=1;}
            else{vm->equal_flag=0;}
            break;
        case LT:
            register1 = Next8bits(vm);
            register2 = Next8bits(vm);
            Next8bits(vm);
            if(vm->registers[register1]<vm->registers[register2]){vm->equal_flag=1;}
            else{vm->equal_flag=0;}
            break;
        case GT:
            register1 = Next8bits(vm);
            register2 = Next8bits(vm);
            Next8bits(vm);
            if(vm->registers[register1]>vm->registers[register2]){vm->equal_flag=1;}
            else{vm->equal_flag=0;}
            break;
        case LTQ:
            register1 = Next8bits(vm);
            register2 = Next8bits(vm);
            Next8bits(vm);
            if(vm->registers[register1]<=vm->registers[register2]){vm->equal_flag=1;}
            else{vm->equal_flag=0;}
            break;
        case GTQ:
            register1 = Next8bits(vm);
            register2 = Next8bits(vm);
            Next8bits(vm);
            if(vm->registers[register1]>=vm->registers[register2]){vm->equal_flag=1;}
            else{vm->equal_flag=0;}
            break;
        case JEQ:
            if(vm->equal_flag)
            {
                register1 = Next8bits(vm);
                vm->program_counter = vm->registers[register1];
            }
            else
            {
                Next8bits(vm);
                Next16bits(vm);
            }
            break;
        case ALOC:
            register1 = Next8bits(vm);
            Next16bits(vm);
            Reallocate(vm->heap,vm->registers[register1]);
        default:
            printf("Illegal statement\n");
            return 1;
    }
    return 0;   
}

