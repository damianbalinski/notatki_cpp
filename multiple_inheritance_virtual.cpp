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

class B : public virtual A
{
public:
	B() { printf(">>B\n"); }
	B(int) { printf(">>B(int)\n"); }
};

class C : public virtual A
{
public:
	C() { printf(">>C\n"); }
	C(int) { printf(">>C(int)\n"); }
};

class D : public B, public C
{
public:
	D() { printf(">>D\n"); }
	D(int) : C(0), B(0), A(0) { printf(">>D(int)\n"); }
};

int main()
{
	D d(0);
	d.foo();

	return 0;
}