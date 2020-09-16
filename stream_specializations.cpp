#include <iostream>
#include <ostream>
#include <istream>

/*
 * SPECJALIZACJE STRUMIENI
 */

using namespace std;

int main()
{
	// SPECJALIZACJE STRUMIENI - CHAR
	// KONSOLA		STRING			PLIK
	streambuf;		stringbuf;		filebuf;		// obsluga bufora
	istream;		istringstream;	ifstream;		// strumien wejscia
	ostream;		ostringstream;	ofstream;		// strumien wyjscia
	iostream;		stringstream;	fstream;		// strumien wejscia/wyjscia

	// SPECJALIZACJE KLAS POMOCNICZYCH - CHAR
	ios_base;			// ogolne wlasciwosci strumienia
	ios;				// wskaznik na streambuf, stale formatowania (pochodna ios_base)
	
	// SPECJALIZACJE STRUMIENI - WCHAR_T
	// KONSOLA		STRING			PLIK
	wstreambuf;		wstringbuf;		wfilebuf;		// obsluga bufora
	wistream;		wistringstream;	wifstream;		// strumien wejscia
	wostream;		wostringstream;	wofstream;		// strumien wyjscia
	wiostream;		wstringstream;	wfstream;		// strumien wejscia/wyjscia

	// SPECJALIZACJE KLAS POMOCNICZYCH - WCHAR_T
	ios_base;			// ogolne wlasciwosci strumienia
	wios;				// wskaznik na streambuf, stale formatowania (pochodna ios_base)

	return 0;
}