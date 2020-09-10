#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
#include <functional>
#include <random>

/*
 * WYSZUKIWANIE BINARNE
 */

using namespace std;

bool compb(int a, int b) { return a < b; }

void print(vector<int> vec)
{
	for (auto i : vec) cout << i << ", ";
	cout << endl;
}

int main()
{
	/*
	 * lower_bound			DONE	DONE	DONE
	 * upper_bound			DONE	DONE	DONE
	 * equal_range			DONE	DONE	DONE
	 * binary_search		DONE	DONE	DONE
	 */

	 // kontenery
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<int> vec2 = { 1, 2, 3, 4, 5 };
	vector<int> vec3 = { 1, 2, 3, 4, 5 };
	vector<int> rvec = { 1, 2, 3, 4, 5 };

	// iteratory
	auto first = vec.begin();
	auto last = vec.end();
	auto middle = vec.begin() + 2;
	auto first2 = vec2.begin();
	auto last2 = vec2.end();
	auto first3 = vec3.begin();
	auto last3 = vec3.end();
	auto rfirst = rvec.begin();
	auto rlast = rvec.end();
	auto iter1 = vec.begin();
	auto iter2 = vec.begin() + 1;

	// dane
	auto policy = std::execution::par;
	int n = 2;
	int val = 3;


	// lower_bound() SORT
	// zwraca iterator na pierwsza pozycje w [first, last), przed ktora
	// mozna wstawic val bez naruszania porzadku sortowania
	// (iterator na pierwszy element wiekszy/rowny val
	// lub last, jesli takgo elementu nie ma)

	lower_bound(first, last, val);				// (F, F)		iterator	<
	lower_bound(first, last, val, compb);		// (F, F, -, 2)	iterator	compb

	// upper_bound() SORT
	// zwraca iterator na ostatnia pozycje w [first, last), przed ktora
	// mozna wstawic val bez naruszania porzadku sortowania
	// (iterator na pierwszy element wiekszy od wartosci val
	// lub last, jesli takiego elementu nie ma)
	upper_bound(first, last, val);				// (F, F)		iterator	<
	upper_bound(first, last, val, compb);		// (F, F, -, 2)	iterator	compb

	// equal_range() SORT
	// zwraca pare zlozona z iteratorow okreslajacych maksymlany zakres
	// taki ze przed kazda pozycja w tym zakresie mozna wstawic val
	// bez naruszania porzadku sortowania
	// (zwraca pair<lower_bound(), upper_bound()> lub pair<last, last>, jesli
	// takiego zakresu nie ma)
	equal_range(first, last, val);				// (F, F)		pair<iterator, iterator>	<
	equal_range(first, last, val, compb);		// (F, F, -, 2)	pair<iterator, iterator>	compb

	// binary_search() SORT
	// sprawdza, czy [first, last) zawiera element val
	binary_search(first, last, val);			// (F, F)		bool	<
	binary_search(first, last, val, compb);		// (F, F, -, 2)	bool	compb
	
	// TEST
	vector<int> v1 = { 1, 1, 3, 3 };
	cout << binary_search(v1.begin(), v1.end(), 2);

	return 0;
}