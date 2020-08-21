#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string str = "abcdefgh";
	string test = "def";
	

	// find - wyszukuje pierwszego wystapienia podciagu/znaku, zaczyna od indeksu i,
	// rozpatruje maksymalnie n znakow lancucha wejsiowego,
	// zwraca indeks pierwszego wystapienia lub sting::npos,
	str.find(test, 5);		// size_type find(const basic_string& str, size_type i = 0)
	str.find("de", 5);		// size_type find(const char* arr, size_type i = 0)
	str.find("de", 5, 2);	// size_type find(const char* arr, size_type i, size_type n)
	str.find('A', 5);		// size_type find(charT c, size_type i = 0)
							// template<class T>
							// size_type find(const T& t, size_type i = 0)
	

	// rfind - wyszukuje ostatniego wystapienia podciagu/znaku,
	// znaleziony podciag nie moze zaczynac sie w pozycji nastepujacej za indeksem i,
	// rozpatruje maksymalnie n znakow lancucha wejsciowego,
	// zwraca indeks ostatniego wystapienia lub string::npos,
	str.rfind(test, 5);		// size_type rfind(const basic_string& str, size_type i = npos)
	str.rfind("de", 5);		// size_type rfind(const char* arr, size_type i = npos)
	str.rfind("de", 5, 2);	// size_type rfind(const char* arr, size_type i, size_type n)
	str.rfind('A', 5);		// size_type rfind(charT c, size_type i = npos)
							// template<class T>
							// size_type rfind(const T& t, size_type i = npos)


	// find_first_of - wyszukuje pierwszego wystapienia dowolnego znaku z podanego podciagu/znaku,
	// zaczyna od indeksu i, rozpatruje maksymalnie n znakow lancucha wejsciowego,
	// zwraca indeks pierwszego wystapienia lub string::npos,
	str.find_first_of(test, 5);		// size_type find_first_of(const basic_string& str, size_type i = 0)
	str.find_first_of("de", 5);		// size_type find_first_of(const charT* arr, size_type i = 0)
	str.find_first_of("de", 5, 2);	// size_type find_first_of(const charT* arr, size_type i, size_type n)
	str.find_first_of('A', 5);		// size_type find_first_of(charT c, size_type i = 0)
									// template<class T>
									// size_type find_first_of(const T& t, size_type pos = 0);


	// find_last_of - wyszukuje ostatniego wystapienia dowolnego znaku z podanego podciagu/znaku,
	// znaleziony podciag nie moze zaczynac sie w pozycji nastepujacej za indeksem i,
	// rozpatruje maksymalnie n znakow lancucha wejsciowego,
	// zwraca indeks ostatniego wystapienia lub string::npos,
	str.find_last_of(test, 5);		// size_type find_last_of(const basic_string& str, size_type i = npos)
	str.find_last_of("de", 5);		// size_type find_last_of(const charT* arr, size_type i = npos)
	str.find_last_of("de", 5, 2);	// size_type find_last_of(const charT* arr, size_type i, size_type n)
	str.find_last_of('A', 5);		// size_type find_last_of(charT c, size_type i = npos)
									// template<class T>
									// size_type find_last_of(const T& t, size_type pos = npos);


	// find_first_not_of - wyszukuje pierwsze wystapienie znaku z poza podanego lancucha/znaku,
	// zaczyna od indeksu i, rozpatruje maksymalnie n znakow lancucha wejsciowego,
	// zwraca indeks pierwszego niewystapienia lub string::npos,
	str.find_first_not_of(test, 5);		// size_type find_first_not_of(const basic_string& str, size_type i = 0)
	str.find_first_not_of("de", 5);		// size_type find_first_not_of(const charT* arr, size_type i = 0)
	str.find_first_not_of("de", 5, 2);	// size_type find_first_not_of(const charT* arr, size_type i, size_type n)
	str.find_first_not_of('A', 5);		// size_type find_first_not_of(charT c, size_type i = 0)
										// template<class T>
										// size_type find_first_not_of(const T& t, size_type pos = 0);


	// find_last_not_of - wyszukuje ostatnie wystapienie znaku z poza podanego lancucha/znaku,
	// znaleziony podciag nie moze zaczynac sie w pozycji nastepujacej za indeksem i,
	// rozpatruje maksymalnie n znakow lancucha wejsciowego,
	// zwraca indeks ostatniego niewystapienia lub string::npos,
	str.find_last_not_of(test, 5);		// size_type find_last_not_of(const basic_string& str, size_type i = npos)
	str.find_last_not_of("de", 5);		// size_type find_last_not_of(const charT* arr, size_type i = npos)
	str.find_last_not_of("de", 5, 2);	// size_type find_last_not_of(const charT* arr, size_type i, size_type n)
	str.find_last_not_of('A', 5);		// size_type find_last_not_of(charT c, size_type i = npos)
										// template<class T>
										// size_type find_last_not_of(const T& t, size_type pos = npos);


	// TEST
	//str = "ababab";
	//test = "ab";
	//cout << str.find_last_not_of("abxy", 4, 1) << endl;
}