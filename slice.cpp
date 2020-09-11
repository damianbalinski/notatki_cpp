#include <iostream>
#include <valarray>

/*
 * SELEKTOR

 * start	size	stride
 * 3		4		7
 * i0 = 3 + 0*7
 * i1 = 3 + 1*7
 * i2 = 3 + 2*7
 * i3 = 3 + 3*7
 * LACZNIE = 4
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

	// KONSTRUKTORY
	slice s1;						// domyslny slice(0, 0, 0)
	slice s2(s1);					// kopiujacy
	slice s3(start, size, stride);

	// METODY
	s1.start();		// indeks pierwszego elemetu
	s1.size();		// liczba elemenow
	s1.stride();	// przesuniecie pomiedzy elementami

	return 0;
}