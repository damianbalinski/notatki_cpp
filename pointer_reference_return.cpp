#include <iostream>

int foo1(int x)
{
	return x;
}

int* foo2(int* x)
{
	return x;
}

const int& foo3(const int& x)
{
	return x;
}

int main()
{
	using namespace std;

	int x = 100;
	int v = -10;
	int* p;

	printf("%d\n", v);

	v = foo1(10);
	printf("%d\n", v);
	v = foo1(x);
	printf("%d\n", v);
	putchar('\n');

	x = 200;
	//v = foo2(10);
	p = foo2(&x);
	printf("%d\n", v);
	putchar('\n');

	x = 300;
	v = foo3(30);
	printf("%d\n", v);
	v = foo3(x);
	printf("%d\n", v);
	putchar('\n');

	return 0;
}