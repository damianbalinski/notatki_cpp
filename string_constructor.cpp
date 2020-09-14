#include <iostream>
#include <string>
#include <memory>

using namespace std;
int main()
{
	// dane
	int n = 2;
	int i = 0;
	char c = 'A';
	const char* arr = "abc";
	auto first = arr;
	auto last = arr + 3;
	auto list = { 'a', 'b', 'c' };
	string t;
	string str = "abc";
	string rstr = "abc";
	allocator<char> alloc;

	string;						// domyslny, nieokreslony rozmiar alokowanego obszaru
	string(alloc);

	string(n, c);				// n kopii znaku c
	string(n, c, alloc);

	string(str);				// kopiujacy/przenoszacy
	string(rstr);
	string(str, alloc);
	string(rstr, alloc);

	string(str, i);				// OK kopiujacy, zaczyna od i-tego indeksu, kopiuje co najwyzej n znakow
	string(str, i, n);
	string(str, i, alloc);
	string(str, i, n, alloc);

	string(arr);				// NOT-OK konwertujacy z lancucha, kopiuje dokladnie n znakow
	string(arr, n);
	string(arr, alloc);
	string(arr, n, alloc);

	string(first, last);		// z zakresu [first, last)
	string(first, last, alloc);

	string(list);				// z listy inicjalizacyjnej
	string(list, alloc);

	string(t);					// dedukcja typu szablonowego
	string(t, i, n);
	string(t, alloc);
	string(t, i, n, alloc);						

	
	// PARAMETRY
	// arr === const charT* arr					- lancuch znakowy
	// str === const string& str				- referencja do string
	// str_ref === string&& str_ref				- referencja r-wartosciowa do string
	// alloc === const Allocator& alloc			- alokator
	// list === initializer_list<charT> list	- lista inicjalizacyjna
	// iter1, iter2 === T iter1, T iter2		- iteratory
	// n === size_type n						- dlugosc/rozmiar
	// i === size_type i						- indeks poczatkowy
	// c === charT c							- znak
	// t === const T& t							- parametr szablonowy

	return 0;
}