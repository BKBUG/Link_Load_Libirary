/*Lib.c*/
#include <stdio.h>

void foobar(int i)
{
    printf("Printing from Lib.so %d\n", i);
    sleep(-1);
}