#include <iostream>
#include <fstream>

/*
 * is_open() - zwraca true jestli uda sie otworzyc plik, zwraca false w
 * przeciwnym wypadku
 */
int main()
{
	using namespace std;

	ifstream file1;
	ifstream file2;

	file1.open("test.txt");
	file2.open("test2.txt");

	cout << file1.is_open() << endl;
	cout << file2.is_open() << endl;

	return 0;
}