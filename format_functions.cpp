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
	cout.width();		// [streamsize]
	cout.width(n);		// [streamsize, SINGLE, DEF=0] minimalna szerokosc pola, zwraca poprzednia szerokosc pola

	cout.fill('c');		// [MULTI, DOMYSLNIE=' '] znak wypelnienia

	cout.precision();	// [streamsize]
	cout.precision(n);	// [streamsize, MULTI, DEF=6] w trybie domyslnym liczba cyfr znaczacych,
						// w trybie staloprzecinkowym i naukowym liczba cyfr po przecinku, zwraca poprzednia precyzje

	cout.setf(flags);	// [fmtflags] wlacza znaczniki zawarte w masce, zwraca poprzednie ustawienia
	cout.setf(flags1, flags);	// wlacza znaczniki zawarte w masce sterowalne przez wiecej niz jeden bit,  pierwszy argument jest pozadanym ustawieniem
								// drugi argument zeruje odpowiednie bity
	
	cout.unsetf(flags);	// [void] zeruje znaczniki zawarte w masce

	cout.flags();		// [fmtflags] zwraca ustawienia formatowania
	cout.flags(flags);	// [fmtflags] zmienia ustawienia formatowania na podana maske, zwraca poprzednie ustawienia
	
	// TEST


	return 0;
}