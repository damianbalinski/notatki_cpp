#include <iostream>

/*
 * PRZECHWYTYWANIE ZMIENNYCH - moze uzyskac dostep do 
 * zmiennych automatycznych znajdujacych sie w biezacym zakresie,
 * wartosc zmiennych przechwytywanych przez wartosc jest okreslana w momencie deklaracji,
 * a nie podczas wywolywania funkcji
 *
 * [] - brak przechwytywania zmiennych
 * [val] - dostep do podanej zmiennej przez wartosc
 * [&val] - dostep do podanej zmiennej przez referencje
 * [=] - dostep do wszystkich zmiennych przez wartosc
 * [&] - dostep do wszystkich zmiennych przez referencje
 * [=, &val] - dostep do wszystkich zmiennych przez wartosc, dostep do zmiennej val przez referencje
 * [&, val] - dostep do wszystkich zmiennych przez referencje, dostep do zmiennej val przez wartosc
 * [this] - dostep do skladowych bierzacej klasy przez referencje
 * [*this] - dostep do skladowych bierzacej klasy przez wartosc
 * [i = 10] - dostep do zainicjalizowanej zmiennej przez wartosc
 * [&i = 10] - dostep do zainicjalizowanej zmiennej przez wartosc
 * [args...]

 */

using namespace std;

class C
{
public:
	int c = 100;
	void func();
	void func2() { c = -100; }
};

void C::func() {
	auto lamb = [this]() { func2(); };
	lamb();
}

int main()
{
	// dane
	int val = 10;
	int val2 = 20;

	//auto lamb1 = [val]() {cout << val << endl; };
	//auto lamb2 = [&val]() {cout << val << endl; };
	//auto lamb3 = [=] { cout << val << ", " << val2 << endl; };
	//auto lamb4 = [&] { cout << val << ", " << val2 << endl; };

	// TEST
	[&i = val]
	{ 
		cout << i << endl;
		i = -10;
		cout << i << endl;
	}();

	return 0;
}