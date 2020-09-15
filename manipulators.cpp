#include <iostream>
#include <iomanip>
#include <ios>

/*
 * STANDARDOWE MANIPULATORY WYJSCIA/WEJSCIA
 * manipulatory to funkcje nieskladowe, ktore przyjmuja jako argument strumien
 * WERSJA OPERATOROWA / WERSJA FUNKCYJNA
 */

using namespace std;

int main()
{
	/*
	 * boolalpha	DONE	DONE	DONE
	 * noboolalpha	DONE	DONE	DONE
	 * oct			DONE	DONE	DONE
	 * dec			DONE	DONE	DONE
	 * hex			DONE	DONE	DONE
	 * setbase		DONE	DONE	DONE
	 * showbase		DONE	DONE	DONE
	 * noshowbase	DONE	DONE	DONE
	 * flush_emit			c++20
	 * emit_on_flush		c++20
	 * no_emit_on_flush		c++20
	 * left			DONE	DONE	DONE
	 * right		DONE	DONE	DONE
	 * internal		DONE	DONE	DONE
	 * setfill		DONE	DONE	DONE	DONE
	 * setw			DONE	DONE	DONE	DONE
	 * showpoint	DONE	DONE	DONE
	 * noshowpoint	DONE	DONE	DONE
	 * setprecision	DONE	DONE	DONE
	 * fixed		DONE	DONE	DONE
	 * scientific	DONE	DONE	DONE
	 * hexfloat		DONE	DONE	DONE
	 * defaultfloat	DONE	DONE	DONE
	 * showpos		DONE	DONE	DONE
	 * noshowpos	DONE	DONE	DONE
	 * endl			DONE	DONE	DONE
	 * flush		DONE	DONE	DONE	DONE
	 * unitbuf		DONE	DONE	DONE
	 * nounitbuf	DONE	DONE	DONE
	 * ws			DONE	DONE	DONE
	 * ends			DONE	DONE	DONE
	 * skipws		DONE	DONE	DONE
	 * noskipws		DONE	DONE	DONE
	 * resetiosflagsDONE	DONE	DONE
	 * setiosflags	DONE	DONE	DONE
	 * get_money
	 * get_time
	 * put_money
	 * put_time
	 * quoted
	 */

	// dane
	int n = 2;
	char c = 'A';
	ios_base::fmtflags mask = 10;

	// ZMIENNE LOGICZNE
	//cout << boolalpha;	boolalpha(cout);	// [ios, IN/OUT, MULTI] znakowa reprezentacja zmiennych logicznych
	//cout << noboolalpha;	noboolalpha(cout);	// [ios, IN/OUT, MULTI] liczbowa reprezentacja zmiennych logicznych

	// SYSTEMY LICZBOWE
	//cout << oct;			oct(cout);			// [ios, IN/OUT, MULTI] osemkowy 
	//cout << dec;			dec(cout);			// [ios, IN/OUT, MULTI] dziesietny 
	//cout << hex;			hex(cout);			// [ios, IN/OUT, MULTI] szesnastkowy 
	//cout << setbase(n);						// [iomanip, IN/OUT, MULTI] podstawa systemu liczbowego (mozliwe 8, 10, 16)
	//cout << showbase;		showbase(cout);		// [ios, IN/OUT, MULTI] przedrostek systemu liczbowego
	//cout << noshowbase;	noshowbase(cout);	// [ios, IN/OUT, MULTI] brak przedrostka systemu liczbowego

	// ROZMIAR/WYROWNANIE
	//cout << left;			left(cout);			// [ios, (IN)/OUT, MULT] wyrownanie do lewej
	//cout << right;		right(cout);		// [ios, (IN)/OUT, MULT] wyrownanie do prawej
	//cout << internal;		internal(cout);		// [ios, (IN)/OUT, MULT]  wyrownanie wewnetrzne, do lewej dla znaku i przedrostka, do prawej dla liczby
	//cout << setfill(c);					cout.fill(c);	// [iomanip, (IN)/OUT, MULT] znak wypelnienia
	//cout << setw(n);						cout.width(n);	// [iomanip, IN/OUT, SINGLE] szerokosc pola
	
	// LICZBY ZMIENNOPRZECINKOWE
	//cout << showpoint;		showpoint(cout);	// [ios, (IN)/OUT, MULT] kropka dziesietna oraz koncowe zer
	//cout << noshowpoint;		noshowpoint(cout);	// [ios, (IN)/OUT, MULT] brak kropki dziesietnej oraz koncowych zer
	//cout << setprecision(n);						// [iomanip, (IN)/OUT, MULT] liczba cyfr znaczacych/cyfr po przecinku
	//cout << fixed;			fixed(cout);		// [ios, (IN)/OUT, MULT] staloprzecinkowy
	//cout << scientific;		scientific(cout);	// [ios, (IN)/OUT, MULT] naukowy
	//cout << hexfloat;			hexfloat(cout);		// [ios, (IN)/OUT, MULT] naukowy szesnastkowy
	//cout << defaultfloat;		defaultfloat(cout);	// [ios, (IN)/OUT, MULT] domyslny

	// INNE
	//cout << showpos;		showpos(cout);			// [ios, (IN)/OUT, MULT] symbol '+' przed liczbami dodatnimi w systemie dziesietnym
	//cout << noshowpos;		noshowpos(cout);	// [ios, (IN)/OUT, MULT] brak symbolu '+' przed liczbami dodatnimi w systemie dziesietnym
	//cout << uppercase;		uppercase(cout);	// [ios, (IN)/OUT, MULT] drukowanie liczb szesnastkowych wielkimi literami
	//cout << nouppercase;	nouppercase(cout);		// [ios, (IN)/OUT, MULT] drukowanie liczb szesnastkowych malymi literami

	// BUFOR
	//cout << endl;			endl(cout);						// [ostream, OUT, SINGLE] oproznia bufor, drukuje znak nowej linii
	//cout << flush;		flush(cout);	cout.flush();	// [ostream, OUT, SINGLE] oproznia bufor
	//cout << unitbuf;		unitbuf(cout);					// [ios, (IN)/OUT, MULTI] automatyczne oproznianie bufora po kazdej operacji wyjscia
	//cout << nounitbuf;	nounitbuf(cout);				// [ios, (IN)/OUT, MULTI] brak automatycznego oprozniania bufora po kazdej operacji wyjscia

	// ZNAKI BIALE
	//cin >> ws;			ws(cin);						// [istream, IN, MULT] pomijanie wiodacych bialych znakow
	//cout << ends;			ends(cout);						// [ostream, OUT, ??] dodaje na koniec znak pusty
	//cout << skipws;		skipws(cout);					// [ios. IN/(OUT) ] pomijanie wiodacych bialych znakow
	//cout << noskipws;		noskipws(cout);					// [ios. IN/(OUT), niepomijanie wiodacych bialych znakow
	
	// MASKA
	cout << resetiosflags(mask);							// [iomanip, IN/OUT, MULT] zeruje wszystkie znaczniki zawarte w masce
	cout << setiosflags(mask);								// [iomanip, IN/OUT, MULT] ustawia wszystkie znaczniki zawarte w masce
	
	// CZAS/WALUTA
															
	/*
	 * MULTI - dziala az do nastepnej zmiany stanu formatowania
	 * SINGLE - dziala tylko na nastepne wyswietlenie, nastepnia przywraca wartosc domyslna
	 *
	 * IN - manipulator strumienia wejsciowego
	 * OUT - manipulator strumienia wyjsciowego
	 * (IN) - manipulator strumienia wejsciowego, bez efektu
	 * (OUT) - manipulator strumienia wyjsciowego, bez efektu
	 */

	// TEST

	return 0;
}