#include <iostream>
#include <cstdio>

/*
 * WSPOLDZIELONA FUNKCJA ZAPRZYJAZNIONA
 */

class B;			// MUSI
class A;			// NIE MUSI
void foo(A a, B b);	// NIE MUSI

class A
{
private:
	int a;
public:
	friend void foo(A a, B b);
};

class B
{
private:
	int b;
public:
	friend void foo(A a, B b);
};

void foo(A a, B b)
{
	printf("(%d,%d)\n", a.a, b.b);
}

int main()
{
	return 9;
}