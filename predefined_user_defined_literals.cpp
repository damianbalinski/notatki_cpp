#include <iostream>
#include <string>
#include <complex>
#include <chrono>

/*
 * PREDEFINE LITERALY UZYTKOWNIKA
 */

//using namespace std;
using namespace std::chrono_literals;
using namespace std::string_literals;
using namespace std::string_view_literals;
using namespace std::complex_literals;

int main()
{
	// LITERAL		// TYP						// PRZESTRZEÑ NAZW	// NAGLOWEK
	
	// STRING
	"abc"s;			// string					<string>
	"abc"sv;		// string_view

	// COMPLEX							
	10.0if;			// complex<float>			<complex>
	10.0i;			// complex<double>	
	10.0il;			// complex<long double>

	// TIME
	//10y;			// year						<chrono>
	//10d;			// day
	10h;			// hours
	10min;			// minutes
	10s;			// seconds
	10ms;			// miliseconds
	10us;			// microseconds
	10ns;			// nanoseconds

	return 0;
}