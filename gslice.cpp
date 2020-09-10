#include <iostream>
#include <valarray>
#include <cstddef>

/*
 * SELEKTOR UOGÓLNIONY
 */

using namespace std;

void print(valarray<int> arr)
{
	for (auto i : arr) cout << i << ", ";
	cout << endl;
}


int main()
{
	// kontenery
	valarray<int> arr = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 
	};

	// dane
	size_t start = 0;
	valarray<size_t> sizes;
	valarray<size_t> strides;

	// KONSTRUKTORY
	gslice g1;		// komyslny
	gslice g2(g1);	// kopiujacy
	gslice g3(start, sizes, strides);
	gslice g4(0, { 1, 2 }, { 1, 2 });

	// METODY
	//g1.start();
	//g1.size();
	//g1.stride();

	// TEST
	gslice sli(0, { 1, 2, 3 }, { 1, 2, 3 });
	print(arr);
	arr[sli] = 0;
	print(arr);

	return 0;
}