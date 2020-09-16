#include <iostream>
#include <iomanip>
#include <ios>

/*
 * STANDARDOWE MANIPULATORY WYJSCIA/WEJSCIA
 * manipulatory to funkcje nieskladowe, ktore przyjmuja jako argument strumien
 * WERSJA OPERANDOWA / WERSJA FUNKCYJNA
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
	ios_base::fmtflags mask;
	long double mon = 123.45;
	tm time;
	char format[100] = "";

	// ZMIENNE LOGICZNE
	// boolalpha [ios, IN/OUT, MULTI] znakowa reprezentacja zmiennych logicznych
	// cout << boolalpha;
	// boolalpha(cout);
	// cout.setf(ios_base::boolalpha);

	// noboolalpha [ios, IN/OUT, MULTI] liczbowa reprezentacja zmiennych logicznych
	// cout << noboolalpha;
	// noboolalpha(cout);
	// cout.unsetf(ios_base::boolalpha);


	// SYSTEMY LICZBOWE
	// oct [ios, IN/OUT, MULTI] osemkowy
	// cout << oct;
	// oct(cout);
	// cout.setf(ios_base::oct, ios_base::basefield);

	// dec [ios, IN/OUT, MULTI] dziesietny 
	// cout << dec;
	// dec(cout);
	// cout.setf(ios_base::dec, ios_base::basefield);

	// hex [ios, IN/OUT, MULTI] szesnastkowy
	// cout << hex;
	// hex(cout);
	// cout.setf(ios_base::hex, ios_base::basefield);

	// showbase [ios, IN/OUT, MULTI] przedrostek systemu liczbowego
	// cout << showbase;
	// showbase(cout);
	// cout.setf(ios_base::showbase);

	// noshowbase [ios, IN/OUT, MULTI] brak przedrostka systemu liczbowego
	// cout << noshowbase;
	// noshowbase(cout); 
	// cout.unsetf(ios_base::showbase);

	// setbase [iomanip, IN/OUT, MULTI] podstawa systemu liczbowego (mozliwe 8, 10, 16)
	// cout << setbase(n);


	// SZEROKOSC/WYROWNANIE
	// left [ios, (IN)/OUT, MULT] wyrownanie do lewej
	// cout << left;
	// left(cout);
	// cout.setf(ios_base::internal, ios_base::adjustfield);

	// right [ios, (IN)/OUT, MULT] wyrownanie do prawej
	// cout << right;
	// right(cout);
	// cout.setf(ios_base::right, ios_base::adjustfield);

	// internal [ios, (IN)/OUT, MULT]  wyrownanie wewnetrzne, do lewej dla przedrostka, do prawej dla liczby
	// cout << internal;
	// internal(cout);
	// cout.setf(ios_base::internal, ios_base::adjustfield);

	// setw [iomanip, IN/OUT, SINGLE, DEF=6] szerokosc pola
	// cout << setw(n);
	// cout.width(n);
	// cout.width(); 

	// setfill [iomanip, (IN)/OUT, MULT, DEF=' '] znak wypelnienia
	// cout << setfill(c);						
	// cout.fill(c);
	// cout.fill();


	// LICZBY ZMIENNOPRZECINKOWE
	// showpoint [ios, (IN)/OUT, MULT] kropka dziesietna oraz koncowe zer
	// cout << showpoint;
	// showpoint(cout);
	// cout.setf(ios_base::showpoint);

	// noshowpoint [ios, (IN)/OUT, MULT] brak kropki dziesietnej oraz koncowych zer
	// cout << noshowpoint;
	// noshowpoint(cout);
	// cout.unsetf(ios_base::showpoint);

	// setprecision [iomanip, (IN)/OUT, MULT, DEF=6] cyfry znaczace/po przecinku
	// cout << setprecision(n);
	// cout.precision(n);
	// cout.precision();
	
	// fixed [ios, (IN)/OUT, MULT] staloprzecinkowy
	// cout << fixed;
	// fixed(cout);
	// cout.setf(ios_base::fixed, ios_base::floatfield);

	// scientific [ios, (IN)/OUT, MULT] naukowy
	// cout << scientific;
	// scientific(cout);
	// cout.setf(ios_base::scientific, ios_base::floatfield);

	// hexfloat [ios, (IN)/OUT, MULT] naukowy szesnastkowy
	// cout << hexfloat;
	// hexfloat(cout);
	// cout.setf(ios_base::fixed | ios_base::scientific, ios_base::floatfield);

	// defaultfloat [ios, (IN)/OUT, MULT] domyslny
	// cout << defaultfloat;
	// defaultfloat(cout);
	// cout.unsetf(ios_base::floatfield);


	// ROZNE
	// showpos [ios, (IN)/OUT, MULT] symbol '+' przed liczbami dodatnimi w systemie dziesietnym
	// cout << showpos;
	// showpos(cout);
	// cout.setf(ios_base::showpos);

	// noshowpos [ios, (IN)/OUT, MULT] brak symbolu '+' przed liczbami dodatnimi w systemie dziesietnym
	// cout << noshowpos;
	// noshowpos(cout);
	// cout.unsetf(ios_base::showpos);

	// uppercase [ios, (IN)/OUT, MULT] drukowanie liczb szesnastkowych wielkimi literami
	// cout << uppercase;
	// uppercase(cout);
	// cout.setf(ios_base::uppercase);

	// nouppercase [ios, (IN)/OUT, MULT] drukowanie liczb szesnastkowych malymi literami
	// cout << nouppercase;
	// nouppercase(cout);		
	// cout.unsetf(ios_base::uppercase);


	// BUFOR
	// endl [ostream, OUT, SINGLE] oproznia bufor, drukuje znak nowej linii
	// cout << endl;
	// endl(cout);
	
	// flush [ostream, OUT, SINGLE] oproznia bufor
	// cout << flush;
	// flush(cout);
	// cout.flush();

	// unitbuf [ios, (IN)/OUT, MULTI] automatyczne oproznianie bufora po kazdej operacji wyjscia
	// cout << unitbuf;
	// unitbuf(cout);
	// cout.setf(ios_base::unitbuf);
	
	// nounitbuf [ios, (IN)/OUT, MULTI] brak automatycznego oprozniania bufora po kazdej operacji wyjscia
	// cout << nounitbuf;
	// nounitbuf(cout);
	// cout.unsetf(ios_base::unitbuf);


	// ZNAKI BIALE
	// ws [istream, IN, MULT] pomijanie poprzedzajacych bialych znakow
	// cin >> ws;
	// ws(cin);

	// skipws [ios, IN/(OUT), MULT] pomijanie poprzedzajacych bialych znakow
	// cin >> skipws;
	// skipws(cin);
	// cin.setf(ios_base::skipws);

	// noskipws [ios. IN/(OUT), MULT] niepomijanie wiodacych bialych znakow
	// cin >> noskipws;
	// noskipws(cin);
	// cin.unsetf(ios_base::skipws);

	// ends [ostream, OUT, ??] dodaje na koniec znak pusty
	// cout << ends;
	// ends(cout);
	

	// MASKA
	// resetiosflags [iomanip, IN/OUT, MULT] zeruje znaczniki zawarte w masce
	// cout << resetiosflags(mask);
	// cout.setf(std::ios_base::fmtflags(0), mask);

	// setiosflags [iomanip, IN/OUT, MULT] ustawia znaczniki zawarte w masce
	// cout << setiosflags(mask);								
	// cout.setf(mask);

	// WALUTA/CZAS
	// get_money [] - parsuje wartosc monetarna do typu long double lub string
	// jesli intl=false, uzywa symboli walut, w przeciwnym razie uzywa lancuchow walut
	// cin >> get_money(mon, false);

	// put_money [] - drukuje wartosc monetarna z typu long double lub string,
	// jesli intl=false, uzywa symboli walut, w przeciwnym razie uzywa lancuchow walut
	// cout << put_money(mon, false);

	// get_time [] - parsuje data/czas zgodnie z podanym lancuchem formatujacym
	cin >> get_time(&time, format);

	// put_time [] drukuje date/czas zgodnie z podanym lancuchem formatujacym
	cout << put_time(&time, format);

	/*
	 * MULTI - dziala az do nastepnej zmiany stanu formatowania
	 * SINGLE - dziala tylko na nastepne wyswietlenie, nastepnia przywraca wartosc domyslna
	 *
	 * IN - manipulator strumienia wejsciowego
	 * OUT - manipulator strumienia wyjsciowego
	 * (IN) - manipulator strumienia wejsciowego, bez efektu
	 * (OUT) - manipulator strumienia wyjsciowego, bez efektu
	 */

	return 0;
}