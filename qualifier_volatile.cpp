#include <iostream>

/*
 * KWALIFIKATOR VOLATILE
 *
 * ZMIENNA W BLOKU / POZA BLOKIEM
 * informacja dla kompilatora, ze wartosc moze zostac zmodyfikowana przez
 * czynniki inne niz program, wymusza kazdorazowy odczyt wartosci z pamieci
 * zamiast np. buforowania w rejestrze
 *
 * FUNKCJA	
 * O<-() - zwraca wartosc ulotna
 * ()->O - obiekt wywolujacy jest wolatile
 */

using namespace std;

class C
{
public:
	void volatile func() { cout << "hi" << endl; }
};

volatile int v1 = 10;

volatile int func() { return 10; }

int main()
{
	volatile int v2 = 10;

	// TEST
	C c;
	c.func();
	cout << func() << endl;

	return 0;
}