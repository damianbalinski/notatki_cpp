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

	// MEMBER OPERATORS

	//operator= wypelnia string podanymi znakami, lancuchem znakow, innym stringiem
	str = 'A';
	str = str0;
	str = { 'x', 'y', 'z' };

	// operator[] - dostep do podanego elementu BEZ sprawdzania poprawnosci zakresu
	str[0];

	// operator+= - dodaje znak, wiele znakow, lancuch znakow, inny string na koniec lancucha
	str += "abc";
	str += str;
	str += 'A';
	str += {'x', 'y', 'z'};

	str == str0;
	str != str0;
	str < str0;
	str <= str0;
	str > str0;
	str >= str0;

	cin >> str;
	cout << str;
}