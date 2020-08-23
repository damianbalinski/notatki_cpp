#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	// data
	string str = "ABCD";
	string test = "XYZ";
	string::size_type i = 0;
	string::size_type n = 2;
	// erase()

	// basic_string&
	str.erase(i, n);	//  usuwa maksymalnie n znakow zaczynajac od i-tego indeksu
	
	// iterator
	//str.erase(str.begin());					// usuwa znak pod podanym iteratorem
	//str.erase(str.begin(), str.begin() + 2);	//usuwa znaki z zakresu [iter1, iter2), zwraca iterator do elementu
												// po ostatnim usunietym znaku
	cout << str << endl;

	return 0;
}