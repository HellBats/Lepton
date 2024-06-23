#include<stdio.h>
#include"include/VM.h"
#include"include/program.h"
#include"include/REPL.h"
void main()
{
    REPL repl = NewREPL();
    RunREPL(&repl);
    // for(int i=0;i<sizeof(vm.registers)/4;i++)
    // {
    //     printf("%d %d\n",i,vm.registers[i]);
    // }
}