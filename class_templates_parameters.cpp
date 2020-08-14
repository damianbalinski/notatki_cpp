#include <iostream>
#include <cstdio>

// 1 - POJEDYNCZY PARAMETR
template<typename T>
class A1
{
public:
	void foo() { printf("foo1\n"); }
};

// 2 - WIELE MARAMETROW
template<typename T, typename U>
class A2
{
public:
	void foo() { printf("foo2\n"); }
};

// 3 - SZABLON JAKO PARAMETR
template<template<typename T> class C, typename T>
class A3
{
public:
	C<T> a3;
};

// 4 - SZABLON JAKO PARAMETR
template<template<typename T, typename U> class C, typename T, typename U>
class A4
{
public:
	C<T,U> a4;
};

// 5 - SZABLON REKURENCYJNY
template<typename T>
class A5
{

public:
	T a5;
};

int main()
{
	A1<int> a1;
	a1.foo();

	A2<int, int> a2;
	a2.foo();

	A3<A1, int> a3;
	a3.a3.foo();

	A4<A2, int, int> a4;
	a4.a4.foo();

	// szablon rekurencyjny
	A5<A1<int>> a5;
	a5.a5.foo();


	return 0;
}