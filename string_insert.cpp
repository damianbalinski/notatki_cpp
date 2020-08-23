#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	// data
	string str = "++++";
	string test = "XYZ";
	const char* arr = "XYZ";
	string::size_type i1 = 2, i2 = 1;
	string::size_type n = 5, n2 = 1;
	char c = 'A';
	class T {} t;

	// basic_string& insert() - wstawia w okreslonym miejscu string,
	// lancuch, liste znakow, wielokrotna kopia znaku, zakres iteratorow,
	// pozostala czesc za podanym indeksem przesuwa na koniec, kopiuje maksy-
	// malnie n2 znakow z lancucha wejsciowego, zaczynajac od i2-tego
	// indeksu

	// basic_string&
	// str.insert(i1, n, c);
	// str.insert(i1, test);
	// str.insert(i1, test, i2);				// n2 = npos
	// str.insert(i1, test, i2, n2);
	// str.insert(i1, arr);
	// str.insert(i1, arr, n2);				(X)
	// str.insert(i1, t);						// since c++17
	// str.insert(i1, t, i2);					// since c++17, n = npos
	// str.insert(i1, t, i2, n2);				// since c++17


	// iterator
	// str.insert(str.begin(), c);				// iter_i1, c
	// str.insert(str.begin(), n, c);			// iter_i1, n, c
	// str.insert(str.begin(), arr, arr + 2);	// iter_i1, iter1, iter2
	// str.insert(str.begin(), { 'a', 'b', 'c' });	// iter_i1. initializer_list

	cout << str << endl;

	return 0;
}