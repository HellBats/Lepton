#include"include/parser.h"
#include"include/instruction.h"
#include<stdio.h>

void Parser(Inst *instruct,char *hex_string)
{
    switch (instruct->opcode)
    {
        case LOAD:
            if(instruct->operands_no==1 && instruct->registers_no==1)
            {
                ParseDecToHex2(1,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex4((int)instruct->operands[0],hex_string,6); 
            }
            break;
        case ADD:
            if(instruct->operands_no==0 && instruct->registers_no==3)
            {
                ParseDecToHex2(2,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2((int)instruct->registers[1],hex_string,6);
                ParseDecToHex2((int)instruct->registers[2],hex_string,9); 
            }
            break;
        case SUB:
            if(instruct->operands_no==0 && instruct->registers_no==3)
            {
                ParseDecToHex2(3,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2((int)instruct->registers[1],hex_string,6);
                ParseDecToHex2((int)instruct->registers[2],hex_string,9); 
            }
            break;
        case MUL:
            if(instruct->operands_no==0 && instruct->registers_no==3)
            {
                ParseDecToHex2(4,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2((int)instruct->registers[1],hex_string,6);
                ParseDecToHex2((int)instruct->registers[2],hex_string,9); 
            }
            break;
        case DIV:
            if(instruct->operands_no==0 && instruct->registers_no==3)
            {
                ParseDecToHex2(5,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2((int)instruct->registers[1],hex_string,6);
                ParseDecToHex2((int)instruct->registers[2],hex_string,9); 
            }
            break;
        case JMP:
            if(instruct->operands_no==0 && instruct->registers_no==1)
            {
                ParseDecToHex2(6,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2(0,hex_string,6);
                ParseDecToHex2(0,hex_string,9); 
            }
            break;
        case JMPF:
            if(instruct->operands_no==0 && instruct->registers_no==1)
            {
                ParseDecToHex2(7,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2(0,hex_string,6);
                ParseDecToHex2(0,hex_string,9); 
            }
            break;
        case JMPB:
            if(instruct->operands_no==0 && instruct->registers_no==1)
            {
                ParseDecToHex2(8,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2(0,hex_string,6);
                ParseDecToHex2(0,hex_string,9); 
            }
            break;
        case EQ:
            if(instruct->operands_no==0 && instruct->registers_no==2)
            {
                ParseDecToHex2(9,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2((int)instruct->registers[1],hex_string,6);
                ParseDecToHex2(0,hex_string,9); 
            }
            break;
        case NEQ:
            if(instruct->operands_no==0 && instruct->registers_no==2)
            {
                ParseDecToHex2(10,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2((int)instruct->registers[1],hex_string,6);
                ParseDecToHex2(0,hex_string,9); 
            }
            break;
        case GT:
            if(instruct->operands_no==0 && instruct->registers_no==2)
            {
                ParseDecToHex2(11,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2((int)instruct->registers[1],hex_string,6);
                ParseDecToHex2(0,hex_string,9); 
            }
            break;
        case LT:
            if(instruct->operands_no==0 && instruct->registers_no==2)
            {
                ParseDecToHex2(12,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2((int)instruct->registers[1],hex_string,6);
                ParseDecToHex2(0,hex_string,9); 
            }
            break;
        case GTQ:
            if(instruct->operands_no==0 && instruct->registers_no==2)
            {
                ParseDecToHex2(13,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2((int)instruct->registers[1],hex_string,6);
                ParseDecToHex2(0,hex_string,9); 
            }
            break;
        case LTQ:
            if(instruct->operands_no==0 && instruct->registers_no==2)
            {
                ParseDecToHex2(14,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2((int)instruct->registers[1],hex_string,6);
                ParseDecToHex2(0,hex_string,9); 
            }
            break;
        case JEQ:
            if(instruct->operands_no==0 && instruct->registers_no==1)
            {
                ParseDecToHex2(15,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2(0,hex_string,6);
                ParseDecToHex2(0,hex_string,9); 
            }
            break;
        case ALOC:
            if(instruct->operands_no==0 && instruct->registers_no==1)
            {
                ParseDecToHex2(16,hex_string,0);
                ParseDecToHex2((int)instruct->registers[0],hex_string,3);
                ParseDecToHex2(0,hex_string,6);
                ParseDecToHex2(0,hex_string,9); 
            }
            break;
        default:
            break;
        }
}

void ParseDecToHex2(int a,char *hex,int n)
{
    int temp,i;
    for(i=n;i<n+2;i++)
    {
        temp = a%16;
        if(temp<10){temp+=48;}
        else{temp+=55;}
        *(hex+2*n-i+1) = temp;
        a /=16;
    }
    *(hex+i) = 32;
}

void ParseDecToHex4(int a,char *hex,int n)
{
    int temp,i;
    for(i=n;i<n+5;i++)
    {
        if(i==n+2){*(hex+4-i+2*n) = 32;}
        else
        {
            temp = a%16;
            if(temp<10){temp+=48;}
            else{temp+=55;}
            *(hex+4-i+2*n) = temp;
            a /=16;
        }
    }
    *(hex+i) = 32;
}