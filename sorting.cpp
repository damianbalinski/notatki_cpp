#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
#include <functional>

/*
 * SORTOWANIE
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
	 * sort					DONE	DONE	DONE	1
	 * stable_sort			DONE	DONE	DONE	2
	 * partial_sort			DONE	DONE	DONE
	 * partial_sort_copy	DONE	DONE	DONE
	 * is_sorted			DONE	DONE	DONE	3
	 * is_sorted_unit		DONE	DONE	DONE	4
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
	sort(first, last);					// (R, R)		void	<
	sort(policy, first, last);			// (-, R, R)	void	<
	sort(first, last, compb);			// (R, R, 2)	void	compb
	sort(policy, first, last, compb);	// (-, R, R, 2)	void	compb

	// stable_sort()
	// sortuje rosnaco zakres [first, last)
	// zachowuje porzadek elementow rownowaznych
	stable_sort(first, last);					// (R, R)		void	<
	stable_sort(policy, first, last);			// (-, R, R)	void	<
	stable_sort(first, last, compb);			// (R, R, 2)	void	compb
	stable_sort(policy, first, last, compb);	// (-, R, R, 2)	void	compb

	// partial_sort()
	// czesciowo sortuje rosnaco zakres [first, last) tak, ze 
	// [first, middle) jest posortowany oraz 
	// wszystkie elementy w [first, middle) sa mniejsze/rowne od wszystkich
	// elementow w [middle, last)
	partial_sort(first, middle, last);					// (R, R, R)		void	<
	partial_sort(policy, first, middle, last);			// (-, R, R, R)		void	<
	partial_sort(first, middle, last, compb);			// (R, R, R, 2)		void	compb
	partial_sort(policy, first, middle, last, compb);	// (-, R, R, R, 2)	void	compb

	// partial_sort_copy()
	// kopiuje czesciowo posortowany rosnaco zakres tak, ze
	// [first2, ...) zawiera n najmniejszych posortowanych elementow, gdzie
	//  n = min(last-first, last2-first2)
	// zwraca iterator za ostatni skopiowany element w zakresie docelowym
	partial_sort_copy(first, last, first2, last2);					// (I, I, R, R)			iterator	<
	partial_sort_copy(policy, first, last, first2, last2);			// (-, F, F, R, R)		iterator	<
	partial_sort_copy(first, last, first2, last2, compb);			// (I, I, R, R, 2)		iterator	compb
	partial_sort_copy(policy, first, last, first2, last2, compb);	// (-, F, F, R, R, 2)	iterator	compb

	// is_sorted()
	// sprawdza, czy [first, last) jest posortowany rosnaco
	is_sorted(first, last);					// (F, F)		bool	<
	is_sorted(policy, first, last);			// (-, F, F)	bool	<
	is_sorted(first, last, compb);			// (F, F, 2)	bool	compb
	is_sorted(policy, first, last, compb);	// (-, F, F, 2)	bool	compb

	// is_sorted_unit()
	// zwraca iterator iter, taki ze [first, iter) jest najwiekszym
	// mozliwym zakresem posortowanym rosnaco
	is_sorted_until(first, last);					// (F, F)		iterator	<
	is_sorted_until(policy, first, last);			// (-, F, F)	iterator	<
	is_sorted_until(first, last, compb);			// (F, F, 2)	iterator	compb
	is_sorted_until(policy, first, last, compb);	// (-, F, F, 2)	iterator	compb

	// nth_element()
	// znajduje n-ty najmniejszy element oraz umieszcza go w nth,
	// wszystkie elementy w [first, nth) sa mniejsze/rowne od kazdego
	// elementu z [nth, last)
	nth_element(first, nth, last);					// (R, R, R)		void	<
	nth_element(policy, first, nth, last);			// (-, R, R, R)		void	<
	nth_element(first, nth, last, compb);			// (R, R, R, 2)		void	compb
	nth_element(policy, first, nth, last, compb);	// (-, R, R, R, 2)	void	compb

	// TEST
	vector<int> v1 = { 6, 7, 8, 5, 4, 3, 2, 1 };
	vector<int> v2 = { 7, 7, 7, 7, 7 };
	print(v1);
	nth_element(v1.begin(), v1.begin()+1, v1.end());
	print(v1);

	return 0;
}