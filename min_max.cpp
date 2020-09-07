#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
#include <functional>
#include <random>

/*
 * MINIMUM / MAKSIMUM
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
	 * min						DONE	DONE	DONE
	 * max						DONE	DONE	DONE
	 * minmax					DONE	DONE	DONE
	 * min_element				DONE	DONE	DONE
	 * max_element				DONE	DONE	DONE
	 * clamp					DONE	DONE	DONE
	 */

	 // kontenery
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<int> vec2 = { 1, 2, 3, 4, 5 };
	vector<int> vec3 = { 1, 2, 3, 4, 5 };

	// iteratory
	auto first = vec.begin();
	auto last = vec.end();
	auto middle = vec.begin() + 2;
	auto first2 = vec2.begin();
	auto last2 = vec2.end();
	auto first3 = vec3.begin();
	auto last3 = vec3.end();

	// dane
	auto policy = std::execution::par;
	int n = 2;
	int val = 3;
	int& val1 = vec[0];
	int& val2 = vec[1];
	int& val3 = vec[2];
	auto list = { 1, 2, 3, 4, 5, 6 };

	// min()
	// zwraca najmniejszy element z podanej pary/listy
	// jesli najmniejszych elementow jest wiele, zwraca pierwsze wystapienie
	min(val1, val2);							// T&		<
	min(val1, val2, compb);						// T&		compb (2)
	min(list);									// T		<
	min(list, compb);							// T		compb (2)

	// max()
	// zwraca najwiekszy element z podanej pary/listy
	// jesli najmniejszych elementow jest wiele, zwraca pierwsze wystapienie
	max(val1, val2);							// T&		<
	max(val1, val2, compb);						// T&		compb (2)
	max(list);									// T		<
	max(list, compb);							// T		compb (2)

	// minmax()
	// zwrca pair<min(), max()>
	// jesli najmniejszych elementow jest wiele, zwraca pierwsze wystapienie
	// jesli najwiekszych elementow jest wiele, zwraca ostatnie wystapienie
	minmax(val1, val2);							// pair<T&, T&>		<
	minmax(val1, val2, compb);					// pair<T&, T&>		compb (2)
	minmax(list);								// pair<T, T>		<
	minmax(list, compb);						// pair<T, T>		compb (2)

	// min_element()
	// zwraca iterator na najmniejszy element z [first, last)
	// jesli najmniejszych elementow jest wiele, zwraca pierwsze wystapienie
	min_element(first, last);					// (F, F)		iterator		<
	min_element(policy, first, last);			// (-, F, F)	iterator		<
	min_element(first, last, compb);			// (F, F)		iterator		compb (2)
	min_element(policy, first, last, compb);	// (-, F, F)	iterator		compb (2)

	// max_element()
	// zwraca iterator na najwiekszy element z [first, last)
	// jesli najwiekszych elementow jest wiele, zwraca pierwsze wystapienie
	max_element(first, last);					// (F, F)		iterator		<
	max_element(policy, first, last);			// (-, F, F)	iterator		<
	max_element(first, last, compb);			// (F, F)		iterator		compb (2)
	max_element(policy, first, last, compb);	// (-, F, F)	iterator		compb (2)

	// minmax_element()
	// zwraca pair<min_element(), max_element()>
	// jesli najmniejszych elementow jest wiele, zwraca pierwsze wystapienie
	// jesli najwiekszych elementow jest wiele, zwraca ostatnie wystapienie
	minmax_element(first, last);					// (F, F)		pair<iterator, iterator>		<
	minmax_element(policy, first, last);			// (-, F, F)	pair<iterator, iterator>		<
	minmax_element(first, last, compb);				// (F, F)		pair<iterator, iterator>		compb (2)
	minmax_element(policy, first, last, compb);		// (-, F, F)	pair<iterator, iterator>		compb (2)

	// clamp()
	// zwraca element srodkowy pomiedzy val1, val2, val3
	// val2 musi byc mniejsze niz val2
	clamp(val1, val2, val3);						// T&	<
	clamp(val1, val2, val3, compb);					// T&	compb (2)

	// TEST
	vector<int> v1 = { 1, 1, 1, 2, 2, 2 };
	cout << clamp(1, 2, 3) << endl;
	cout << clamp(2, 1, 3) << endl;
	cout << clamp(3, 1, 2) << endl;

	return 0;
}