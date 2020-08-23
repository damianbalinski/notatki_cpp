#include <iostream>
#include <string>
#define MAX 100

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str;
	char arr[MAX];
	std::streamsize n = MAX;
	char c = ':';

	// CHAR* (1) - pobiera napis zakonczony znakiem bialym
	//cin.operator>>(arr);
	cin >> arr;

	// CHAR* (2) - pobiera zdania zakonczonego na \n, pomina \n
	cin.getline(arr, n);

	// CHAR* (3) - pobiera maksymalnie n znakow ze zdania zakonczonego na c, pomija c
	cin.getline(arr, n, c);

	// CHAR* (4) - pobiera maksymalnie n znakow ze zdania zakonczonego na \n, odklada \n do kolejki
	cin.get(arr, n);

	
	// STRING (1) - pobiera napis zakonczony znakiem bialym, odklada znak bialy do kolejki
	//operator>>(cin, str);
	cin >> str;

	// STRING (2) - pobiera zdanie zakonczone na \n, pomina \n
	getline(cin, str);

	// STRING(3) - pobiera zdanie zakonczona na c, pomija c
	getline(cin, str, c);

	return 0;
}