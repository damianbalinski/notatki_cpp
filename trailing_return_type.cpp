// OPOZNIONA DEKLARACJA TYPU ZWRACANEGO
#include <iostream>

/*
 * Deklaracja jawna.
 */
double func1(int a, int b)
{
	return a + b;
}

/*
 * Dedukcja automatyczna
 * Nie dziala dla referencji.
 */
auto func2(int a, float b)
{
	// return a + b;
	return;
}

/*
 * Deklaracja opozniona.
 */
auto func3(int a, int b) -> double
{
	return a + b;
}

/*
 * Deklaracja opozniona z szablonem.
 */
template<typename T, typename U>
auto func4(T t, U u) -> decltype(t + u)
{
	return t + u;
}

/*
 * Deklaracja opozniona z szablonem.
 */
template<typename T, typename U>
decltype(std::declval<T>() + std::declval<U>()) func5(T t, U u)
{
	return t + u;
}

// ERROR: a+b nie sa w zasiegu parametrow funkcji
//decltype(a + b) func4(int a, float b)
//{
//	return a + b;
//}

int main()
{
	using namespace std;

	auto a1 = func1(1, 1.);
	auto a2 = func2(1, 1.);
	auto a3 = func3(1, 1.);
	auto a4 = func4(1, 1.);
	auto a5 = func5(1, 1.);

	cout << typeid(a1).name() << endl;
	cout << typeid(a2).name() << endl;
	cout << typeid(a3).name() << endl;
	cout << typeid(a4).name() << endl;
	cout << typeid(a5).name() << endl;

	return 0;
}