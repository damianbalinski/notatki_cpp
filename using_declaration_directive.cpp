#include <iostream>

namespace test1
{
	int value1 = 10;
}

namespace test1_dup
{
	int value1 = -10;
}

namespace test2
{
	int value2 = 20;
}

int main()
{
	// DEKLARACJA USING
	using test1::value1;

	// ERROR - deklaracja using powoduje wielokrotna deklaracja
	// using test1_dup::value1;

	// ERROR - redeklaracja
	// int value1 = 100;

	using namespace std;

	// OK - zmienna lokalna przyslania nazwe z przestrzeni nazw
	int value2 = 200;

	return 0;
}