#include<string.h>
#include<stdio.h>
#include"include/instruction.h"
Inst NewInst()
{
    Inst instruction;
    return instruction;
}

int SetInst(Inst *instruct,char* instructions[])
{
    int register_no = 0,operand_no= 0;
    int opcode_flag = 0;
    for(int i=0;*(instructions[i])!=0;i++)
    {
        if(*(instructions[i])=='.')
        {

        }
        else if(*(instructions[i])=='@')
        {

        }
        else if(*(instructions[i])=='?')
        {

        }
        if(*(instructions[i])=='$')
        {
            instruct->registers[register_no] = SetRegister(instructions,i);
            register_no++;
        }
        else if(*(instructions[i])=='#')
        {
            instruct->operands[operand_no] = SetOperand(instructions,i);
            operand_no++;
        }
        else
        {
            Opcode code = SetOpcode(instructions,i);
            if(code<0 || code>16 || opcode_flag>1)
            {
                return 0;
            }
            instruct->opcode = code;
            opcode_flag++;
        }
    }
    instruct->registers_no = register_no;
    instruct->operands_no = operand_no;
    return 1;
}

Opcode SetOpcode(char* instructions[],int i)
{
    if(!strcmp(instructions[i],"load")){return LOAD;}
    else if(!strcmp(instructions[i],"add")){return ADD;}
    else if(!strcmp(instructions[i],"sub")){return SUB;}
    else if(!strcmp(instructions[i],"mul")){return MUL;}
    else if(!strcmp(instructions[i],"div")){return DIV;}
    else if(!strcmp(instructions[i],"jpm")){return JMP;}
    else if(!strcmp(instructions[i],"jmpf")){return JMPF;}
    else if(!strcmp(instructions[i],"jmpb")){return JMPB;}
    else if(!strcmp(instructions[i],"eq")){return EQ;}
    else if(!strcmp(instructions[i],"neq")){return NEQ;}
    else if(!strcmp(instructions[i],"gt")){return GT;}
    else if(!strcmp(instructions[i],"lt")){return LT;}
    else if(!strcmp(instructions[i],"gtq")){return GTQ;}
    else if(!strcmp(instructions[i],"ltq")){return LTQ;}
    else if(!strcmp(instructions[i],"jeq")){return JEQ;}
    else if(!strcmp(instructions[i],"hlt")){return HLT;}
    else if(!strcmp(instructions[i],"aloc")){return ALOC;}
    else{printf("not a inst");}
}

uint8_t SetRegister(char* instructions[],int j)
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

uint16_t SetOperand(char* instructions[],int j)
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
