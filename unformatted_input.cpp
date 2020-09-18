#include <iostream>
#include <string>
#include <streambuf>

/*
 * NIEFORMATOWANE WEJSCIE
 * dane sa odczytywane w postaci bitow, bez konwersji na okreslone typy
 */

using namespace std;

int main()
{
	// MODEL
	// [return_type		ZNAK/LANCUCH		DELIM		CZY_DODAJE_ZNAK_PUSTY	DZIALANIE
	// dane
	char c;
	char buff[100];
	string str;
	int n = 3;
	char delim = '$';
	//basic_streambuf<char> str_buff{};

	cin.get();					// [int_type, ZNAK, -, TAK, -]					konwertuje pobrany znak na typ calkowity, zwraca EOF w przypadku konca pliku
	cin.get(c);					// [basic_istream&, ZNAK, -, TAK, -]			zapisuje pobrany znak pod c
	cin.get(buff, n);			// [basic_istream&, LANC, '\n', TAK, (X)()]		pobiera co najwyzej n znakow
	cin.get(buff, n, delim);	// [basic_istream&, LANC, ?, TAK, (X)()]		pobiera co najwyzej n znakow
	//cin.get(str_buff);		// [basic_istream&, LANC, '\n', TAK, (X)()]		pobiera co najwyzej n znakow, zapisuje do bufora
	//cin.get(str_buff, delim);	// [basic_istream&, LANC, ?, TAK, (X)()]		pobiera co najwyzej n znakow, zapisuje do bufora

	// getline [basic_istream&, LANC, '\n', TAK, ()()] pobiera co najwyzej n znakow
	cin.getline(buff, n);		
	getline(cin, str);

	// getline [basic_istream&, LANC, ?, TAK, ()()] pobiera co najwyzej n znakow
	cin.getline(buff, n, delim);
	getline(cin, str, delim);

	cin.peek();					// [int_type, ZNAK, -, (X)(X)]				pobiera pojedynczy znak, odklada go do strumienia

	cin.unget();				// [basic_istream&, ZNAK, -, -]				odklada do strumienia ostatnio pobrany znak

	cin.putback(c);				// [basic_istream&, -, -, -]					odklada do strumienia podany znak

	cin.ignore();				// [basic_istream&, ZNAK, EOF, ()()]		pobiera i porzuca pojedynczy znak
	cin.ignore(n);				// [basic_istream&, LANC, EOF, ()()]		pobiera i porzuca co najwyzej n znakow
	cin.ignore(n, delim);		// [basic_istream&, LANC, ?, ()()]			pobiera i porzuca co najwyzej n znakow
	
	cin.read(buff, n);			// [basic_istream&, LANC, -, NIE, -]		odczyt binarny, pobiera dokladnie n znakow
	cin.readsome(buff, n);		// [streamsize, LANC, -, -]					pobiera co najwyzej n znakow dostepnych natychmiast
	cin.gcount();				// [streamsize, -, -, -]					zwraca liczbe odczytanych znakow przy ostatniej operacji nieformatowanego odczytu

	/*
	 * (A)    - automatycznie dopasowuje wielkosc obiektu
	 * (X)( ) - odklada delimiter do bufora, nie zapisuje go do obietku
	 * ( )( ) - pobiera delimiter z bufora, nie zapisuje go do obiektu
	 * ( )(X) - pobiera delimiter z bufora, zapisuje go do obiektu
	 */

	return 0;
}