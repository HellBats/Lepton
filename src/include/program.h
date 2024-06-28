#ifndef PROGRAM_DOT_H
#define PROGRAM_DOT_H
#include<stdlib.h>
#include<stdint.h>
typedef struct Vector
{
    unsigned int size;
    uint8_t *ptr;          
} vector;

vector* NewVec(unsigned int size);
void Reallocate(vector *vec,int size);
uint8_t vecget(vector *vec,unsigned int index);
void vecset(vector *vec,unsigned int index,uint8_t value);
#endif