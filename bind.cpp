#include <iostream>
#include <functional>

/*
 * WRAPPERY (ADAPTATORY) - przeksztalcaja funkcje
 * na funkcje bardziej wyspecjalizowana
 */

using namespace std;
using namespace std::placeholders;

int func(int v1, int v2, int v3, int v4)
{
	return 1000*v1 + 100*v2 + 10*v3 + v4;
}

int main()
{
	auto func1 = bind(func, _1, _2, _3, _4);
	auto func2 = bind(func, _4, _3, _2, _1);
	auto func3 = bind(func, _1, _2, _3, 0);
	auto func4 = bind(func, 0, _1, _2, _3);

	cout << func(1, 2, 3, 4) << endl;
	cout << func1(1, 2, 3, 4) << endl;
	cout << func2(1, 2, 3, 4) << endl;
	cout << func3(1, 2, 3) << endl;

	cout << typeid(func).name() << endl;
	cout << typeid(func1).name() << endl;
	cout << typeid(func2).name() << endl;
	cout << typeid(func3).name() << endl;

	return 0;
}