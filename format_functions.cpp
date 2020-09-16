#include <iostream>

using namespace std;

/*
 * METODY FORMATUJACE
 */

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

	
	// TEST
	cout.precision(5);
	cout << 10.0 << endl;
	cout.setf(ios_base::showpoint);
	cout << 10.0 << endl;

	return 0;
}