#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	// data
	string str = "___";
	string test = "XYZ";
	const char* arr = "XYZ";
	string::size_type i = 1;
	string::size_type n = 1;
	char c = 'A';
	class T {} t;

	// basic_string& append() - dodaje na koniec string, lancucha, 
	// liste znakow, wielokrotna kopia znaku, zakres iteratorow,
	// kopiuje maksymalnie n znakow z lancucha wejsciowego, zaczynajac 
	// od i-tego indeksu
	//str.append(n, c);
	//str.append(test);
	//str.append(test, i);			// n = npos
	//str.append(test, i, n);
	//str.append(arr);
	//str.append(arr, n);
	//str.append(arr, arr + 2);		// iter1, iter2
	//str.append({ 'a', 'b', 'c' });	// initializer_list
	//str.assign(t);				// since c++17
	//str.assign(t, i);				// since c++17, n = npos
	//str.assign(t, i, n);			// since c++17

	cout << str << endl;

	return 0;
}