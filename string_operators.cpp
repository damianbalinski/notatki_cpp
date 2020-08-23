#include <iostream>
#include <string>
#define MAX 100
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	return 0;
	string str = " abc";
	string str0 = "xyz";
	char arr[MAX] = "abc";

	/********************/
	/* MEMBER OPERATORS */
	/********************/

	// OK	operator= przypisanie wartosci
	str.operator=(str0);				str = str0;					// = str;
	str.operator=("abc");				str = "abc";				// = arr;
	str.operator=('A');					str = 'A';					// = c;
	str.operator=(string());										// operator=(str_ref);
	str.operator=({ 'a', 'b', 'c' });	str = { 'a', 'b', 'c' };	// operator=(list);
	//																// operator=(t);
	str = 'A';
	str = str0;
	str = { 'x', 'y', 'z' };

	// operator[] - pobiera/modyfikuje element o podanym indeksie, NIE sprawdza poprawnosc zakresu
	str[0];

	// operator+= - dolacza na koniec pojedynczy znak, wiele znakow, lancuch znakow, string
	str += "abc";
	str += str;
	str += 'A';
	str += {'x', 'y', 'z'};
	str += (string("asda") + string("asvsa"));



	/************************/
	/* NON-MEMBER OPERATORS */
	/************************/

	// operator+ - (NIE MODYFIKUJACY, NON-MEMBER)	konkatenacja lancuchow
	// dolaczanie string, lancucha znakowego, 

	// OPERATORY POROWNANIA
	// porownuja (str, str), (str, arr), (arr, str)
	str == str0;
	str != str0;
	str < str0;
	str <= str0;
	str > str0;
	str >= str0;

	operator<(string(), string("abc"));

	operator<(str, str);
	"abc" < str;
	operator<("abc", str);
	str < "abc";
	operator<(str, "abc");

	cin >> str;
	cout << str;
}