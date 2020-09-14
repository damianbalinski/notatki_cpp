#include <iostream>
#include <utility>

using namespace std;

int main()
{
	// DANE
	int val1 = 1, val2 = 2;
	int rval1 = 1, rval2 = 2;

	// KONTENERY
	pair my_pair(10, 20);
	pair rmy_pair(10, 20);
	pair p(10, 20);
	pair p1(10, 20);
	pair p2(10, 20);

	// KONSTRUKTORY
	pair<int,int> p1;		// domyslny
	pair p4(my_pair);		// kopiujacy
	pair p5(rmy_pair);		// przenoszacy
	pair p2(val1, val2);
	pair p3(rval1, rval2);
	// TODO tuple in pair constructor

	// METODY
	p1.swap(my_pair);		// zamienia miejscami odpowiadajace sobie elementy
	
	// FUNKCJE
	make_pair(val1, val2);	// zwraca obiekt pair z podanych argumentow, automatyczna dedukcja typu arguemntow
	make_pair(rval1, rval2);

	// OPERATORY					
	p = my_pair;
	p = rmy_pair;
	
	p1 == p2;				// sprawdza, czy odpowiadajace sobie elementy sa takie same
	p1 != p2;
	p1 < p2;				// porownuje najpierw pierwszy element, potem drugi
	p1 <= p2;
	p1 > p2;
	p1 >= p2;

	// TEST

	return 0;
}