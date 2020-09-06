#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
#include <functional>

/*
 * SORTOWANIE
 */

using namespace std;

bool pred(int a) { return true; }
bool predb(int a, int b) { return a < b; }
int func(int& a) { return a * 10; }
int funcb(int& a, int& b) { return a + b; }
int gener_rand() { return rand() % 6; }
int gener() { return 9; }

void print(vector<int> vec)
{
	for (auto i : vec) cout << i << ", ";
	cout << endl;
}

int main()
{
	/*
	 * sort					DONE	DONE	DONE
	 * stable_sort			DONE	DONE	DONE
	 * partial_sort			DONE	DONE	DONE
	 * partial_sort_copy	DONE	DONE	DONE
	 * is_sorted			DONE	DONE	DONE
	 * is_sorted_unit		DONE	DONE	DONE
	 * nth_element			DONE	DONE	DONE
	 */

	// kontenery
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<int> vec2 = { 1, 2, 3, 4, 5 };
	
	// iteratory
	auto first = vec.begin();
	auto middle = vec.begin() + 2;
	auto nth = vec.begin() + 2;
	auto last = vec.end();
	auto first2 = vec2.begin();
	auto last2 = vec2.end();

	// dane
	auto policy = std::execution::par;

	// sort()
	// sortuje rosnaco zakres [first, last)
	// elementy sa porownywane operatorem < lub, jesli podano
	// predykatem binarnym predb
	sort(first, last);					// (R, R)		void
	sort(policy, first, last);			// (-, R, R)	void
	sort(first, last, predb);			// (R, R, 2)	void
	sort(policy, first, last, predb);	// (-, R, R, 2)	void

	// stable_sort()
	// sortuje rosnaco zakres [first, last)
	// zachowuje porzadek elementow rownowaznych
	// elementy sa porownywane operatorem < lub, jesli podano
	// predykatem binarnym predb
	stable_sort(first, last);					// (R, R)		void
	stable_sort(policy, first, last);			// (-, R, R)	void
	stable_sort(first, last, predb);			// (R, R, 2)	void
	stable_sort(policy, first, last, predb);	// (-, R, R, 2)	void

	// partial_sort()
	// czesciowo sortuje rosnaco zakres [first, last) tak, ze 
	// [first, middle) jest posortowany oraz 
	// wszystkie elementy w [first, middle) sa mniejsze/rowne od wszystkich
	// elementow w [middle, last)
	// elementy sa porownywane operatorem < lub, jesli podano
	// predykatem binarnym predb
	partial_sort(first, middle, last);					// (R, R, R)		void
	partial_sort(policy, first, middle, last);			// (-, R, R, R)		void
	partial_sort(first, middle, last, predb);			// (R, R, R, 2)		void
	partial_sort(policy, first, middle, last, predb);	// (-, R, R, R, 2)	void

	// partial_sort_copy()
	// kopiuje czesciowo posortowany rosnaco zakres tak, ze
	// [first2, ...) zawiera n najmniejszych posortowanych elementow, gdzie
	//  n = min(last-first, last2-first2)
	// zwraca iterator za ostatni skopiowany element w zakresie docelowym
	// elementy sa porownywane operatorem < lub, jesli podano
	// predykatem binarnym predb
	partial_sort_copy(first, last, first2, last2);			// (I, I, R, R)	iterator
	partial_sort_copy(policy, first, last, first2, last2);	// (-, F, F, R, R)	iterator
	partial_sort_copy(first, last, first2, last2, predb);			// (I, I, R, R, 2)	iterator
	partial_sort_copy(policy, first, last, first2, last2, predb);	// (-, F, F, R, R, 2)	iterator

	// is_sorted()
	// sprawdza, czy [first, last) jest posortowany rosnaco
	// elementy sa porownywane operatorem < lub, jesli podano
	// predykatem binarnym predb
	is_sorted(first, last);					// (F, F)		bool
	is_sorted(policy, first, last);			// (-, F, F)	bool
	is_sorted(first, last, predb);			// (F, F, 2)	bool
	is_sorted(policy, first, last, predb);	// (-, F, F, 2)	bool

	// is_sorted_unit()
	// zwraca iterator iter, taki ze [first, iter) jest najwiekszym
	// mozliwym zakresem posortowanym rosnaco
	// elementy sa porownywane operatorem < lub, jesli podano
	// predykatem binarnym predb
	is_sorted_until(first, last);					// (F, F)		iterator
	is_sorted_until(policy, first, last);			// (-, F, F)	iterator
	is_sorted_until(first, last, predb);			// (F, F, 2)	iterator
	is_sorted_until(policy, first, last, predb);	// (-, F, F, 2)	iterator

	// nth_element()
	// znajduje n-ty najmniejszy element oraz umieszcza go w nth,
	// wszystkie elementy w [first, nth) sa mniejsze/rowne od wszystkich
	// elementow w [nth, last)
	// elementy sa porownywane operatorem < lub, jesli podano
	// predykatem binarnym predb
	nth_element(first, nth, last);					// (R, R, R)		void
	nth_element(policy, first, nth, last);			// (-, R, R, R)		void
	nth_element(first, nth, last, predb);			// (R, R, R, 2)		void
	nth_element(policy, first, nth, last, predb);	// (-, R, R, R, 2)	void

	/*
	 * SLOWNIK
	 * first, middle, last - iteratory zakresu zrodlowego
	 * first2, last2 - iteratory zakresu docelowego
	 * rfirst, rlast - iteratory zakresu docelowego
	 * nth - iterator na n-ta element w zakresie
	 * pred - predykat
	 * predb - predykat binarny
	 * func - funktor jednoargumentowy
	 * funcb - funktor dwuargumentowy
	 * gener - generator
	 * gener_rand - rownomierny generator losowy
	 * policy -
	 * search -
	 * n - ilosc/dlugosc
	 */

	// TEST
	vector<int> v1 = { 6, 7, 8, 5, 4, 3, 2, 1 };
	vector<int> v2 = { 7, 7, 7, 7, 7 };
	print(v1);
	nth_element(v1.begin(), v1.begin()+1, v1.end());
	print(v1);

	return 0;
}