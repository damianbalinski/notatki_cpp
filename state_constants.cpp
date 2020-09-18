//#include <iostream>
#include <ios>

/*
 * STALE STANU
 * ios_base::iostate
 */

using namespace std;

int main()
{
	ios_base::goodbit;		// brak bledu
	ios_base::eofbit;		// koniec pliku
	ios_base::failbit;		// blad odczytu/zapisu, proba otwarcia nieistniejacego pliku, brak danych wejsciowych lub przekroczenie maksymalnej dlugosci danych wejsciowych
	ios_base::badbit;		// nierozpoznany blad

	return  0;
}