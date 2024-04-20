#include <stdio.h>
#include <pthread.h>

int pthread_create (
	pthread_t*,
	const pthread_attr_t*, 
	void* (*) (void*), 
	void*) __attribute__ ((weak)); //explict declare func is a weak reference

int main()
{
	if (pthread_create) { //could find pthread_create of define, so it can use pthread_create//that meaning pthread_create != 0
		printf("This is multi-thread version!\n");
		//run the multi-thread version
		//main_multi_thread()
	}
	else {
		printf("This is single-thread version!\n");
		//run the single-thread version
		//main_single_thread()
	}
}
