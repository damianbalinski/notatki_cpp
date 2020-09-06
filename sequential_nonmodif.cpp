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
void func(int& a){ /*a *= 10;*/}

void print(vector<int> vec)
{
	for (auto i : vec) cout << i << ", ";
	cout << endl;
}

int main()
{
	/*
	 * all_of			DONE	DONE
	 * any_of			DONE	DONE
	 * none_of			DONE	DONE
	 * for_each			DONE	DONE
	 * for_each_n		DONE	DONE
	 * find				DONE	DONE
	 * find_if			DONE	DONE
	 * find_if_not		DONE	DONE
	 * find_end			DONE	DONE
	 * find_first_of	DONE	DONE
	 * adjacent_find	DONE	DONE
	 * count			DONE	DONE
	 * count_if			DONE	DONE
	 * mismatch			DONE	DONE
	 * equal			DONE	DONE
	 * search			DONE	DONE
	 * search_n			DONE	DONE
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
	// zwraca true, jesli predykat pred jest prawdziwy
	// dla kazdego elemetnu z [first, last)
	all_of(first, last, pred);				// (I, I, 1)	bool 
	all_of(policy, first, last, pred);		// (-, F, F, 1)	bool

	// any_of() 
	// zwraca true, jesli predykat pred jest prawdziwy
	// dla co najmniej jednego elementu z [first, last)
	any_of(first, last, pred);				// (I, I, 1)	bool 
	any_of(policy, first, last, pred);		// (-, F, F, 1)	bool

	// none_of()
	// zwraca true, jesli predykat pred jest falszywy
	// dla kazdego elementu z [first, last)
	none_of(first, last, pred);				// (I, I, 1)	bool
	none_of(policy, first, last, pred);		// (-, F, F, 1)	bool

	// for_each() NOT_COPY
	// stosuje funktor func dla kazdego elemetnu 
	// z [first, last), zwraca funktor, wartosc zwracana
	// przez func jest ignorowana
	for_each(first, last, func);			// (I, I, 1)	void
	for_each(policy, first, last, func);	// (-, F, F, 1)	Functor
	

	// for_each_n()	COPY-NOT
	// stosuje funktor func dla kazdego elemetnu
	// z zakresu [first, first+n)
	for_each_n(first, n, func);				// (I, -, 1)	iterator
	for_each_n(policy, first, n, func);		// (-, F, -, 1)	iterator

	// find()
	// szuka pierwszego wystapienia elementu val w 
	// [first, last) zwraca iterator na ten element 
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
	
	// find_end()
	// szuka ostatniego wystapienia podsekwencji [first2, last2)
	// w [first, last), elementy sa porownywane operatorem ==
	// lub, jesli podano, predykatem binarnym predb
	// zwraca iterator na poczatek podsekwencji lub last, jesli
	// podsekwencji nie ma
	find_end(first, last, first2, last2);				// (F, F, F, F)			iterator
	find_end(policy, first, last, first2, last2);		// (-, F, F, F, F)		iterator
	find_end(first, last, first2, last2, predb);		// (F, F, F, F, 2)		iterator
	find_end(policy, first, last, first2, last2, predb);// (-, F, F, F, F, 2)	iterator
	
	// find_first_of()
	// szuka pierwszego wystapienia dowolnego elementu z [first2, last2)
	// w [first, last), elementy sa porownywanie operatorem == lub,
	// jesli podano, predykatem bianrnym predb, zwraca iterator
	// na znaleziony element lub last, jesli elementu nie ma
	find_first_of(first, last, first2, last2);					// (F, F, F, F		iterator
	find_first_of(policy, first, last, first2, last2);			// (-, F, F, F, F)	iterator
	find_first_of(first, last, first2, last2, predb);			// (F, F, F, F, 2)	iterator
	find_first_of(policy, first, last, first2, last2, predb);	//(-, F, F, F, F, 2)iterator

	// adjacent_find()
	// szuka pierwszego wystapienia elementu rownowaznego z elementem nastepnym
	// w [first, last), elementy sa porownywane operatorem == lub,
	// jesli podano, predykatem binarnym predb, zwraca iteraotr
	// na znaleziony element lub last, jesli elemetnu nie ma
	adjacent_find(first, last);					// (F, F)		iterator
	adjacent_find(policy, first, last);			// (-, F, F)	iterator
	adjacent_find(first, last, predb);			// (F, F, 2)	iterator
	adjacent_find(policy, first, last, predb);	// (-, F, F, 2)	iterator

	// count()
	// zwraca liczbe wystapien val w [first, last), elementy sa porownywane
	// operatorem ==
	count(first, last, val);			// (I, I)		difference_type
	count(policy, first, last, val);	//(-, F, F)		difference_type

	// count_if()
	// zwraca liczbe elementow w [first, last) spelniajacych predykat pred
	count_if(first, last, pred);			// (I, I, 1)	difference_type
	count_if(policy, first, last, pred);	// (-, F, F, 1)	difference_type

	// mismatch()
	// szuka pierwszego wystapienia elementu w [first, last) niezgodnego
	// z odpowiadajacym mu elementem w [first2, last2), elementy sa
	// porownywane operatorem == lub, jesli podano predykatorem binarnym
	// predb, zwraca pare zlozona z iteratorow na niepasujace elementy
	// w obydwu zakresach
	mismatch(first, last, first2);						// (I, I, I)		pair<iterator, iterator>
	mismatch(policy, first, last, first2);				// (-, F, F, F)		pair<iterator, iterator>
	mismatch(first, last, first2, predb);				// (I, I, I, 2)		pair<iterator, iterator>
	mismatch(policy, first, last, first2, predb);		// (-, F, F, F, 2)	pair<iterator, iterator>
	mismatch(first, last, first2, last2);				// (I, I, I, I)		pair<iterator, iterator>
	mismatch(policy, first, last, first2, last2);		// (-, F, F, F, F)	pair<iterator, iterator>
	mismatch(first, last, first2, last2, predb);		// (I, I, I, I, 2)	pair<iterator, iterator>
	mismatch(policy, first, last, first2, last2, predb);	// (-, F, F, F, F, 2)	pair<iterator, iterator>

	// equal()
	// zwraca true, jesli kazdy element w [first, last) jest zgodny z
	// odpowiadajacym mu elementem w [forst2, last2), elementy sa
	// porownywane operatorem == lub, jesli podano predykatem binarym
	// pred
	equal(first, last, first2);							// (I, I, I)		bool
	equal(policy, first, last, first2);					// (-, F, F, F)		bool
	equal(first, last, first2, predb);					// (I, I, I, 2)		bool
	equal(policy, first, last, first2, predb);			// (-, F, F, F, 2)	bool
	equal(first, last, first2, last2);					// (I, I, I, I)		bool
	equal(policy, first, last, first2, last2);			// (-, F, F, F, F)	bool
	equal(first, last, first2, last2, predb);			// (I, I, I, I, 2)	bool
	equal(policy, first, last, first2, last2, predb);	// (-, F, F, F, F, 2) bool

	// search()
	// szuka pierwszego wystapienia podciagu [first2, last2)
	// w [first, last), elementy sa porownywane operatorem ==
	// lub, jesli podano, predykatem binarnym predb
	// zwraca iterator na poczatek podciagu lub last, jesli
	// podciagu nie ma
	search(first, last, first2, last2);			// (F, F, F, F)			iterator
	search(policy, first, last, first2, last2);	// (-, F, F, F, F)		iterator
	search(first, last, first2, last2, predb);	// (F, F, F, F, 2)		iterator
	search(policy, first, last, first2, last2, predb);	// (-, F, F, F, F, 2) iterator
	search(first, last, searcher);				// (F, F)				iterator

	// search_n()
	// szuka pierwszego wystapnia n-elementowego ciagu wartosci val
	// w [first, last), elementy sa porownywane operatorem ==
	// lub, jesli podano, predykatem binarnym predb
	// zwraca iterator na poczatek podciagu lub last, jesli
	// podciagu nie ma
	search_n(first, last, n, val);					// (F, F)			iterator
	search_n(policy, first, last, n, val);			// (-, F, F)		iterator
	search_n(first, last, n, val, predb);			// (F, F, -, -, 2)	iterator
	search_n(policy, first, last, n, val, predb);	// (-, F, F, -, -, 2)	iterator
	
	// TEST
	vector<int> v = { 0, 1, 4, 2, 1, 1, 3};
	vector<int> v2 = { 2, 3};
	auto it = search_n(v.begin(), v.end(), 2, 1);
	cout << *(it+2) << endl;

	return 0;
}