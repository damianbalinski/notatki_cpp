#include <iostream>

class Base {};

class Derived : public Base {};

int main(void)
{
	Base base = Base();
	Derived derived = Derived();

	Base a1 = derived;
	//Derived a2 = base;	// ERROR

	Base* b1 = &derived;
	//Derived* b2 = &base;	// ERROR

	Base& c1 = derived;
	//Derived& c2 = base;	// ERROR

	return 0;
}