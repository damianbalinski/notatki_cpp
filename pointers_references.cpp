#include <iostream>

void fun1(int a, int b)
{
	a = 1;
	b = 2;
}

void fun2(int* a, int* b)
{
	*a = 10;
	*b = 20;
}

void fun3(int& a, int& b)
{
	a = 100;
	b = 200;
}

int main()
{
	using namespace std;
	int a = 0, b = 0;

	printf("(%d,%d)\n", a, b);
	
	fun1(a, b);
	printf("(%d,%d)\n", a, b);

	fun2(&a, &b);
	printf("(%d,%d)\n", a, b);

	fun3(a, b);
	printf("(%d,%d)\n", a, b);

	return 0;
}