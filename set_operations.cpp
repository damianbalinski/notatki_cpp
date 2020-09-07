#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
#include <functional>
#include <random>

/*
 * ALGORYTMY NA ZBIORACH
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
	 * merge						DONE	DONE	DONE
	 * inplace_merge				DONE	DONE	DONE
	 * includes						DONE	DONE	DONE
	 * set_union					DONE	DONE	DONE
	 * set_intersection				DONE	DONE	DONE
	 * set_difference				DONE	DONE	DONE
	 * set_symmetric_difference		DONE	DONE	DONE
	 */

	 // kontenery
	vector<int> vec = { 1, 2, 3 };
	vector<int> vec2 = { 1, 2, 3 };
	vector<int> vec3 = { 1, 2, 3, 4, 5, 6, 7 };

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
	int& val1 = vec.at(0);
	int& val2 = vec.at(1);

	// merge() SORT | COPY-NOT | STABLE
	// scala elementy z [first, last) oraz [first2, last2) zachowujac porzadek sortowania
	// wynik zapisuje w [first3, ...)
	// zwraca iterator na ostatni skopiowany element w zakresie docelowym
	merge(first, last, first2, last2, first3);				// (I, I, I, I, O)			iterator	<
	merge(policy, first, last, first2, last2, first3);		// (-, F, F, F, F, F)		iterator	<
	merge(first, last, first2, last2, first3, compb);		// (I, I, I, I, O, 2)		iterator	compb
	merge(policy, first, last, first2, last2, first3, compb);// (-, F, F, F, F, F, 2)	iterator	compb

	// implace_merge() SORT | STABLE
	// scala posortowane zakresy [first, middle) oraz [middle, last) w
	// pojedynyczy posortowany zakres [first, last)
	inplace_merge(first, middle, last);						// (B, B, B)		void	<
	inplace_merge(policy, first, middle, last);				// (-, B, B, B)		void	<
	inplace_merge(first, middle, last, compb);				// (B, B, B)		void	compb
	inplace_merge(policy, first, middle, last, compb);		// (-, B, B, B)		void	compb

	// includes() SORT
	// sprawdza, czy [first2, last2) jest podzbiorem [first, last)
	includes(first, last, first2, last2);					// (I, I, I, I)			bool	<
	includes(policy, first, last, first2, last2);			// (-, F, F, F, F)		bool	<
	includes(first, last, first2, last2, compb);			// (I, I, I, I)			bool	compb
	includes(policy, first, last, first2, last2, compb);	// (-, F, F, F, F)		bool	compb

	// set_union() SORT | COPY-NOT | STABLE
	// umieszcza sume zbiorow [first, last) oraz [first2, last2) pod [first3, ...)
	// zwraca iterator za ostatni skopiowany element w zakresie docelowym
	// jesli element e wystepuje a razy w [first, last) oraz b razy w [first2, last2),
	// element e wystapi max(a, b) razy w [first3, ...)
	set_union(first, last, first2, last2, first3);					// (I, I, I, I, O)			iterator	<
	set_union(policy, first, last, first2, last2, first3);			// (-, F, F, F, F, F, F)	iteraotor	<
	set_union(first, last, first2, last2, first3, compb);			// (I, I, I, I, O)			iterator	compb
	set_union(policy, first, last, first2, last2, first3, compb);	// (-, F, F, F, F, F, F)	iteraotor	compb

	// set_intersection() SORT | COPY-NOT | STABLE
	// umieszcza przeciecie zbiorow [first, last) oraz [first2, last2) pod [first3, ...)
	// zwraca iterator za ostatni skopiowany element w zakresie docelowym
	// jesli element e wystepuje a razy w [first, last) oraz b razy w [first2, last2),
	// element e wystapi min(a, b) razy w [first3, ...)
	set_intersection(first, last, first2, last2, first3);					// (I, I, I, I, O)		iterator	<
	set_intersection(policy, first, last, first2, last2, first3);			// (-, F, F, F, F, F)	iteraotor	<
	set_intersection(first, last, first2, last2, first3, compb);			// (I, I, I, I, O)		iterator	predb (2)
	set_intersection(policy, first, last, first2, last2, first3, compb);	// (-, F, F, F, F, F)	iteraotor	predb (2)
	
	// set_difference() SORT | COPY-NOT | STABLE
	// umieszcza roznice zbiorow [first, last) oraz [first2, last2) pod [first3, ...)
	// zwraca iterator za ostatni skopiowany element w zakresie docelowym
	// jesli element e wystepuje a razy w [first, last) oraz b razy w [first2, last2),
	// element e wystapi max(a-b, 0) razy w [first3, ...)
	set_difference(first, last, first2, last2, first3);					// (I, I, I, I, O)		iterator	<
	set_difference(policy, first, last, first2, last2, first3);			// (-, F, F, F, F, F)	iteraotor	<
	set_difference(first, last, first2, last2, first3, compb);			// (I, I, I, I, O)		iterator	compb
	set_difference(policy, first, last, first2, last2, first3, compb);	// (-, F, F, F, F, F)	iteraotor	compb

	// set_symmetric_difference() SORT | COPY-NOT | STABLE
	// umieszcza roznice symbetryczna zbiorow [first, last) oraz [first2, last2) pod [first3, ...)
	// zwraca iterator za ostatni skopiowany element w zakresie docelowym
	// jesli element e wystepuje a razy w [first, last) oraz b razy w [first2, last2),
	// element e wystapi max(a-b, b-a) razy w [first3, ...)
	set_symmetric_difference(first, last, first2, last2, first3);					// (I, I, I, I, O)		iterator	<
	set_symmetric_difference(policy, first, last, first2, last2, first3);			// (-, F, F, F, F, F)	iteraotor	<
	set_symmetric_difference(first, last, first2, last2, first3, compb);			// (I, I, I, I, O)		iterator	compb
	set_symmetric_difference(policy, first, last, first2, last2, first3, compb);	// (-, F, F, F, F, F)	iteraotor	compb

	// TEST
	//vector<int> v1 = { 1, 1, 1, 2, 2, 2};
	//vector<int> v2 = { 1, 1, 2, 2, 2, 2};
	//vector<int> v3 = { 7 ,7 ,7, 7, 7, 7, 7, 7, 7, 7, 7, 7};

	//print(v3);
	//auto it = set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	//print(v3);
	//cout << it - v3.begin();

	return 0;
}