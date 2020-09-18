#include <iostream>

/*
 * NIEFORMATOWANE WYJSCIE
 */

using namespace std;

int main()
{
	// dane
	int n = 10;
	char c = 'A';
	const char* buff = "abc";

	cout.put(c);			// [basic_ostream&, ZNAK] drukuje pojedynczy znak
	cout.write(buff, n);	// [basic_ostream&, LANCUCH] zapis binarny, drukuje dokladnie n znakow, przydane do zapisu binarnego obiektow nie zawierajacych funkcji wirtualnych
	
	return 0;
}