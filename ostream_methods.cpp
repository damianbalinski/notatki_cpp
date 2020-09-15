#include <iostream>

using namespace std;

int main()
{
	// DANE
	char c1 = 'A';
	char c2 = 'B';
	const char* arr1 = "abc";
	const char* arr2 = "xyz";
	int val = 0x41414141;
	int n = 5;


	cout.put(c1);
	// basic_ostream&
	// drukuje znak, automatycznie konwertuje argument na wartosci znakowa

	cout.write(arr1, n);
	// basic_ostream&
	// drukuje dokladnie n znakow z podanego lancucha
	// NIE SPRAWDZA INDEKSOWANIA

	return 0;
}