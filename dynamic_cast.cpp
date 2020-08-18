#include <iostream>
#include <cstdio>
#include <typeinfo>

using std::endl, std::cout;

class A 
{
public:
	virtual void func() { printf("funcA\n"); }
};

class B : public A 
{
public:
	int x;
public:
	B() : x(0) {}
	virtual void func() { printf("funcB %d\n", x); }
};

int main()
{
	A* a = new A;
	B* b = new B;

	/*
	 * DYNAMIC CAST
	 * przeksztalca wskaznik na podany typ, jesli wskazywany obiekt
	 * jest tego samego typu lub typu pochodnego, w przeciwnym razie
	 * zwraca wskaznik zerowy.
	 */

	// DYNAMIC CAST POINTER
	B* p1 = dynamic_cast<B*>(b);
	B* p2 = dynamic_cast<B*>(a);
	printf("p1 = %p\n", p1);
	printf("p1 = %p\n", p2);

	// DYNAMIC CAST REFERENCE
	try {
		B& r1 = dynamic_cast<B&>(*b);
		B& r2 = dynamic_cast<B&>(*a);
	}
	catch (std::bad_cast e) {
		cout << e.what() << endl;
	}

	return 0;
}