#include <iostream>
#include <valarray>

/*
 * SELEKTOR
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
	valarray<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8,9 };

	// dane
	int start = 0;
	int size = 3;
	int stride = 2;
	slice s1;						// domyslny slice(0, 0, 0)
	slice s2(s1);					// kopiujacy
	slice s3(start, size, stride);	// start, size, stride


	s1.start();		// indeks pierwszego elemetu
	s1.size();		// liczba elemenow
	s1.stride();	// odleglosc pomiedzy kolejnymi elementami 

	// TEST
	//print(arr);
	//arr[slice{}] = 0;
	//print(arr);

	return 0;
}