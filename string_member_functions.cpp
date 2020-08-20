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
	string str1 = "abcdefghij";
	string str2 = "xyz";
	char c;
	char tab[MAX];
	const char* arr;
	GLOBAL = str;

	/************************
	/* CONVERSION FUNCTIONS *
	/************************/

	/**************************
	 * OTHER MEMBER FUNCTIONS *
	 **************************/
	str.assign(str2);		// wypelnia string podanymi znakami, lancuchem znakow, innym stringiem
	str.get_allocator();	// kopia alokatora powiazany z stringiem, sluzy do alokowania pamieci
	str.swap(str1);			// zamienia miejscami lancuchy

	// DOSTEP DO ELEMENTOW
	c = str.at(NUM);			// dostep do podanego elementu ze sprawdzaniem poprawnosci zakresu
	c = str.front();			// referencja do pierwszego znaku
	c = str.back();				// referencja do ostatniego znaku
	arr = str.data();			// wskaznik do stalego lancucha, nie musi zawierac znaku pustego
	arr = str.c_str();			// wskaznik do stalego lancucha, zawiera na koncu znak pusty
	
	// KOPIOWANIE
	str.substr(0, 5);			// zwraca podciag
	//str.copy(tab, 0, 5);		// kopiuje podciag do lancucha znakowego, nie dodaje znaku pustego na koniec

	// ITERATORY
	// MOD. & NIEMOD.	// NIEMOD.
	str.begin();		str.cbegin();	// -> // iterator do pierwszego znaku lancucha
	str.end();			str.cend();		// <- // iterator do znaku nastepujacego po ostatnim znaku lancucha
	str.rbegin();		str.crbegin();	// -> // iterator do pierwszego znaku w odwroconym lancuchu
	str.rend();			str.crend();	// <- // iterator do znaku nastepujacego po ostatnim znaku w odwroconym lancuchy
	// MOD. - modyfikujacy, NIEMOD. - niemodyfikujacy
	// -> iterator postepujacy
	// -> iterator odwrotny

	// POJEMNOSC
	str.empty();			// zwraca true jesli napis jest pusty
	str.length();			// liczba elementow w lancuchu
	str.size();				// liczba elementow w lancuchu
	str.max_size();			// maksymalna liczba elementow w lancuchu
	str.reserve(10);			// informuje obiekt o planowanej zmianie dlugosci napisu, aby ten mogl z wyprzedzeniem zaalokowac pamiec
	str.capacity();			// liczba zaalokowanych elementow w lancuchu
	str.shrink_to_fit();		// zwalnia zaalokowana, ale niewykozystana pamiec
	
	// OPERACJE NA LANCUCHU
	str.clear();			// usuwa wszystkie znaki z napisu
	str.insert(0, 2, 'A');	// wstawia znak, wiele znakow, lancuch, innny string, iterator w podanym miejscu
	str.erase(0, 2);		// usuwa znaki z podanego zakresu
	str.push_back('A');		// dodaje znak na koniec lancucha
	str.pop_back();			// usuwa  znak z konca lancucha
	str.append("abc");		// dodaje znak, wiele znakow, lancuch, inny string, iterator na koniec lancucha
	str.replace(0, 2, "abcd");		// zamienia znaki z podanego zakresu
	str.resize(10, 'A');	// ziweksza/zmniejsza rozmiar lancucha, puste pola wypelnia podanym znakiem

	// POROWNYWANIE
	str.compare("abc");		// porownyje z lancuchem, znakami, stringiem
	str.starts_with("abc");	// sprawdza, czy zaczyna sie podanym znakiem, lancuchem, stringiem
	str.ends_with("c");		// sprawdza, czy konczy sie podanym znakiem, lancuchem, stringiem
	
	// WYSZUKIWANIE
	str.find("abc", 5);		// find(const string& str)	// wyszukuje pierwszego wystapienia podciagu str, zwraca indeks pierwszego wystapienia lub sting::npos


	// TEST
	string s1 = "abc";
	string s2 = "qwerty";
	cout << s1 << ", " << s2 << endl;
	s1.swap(s2);
	cout << s1 << ", " << s2 << endl;

	return 0;
}