#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;

int main()
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::vector<int>::iterator iter;

	// ADVANCE() - inkrementacja iteratora o podana liczbe jednostek
	// modyfikuje iterator
	{
		iter = vec.begin();
		iter++;
		std::advance(iter, 3);
		cout << *iter << endl;
	}

	// NEXT() - zwraca nowy iterator zinkrementowany o 1 lub o podana
	// liczbe jednostek, nie modyfikuje iteratora zrodlowego
	{
		iter = vec.begin();
		iter = std::next(iter);
		cout << *iter << endl;
		iter = std::next(iter, 3);
		cout << *iter << endl;
	}

	// PREV() - zwraca nowy iterator zdekrementowany o 1 lub o podana
	// liczbe jednostek, nie modyfikuje iteratora zrodlowego
	{
		iter = vec.end();
		iter = std::prev(iter);
		cout << *iter << endl;
		iter = std::prev(iter, 3);
		cout << *iter << endl;
	}

	// TODO INSERTER() - zwraca iterator sluzacy do wstawiania elementow
	// w danym kontenerze na okreslonej pozycji
	{
		auto iter = std::inserter(vec, vec.begin());
		iter++ = 10;
		iter++ = 20;
		for (auto i : vec) cout << i << ", ";
		cout << endl;
	}

	return 0;
}