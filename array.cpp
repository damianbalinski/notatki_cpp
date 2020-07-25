#include <iostream>
#include <array>

/*
 * Klasa array - mniej elastyczna niz wektor, wydajniejsza.
 * Bezpieczniejsza niz zwykla tablica, ma statyczny, staly rozmiar.
 */
int main()
{
	using namespace std;

	array<int, 5> a1;
	array<int, 5> a2 = { 1, 2, 3, 4 };

	a2.at(0) = 5;				// chroniony dostep do wartosci, sprawdza poprawny zakres indeksowania
	auto begin = a2.begin();	// zwraca iterator
	auto end = a2.end();		// zwraca iterator

	cout << a2[0] << endl;
	cout << a2[1] << endl;
	cout << a2[2] << endl;
	cout << a2[3] << endl;

	cout << typeid(begin).name() << endl;
	cout << typeid(end).name() << endl;

	return 0;
}