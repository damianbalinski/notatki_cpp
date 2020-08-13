#include <iostream>
#include <cstdio>

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
	A a;
	B b;
	C c;
	D d;

	// PRZYPISANIE - niejednoznacznosc
	A a1 = (B)d;
	A a2 = (C)d;
	A* a3 = (B*)&d;
	A* a4 = (C*)&d;
	A& a5 = (B&)d;
	A& a6 = (C&)d;

	// DOSTEP DO METODY - niejednoznacznosc
	d.B::foo();
	d.C::foo();
	((B)d).foo();
	((C)d).foo();

	// DOSTEP DO PODOBIEKTU
	a = (A)(B)d;
	a = (A)(C)d;

	return 0;
}