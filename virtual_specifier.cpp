#include <iostream>

/*
 * SPECYFIKATOR VIRTUAL
 *
 * FUNKCJA / METODA
 * kompilator wybiera wersje metody na podstawie typu obiektu, a nie na podstawie
 * typu referncji/wskaznika (zalecane dla metod przyslanianych przez klasy pochodne)
 *
 * ZMIENNNA POZA BLOKIEM
 * ---
 *
 * ZMIENNA WEWNATRZ BLOKU
 * ---
 */

using namespace std;

class A
{
public:
	void func1() { cout << "A\n"; }
	virtual void func2() { cout << "A\n"; }
};

class B : public A
{
public:
	void func1() { cout << "B\n"; }
	virtual void func2() override { cout << "B\n"; }
};

int main()
{
	A a;
	B b;
	A* ap = &a;
	A* bp = &b;
	A& ar = a;
	A& br = b;

	//a.func1();
	//a.func2();
	//b.func1();
	//b.func2();

	//ap->func1();
	//ap->func2();
	//bp->func1();
	//bp->func2();

	ar.func1();
	ar.func2();
	br.func1();
	br.func2();

	return 0;
}