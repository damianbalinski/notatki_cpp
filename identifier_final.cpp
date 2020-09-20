#include <iostream>


/*
 * FINAL METHOD - informacja dla kompilatora ze dana metoda wirtualna jest finalna
 * uniemozliwia zmiane definicji metody w klasach pochodnych
 *
 * FINAL CLASS - informacja dla kompilatora ze dana klasa jest finalna,
 * uniemozliwia dziedzieczenie po tej klasie
 */

using namespace std;

// FINAL METHOD
class A
{
public:
	virtual void func() final { cout << "A\n"; }
};

class B : public A
{
public:
	//virtual void func() { cout << "A\n"; }	// ERROR
};


// FINAL CLASS
class C final {};

//class D : C {};	// ERROR

int main()
{
	A a;
	B b;

	a.func();
	b.func();

	return 0;
}