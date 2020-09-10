#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
#include <functional>

/*
 * ALGORYTMY SEKWENCYJNE NIEMODYFIKUJACE (NIEMUTUJACE)
 */

using namespace std;

bool pred(int a) { return a <= 3; }
bool predb(int a, int b) { return true; }
bool compb(int a, int b) { return a < b; }
void func(int& a){ /*a *= 10;*/}

void print(vector<int> vec)
{
	for (auto i : vec) cout << i << ", ";
	cout << endl;
}

int main()
{
	/*
	 * all_of					DONE	DONE	1
	 * any_of					DONE	DONE	2
	 * none_of					DONE	DONE	3
	 * for_each					DONE	DONE	16
	 * for_each_n				DONE	DONE	17
	 * find						DONE	DONE	8
	 * find_if					DONE	DONE	9
	 * find_if_not				DONE	DONE	10
	 * find_first_of			DONE	DONE	11
	 * adjacent_find			DONE	DONE	12
	 * find_end					DONE	DONE	13
	 * search					DONE	DONE	14
	 * search_n					DONE	DONE	15
	 * count					DONE	DONE	6
	 * count_if					DONE	DONE	7
	 * mismatch					DONE	DONE	5		QQQ
	 * equal					DONE	DONE	4		QQQ
	 * lexicographical_compare	DONE	DONE	18
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

	// all_of()
	// sprawdza, czy predykat pred jest prawdziwy
	// dla kazdego elemetnu z [first, last)
	all_of(first, last, pred);				// (I, I, 1)	bool 
	all_of(policy, first, last, pred);		// (-, F, F, 1)	bool

	// any_of() 
	// sprawdza, czy predykat pred jest prawdziwy
	// dla co najmniej jednego elementu z [first, last)
	any_of(first, last, pred);				// (I, I, 1)	bool 
	any_of(policy, first, last, pred);		// (-, F, F, 1)	bool

	// none_of()
	// sprawdza, czy predykat pred jest falszywy
	// dla kazdego elementu z [first, last)
	none_of(first, last, pred);				// (I, I, 1)	bool
	none_of(policy, first, last, pred);		// (-, F, F, 1)	bool

	// for_each() COPY-NOT
	// stosuje funktor func dla kazdego elemetnu 
	// z [first, last), wartosc zwracana przez func jest ignorowana
	for_each(first, last, func);			// (I, I, 1)	void
	for_each(policy, first, last, func);	// (-, F, F, 1)	Functor
	
	// for_each_n()	COPY-NOT
	// stosuje funktor func dla kazdego elemetnu
	// z zakresu [first, first+n)
	for_each_n(first, n, func);				// (I, -, 1)	iterator
	for_each_n(policy, first, n, func);		// (-, F, -, 1)	iterator

	// find()
	// szuka pierwszego wystapienia val w 
	// [first, last), zwraca iterator na ten element 
	// lub last, jesli elementu nie ma
	find(first, last, val);					// (I, I);		iterator
	find(policy, first, last, val);			// (-, F, F)	iterator

	// find_if()
	// szuka pierwszego elementu w [first, last)
	// spelniajacego predykat pred, zwraca iterator na 
	// ten element lub last, jesli elemetnu nie ma
	find_if(first, last, pred);				// (I, I, 1)	iterator
	find_if(policy, first, last, pred);		// (-, F, F, 1)	iterator

	// find_if_not()
	// szuka pierwszego elementu w [first, last)
	// niespelniajacego predykatu pred, zwraca iterator na
	// ten element lub last, jesli elemetnu nie ma
	find_if_not(first, last, pred);			// (I, I, 1)	iterator
	find_if_not(policy, first, last, pred);	// (-, F, F, 1)	iterator

	// find_first_of()
	// szuka pierwszego wystapienia dowolnego elementu z [first2, last2)
	// w [first, last), zwraca iterator na znaleziony element lub last, 
	// jesli elementu nie ma
	find_first_of(first, last, first2, last2);					// (F, F, F, F		iterator	==
	find_first_of(policy, first, last, first2, last2);			// (-, F, F, F, F)	iterator	==
	find_first_of(first, last, first2, last2, compb);			// (F, F, F, F, 2)	iterator	compb
	find_first_of(policy, first, last, first2, last2, compb);	//(-, F, F, F, F, 2)iterator	compb

	// adjacent_find()
	// szuka pierwszego wystapienia pary takich samych sasiednich elementow 
	// w [first, last), zwraca iterator na pierwszy element lub last,
	// jesli elementu nie ma
	adjacent_find(first, last);					// (F, F)		iterator	==
	adjacent_find(policy, first, last);			// (-, F, F)	iterator	==
	adjacent_find(first, last, compb);			// (F, F, 2)	iterator	compb
	adjacent_find(policy, first, last, compb);	// (-, F, F, 2)	iterator	compb

	// find_end()
	// szuka ostatniego wystapienia podciagu [first2, last2)
	// w [first, last), zwraca iterator na poczatek podciagu 
	// lub last, jesli podciagu nie ma
	find_end(first, last, first2, last2);				// (F, F, F, F)			iterator	==
	find_end(policy, first, last, first2, last2);		// (-, F, F, F, F)		iterator	==
	find_end(first, last, first2, last2, compb);		// (F, F, F, F, 2)		iterator	compb
	find_end(policy, first, last, first2, last2, compb);// (-, F, F, F, F, 2)	iterator	compb

	// search()
	// szuka pierwszego wystapienia podciagu [first2, last2)
	// w [first, last), zwraca iterator na poczatek podciagu 
	// lub last, jesli podciagu nie ma
	search(first, last, first2, last2);				// (F, F, F, F)			iterator	==
	search(policy, first, last, first2, last2);		// (-, F, F, F, F)		iterator	==
	search(first, last, first2, last2, compb);		// (F, F, F, F, 2)		iterator	compb
	search(policy, first, last, first2, last2, compb);	// (-, F, F, F, F, 2) iterator	compb
	search(first, last, searcher);					// (F, F)				iterator	searcher

	// search_n()
	// szuka pierwszego wystapnia n-elementowego ciagu wartosci val
	// w [first, last), zwraca iterator na poczatek podciagu lub last, 
	// jesli podciagu nie ma
	search_n(first, last, n, val);					// (F, F)				iterator	==
	search_n(policy, first, last, n, val);			// (-, F, F)			iterator	==
	search_n(first, last, n, val, compb);			// (F, F, -, -, 2)		iterator	compb
	search_n(policy, first, last, n, val, compb);	// (-, F, F, -, -, 2)	iterator	compb

	// count()
	// zwraca liczbe wystapien val w [first, last)
	count(first, last, val);			// (I, I)		difference_type		==
	count(policy, first, last, val);	//(-, F, F)		difference_type		==

	// count_if()
	// zwraca liczbe elementow w [first, last) spelniajacych predykat pred
	count_if(first, last, pred);			// (I, I, 1)	difference_type
	count_if(policy, first, last, pred);	// (-, F, F, 1)	difference_type

	// mismatch()
	// szuka pierwszego wystapienia pary niezgodnych odpowiadajacych sobie
	// elementow w [first, last) oraz [first2, last2), zwraca pare zlozona 
	// z iteratorow na niepasujace elementy w obydwu zakresach
	mismatch(first, last, first2);						// (I, I, I)		pair<iterator, iterator>	==
	mismatch(policy, first, last, first2);				// (-, F, F, F)		pair<iterator, iterator>	==
	mismatch(first, last, first2, compb);				// (I, I, I, 2)		pair<iterator, iterator>	compb
	mismatch(policy, first, last, first2, compb);		// (-, F, F, F, 2)	pair<iterator, iterator>	compb
	mismatch(first, last, first2, last2);				// (I, I, I, I)		pair<iterator, iterator>	==
	mismatch(policy, first, last, first2, last2);		// (-, F, F, F, F)	pair<iterator, iterator>	==
	mismatch(first, last, first2, last2, compb);		// (I, I, I, I, 2)	pair<iterator, iterator>	compb
	mismatch(policy, first, last, first2, last2, compb);	// (-, F, F, F, F, 2)	pair<iterator, iterator>	compb

	// equal()
	// sprawdza, czy kazdy element w [first, last) jest zgodny z
	// odpowiadajacym mu elementem w [first2, last2)
	equal(first, last, first2);							// (I, I, I)		bool	==
	equal(policy, first, last, first2);					// (-, F, F, F)		bool	==
	equal(first, last, first2, compb);					// (I, I, I, 2)		bool	compb
	equal(policy, first, last, first2, compb);			// (-, F, F, F, 2)	bool	compb
	equal(first, last, first2, last2);					// (I, I, I, I)		bool	==
	equal(policy, first, last, first2, last2);			// (-, F, F, F, F)	bool	==
	equal(first, last, first2, last2, compb);			// (I, I, I, I, 2)	bool	compb
	equal(policy, first, last, first2, last2, compb);	// (-, F, F, F, F, 2) bool	compb
	
	// lexicographical_compare()
	// sprawdza, czy [first, last) jest leksykograficznie mniejszy niz [first2, last2)
	lexicographical_compare(first, last, first2, last2);				// (I, I, I, I)			bool	<
	lexicographical_compare(policy, first, last, first2, last2);		// (-, F, F, F, F)		bool	<
	lexicographical_compare(first, last, first2, last2, compb);			// (I, I, I, I)			bool	compb (2)
	lexicographical_compare(policy, first, last, first2, last2, compb);	// (-, F, F, F, F)		bool	compb (2)

	// TEST
	vector<int> v1 = { 0, 1, 2};
	vector<int> v2 = { 0, 1, 2};
	cout << lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());

	return 0;
}