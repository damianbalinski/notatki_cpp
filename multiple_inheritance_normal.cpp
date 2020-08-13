#include <iostream>

/*
 * brak automatycznego przekazywania informacji
 * do bezposredniej wirtualnej klasy bazowej
 */
class A
{
public:
	void foo() { printf("A\n"); }
	A() { printf(">>A\n"); }
	A(int) { printf(">>A(int)\n"); }
};

class B : public A
{
public:
	B() : A() { printf(">>B\n"); }
	B(int) : A(0) { printf(">>B(int)\n"); }
};

class C : public A
{
public:
	C() : A() { printf(">>C\n"); }
	C(int) : A(0) { printf(">>C(int)\n"); }
};

class D : public B, public C
{
public:
	D() { printf(">>D\n"); }
	D(int) : C(0), B(0) { printf(">>D(int)\n"); }
};

int main()
{
	D d(0);
	d.A::foo();
	d.B::foo();
	d.C::foo();

	return 0;
}