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

	// ARYTMETYCZNE
	arr = arr1 + arr2;
	arr = val + arr1;
	arr = arr1 + val;
	arr += arr1;
	arr += val;

	arr = arr1 - arr2;
	arr = arr1 * arr2;
	arr = arr1 / arr2;

	// LOGICZNE
	// tworzy tablice wartosci logicznych, w danym polu wstawia true,
	// jesli odpowiedni element spelnia podany warunek, w przeciwnym
	// wypadku wstawia false
	arr1 > arr2;
	arr1 > 9;
	9 > arr1;

	// DOSTEP
	// indeksowanie liczba lub obiektem slice
	arr[10];

	// TEST
	valarray<int> v1 = { 1, 2, 3 };
	valarray<int> v2 = { 1, 2, 3 };
	valarray<int> v3 = { 0, 0, 0 };
	
	print(v3);
	v3 = v1 + v2;
	print(v3);
	
	return 0;
}