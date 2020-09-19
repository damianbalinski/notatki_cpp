#include <iostream>

/*
 * DECLTYPE(val)
 * tworzy zmienna o typie podanej wartosci/wyrazenia
 */

using namespace std;

int main()
{
	decltype(10 + 20) v1 = 10 + 20;
	decltype(10 + 20.0) v2 = 10 + 20.0;

	cout << typeid(v1).name() << endl;
	cout << typeid(v2).name() << endl;

	return 0;
}