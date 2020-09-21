#include <iostream>

/*
 * WARIADYCZNE SABLONY FUNKCJI
 * szablony funkcji ze zmienna liczba parametrow
 */

using namespace std;

// PUSTY WARUNEK BRZEGOWY
void func() { cout << "END\n"; }

// JEDNOELEMENTOWY WARUNEK BRZEGOWY
template<typename T>
void func(T t) { cout << t << " END\n"; }

// DEKLARACJA
template<typename T, typename... Args>	// PAKIET PARAMETROW SZABLONU, reprezentuje dowolna liczbe typow, lacznie z lista pusta
void func(T t, Args... args)			// PAKIET PARAMETROW FUNKCJI, lista wartosci o typach odpowiadajacych liscie typow w pakiecie parametrow Args
{
	/*
	 * przetworzenie pierwszego parametru, rekurencyjne przekazanie pozostalych 
	 * parametrow, rekurencja powtarza sie do momentu otrzymania pustego pakietu
	 */
	cout << t << ", ";

	/*
	 * ROZPAKOWYWANIE PAKIETU
	 * rozwijana do rozdzielonej przecinkami listy zero lub wielu parametrow
	 */
	func(args...);
}


int main()
{
	// DANE
	int i = 10;
	double d = 1.99;
	char c = 'A';
	string s = "abc";

	/*
	 * WYWOLANIE
	 * funkcja moze byc wywolana z dowolna liczba argumentow
	 */

	func();
	func(i);
	func(i, d);
	func(i, d, c);
	func(i, d, c, s);

	return 0;
}