#include <iostream>
#include <fstream>

/*
 * STALE TRYBOW OTWARCIA
 * ios_base::openmode;
 * tryby mozna laczyc za pomoca bitowej alternatywy
 */

using namespace std;

int main()
{
	// dane
	const char* file = "test.txt";
	auto in = ios_base::in;
	auto out = ios_base::out;
	auto ate = ios_base::ate;
	auto app = ios_base::app;
	auto trunc = ios_base::trunc;
	auto binary = ios_base::binary;
	auto _Nocreate = ios_base::_Nocreate;
	auto _Noreplace = ios_base::_Noreplace;

	// strumienie
	fstream f;

	// STALE TRYBOW OTWARCIA
	ios_base::in;		// odczyt 
	ios_base::out;		// zapis
	ios_base::app;		// przed kazdym zapisem ustawia pozycje na koniec pliku
	ios_base::ate;		// ustawia pozycje poczatkowa na koniec pliku
	ios_base::trunc;	// obcina zawartosc pliku do zera
	ios_base::binary;	// binarny
	ios_base::_Nocreate;// nie tworzy pliku						// MSVC
	ios_base::_Noreplace;// nie nadpisuje zawartosci pliku		// MSVC


	// KOMBINACJE TRYBOW OTWARCIA
	// ZNAKOWO							
	f.open(file, in);								// r
	f.open(file, in | out);							// r+
	f.open(file, out | trunc);						// w
	f.open(file, in | out | trunc);					// w+
	f.open(file, out | _Noreplace);					// wx
	f.open(file, in | out | _Noreplace);			// w+x
	f.open(file, out | app);						// a
	f.open(file, in | out | app);					// a+
	

	// BINARNIE
	f.open(file, binary | in);						// br
	f.open(file, binary | in | out);				// br+
	f.open(file, binary | out | trunc);				// bw
	f.open(file, binary | in | out | trunc);		// bw+
	f.open(file, binary | out | _Noreplace);		// bwx
	f.open(file, binary | in | out | _Noreplace);	// bw+x
	f.open(file, binary | out | app);				// ba
	f.open(file, binary | in | out | app);			// ba+

	return 0;;
}