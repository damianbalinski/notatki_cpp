#include <iostream>
#include <ios>

/*
 * STALE STANU
 * stala/wartosc domyslna
 */

using namespace std;

int main()
{
	ios_base::goodbit;		// [-] brak bledu
	ios_base::eofbit;		// [DEF=0] koniec pliku
	ios_base::failbit;		// [DEF=0] blad odczytu/zapisu
	ios_base::badbit;		// [DEF=0] nierozpoznany blad

	return  0;
}