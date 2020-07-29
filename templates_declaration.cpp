#include <iostream>
#include <cstdio>

#define MAX 100

using namespace std;

template<typename T>
void func1(T t)
{
	cout << "func1" << endl;
}

template<typename T, typename U>
void func2(T t, U u)
{
	cout << "func2" << endl;
}

template<class T>
void func3(T t)
{
	cout << "func3" << endl;
}

template<class T, class U>
void func4(T t, U u)
{
	cout << "func4" << endl;
}

template<class T, class U>
void func5(T t)
{
	cout << t + (U)MAX << endl;
}

//template<typename ... ARG>
//void func6(T t, U u, V v)
//{
//	cout << t << ", " << u << ", " << v << endl;
//}

/*
 * Wartosc parametry niesparametryzowanego w szablonie jest
 * okreslana w czasie kompilacji, podczas wywolania funkcji
 * parametr ten musi byc stala
 */
template<typename T, int size>
void func7(T t)
{
	cout << "func7" << endl;
}

int main()
{
	func1(10);
	func2(10, 20);
	func3(10);
	func4(10, 20);
	putchar('\n');

	func1(10.0);
	func2(10.0, 20.0);
	func3(10.0);
	func4(10.0, 20.0);
	putchar('\n');

	func5<int,int>(-200);

	//func6<int, int, int>(20, 30, 20);

	func7<int, 10>(100);

	return 0;
}
