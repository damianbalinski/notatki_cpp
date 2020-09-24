#include <iostream>
#include <cstdio>

/*
 * SPECYFIKATOR MUTABLE - tylko w klasie/tylko lambda
 * pozwala na modyfikacje skladowej klasy, nawet jesli zostala zadeklarowana jako stala.
 */
const class C
{
public:
	int a;
	int b;
	mutable int c;
public:
	C(int a, int b, int c) : a(a), b(b), c(c) {}
	void print() const { printf("(%d,%d,%d)\n", a, b, c); }
	void setA(int a2) { a = a2; }
};

int main()
{
	using namespace std;

	C c1 = { 1, 2, 3 };
	const C c2 = { 1, 2, 3 };

	// CLASS 1
	c1.print();
	c1.a = 10;
	c1.b = 20;
	c1.c = 30;
	c1.print();

	// CLASS 2
	c2.print();
	//c2.a = 10;	// ERROR
	//c2.b = 20;	// ERROR
	c2.c = 30;
	c2.print();

	return 0;
}