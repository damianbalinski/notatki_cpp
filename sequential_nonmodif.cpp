#include <iostream>
//#include <algorithm>
#include <vector>
#include <execution>

/*
 * ALGORYTMY SEKWENCYJNE NIEMODYFIKUJACE
 */

using namespace std;

bool pred(int a) { return a <= 3; }
bool predb(int a, int b) { return true; };

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
	 * adjacent_find
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
	auto policy = std::execution::par;
	int n = 2;
	int val = 3;

	// dane

	// all_of()
	// zwraca true, jesli predykat pred jest prawdziwy
	// dla kazdego elemetnu z zakresu [first, last)
	all_of(first, last, pred);				// (I, I, 1)	bool 
	all_of(policy, first, last, pred);		// (-, F, F, 1)	bool

	// any_of() 
	// zwraca true, jesli predykat pred jest prawdziwy
	// dla co najmniej jednego elementu z zakresu [first, last)
	any_of(first, last, pred);				// (I, I, 1)	bool 
	any_of(policy, first, last, pred);		// (-, F, F, 1)	bool

	// none_of()
	// zwraca true, jesli predykat pred jest falszywy
	// dla kazdego elementu z zakresu [first, last)
	none_of(first, last, pred);				// (I, I, 1)	bool
	none_of(policy, first, last, pred);		// (-, F, F, 1)	bool

	// for_each() NOT_COPY
	// stosuje funktor func dla kazdego elemetnu 
	// z zakresu [first, last), zwraca funktor, wartosc zwracana
	// przez func jest ignorowana
	for_each(first, last, func);			// (I, I, 1)	void
	for_each(policy, first, last, func);	// (-, F, F, 1)	Functor
	

	// for_each_n()	NOT_COPY
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



	/*	
	 * SLOWNIK
	 * first, last - iteratory danych wejsciowych
	 * first2, last2 - iteratory danych wejsciowych
	 * rfirst, rlast - iteratory danych wyjsciowych
	 * pred - predykat
	 * predb - predykat binarny
	 * func - funktor jednoargumentowy
	 * funcb - funktor dwuargumentowy
	 * policy - 
	 * n - ilosc/dlugosc
	 */

	/*
	 * SYMBOLE / ITERATORY
	 * M - funkcja dzialajaca w miejscu
	 * K - funkcja kopiujaca
	 * I - wejsciowy
	 * O - wyjsciowy
	 * F - postepujacy
	 * B - dwukierunkowy
	 * R - dostepu swobodnego
	 * C - ciagly
	 * 1 - predykat/funktor unarny
	 * 2 - predykat/funktor binarny
	 */

	// TEST
	vector<int> v = { 1, 2, 3, 1, 2, 4, 1, 2, 5 };
	vector<int> sec = { 4 };
	auto it = find_first_of(v.begin(), v.end(), sec.begin(), sec.end());
	cout << *it;

	return 0;
}