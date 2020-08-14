#include <iostream>
#include <cstdio>

#define MAX 100

using namespace std;

// TEST
template<typename T>
class A 
{
public:
	int x;
	A() { x = 10; };
	A(int x_n) { x = x_n; };
};

// POJEDYNCZY PARAMETR
template<typename T>	// template<class T>
void func1(T t)
{
	cout << "func1 " << t << endl;
}

// WIELE PARAMETROW
template<typename T, typename U>	// template<class T, class U>
void func2(T t, U u)
{
	cout << "func2 " << t <<" " << u << endl;
}

/*
 * PARAMETR POZATYPOWY
 * Wartosc parametry pozatypowego w szablonie jest
 * okreslana w czasie kompilacji, jego wartosc musi
 * byc znana w czasie kompilacji
 */
template<typename T, int size>
void func3(T t)
{
	cout << "func3 " << t << " s" << size << endl;
}

// SZABLON JAKO PARAMETR SZABLONU
template<template<typename T> class C, typename U>
void func4(C<U> c)
{
	cout << "func4 " << "c" << c.x << endl;
}

// OBIEKT SZABLONU JAKO PARAMETR SZABLONU
template<typename T>
void func5(T t)
{
	cout << "func5 " << t.x << endl;
}

// ELIPSA
//template<typename ... ARG>
//void func4(T t, U u, V v)
//{
//	cout << t << ", " << u << ", " << v << endl;
//}

int main()
{
	func1(10);
	func1(10.0);
	func1<int>(10.0);
	cout << endl;

	func2(10, 20);
	func2(10.0, 20.0);
	func2<double>(10, 10);
	func2<double,double>(10, 10);
	cout << endl;

	func3<int, 10>(100);
	cout << endl;
	
	cout << endl;

	A<int> b1;
	A<double> b2;
	func5(b1);
	func5<>(b1);
	func5<A<double>>(b2);

	A<int> a1;
	func4(a1);
	func4<>(a1);
	func4<A, int>(a1);

	return 0;
}
