#include <iostream>

/*
 * DZIEDZICZENIE KONSTRUKTOROW
 * udostepnienie klasie pochodnej konstruktorow z klasy bazowej, z wylaczeniem
 * konstruktorow domyslnego/kopiujacego/przenoszacego
 */

using namespace std;

class A
{
public:
	A() { cout << "A def\n"; }
	A(int) { cout << "A int\n"; }
	A(double) { cout << "A double\n"; }
	A(const A& a) { cout << "A copy\n"; }
	A(A&& a) { cout << "A move\n"; }
};

class B : A
{
public:
	using A::A;
};

int main()
{
	// dane
	A a;
	B b;

	// konstruktory
	A();
	A(10);
	A(10.0);
	A{ a };

	cout << endl;

	B();
	B(10);
	B(10.0);
	B{ b };

	return 0;
}