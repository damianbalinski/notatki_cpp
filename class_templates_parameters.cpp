#include <iostream>
#include <cstdio>

// TEMPLATE 1
template<typename T>
class A
{
public:
	void foo() { printf("foo\n"); }
};

// TEMPLATE 2
template<typename T, typename U>
class A2
{
public:
	void foo() { printf("foo2\n"); }
};

// TEMPLATE PARAMETER 1
template<template<typename T> class U>
class B
{
public:
	U<int> b1;
};

// TEMPLATE PARAMETER 2
template<template<typename T, typename V> class U>
class B2
{
public:
	U<int, int> b2;
};

int main()
{
	A<int> a1;
	a1.foo();

	A2<int, int> a2;
	a2.foo();

	B<A> b1;
	b1.b1.foo();

	B2<A2> b2;
	b2.b2.foo();

	return 0;
}