#include <iostream>

/*
 * STALE FORMATOWANIA
 */

using namespace std;

int main()
{
	// JEDNOARGUMENTOWE (1)
	ios_base::boolalpha;		// znakowa reprezentacja zmiennych logicznych
	ios_base::showbase;			// przedrostek systemu liczbowego
	ios_base::showpoint;		// kropka dziesietna oraz koncowe zera
	ios_base::showpos;			// symbol '+' przed liczbami dodatnimi w systemie dziesietnym
	ios_base::uppercase;		// drukowanie liczb szesnastkowych wielkimi literami
	ios_base::unitbuf;			// automatyczne oproznianie bufora po kazdej operacji wyjscia
	ios_base::skipws;			// pomijanie poprzedzajacych bialych znakow

	// DWUARGUMENTOWE (1 | 2)
	ios_base::oct;			ios_base::basefield;		// osemkowy
	ios_base::dec;			/**/						// dziesietny
	ios_base::hex;			/**/						// szesnastkowy
	ios_base::left;			ios_base::adjustfield;		// wyrownanie do lewej
	ios_base::right;		/**/						// wyrownanie do prawej
	ios_base::internal;		/**/						// wyrownanie wewnetrzne, do lewej dla przedrostka, do prawej dla liczby
	ios_base::fixed;		ios_base::floatfield;		// staloprzecinkowy
	ios_base::scientific;	/**/						// naukowy

	return 0;
}