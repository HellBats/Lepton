#ifndef PARSER_DOT_H
#define PARSER_DOT_H
#include"include/instruction.h"

char* Parser(Inst *instruct,char *hex_string);
char* ParseDecToHex2(int a,char *hex,int n);
char* ParseDecToHex4(int a,char *hex,int n);
void StrCat(char *a,char *b,char *result,int i);

#endif