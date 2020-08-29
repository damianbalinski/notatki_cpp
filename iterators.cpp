#include <iostream>
#include <vector>

using std::vector;

int main()
{
	// ITERATOR WEJSCIOWY -> (1)
	// tylko odczyt
	// nie gwaratuje zachowania tej samoej kolejnosci przy wielokrotnym
	// odwiedzaniu elementow

	// ITERATOR WYJSCIOWY -> (1)
	// tylko zapis
	// nie gwaratuje zachowania tej samej kolejnosci przy wielokrotnym
	// odwiedzaniu elementow

	// ITERATOR POSTEPUJACY -> (8)
	// odczyt/zapis
	// kolejnosc odwiedzanych elementow jest zawsze taka sama

	// ITERATOR DWUKIERUNKOWY <-> (8)
	// odczyt/zapis
	// kolejnosc odwiedzanych elementow jest zawsze taka sama

	// ITERATOR DOSTEPU SWOBODNEGO <-> (8)
	// umozliwia dostep swobodny
	// odczyt/zapis
	// kolejnosc odwiedzanych elementow jest zawsze taka sama

	// SYMBOLE
	// ->	- jednokierunkowy mozna zwiekszyc, nie mozna zmniejszyc jego wartosci
	// <->	- dwukierunkowy, mozna zwiekszyc lub zmniejszyc jego wartosc
	// (1)	- dla algorytmow jednoprzebiegowych (single-pass algorithm), nie gwarantuje mozliwosci dostepu
	//		do wartosci iteratorow z poprzednich przebiegow
	// (8)	- dla algorytmow wieloprzebiegowych, gwarantuje mozliwosc dostepu
	//		do wartosci iteratorow z poprzednich przebiegow
	
	// TEST
	vector<int> vec = { 1, 2, 3, 4, 5 };
	auto iter = vec.begin();

	vector<int>::reference;
	vector<int>::value_type;

	int* val1 = new int(1);
	int* val2 = new int(2);

	return 0;
}