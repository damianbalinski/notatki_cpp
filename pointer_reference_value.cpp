#include <iostream>

void foo1(int a, int b)
{
	a = 1;
	b = 2;
}

void foo2(int* a, int* b)
{
	*a = 10;
	*b = 20;
}

void foo3(int& a, int& b)
{
	a = 100;
	b = 200;
}

int main()
{
	using namespace std;
	int a = 0;
	int b = 0;

	printf("(%d,%d)\n", a, b);
	foo1(a, b);		printf("(%d,%d)\n", a, b);
	foo2(&a, &b);	printf("(%d,%d)\n", a, b);
	foo3(a, b);		printf("(%d,%d)\n", a, b);

	return 0;
}