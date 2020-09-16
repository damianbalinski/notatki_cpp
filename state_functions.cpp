#include <iostream>
#include <cstdio>

/*
 * METODY STANU STRUMIENIA
 * po ustawieniu ktoregolokwiek z bitow stanu, strumien pozostaje zamkniety
 * na operacje wejsica/wyjscia az do wyzerowania jego stanu
 */

using namespace std;

void print_mask(ios_base::iostate mask)
{
	cout << "("
		<< (mask & ios_base::eofbit) << ","
		<< (mask & ios_base::failbit) << ","
		<< (mask & ios_base::badbit) << ")"
		<< endl;
}

void print_state()
{
	printf("(%d,%d,%d,%d)\n", cout.good(), cout.eof(), cout.fail(), cout.bad());
}

int main()
{
	// DANE
	ios_base::iostate state = ios_base::goodbit;
	ios_base::iostate mask = ios_base::goodbit;

	cout.good();			// bool, sprawdza, czy wszystkie bity stanu sa wyzerowane
	cout.eof();				// bool, sprawdza, czy ustawiono eofbit
	cout.fail();			// bool, sprawdza, czy ustawiono badbit lub failbit
	cout.bad();				// bool, sprawdza, czy ustawiono badbit
	
	cout.clear();			// void zmienia stan strumienia na goodbit lub na podana maske, wplywa na wszystkie bity
	cout.clear(state);
	
	cout.setstate(state);	// void zmienia stan strumienia tylko dla bitow zawartych w masce, nie wplywa na pozostale bity
	
	cout.rdstate();			// iostate zwraca stan strumienia

	cout.exceptions();		// iostate zwraca maske bitowa, okreskajaca ktore znaczniki bledow powoduja zgloszenie wyjatku

	cout.exceptions(mask);	// void okresla, ktore znaczniki bledow powoduja zgloszenie wyjatku

	return 0;
}