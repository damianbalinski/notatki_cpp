#include <iostream>

/*
 * OVERRIDE - informacja dla kompilatora, ze dana metoda
 * przyslania metode wirtualna z klasy bazowej
 */

using namespace std;

class A
{
public:
	virtual void func() { cout << "A\n"; }
};

class B : public A
{
public:
	void func() override { cout << "B\n"; }
};
int main()
{
	A a;
	B b;

	a.func();
	b.func();

	return 0;
}