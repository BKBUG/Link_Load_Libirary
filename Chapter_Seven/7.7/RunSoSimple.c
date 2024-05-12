#include <stdio.h>
#include <dlfcn.h>

int main (int argc, char* argv[])
{
    void* handle;
    double (*func) (double);
    char* error;

    handle = dlopen(argv[1], RTLD_NOW); //in running time load the math library 
    if (NULL == handle) {
        printf("Open library %s error: %s\n", argv[1], dlerror());
        return -1;
    }

    func = dlsym(handle, "sin"); //to find the function that named "sin"
                                //than dlsym return the address of the function that find

    if (NULL != (error = dlerror())) { //if not find the function that named "sin"
        printf("Symbol sin not found: %s\n", error); //then dlsym return null; and set error 
        goto exit_runso;
    }

    printf("%f\n", func(3.1415926 / 2));

    exit_runso:
        dlclose(handle);
}