#include <iostream>
#include <vector>
#include <initializer_list>

/*
 * LISTA INICJALIZACYJNA - tworzona automatycznie podczas
 * inicjalizacji klamrowej obiektu obslugujacego liste inicjalizujaca,

 * implementowana jako para wskaznikow na poczatek i za koniec, lub
 * jako wskaznik na poczatek i liczba elementow
 *
 * mozliwa konwersja niezawezajaca
 * typu elementow listy
 *
 * kopia listy inicjalizacyjnej nie zawiera kopii elemenotw, lecz
 * kopie wskaznikow na te same elementy
 */

using namespace std;

int main()
{
	// dane
	vector<int> v1(10);
	vector<int> v2{ 10 };
	vector<int> v3({ 10 });
	int tab[5] = { 1, 2, 3, 4, 5 };
	initializer_list<int> list{ 0, 1, 2, 3, 4, 5 };

	// konstruktory - jedynym sposobem ustawienia wartosci listy
	// inicjalizujacej jest przypisanie tej listy przez kompilator
	initializer_list<int> l1;
	initializer_list<int> l2{ 1, 2, 3, 4, 5 }; // mozliwe, pomimo braku odpowiedniego konstruktora
	initializer_list<int> l3(tab, tab + 5);		// MSVC only

	// metody
	list.begin();		// wskaznik na pierwszy element
	list.end();			// wskaznik za ostatni element
	list.size();		// liczba elementow

	return 0;
}