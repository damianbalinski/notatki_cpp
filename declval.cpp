#include <iostream>
#include <utility>

/*
 * #include <utility>
 * DECLVAL(val)
 * konwertuje typ na referencje do typu, umozliwia sprawdzanie typu
 * metod bez koniecznosci inicjalizacji obiektu
 */

using namespace std;

int main()
{
	int val = 10;
	int rval = val;

	cout << typeid(val).name() << endl;
	cout << typeid(rval).name() << endl;

	cout << typeid(std::declval<int>).name() << endl;

	return 0;
}