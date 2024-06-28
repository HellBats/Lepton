#ifndef PARSER_DOT_H
#define PARSER_DOT_H
#include"include/instruction.h"

void Parser(Inst *instruct,char *hex_string);
void ParseDecToHex2(int a,char *hex,int n);
void ParseDecToHex4(int a,char *hex,int n);

#endif