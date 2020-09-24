#include <iostream>

/*
 * SPECYFIKATOR EXPLICIT
 *
 * FUNKCJA / METODA (TYLKO KONSTRUKTOR/FUNKCJA KONWERSJI)
 * uniemozliwia niejawne wykorzystanie konstruktora klasy, zapobiega
 * niejawnej konwersji oraz inicjalizacji kopiujacej
 *
 * ZMIENNNA POZA BLOKIEM
 * ---
 *
 * ZMIENNA WEWNATRZ BLOKU
 * ---
 */

using namespace std;

class C
{
public:
	explicit C(int) {};
};

class D
{
public:
	D(int) {};
};

int main()
{
	C c1(10);
	//C c2 = 10;	// ERROR
	D d(20);
	D d = 20;

	return 0;
}