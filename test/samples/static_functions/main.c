#include <stdio.h>

int foo()
{
	return 21;
}

static int bar()
{
	return 42;
}

int main()
{
    printf("foo=%d\n", foo());
	printf("bar=%d\n", bar());
}
