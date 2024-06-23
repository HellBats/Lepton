#include"include/program.h"
#include<stdlib.h>
#include<stdint.h>
vector* NewVec(unsigned int size)
{
    vector *vec = (vector*)malloc(sizeof(vector));;
    vec->size = size;
    vec->ptr = (uint8_t*)malloc(vec->size*sizeof(uint8_t));
    return vec;
}

void Reallocate(vector *vec)
{
    vec->ptr = (uint8_t*)realloc(vec->ptr,2*sizeof(uint8_t));
    vec->size = 2*vec->size;
}

uint8_t vecget(vector *vec,unsigned int index)
{
    return *(vec->ptr+index);
}

void vecset(vector *vec,unsigned int index,uint8_t value)
{   if(index==vec->size-1)
    {
        Reallocate(vec);
    }
    *(vec->ptr+index) = value;
}
