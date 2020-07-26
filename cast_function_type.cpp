#include <iostream>
#include <cstdio>

const char* STR = "abc";

int foo()
{
	return 100;
}

const char* goo()
{
	return STR;
}

int main()
{
	using namespace std;

	int a, b;
	const char* c;

	a = foo();
	b = (int)goo();
	c = goo();

	printf("%x\n", a);
	printf("%x\n", b);
	printf("%s\n", b);
	printf("%x\n", c);
	printf("%s\n", c);

	printf("a = %x\n", 'a');
	printf("b = %x\n", 'b');
	printf("c = %x\n", 'c');

	return 0;
}