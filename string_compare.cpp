#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	// data
	string str = "abc";
	string test = "xyz";
	char t = 'A';
	string::size_type i1 = 0, i2 = 0;
	string::size_type n1 = 1, n2 = 0;


	// bool starts_with() - sprawdza, czy zaczyna sie podanym znakiem, lancuchem, stringiem
	str.starts_with(test);
	str.starts_with("abc");
	str.starts_with('a');		


	//bool ends_with() - sprawdza, czy konczy sie podanym znakiem, lancuchem, stringiem
	str.ends_with(test);
	str.ends_with("abc");
	str.ends_with('a');


	// int compare() - porownuje dwa ciagi, zwraca 0 jesli sa takie same,
	// liczbe ujemna jesli str1 < str2 oraz liczbe dodatnia jestli str1 > str2,
	// pod uwage brane jest n pierwszych znakow zaczynajac od i-tego indeksu

	str.compare(test);
	str.compare(i1, n1, test);
	str.compare(i1, n1, test, i2);
	str.compare(i1, n1, test, i2, n2);

	str.compare("test");
	str.compare(i1, n1, "test");
	str.compare(i1, n1, "test", n2);

	//str.compare(t);					// since c++17
	//str.compare(i1, n1, t);			// since c++17
	//str.compare(i1, n1, t, i2);		// since c++17
	//str.compare(i1, n1, t, i2, n2);	// since c++17
}