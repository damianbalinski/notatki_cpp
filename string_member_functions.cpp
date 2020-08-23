#include <iostream>
#include <string>
#define NUM 0
#define MAX 10
#define CHAR 'A'

using std::string;
using std::cout;
using std::endl;

string GLOBAL;

void print() { cout << GLOBAL << endl; }
void printn() { cout << endl; }

int main()
{
	string str = "abcdefghij";
	string test = "abcdefghij";
	string::size_type i = 0;
	string::size_type n = 0;
	char c = 'A';
	char arr[MAX];
	GLOBAL = str;


	// ROZNE DONE
	str.get_allocator();	// zwraca kopie alokatora powiazanego ze stringiem, sluzy do alokowania pamieci


	// DOSTEP DO ELEMENTOW
	str.at(0);				// DONE zwraca referencje do elementu o podanym indeksie, sprawdza poprawnosc zakresu
	str.front();			// DONE zwraca referencje do pierwszego elementu
	str.back();				// DONE zwraca referencja do ostatniego elementu
	str.data();				// DONE zwraca wskaznik do niemodyfikowalnego lancucha, nie musi zawierac na koncu znaku pustego
	str.c_str();			// DONE zwraca wskaznik do niemodyfikowalnego lancucha, musi zawierac na koncu znak pusty
	

	// KOPIOWANIE DONE
	// substr() - zwraca podciag o podanym zakresie lub mniejszym, jesli wychodzi poza zakres,
	str.substr();			// i = 0, n = npos
	str.substr(i);			// n = npos
	str.substr(i, n);

	// copy() - kopiuje podciag do podanego lancucha, nie dodaje znaku pustego na koniec
	str.copy(arr, 0);		// i = 0
	str.copy(arr, 0, 5);

	// swap() - zamienia miejscami stringi
	str.swap(test);


	// ITERATORY DONE
	// MODYFIKOWALNY	// NIEMODYFIKOWALNY
	str.begin();		str.cbegin();	// -> // iterator do pierwszego znaku lancucha
	str.end();			str.cend();		// <- // iterator do znaku nastepujacego po ostatnim znaku lancucha
	str.rbegin();		str.crbegin();	// -> // iterator do pierwszego znaku w odwroconym lancuchu
	str.rend();			str.crend();	// <- // iterator do znaku nastepujacego po ostatnim znaku w odwroconym lancuchy
	// -> iterator postepujacy
	// -> iterator odwrotny


	// POJEMNOSC DONE
	str.empty();			// zwraca true jesli string jest pusty
	str.length();			// liczba elementow w stringu
	str.size();				// liczba elementow w stringu
	str.max_size();			// maksymalna liczba elementow w lancuchu
	str.capacity();			// liczba zaalokowanych elementow w lancuchu
	str.shrink_to_fit();	// polecenie zwolniania zaalokowanej, ale nie wykozystanej pamieci,
	str.reserve(n);			// polecenie zaalokowania/zwolnienia pamieci
	str.resize(n);			// zwieksza/zmniejsza rozmiar stringa, nowe pola wypelnia znakiem pustym
	str.resize(10, c);		// zwieksza/zmniejsza rozmiar stringa, nowe pola wypelnia podanym znakiem


	// OPERACJE NA LANCUCHU DONE
	str.clear();			// DONE usuwa wszystkie znaki
	str.push_back('A');		// DONE dolacza znak na koniec
	str.pop_back();			// DONE usuwa znak z konca

	return 0;
}