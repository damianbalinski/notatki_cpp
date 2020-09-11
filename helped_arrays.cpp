#include <iostream>
#include <valarray>

using namespace std;

void print(valarray<int> arr)
{
	cout << "INT : ";
	for (auto i : arr) cout << i << ", ";
	cout << endl;
}

void print(valarray<bool> arr)
{
	cout << "BOOL: ";
	for (auto i : arr) cout << i << ", ";
	cout << endl;
}

int main()
{
	// DANE
	valarray<int> arr = { 1, 2, 3, 4, 5 };
	valarray<size_t> ids = { 0, 2, 4 };


	// TABLICA WARTOSCI - dostep do wszystkich elementow
	valarray<int>;
	arr;

	// TABLICA INDEKSOW - zawiera indeksy elementow
	valarray<size_t>;
	ids;

	// TABLICA WARTOSCI LOGICZNYCH - zawiera wartosci wyrazenia logicznego
	// dla poszczegolnych elementow tablicy wejsciowej
	valarray<bool>;
	arr > 3;

	// MASKA TABLICY - dostep do elementow tablicy wejsciowej,
	// spelniajacych warunek logiczny
	mask_array<int>;
	arr[arr > 3];

	// TABLICA POSREDNIA - posredni dostep do elementow za pomoca tablicy indeksow
	indirect_array<int>;
	arr[ids];

	// TABLICA SLICE - dostep do elementow za pomoca selektora
	slice_array<int>;
	arr[slice(1, 2, 3)];

	// TABLICA GSLICE - dostep do elementow za pomoca selektora uogolnionego
	gslice_array<int>;
	arr[gslice(1, {2}, {3})];

	return 0;
}