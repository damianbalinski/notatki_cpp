#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	// data
	string str = "abcdefghijk";
	string test = "xyz";
	const char* arr = "test";
	string::size_type i = 1;
	string::size_type n = 1;
	char c = 'A';
	class T {} t;

	// basic_string& assign() - wypelnia podanym stringiem, lancuchem, 
	// lista znakow, wielokrotna kopia znaku, zakresem iteratorow,
	// przypisuje maksymalnie n znakow z lancucha wejsciowego, zaczynajac 
	// od i-tego indeksu
	str.assign(n, c);
	str.assign(test);
	str.assign(test, i);			// n = npos
	str.assign(test, i, n);
	str.assign(string("abc"));
	str.assign(arr);
	str.assign(arr, n);
	cout << str << endl;
	str.assign(arr, arr + 2);		// iter1, iter2
	cout << str << endl;
	str.assign({ 'a', 'b', 'c' });	// initializer_list
	cout << str << endl;
	//str.assign(t);				// since c++17
	//str.assign(t, i);				// since c++17, n = npos
	//str.assign(t, i, n);			// since c++17

	return 0;
}