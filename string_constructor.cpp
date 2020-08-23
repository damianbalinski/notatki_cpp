#include <iostream>
#include <string>
#include <memory>
#define ITER "abcdefgh"

int main()
{
	using std::string;
	using std::cout;
	using std::endl;
	string s0 = "abcdefgh";
	string ref = s0;

	// OK DOC
	// string((alloc)) - domyslny, rozmiar alokowanego obszaru jest nieokreslony
	//string s1(std::allocator<char>());
	
	// OK DOC
	// string(n, c, (alloc)) - n kopii znaku c
	string s4(10, 'A');

	// OK DOC
	// string(arr, (alloc)) - konwertujacy lancuch znakowy
	string s2("abc");									

	// OK DOC
	// string(arr, n, (alloc)) - konwertujacy, kopiuje dokladnie n znakow (nawet jesli n wychodzi poza zakres)
	string s3("abc", 10);


	// OK DOC
	// string(str) - kopiujacy bez alokatora
	string s5(s0);

	// OK DOC
	// string(str, alloc) - kopiujacy z alokatorem
	string s6(s0, std::allocator<char>());

	// OK DOC
	// string(str_ref) - przenoszacy bez alokatora

	// OK DOC
	// string(str_ref, alloc) - przenoszacy z alokatorem

	// OK DOC
	// string(str, i, (alloc)) - kopiujacy, kopiuje zaczynajac od i-tego indeksu, nie wychodzi poza zakres
	string s9(s0, 0);

	// OK DOC
	// string(str, i, n, (alloc)) - kopiujacy, kopiuje co najwyzej n znakow zaczynajac od i-tego indeksu, nie wychodzi poza zakres
	string s10(s0, 10, 2);
	
	// OK DOC
	// template<class T> 
	// string(T iter1, T iter2, (alloc)) - pobiera zakres okreslony iteratorami w zbiorze [iter1, iter2)
	string s11(ITER, ITER + 6);

	// string(list, (alloc)) - lista inicjalizacyjna
	string s12 = { 'A', 'B', 'C' };

	// OK DOC
	// template<class T>
	// string(t, (alloc)) - - dedukcja typu szablonowego klasy

	// OK DOC
	// template<class T>
	// string(t, i, n, (alloc)) - dedukcja typu szablonowego klasy z podanym zakresem
	

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


	// PARAMETRY DOMYSLNE
	// (alloc) == = const Allocator & alloc = Allocator()	- alokator domyslny
	// (n) === size_type n = string::npos


	return 0;
}