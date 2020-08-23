#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	// data
	string str = "abcdefgh";
	string test = "def";
	class T {} t;
	string::size_type i = 0;
	string::size_type n = 1;


	// size_type find() - wyszukuje pierwszego wystapienia podciagu/znaku,
	// zaczyna od indeksu i,
	// rozpatruje maksymalnie n znakow lancucha wejsiowego,
	// zwraca indeks pierwszego wystapienia lub npos,
	str.find(test);				// i = 0
	str.find(test, i);
	str.find("test");			// i = 0
	str.find("test", i);
	str.find("test", i, n);
	str.find('A');				// i = 0
	str.find('A', i);
	//str.find(t);				// since c++20
	//str.find(t, i);			// since c++20


	// size_type rfind() - wyszukuje ostatniego wystapienia podciagu/znaku,
	// wynik nie moze zaczynac sie za indeksem i,
	// rozpatruje maksymalnie n znakow lancucha wejsciowego,
	// zwraca indeks ostatniego wystapienia lub npos,
	str.rfind(test);			// i = npos
	str.rfind(test, i);
	str.rfind("test");			// i = npos
	str.rfind("test", i);
	str.rfind("test", i, n);
	str.rfind('A');				// i = npos
	str.rfind('A', i);
	//str.rfind(t);				// since c++20
	//str.rfind(t, i);			// since c++20


	// size_type find_first_of() - wyszukuje pierwszego wystapienia 
	// dowolnego znaku z podanego podciagu/znaku,
	// zaczyna od indeksu i, rozpatruje maksymalnie n znakow lancucha wejsciowego,
	// zwraca indeks pierwszego wystapienia lub npos,
	str.find_first_of(test);			// i = 0
	str.find_first_of(test, i);
	str.find_first_of("test");			// i = 0
	str.find_first_of("test", i);
	str.find_first_of("test", i, n);
	str.find_first_of('A');				// i = 0
	str.find_first_of('A', i);
	//str.find_first_of(t);				// since c++20
	//str.find_first_of(t, i);			// since c++20


	// size_type find_last_of() - wyszukuje ostatniego wystapienia 
	// dowolnego znaku z podanego podciagu/znaku,
	// wynik nie moze zaczynac sie za indeksem i,
	// rozpatruje maksymalnie n znakow lancucha wejsciowego,
	// zwraca indeks ostatniego wystapienia lub npos,
	str.find_last_of(test);				// i = npos
	str.find_last_of(test, i);
	str.find_last_of("test");			// i = npos
	str.find_last_of("test", i);
	str.find_last_of("test", i, n);
	str.find_last_of('A');				// i = npos
	str.find_last_of('A', i);
	//str.find_last_of(t);				// since c++20
	//str.find_last_of(t, i);			// since c++20


	// size_type find_first_not_of() - wyszukuje pierwszego wystapienia 
	// znaku z poza podanego ciagu/znaku,
	// zaczyna od indeksu i, 
	// rozpatruje maksymalnie n znakow lancucha wejsciowego,
	// zwraca indeks pierwszego niewystapienia lub npos,
	str.find_first_not_of(test);			// i = 0
	str.find_first_not_of(test, i);
	str.find_first_not_of("test");			// i = 0
	str.find_first_not_of("test", i);
	str.find_first_not_of("test", i, n);
	str.find_first_not_of('A');				// i = 0
	str.find_first_not_of('A', i);
	//str.find_first_not_of(t);				// since c++20
	//str.find_first_not_of(t, i);			// since c++20


	// size_type find_last_not_of - wyszukuje ostatniego wystapienia 
	// znaku z poza podanego ciagu/znaku,
	// wynik nie moze zaczynac sie za indeksem i,
	// rozpatruje maksymalnie n znakow lancucha wejsciowego,
	// zwraca indeks ostatniego niewystapienia lub npos,
	str.find_last_not_of(test);				// i = npos
	str.find_last_not_of(test, i);
	str.find_last_not_of("test");			// i = npos
	str.find_last_not_of("test", i);
	str.find_last_not_of("test", i, n);
	str.find_last_not_of('A');				// i = npos
	str.find_last_not_of('A', i);
	//str.find_last_not_of(t);				// since c++20
	//str.find_last_not_of(t, i);			// since c++20

	return 0;
}