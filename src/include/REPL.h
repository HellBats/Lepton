#ifndef REPL_DOT_H
#define REPL_DOT_H
#include<stdint.h>
#include"include/VM.h"

typedef struct REPL
{
    char command_buffer[40];
    int command_length;
    VM vm;
}REPL;

REPL NewREPL();
void RunREPL(REPL *repl);
int ParseHex(REPL *repl,char *hex);
uint16_t ParseHexAider(char* hex_string,int i,int f);
#endif