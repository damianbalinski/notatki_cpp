#include <iostream>

class A 
{
public:
	void foo() { printf("A\n"); }
};

class W : virtual public A {};

class X : virtual public A {};

class Y : public A {};

class Z : public A {};

class B : public W, public X {};

class C : public Y, public Z {};

class D : public B, public C {};


int main()
{
	A a;
	B b;
	C c;
	D d;
	W w;
	X x;
	Y y;
	Z z;

	// PRZYPISANIE
	A a1 = (B)d;
	A a2 = (Y)d;
	A a2 = (Z)d;
	A* p1 = (B*)&d;
	A* p2 = (X*)&d;
	A* p2 = (Y*)&d;
	A& r1 = (B&)d;
	A& r2 = (X&)d;
	A& r2 = (Y&)d;

	// DOSTEP DO OBIEKTU
	a = (A)(B)d;
	a = (A)(X)d;
	a = (A)(Y)d;

	// DOSTEP DO METODY
	d.B::foo();
	d.Y::foo();
	d.Z::foo();

	return 0;
}