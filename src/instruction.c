#include<string.h>
#include<stdio.h>
#include"include/instruction.h"
Inst NewInst()
{
    Inst instruction;
    return instruction;
}

void SetInst(Inst *instruct,char* instructions[])
{
    SetOpcode(instruct,instructions);
    int register_no = 0,operand_no= 0;
    for(int i=1;*(instructions[i])!=0;i++)
    {
        if(*(instructions[i])=='$')
        {
            instruct->registers[register_no] = SetRegister(instruct,instructions,i);
            register_no++;
        }
        if(*(instructions[i])=='#')
        {
            instruct->operands[operand_no] = SetOperand(instruct,instructions,i);
            operand_no++;
        }
    }
    instruct->registers_no = register_no;
    instruct->operands_no = operand_no;
}

void SetOpcode(Inst *instruct,char* instructions[])
{
    if(!strcmp(instructions[0],"load")){instruct->opcode = LOAD;}
    else if(!strcmp(instructions[0],"add")){instruct->opcode = ADD;}
    else if(!strcmp(instructions[0],"sub")){instruct->opcode = SUB;}
    else if(!strcmp(instructions[0],"mul")){instruct->opcode = MUL;}
    else if(!strcmp(instructions[0],"div")){instruct->opcode = DIV;}
    else if(!strcmp(instructions[0],"jpm")){instruct->opcode = JMP;}
    else if(!strcmp(instructions[0],"jmpf")){instruct->opcode = JMPF;}
    else if(!strcmp(instructions[0],"jmpb")){instruct->opcode = JMPB;}
    else if(!strcmp(instructions[0],"eq")){instruct->opcode = EQ;}
    else if(!strcmp(instructions[0],"neq")){instruct->opcode = NEQ;}
    else if(!strcmp(instructions[0],"gt")){instruct->opcode = GT;}
    else if(!strcmp(instructions[0],"lt")){instruct->opcode = LT;}
    else if(!strcmp(instructions[0],"gtq")){instruct->opcode = GTQ;}
    else if(!strcmp(instructions[0],"ltq")){instruct->opcode = LTQ;}
    else if(!strcmp(instructions[0],"jeq")){instruct->opcode = JEQ;}
    else if(!strcmp(instructions[0],"hlt")){instruct->opcode = HLT;}
}

uint8_t SetRegister(Inst *instruct,char* instructions[],int j)
{
    uint8_t registerr = 0;
    uint8_t numbers[4];
    int i=1;
    for(;*(instructions[j]+i)!=0;i++)
    {
        numbers[i-1] = (uint8_t)*(instructions[j]+i) - 48;
    }
    i-=2;
    for(int k=0;k<=i;k++)
    {
        // printf("%d %d\n",numbers[k],i-k);
        registerr += numbers[k]*(uint8_t)power(10,(i-k));
    }
    return registerr;
}

uint16_t SetOperand(Inst *instruct,char* instructions[],int j)
{
    uint16_t operand = 0;
    uint16_t numbers[6];
    int i=1;
    for(;*(instructions[j]+i)!=0;i++)
    {
        // printf("%d %d\n",*(instructions[j]+i),i);
        numbers[i-1] = (uint16_t)*(instructions[j]+i) - 48;
    }
    i-=2;
    for(int k=0;k<=i;k++)
    {
        operand += numbers[k]*(uint16_t)power(10,(i-k));
    }
    return operand;
}

int power(int a,int b)
{
    if(b==0){return 1;}
    int ao = a;
    for(int i=1;i<b;i++)
    {
        a*=ao;
    }
    return a;
}
