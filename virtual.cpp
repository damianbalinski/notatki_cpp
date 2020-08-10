#include <iostream>
#include <cstdio>

class Base
{
public:
	void foo1()			{ printf("base "); }
	virtual void foo2() { printf("base\n"); }
};

class Derived : public Base
{
public:
	void foo1()			{ printf("derived "); }
	virtual void foo2() { printf("derived\n"); }
};

int main(void)
{
	// VALUE TEST
	Base a1 = Base();
	Base a2 = Derived();
	Derived a3 = Derived();

	a1.foo1();	a1.foo2();
	a2.foo1();	a2.foo2();
	a3.foo1();	a3.foo2();
	printf("\n");


	// POINTER TEST
	Base* b1 = new Base();
	Base* b2 = new Derived();
	Derived* b3 = new Derived();

	b1->foo1();	b1->foo2();
	b2->foo1();	b2->foo2();
	b3->foo1();	b3->foo2();
	printf("\n");


	// REFERENCE TEST
	Base& c1 = *(new Base());
	Base& c2 = *(new Derived());
	Derived& c3 = *(new Derived());

	c1.foo1();	c1.foo2();
	c2.foo1();	c2.foo2();
	c3.foo1();	c3.foo2();
	printf("\n");


	return 0;
}