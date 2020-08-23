#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	// data
	string str = "abcdef";
	string test = "XYZ";
	const char* arr = "XYZ";
	string::size_type i1 = 1, i2 = 1;
	string::size_type n1 = 2, n2 = 1;
	string::size_type n = 2;
	char c = 'A';
	class T {} t;


	// basic_string& insert() - zamienia fragment stringa,
	

	// zamienia w stringu maksymalnie n1 znakow, poczawszy od i1-tego indeksu
	// na maksymalnie n2 znakow z lancucha wejsciowego, poczawszy od i2-tego indeksu

	//str.replace(i1, n1, n, c);
	//str.replace(i1, n1, test);
	//str.replace(i1, n1, test, i2);				// n2 = npos
	//str.replace(i1, n1, test, i2, n2);
	//str.replace(i1, n1, arr);
	//str.replace(i1, n1, arr, n);					// (X)
	//str.replace(i1, n1, t);						// since c++17
	//str.replace(i1, n1, t, i2)					// since c++17, n2 = npos
	//str.replace(i1, n1, t, i2, n2);				// since c++17


	// zamienia obszar pomiedzy iter_i1 a iter_i2 na podany string, lancuch, liste znakow, wielokrotna 
	// kopie znakow, zakres iteratorow

	//str.replace(str.begin(), str.begin()+1, n, c);			// iter_i1, iter_i2, n, c
	//str.replace(str.begin(), str.begin() + 1, test);			// iter_i1, iter_i2, str
	//str.replace(str.begin(), str.begin() + 1, arr);			// iter_i1, iter_i2, arr
	//str.replace(str.begin(), str.begin() + 1, arr, n);		// iter_i1, iter_i2, arr, n
	//str.replace(str.begin(),str.begin()+1, arr, arr + 2);		// iter_i1, iter_i2, iter1, iter2
	//str.replace(str.begin(), str.begin()+1, { 'a', 'b', 'c' });	// iter_i1, iter_i2. initializer_list
	//str.replace(str.begin(), str.begin() + 1, t);				// iter_i1, iter_i2, t, since c++17
	

	cout << str << endl;

	return 0;
}