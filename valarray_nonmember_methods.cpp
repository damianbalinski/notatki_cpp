#include <iostream>
#include <valarray>

using namespace	std;

void print(valarray<int> arr)
{
	for (auto i : arr) cout << i << ", ";
	cout << endl;
}

int main()
{
	/*
	 * +
	 *
	 *
	 *
	 */

	 // KONTENERY
	valarray<int> arr = { 1, 2, 3, 4, 5 };
	valarray<int> arr1 = { 1, 2, 3, 4, 5 };
	valarray<int> arr2 = { 1, 2, 3, 4, 5 };

	// ZMIENNE
	int n = 2;
	int val = 2;

	// iterator na pierwszy element
	begin(arr);

	// iterator za ostatni element
	end(arr);
	
	// TEST


	return 0;
}