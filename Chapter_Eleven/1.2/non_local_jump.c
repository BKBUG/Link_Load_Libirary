#include <setjmp.h>
#include <stdio.h>
jmp_buf b;
void f()
{
    longjmp(b, 1);
}

int main()
{
    if (setjmp(b)) {
        printf("World!\n");
    }
    else {
        printf("Hello ");
        f();
    }
}
