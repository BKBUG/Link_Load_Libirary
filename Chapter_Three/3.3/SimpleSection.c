int printf(const char* format, ...);

int global_init_var = 84; //it will be stroage in .data segment
int global_uninit_var;//it will be storage in .bss segment

void func1 (int i)
{
	printf("%d\n", i);
}

int main(void)
{
	static int static_var  = 85; //it will be stroage in .data segment
	static int static_var2;//it will be storage in .bss segment

	int a = 1;
	int b; //they will storage in .data segment?

	func1(static_var + static_var2 + a + b);

	return a;
}
