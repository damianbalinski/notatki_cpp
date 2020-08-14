#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

template<typename T>
class A
{
private:
	T t;
public:
	A(T t = -1)
	{
		cout << "t = " << t << endl;
		this->t = t;
	}
};

template<int I>
class B
{
public:
	B(int i = I) { cout << "I = " << i << endl; }
};

template<typename T>
class C
{
public:
	T t;
};

template<template<typename T> class C, typename T>
class D
{
public:
	D(C<T> c) {};
};

int main()
{
	A a1;					// parametry domyslne szablonu i konstruktora
	A a2(10.0);				// parametry domyslne szablonu
	A<double> a3;			// parametry domyslne konstruktora
	A<double> a4(10);		// jawne okreslenie parametrow szablonu i parametrow konstruktora

	B<5> b1;				// parametr pozatypowy
	B<5> b2(10);			// parametr pozatypowy

	C<C<int>> c1;			// szablon rekurencyjny
	C<A<int>> c2;			// szablon zagniezdzony

	D<A, int> d2(A<int>);	// szablon jako parametr szablonu

	return 0;
}