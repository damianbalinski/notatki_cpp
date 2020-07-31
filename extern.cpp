#include <iostream>

extern int VALUE;
// extern int VALUE = -100;		// ERROR - wielokrotna deklaracja statycznej zmiennej zewnetrznej
// int VALUE;					// ERROR - wielokrotna deklaracja statycznej zmiennej zewnetrznej

static int VALUE2 = -200;		// OK - przysloniecie zmiennej zewnetrznej zmienna wewnetrzna


int main()
{
	using namespace std;

	int VALUE = 99;

	cout << VALUE << endl;
	cout << ::VALUE << endl;

	cout << VALUE2 << endl;
	cout << ::VALUE2 << endl;

	return 0;
}