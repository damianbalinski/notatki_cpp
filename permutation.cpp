#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
#include <functional>

/*
 * PERMUTACJE
 */

using namespace std;

bool compb(int& a, int& b) { return a < b; }
void func(int& a) { /*a *= 10;*/ }

void print(vector<int> vec)
{
	for (auto i : vec) cout << i << ", ";
	cout << endl;
}

int main()
{
	/*
	 * is_permutation		DONE	DONE	DONE
	 * next_permutation		DONE	DONE	DONE
	 * prev_permutation		DONE	DONE	DONE
	 */

	// kontenery
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<int> vec2 = { 1, 2, 3, 4, 5 };
	vector<int> rvec = { 1, 2, 3, 4, 5 };

	// iteratory
	auto first = vec.begin();
	auto last = vec.end();
	auto first2 = vec2.begin();
	auto last2 = vec2.end();
	auto rfirst = rvec.begin();
	auto rlast = rvec.end();

	// dane
	auto policy = std::execution::par;
	default_searcher searcher(vec2.begin(), vec2.end());
	int n = 2;
	int val = 3;

	// is_permutaion()
	// sprawdza, czy [first, last) jest permutacja zbioru [fist2, last2)
	is_permutation(first, last, first2);				// (F, F, F)		bool	==
	is_permutation(first, last, first2, compb);			// (F, F, F, 2)		bool	compb (2)
	is_permutation(first, last, first2, last2);			// (F, F, F, F)		bool	==
	is_permutation(first, last, first2, last2, compb);	// (F, F, F, F, 2)	bool	compb (2)
	
	// next_permutation()
	// przeksztalca [first, last) do nastepnej permutacji w porzadku
	// leksykograficznym
	// OK zwraca true, jesli nastepna permutacja istnieje
	// NO zwraca false, jesli nastepna permutacja nie istnieje, przeksztalca 
	// do pierwszej permutacji
	next_permutation(first, last);				// (B, B)		bool	<
	next_permutation(first, last, compb);		// (B, B, 2)	bool	compb (2)

	// prev_permutation()
	// przeksztalca [first, last) do poprzedniej permutacji w porzadku
	// leksykograficznym
	// OK zwraca true, jesli poprzednia permutacja istnieje
	// NO zwraca false, jesli poprzednia permutacja nie istnieje, przeksztalca
	// do ostatniej permutacji
	prev_permutation(first, last);				// (B, B)		bool	<
	prev_permutation(first, last, compb);		// (B, B, 2)	bool	compb (2)

	// TEST
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	print(v1);
	cout << prev_permutation(v1.begin(), v1.end()) <<  endl;
	print(v1);

	return 0;
}