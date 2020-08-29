#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#define SIZE 5

using std::vector;
using std::array;
using std::cout;
using std::endl;

void print(vector<int> vec)
{
	cout << "vec: ";
	for (auto i : vec)
		cout << i << ", ";
	cout << endl;
}

void print(array<int, SIZE> arr)
{
	cout << "arr: ";
	for (auto i : arr)
		cout << i << ", ";
	cout << endl;
}

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	vector<int> vec;
	array<int, SIZE> arr;

	vec = { 1, 2, 3, 4, 5 };
	arr = { 5, 4, 3, 2, 1 };

	// INIT
	print(vec);
	print(arr);

	// FOR_EACH - kazdy kontener
	// stosuje podany obiekt funkcyjny dla kazdego elementu z zakresu [first, last)
	//std::for_each(vec.begin(), vec.end(), NULL);

	// RANDOM_SHUFFLE - kontenery o dostepie swobownym do elementow
	// losowo zmienia kolejnosc elementow w zakresie [first, last)
	std::random_shuffle(vec.begin(), vec.end());
	print(vec);

	// SORT - kontenery o dostepie swobodnym do elementow
	// do porownywania elementow kozysta z operatora < zdefiniowanego dla elementow typu przechowywanego przez kontener
	// sortuje elementy w zakresie [first, last)
	std::sort(vec.begin(), vec.end());
	print(vec);
	// do porownywania elemetow kozysta z funkcji/obiektu funkcyjego, funkcja musi zwracac wartosc, ktora da sie przeko-
	// nwertowac na typ bool
	std::sort(vec.begin(), vec.end(), compare);
	print(vec);

	return 0;
}