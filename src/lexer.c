#include<stdlib.h>
#include"include/lexer.h"
#include"include/instruction.h"
#include<stdio.h>
#define NO_OF_TOKENS 5
void Tokenize(Inst* instruct,char instruction[])
{
    char* tokens[NO_OF_TOKENS];
    for(int i=0;i<NO_OF_TOKENS;i++)
    {
        tokens[i] = (char*)malloc(8); 
    }
    int i = 0,k=0;
    for(int j=0;instruction[j]!=0;j++)
    {
        if(instruction[j]==0){break;}
        if(instruction[j]==' ')
        {
            *(tokens[i]+k) = 0;
            k=0;
            i++;
        }
        else
        {
            *(tokens[i]+k) = instruction[j];
            k++;
        }
    }
    *(tokens[i]+k) = 0;
    *(tokens[i+1]) = 0;
    SetInst(instruct,tokens);
    for(int i=0;i<NO_OF_TOKENS;i++)
    {
        free(tokens[i]);
    }
}



