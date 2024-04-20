//ManualNameMangling.cpp
//g++ ManualNameMangling.cpp -o ManualNameMangling

#include <stdio.h>

namespace myname {
	int var = 42;
}

extern "C" double _ZN6myname3varE; //delare a C type variable

int main()
{
	printf("%d\n", _ZN6myname3varE);

	return 0;
}
