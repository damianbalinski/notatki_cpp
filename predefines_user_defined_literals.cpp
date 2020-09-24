#include <iostream>
#include <string>
#include <complex>
#include <chrono>

/*
 * PREDEFINE LITERALY UZYTKOWNIKA
 */

using namespace std;

int main()
{
	"abc"s;		// basic_string
	10.0i;		// complex

	10h;		// duration
	10min;
	10s;
	10ms;
	10us;
	10ns;

	"abc"s + "abc"s;
	(1.0 + 1.0i)* (2.0 + 2.0i);

	return 0;
}