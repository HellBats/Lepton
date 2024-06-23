#ifndef REPL_DOT_H
#define REPL_DOT_H
#include<stdio.h>
#include<stdint.h>
#include"include/VM.h"

typedef struct REPL
{
    char command_buffer[20];
    int command_length;
    VM vm;
}REPL;

REPL NewREPL();
void RunREPL(REPL *repl);
int ParseHex(REPL *repl);
uint16_t ParseHexAider(char hex_string[],int i,int f);
#endif