#include<stdio.h>
#include"include/VM.h"
#include"include/program.h"
#include"include/REPL.h"
void main()
{
    REPL repl = NewREPL();
    RunREPL(&repl);
}