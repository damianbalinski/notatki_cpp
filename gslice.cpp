#include <iostream>
#include <valarray>
#include <cstddef>
#include <numeric>

/*
 * SELEKTOR UOGÓLNIONY
 *
 * start	sizes	strides
 * 3		{2, 3}	{5, 2}
 * i0 = 3 + 0*4 + 0*7
 * i1 = 3 + 0*4 + 1*7
 * i2 = 3 + 0*4 + 2*7
 * i3 = 3 + 1*4 + 0*7
 * i4 = 3 + 1*4 + 1*7
 * i5 = 3 + 1*4 + 2*7
 * LACZNIE = 2*3
 */

using namespace std;

void print(valarray<int> arr)
{
	for (auto i : arr) cout << i << ", ";
	cout << endl;
}

int main()
{
	// dane
	size_t start = 0;
	valarray<size_t> sizes = { 2, 3 };
	valarray<size_t> strides = { 5, 2 };

	// kontenery
	valarray<int> arr(10);
	iota(begin(arr), end(arr), 0);

	// KONSTRUKTORY
	gslice g1;		// komyslny
	gslice g2(g1);	// kopiujacy
	gslice g3(start, sizes, strides);
	gslice g4(2, { 4 }, { 5 });

	// METODY
	g1.start();	//	size_t				indeks pierwszego elementu
	g1.size();	//	valarray<size_t>	liczby elementow w kazdym wymiarze
	g1.stride();//		valarray<size_t>	przesuniecia pomiedzy elementami w kazdym wymiarze

	return 0;
}