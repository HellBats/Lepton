#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include"include/REPL.h"
#include"include/VM.h"
#include"include/program.h"
#include"include/lexer.h"

REPL NewREPL()
{
    VM vm = NewVM(4*1); 
    REPL repl = {.command_length = 0,.vm = vm};
    return repl;
}

void RunREPL(REPL *repl)
{
    char temp;
    printf("Welcome to Quanta Virtual Machine\n");
    while(1)
    {
        printf(">>>");
        scanf("%[^\n]",repl->command_buffer);
        scanf("%c",&temp);
        if(!strcmp(repl->command_buffer,".quit"))
        {
            printf("Farewell have a good day\n");
            break;
        }
        if(!strcmp(repl->command_buffer,".registers"))
        {
            for(int i=0;i<32;i++)
            {
                printf("%d\n",repl->vm.registers[i]);
            }
        }
        else
        {
            Inst inst  = NewInst();
            Tokenize(&inst,repl->command_buffer);
            printf("%d %d %d\n",inst.opcode,inst.operands[0],inst.registers[0]);

            // repl->command_buffer[11] = ' ';
            // if(ParseHex(repl))
            // {
            //     RunOnceVM(&repl->vm);
            // }
            // else
            // {
            //     printf("Illegal statement\n");
            // }
        }
    }
}

int ParseHex(REPL *repl)
{
    unsigned int k = repl->vm.program_counter;
    for(int j=0;j<4;j++)
    {
        uint16_t byte = ParseHexAider(repl->command_buffer,j*3,3+j*3);
        printf("%d\n",byte);
        if(byte==256){return 0;} 
        vecset(repl->vm.program,k+j,byte);
    }
    return 1;
}

uint16_t ParseHexAider(char hex_string[],int i,int f)
{
    uint16_t byte = 0;
    for(i;;i++)
    {
        // printf("%d\n",hex_string[i]);
        if(hex_string[i]=='0'){ byte = byte | 0;}
        else if(hex_string[i]=='1'){byte = byte | 1;}
        else if(hex_string[i]=='2'){byte = byte | 2;}
        else if(hex_string[i]=='3'){byte = byte | 3;}
        else if(hex_string[i]=='4'){byte = byte | 4;}
        else if(hex_string[i]=='5'){byte = byte | 5;}
        else if(hex_string[i]=='6'){byte = byte | 6;}
        else if(hex_string[i]=='7'){byte = byte | 7;}
        else if(hex_string[i]=='8'){byte = byte | 8;}
        else if(hex_string[i]=='9'){byte = byte | 9;}
        else if(hex_string[i]=='A'){byte = byte | 10;}
        else if(hex_string[i]=='B'){byte = byte | 11;}
        else if(hex_string[i]=='C'){byte = byte | 12;}
        else if(hex_string[i]=='D'){byte = byte | 13;}
        else if(hex_string[i]=='E'){byte = byte | 14;}
        else if(hex_string[i]=='F'){byte = byte | 15;}
        else if(hex_string[i]==' '){return byte;}
        else{return 256;}
        if(f-i==3){byte = byte << 4;}
    }    
}