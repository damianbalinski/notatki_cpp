#include <iostream>

/*
 * STATIC_CAST 2 - COMPILE_TIME
 * static_cast<Type*>(ptr)
 * probuje bezpiecznie zrzutowac wskaznik ptr na typ Type*
 *
 * konwersja jest mozliwa tylko po drzewie dziedziczenie w dol/gore,
 * mozliwe zutowanie do typu tak samo/bardziej wykwalifikowanego (const/volatile)
 * bezpieczny dla wskaznikow zerowych,
 */
class A {};

class B : public A {};

class C {};

int main()
{
	A* a = new A();
	B* b = new B();
	C* c = new C();

	A a1;
	B b1;
	C c1;

	// CAST TO A*
	a = static_cast<A*>(a);
	a = static_cast<A*>(b);
	//a = static_cast<A*>(c);

	// CAST TO B*
	b = static_cast<B*>(a);
	b = static_cast<B*>(b);
	//b = static_cast<B*>(c);

	// CAST TO C*
	//c = static_cast<C*>(a);
	//c = static_cast<C*>(b);
	c = static_cast<C*>(c);

	// CAST TO A&
	A& ar1 = static_cast<A&>(a1);
	A& ar2 = static_cast<A&>(b1);
	//A& ar3 = static_cast<A&>(c1);

	// CAST TO B&
	A& br1 = static_cast<B&>(a1);
	A& br2 = static_cast<B&>(b1);
	//A& br3 = static_cast<B&>(c1);

	// CAST TO C&
	//C& cr1 = static_cast<C&>(a1);
	//C& cr2 = static_cast<C&>(b1);
	C& cr3 = static_cast<C&>(c1);

	// VALUE, EXPRESSION CASTING
	int x = 10;
	double y = 10.0;
	char z = 'A';
	x = static_cast<int>(10);
	x = static_cast<int>(10.0);
	x = static_cast<int>(1.0 + 2.0);
	x = static_cast<int>(10 + 20);
	x = static_cast<int>(x);
	x = static_cast<double>(y);
	x = static_cast<char>(z);

	// CHANGE CV QUALIFIERS IN POINTERS
	int* p1 = new int(10);
	const int* p2 = new int(10);
	//p1 = static_cast<int*>(p2);
	//p1 = static_cast<const int*>(p2);
	p2 = static_cast<int*>(p1);
	p2 = static_cast<const int*>(p1);

	// CHANGE CV QUALIFIERS IN REFERENCES
	int& r1 = x;
	const int& r2 = x;
	//int& r11 = static_cast<int&>(r2);
	//int& r12 = static_cast<const int&>(r2);
	const int& r21 = static_cast<int&>(r1);
	const int& r22 = static_cast<const int&>(r1);

	return 0;
}