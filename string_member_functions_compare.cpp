#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	// compare - porownuje dwa ciagi, zwraca 0 jesli sa takie same,
	// liczbe ujemna jesli str1 < str2 oraz liczbe dodatnia jestli str1 > str2,
	// pod uwage brane jest n pierwszysch nnakow zaczynajac od i-tego indeksu

	// int compare(const basic_string& str);

	// int compare(size_type i1, size_type n1, const basic_string& str)
	
	// int compare(size_type i1, size_type n1, const basic_string& str,
	//		size_type i2, size_type n2 = npos)
	
	// int compare(const charT* arr)
	
	// int compare(size_type i1, size_type n1, const charT* arr)
	
	// int compare(size_type i1, size_type n1, const charT* arr,
	//		size_type n2)
	
	// template<class T>
	// int compare(const T& t)

	// template<class T>
	// int compare(size_type i1, size_type n1, const T& t)

	// template<class T>
	// int compare(size_type i1, size_type n1, const T& t,
	//		size_type i2, size_type n2)

	// TEST
	//string str1 = "abcx";
	//string str2 = "abcd";
	//cout << str1.compare(0, 4, "abcd", 0, 4) << endl;

}