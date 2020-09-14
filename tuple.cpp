#include <iostream>
#include <tuple>

using namespace std;

int main()
{
	// KONTENERY
	tuple tup;
	tuple t;
	tuple rtup;
	pair pai(1, 2);
	pair rpai(1, 2);
	tuple tup1;
	tuple tup2;
	tuple tup3;

	// DANE
	int v1 = 10;
	double v2 = 10.0;
	string v3 = "abc";

	// KONSTRUKTORY
	tuple t1;
	tuple t2(v1, v2, v3);
	tuple t3(tup);
	tuple t3(rtup);
	tuple t3(pai);
	tuple t3(rpai);

	// METODY
	t.swap(tup);
	
	// FUNKCJE
	make_tuple(v1, v2, v3);			// zwraca obiekt tuple z podanych argumentow, automatyczna dedukcja typu arguemntow
	tuple_cat(tup1, tup2, tup3);	// zwraca obiekt tuple powstaly z polaczenia podanych krotek

	// OPERATORY
	t = tup;
	t = rtup;
	//t = pai;
	//t = rpai;

	// TEST

	return 0;
}