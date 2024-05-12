#include <windows.h>
#include <stdio.h>

typedef double (*Func) (double, double);

int main(int argc, char* argv[])
{
    Func function;
    double result;

    //Load DLL
    HINSTANCE hinstLib = LoadLibrary("Math.dll");
    if (NULL == hinstLib) {
        printf("ERROR: unable to load DLL\n");
        return 1;
    }

    //Get function address
    function = (Func)GetProAddress(hinstLib, "Add");
    if (NULL == function) {
        printf("ERROR: unable to find DLL function\n");
        FreeLibrary(hinstLib);
        return 1;
    }

    //Call function
    result = function(1.0, 2.0);

    //Unload DLL file
    FreeLibrary(hinstLib);

    //Display result
    printf("Result = %f\n", result);
    
    return 0;
}