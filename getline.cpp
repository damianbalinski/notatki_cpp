#include <iostream>
#include <string>

using std::cout, std::cin;
using std::endl;
using std::string;

int main()
{
	//(A) - automatycznie dopasowuje wielkosc obiektu
	//(X)( ) - odklada delimiter do bufora, nie zapisuje go do obietku
	//( )( ) - pobiera delimiter z bufora, nie zapisuje go do obiektu
	//( )(X) - pobiera delimiter z bufora, zapisuje go do obiektu

	char buff[100];
	string str;

	// CHAR* WORD \n
	//cin >> buff;
	//cout << buff << endl;

	// CHAR* LINE \n, nie dopasowuje bufora
	//cin.getline(buff, 100);
	//cout << buff << endl;

	// CHAR* LINE $ - nie dopasowuje bufora
	//cin.getline(buff, 100, '$');
	//cout << buff << endl;

	// STRING WORD \n (X)( ) (A)
	//cin >> str;
	//cout << str << endl;

	// STRING LINE \n ( )( ) (A)
	//getline(cin, str);
	//cout << str << endl;

	// STRING LINE $ - ( )( ) (A)
	//getline(cin, str, '$');
	//cout << str << endl;
}