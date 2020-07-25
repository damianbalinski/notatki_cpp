#include <iostream>

/*
 * Petla zakresowa for.
 * Przetwarza kolejno wszystkie elementy kontenera.
 */
int main()
{
	using namespace std;

	int tab1[] = { 5, 4, 3, 2, 1 };
	int tab2[] = { 9, 8, 7, 6, 5 };

	//odczytywanie elementow
	for (int k : tab1)
		cout << k << ',';
	cout << endl;

	// modyfikowanie elementow (zmienna referencyjna)
	for (int& k : tab2)
		k = 100;

	return 0;
}