#include <iostream>

/*
 * PRZECHWYTYWANIE ZMIENNYCH
 */

using namespace std;

int main()
{
	// dane
	int val = 10;
	int val2 = 20;

	/*
	 * LAMBDA 4
	 * dostep do zmiennej z danego zakresu przez referencje
	 */
	auto lamb4 = [&val]() {cout << val << endl; };

	/*
	 * LAMBDA 5
	 * dostep do wszystkich zmiennych automatycznych przez wartosc
	 */
	auto lamb5 = [=] { cout << val << ", " << val2 << endl; };

	/*
	 * LAMBDA 6
	 * dostep do wszystkich zmiennych automatycznych przez referencje
	 */
	auto lamb5 = [&] { cout << val << ", " << val2 << endl; };

	return 0;
}