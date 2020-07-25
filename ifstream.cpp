#include <fstream>
#include <iostream>

#define MAX 100

// TODO good()

int main()
{
	using namespace std;

	ifstream file_in;
	char buff[MAX];

	// otwarcie pliku
	file_in.open("test.txt");

	// odczyt z pliku
	file_in >> buff;
	cout << buff << endl;
	file_in >> buff;
	cout << buff << endl;
	file_in >> buff;
	cout << buff << endl;

	// zamkniecie pliku
	file_in.close();

	return 0;
}