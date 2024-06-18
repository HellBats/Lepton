#include<stdio.h>
#include"include/VM.h"
#include"include/program.h"
void main()
{
    VM vm = NewVM(4);
    vecset(vm.program,0,9);
    vecset(vm.program,1,2);
    vecset(vm.program,2,3);
    vecset(vm.program,3,3);
    vecset(vm.program,4,15);
    vecset(vm.program,5,4);
    vm.registers[2] = 13;
    vm.registers[3] = 10;
    RunOnceVM(&vm);
    RunOnceVM(&vm);
    // for(int i=0;i<sizeof(vm.registers)/4;i++)
    // {
    //     printf("%d %d\n",i,vm.registers[i]);
    // }
    printf("%d\n",vm.program_counter);
}