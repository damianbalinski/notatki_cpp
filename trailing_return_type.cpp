#include <iostream>

/*
 * OPOZNIONA DEKLARACJA TYPU ZWRACANEGO
 */
int func1(int a, float b)
{
	return a + b;
}

auto func2(int a, float b)
{
	return a + b;
}

auto func3(int a, float b)
{
	decltype(a + b) c = a + b;
	return c;
}

// ERROR: a+b nie sa w zasiegu parametrow funkcji
//decltype(a + b) func4(int a, float b)
//{
//	return a + b;
//}

auto func5(int a, float b) -> decltype(a + b)
{
	return a + b;
}

int main()
{
	using namespace std;

	auto a1 = func1(1, 1.);
	auto a2 = func2(1, 1.);
	auto a3 = func3(1, 1.);
	//auto a4 = func4(1, 1.);
	auto a5 = func5(1, 1.);

	cout << typeid(a1).name() << endl;
	cout << typeid(a2).name() << endl;
	cout << typeid(a3).name() << endl;
	//cout << typeid(a4).name() << endl;
	cout << typeid(a5).name() << endl;

	return 0;
}