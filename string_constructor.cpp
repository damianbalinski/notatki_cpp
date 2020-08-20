#include <iostream>
#include <string>
#define ITER "abcdefgh"

int main()
{
	using std::string;
	using std::cout;
	using std::endl;
	string s0 = "abcdefgh";
	string ref = s0;

	string s1;				// string()											
							// konstruktor domyslny

	string s2("abc");		// string(const char*)								
							// lancuch znakowy z C

	string s7("abc", 10);	// string(const char*, size_type)					
							// przy uzyciu lancucha znakowego, kopiuje dokladnie 10 znakow

	string s12("abc", 1, 2);// string(const char*, size_type, size_type)		
							// przy uzyciu lancucha znakowego, zaczyna od indeksu 1, kopiuje co najwyzej 2 znaki

	string s3(10, 'A');		// string(size_type n, char c)						
							// 10 kopii znaku 'A'

	string s4(s0);			// string(const string&)		
							// konstruktor kopiujacy

	string s5(s0, 10);		// string(const string&, size_type, size_type)		
							// przy uzyciu innego stringa, kopiuje dokladnie 10 znakow,
							// nawet jezeli wyjdzie poza zakres

	string s6(s0, 1, 2);	// string(const string&, size_type, size_type)		
							// przy uzyciu innego stringa, zaczynajac od indeksu 1, kopiuje co najwyzej 2 znaki
	
	string s8(ITER, ITER + 6); // template<class T> string(T begin, T end)		
							   // inicjalizuje obiekt wartosciami iteratora w zbiorze [begin, end)

	string s10 = { 'A', 'B', 'C' };	//string(initializer_list<char>)			
									// lista inicjalizacyjna

	// template<class T> string(const T&)
	// template<class T> string<const T&, size_type, size_type)
	//string(string && ref);		// konstruktor przenoszacy, obiekt zrodlowy moze byc zmodyfikowany

	string::allocator_type;

	cout << str << endl;
}