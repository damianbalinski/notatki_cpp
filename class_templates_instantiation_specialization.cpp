#include <iostream>
#include <cstdio>

// KLASA NIESZABLONOWA
class A {};

// SZABLON KLASY
template <typename T>
class B {};

// JAWNA SPECJALIZACJA
template<>
class B<int> {};

class B<double>
{
public:
	void foo() { printf("b2\n"); }
};

// JAWNA KONKRETYZACJA
template
class B<int>;

int main()
{
	// NIEJAWNA KONKRETYZACJA
	B<int> b;
	B<double> b2;

	//b.foo();
	b2.foo();

	return 0;
}