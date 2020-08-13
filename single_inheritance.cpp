#include <iostream>

class A
{
public:
	void foo() { printf("hi\n"); }
	A() {}
};

class B : public A
{
public:
	B() : A() {}
};

class D : public B
{
public:
	D() : B() {}
};

int main()
{
	A a;
	B b;
	D d;

	// INICJALIZACJA
	A v1 = d;
	A* p1 = &d;
	A& r1 = d;

	// DOSTEP DO METODY
	a.foo();

	// DOSTEP DO PODOBIEKTU
	a = d;

	return 0;
}