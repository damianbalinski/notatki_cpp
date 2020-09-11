#include <iostream>
#include <valarray>

using namespace std;

int main()
{
	// kontenery
	valarray<int> arr = { 1, 2, 3, 4, 5 };
	valarray<int> rarr = { 1, 2, 3, 4, 5 };
	valarray<size_t> ids = { 0, 1, 4 };

	// dane
	int n = 10;
	int val = 2;
	int tab[] = { 1, 2, 3, 4, 5 };

	// tablice pomocnicze
	auto slice_array = arr[slice(1, 2, 3)];
	auto gslice_array = arr[gslice(1, { 2 }, { 3 })];
	auto mask_array = arr[arr > 3];
	auto indirect_array = arr[ids];
	auto list = { 1, 2, 3, 4, 5 };

	valarray<int> a1;					// domyslny
	valarray<int> a2(n);				// n zainicjalizowanych kopii
	valarray<int> a2(val, n);			// n kopii elementu val
	valarray<int> a2(tab, n);			// n pierwszych elementow tablicy tab
	valarray<int> a2(arr);				// kopiujacy
	valarray<int> a2(rarr);				// przenoszacy
	valarray<int> a2(slice_array);		// slice_array
	valarray<int> a2(gslice_array);		// gslice_array
	valarray<int> a2(mask_array);		// mask_array
	valarray<int> a2(indirect_array);	// indirect_array
	valarray<int> a2(list);				// lista inicjalizujaca


	return 0;
}