#include <iostream>

/*
 * ZAPIS NIEFORMATOWANY
 */

using namespace std;

int main()
{
	// dane
	int n = 10;
	char c = 'A';
	const char* buff = "abc";

	cout.put(c);			// [basic_ostream&, ZNAK] drukuje pojedynczy znak
	cout.write(buff, n);	// [basic_ostream&, LANCUCH] drukuje dokladnie n znakow
	
	return 0;
}