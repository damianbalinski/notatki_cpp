#include <stdio.h>

volatile int foo()
{
	return 10;
}
int main(void)
{

	int val = foo();
	val = 20;
	return 0;
}