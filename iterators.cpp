#include <iostream>
#include <vector>

using std::vector;

int main()
{
	// ITERATOR WEJSCIOWY -> (1)
	// odczyt
	// kolejnosc NO
	// dostep NO

	// ITERATOR WYJSCIOWY -> (1)
	// zapis
	// kolejnosc NO
	// dostep NO

	// ITERATOR POSTEPUJACY -> (8)
	// odczyt/zapis
	// kolejnosc OK
	// dostep NO

	// ITERATOR DWUKIERUNKOWY <-> (8)
	// odczyt/zapis
	// kolejnosc OK
	// dostep NO

	// ITERATOR DOSTEPU SWOBODNEGO <-> (8)
	// odczyt/zapis
	// kolejnosc OK
	// dostep OK

	// ITERATOR CIAGLY <-> (8)
	// odczyt/zapis
	// kolejnosc OK
	// dostep OK
	// kolejne elementy sa przechowywane w sasiadujacych komorkach pamieci

	// WSKAZNIK <-> (8)
	// odczyt/zapis
	// kolejnosc OK
	// dostep OK


	// SYMBOLE

	// odczyt - tylko odczyt (dostep do elementu)
	// zapis - tylko zapis (modyfikowanie wartosci elementu)
	// odczyt/zapis - odczyt oraz zapis

	// ->	- jednokierunkowy mozna zwiekszyc, nie mozna zmniejszyc jego wartosci
	// <->	- dwukierunkowy, mozna zwiekszyc lub zmniejszyc jego wartosc
	
	// (1)	- dla algorytmow jednoprzebiegowych (single-pass algorithm), nie gwarantuje dostepu
	//		do wartosci iteratorow z poprzednich przebiegow
	// (8)	- dla algorytmow wieloprzebiegowych, gwarantuje dostepu
	//		do wartosci iteratorow z poprzednich przebiegow
	
	// kolejnosc NO - nie gwaratuje zachowania tej samej kolejnosci przy wielokrotnym
	//		odwiedzaniu elementu
	// kolejnosc OK - gwarantuje zachowanie tej samej kolejnosci przy wielokrotnym
	//		odwiedzaniu elementu

	// dostep NO - nie umozliwia dostepu swobodnego
	// dostep OK - umozliwia dostep swobodny

	return 0;
}