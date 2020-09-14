#include <iostream>
#include <valarray>

using namespace std;

int func(int a)
{
	return 10 * a;
}

void print(valarray<int> arr)
{
	for (auto i : arr) cout << i << ", ";
	cout << endl;
}

int main()
{
	/*
	 * size
	 * resize
	 * swap
	 * apply
	 * min
	 * max
	 * sum
	 * shift
	 * cshift
	 */

	// KONTENERY
	valarray<int> arr;
	valarray<int> arr1 = { 1, 2, 3, 4, 5, 6 };
	valarray<int> arr2;

	// ZMIENNE
	int n = 2;
	int val = 2;

	// liczba elementow
	arr.size();		

	// zwieksza/zmniejsza rozmiar kontenera, nowe pola wypelnia wartoscia
	// domyslna lub, jesli podano elementem val
	arr.resize(n);
	arr.resize(n, val);

	// zamienia miejscami elementy kontenerow tego samego typu
	arr.swap(arr1);

	// stosuje funktor func do kazdego elementu tablicy, przypisuje zwrocona 
	// wartosc odpowiedniemu elementowi nowej tablicy, nie modyfikuje tablicy
	// zrodlowej, zwraca nowo powstala tablice
	arr.apply(func);

	// najmniejsza wartosc
	arr.min();

	// najwieksza wartosc
	arr.max();

	// suma elementow
	arr.sum();
	
	// zwraca nowa tablice, w ktorej wszystkie elementy sa przesuniete w lewo
	// o podana awrtosc, puste pola wypelnia elementem zerowym, nie modyfikuje
	// tablicy zrodlowej
	arr.shift(n);

	// zwraca nowa tablice, w ktorej wszystkie elementy sa przesuniete cyklicznie w lewo
	// o podana awrtosc, nie modyfikuje tablicy zrodlowej
	// (zamienia miejscami [first, first+n) oraz [first+n, last))
	arr.cshift(n);

	return 0;
}