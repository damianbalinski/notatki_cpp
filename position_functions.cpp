#include <iostream>
#include <fstream>

/*
 * METODY POZYCJI
 */

using namespace std;

int main()
{
	// dane
	ios_base::seekdir mode = ios_base::beg;
	int offset = 2;
	int i = 10;

	// strumienie
	fstream file("file.txt", ios_base::in | ios_base::out);

	file.seekg(offset, mode);		// [basic_istream&] przesuwa znacznik wejsciowy
	file.seekg(i);					// [basic_istream&] ustawia znacznik wejsciowy
	file.tellg();					// [] zwraca pozycje znacznika wejsciowego

	file.seekp(offset, mode);		// [basic_ostream&] przesuwa znacznik wyjsciowy
	file.seekp(i);					// [basic_ostream&] ustawia znacznik  wyjsciowy
	file.tellp();					// [pos_type] zwraca pozycje znacznika wyjsciowego

	return 0;
}