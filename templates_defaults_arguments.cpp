// PARAMETRY DOMYSLNE SZABLONU
#include <iostream>
#include <cstdio>

using namespace std;

template<typename T = int>
void func1(T t = (T)10)
{
	cout << "func1: " << typeid(T).name() << endl;
}

/*
 * W przeciwienstwie do parametrow domyslnych funkcji, parametry domysle szablonu funkcji moga
 * wystepowac przed parametrami niedomyslnymi.
 */
template<typename T, typename U>
void func2()
{
	cout << "func2: " << typeid(T).name() << ", " << typeid(U).name() << endl;
}

template<typename T = float, typename U>
void func2();

template<typename T, typename U = double>
void func2();

template<int I = 10>
void func3()
{
	cout << I << endl;
}

int main()
{
	func1();

	func1(10);
	func1(10.);

	func1<int>(10);
	func1<int>(10.);
	func1<double>(10);
	func1<double>(10.);
	putchar('\n');

	//func2<int>();
	func2();
	func2<char>();

	func2<int, int>();
	func2<int, double>();
	func2<double, int>();
	func2<double, double>();

	func3();
	func3<5>();
	return 0;
}