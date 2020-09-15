#include <iostream>

using namespace std;

int main()
{
	// DATE
	int n = 2;
	char c = 'A';
	auto flags = ios_base::showpoint;
	auto flags1 = ios_base::showpoint;
	auto flags2 = ios_base::showpoint;

	// KONFIGURACJA FORMATOWANIA
	cout.width();		// zwraca aktulane ustawienie szerokosci pol
	cout.width(n);		// [SINGLE, DOMYSLNIE=0] szerokosc pola, zwraca poprzednia szerokosc pola
						// jesli drukowane dane nie mieszcza sie, pole jest automatycznie rozszerzane

	cout.fill('c');		// [MULTI, DOMYSLNIE=' '] znak wypelnienia

	cout.precision(n);	// [MULTI, DOMYSLNIE=6] liczba cyfr znaczacych, w trybie domyslnym oznacza laczna liczba cyfr
						// w trybie staloprzecinkowym i naukowym oznacza liczbe cyfr po przecinku

	cout.setf(flags);	// [MULTI] zwracaja aktualna maske bitowa typu fmtflags, okreslajaca dotychczasowe ustawienie znacznikow
	cout.setf(flags1, flags);	// ustawia opcje sterowalne przez wiecej niz jeden bit, pierwszy argument jest pozadanym ustawieniem
								// drugi argument zeruje odpowiednie bity
	
	cout.unsetf(flags);	// cofa ustawienie podanej flagi, zeruje bity odpowiadajace ustawionym bitom maski

	// STALE FORMATOWANIA
	ios_base::showpoint;		// drukowanie kropki dziesietnej oraz koncowych zer
	ios_base::boolalpha;		// drukowanie wartosci typu bool jako true/falsa
	ios_base::showbase;			// drukowanie przedrostkow systemu liczbowego
	ios_base::uppercase;		// drukowanie liczb szesnastkowych przy pomocy wielkich liter
	ios_base::showpos;			// znak + przed liczbami dodatnimi w systemie dziesietnym

	// BITY USTAWIANE (1 ARG) // BITY ZEROWANE (2 ARG)			
	ios_base::dec;			ios_base::basefield;		// dziesietny
	ios_base::oct;										// osemkowy
	ios_base::hex;										// szesnastkowy
	ios_base::fixed;		ios_base::floatfield;		// notacja staloprzecinkowa
	ios_base::scientific;								// notacja naukowa
	ios_base::left;			ios_base::adjustfield;		// wyrownanie do lewej
	ios_base::right;									// wyrownanie do prawej
	ios_base::internal;									// wyrownanie wewnetrzne, do lewej dla znaku i przedrostka, do prawej dla liczby

	// TODO domyslne wyrownanie
	// TODO koncowe zera sa pomijane
	// kropka dziesietna

	// TEST
	cout.precision(5);
	cout << 10.0 << endl;
	cout.setf(ios_base::showpoint);
	cout << 10.0 << endl;

	return 0;
}