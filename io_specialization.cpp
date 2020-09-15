#include <iostream>
#include <ostream>
#include <istream>


using namespace std;

int main()
{
	/*
	 * SPECJALIZACJE STRUMIENI
	 */

	// STRUMIENIE WEJSCIA
	// strumien		// specjalizacja
	istream;		basic_istream<char, char_traits<char>>;			cin;
	wistream;		basic_istream<wchar_t, char_traits<wchar_t>>;	wcin;

	// STRUMIENIE WYJSCIA
	// strumien		// specjalizacja
	ostream;		basic_ostream<char, char_traits<char>>;	cout;	cout;
	wostream;		basic_ostream<wchar_t, char_traits<wchar_t>>;	wcout;

	// STRUMIENIE WEJSCIA/WYJSCIA
	iostream;		basic_iostream<char, char_traits<char>>;
	// strumien		// specjalizacja


	/*
	 * PREDEFINIOWANE STRUMIENIE
	 */
	// nazwa	typ strumienia	typ danych	klasa	czy buforowany
	cin;		// standardowy strumien wejsciowy, char, istream
	wcin;		// standardowy strumien wejsciowy, wchar_t, wistream

	cout;		// standardowy strumien wyjsciowy, char, ostream
	wcout;		// standardowy strumien wyjsciowy, wchar_t, wostream

	cerr;		// standardowy strumien bledow, ostream, char, nie buforowany
	wcerr;		// standardowy strumien bledow, wostream, wchar_t, nie buforowany
	
	clog;		// standardowy strumien bledow, ostream, char, chyba buforowany
	wclog;		// standardowy strumien bledow, wostream, wchar_t, chyba buforowany

	return 0;
}