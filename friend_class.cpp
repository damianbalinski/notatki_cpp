#include <iostream>

class B;

/*
 * Klasa B kozysta z klasy A, dlatego klasa
 * A musi byc zadeklarowana przed klasa B.
 */
class A
{
public:
	void print(B b);
};

/*
 * Nie wymaga deklaracji wyprzedzajacej, poniewaz
 * wyrazenie friend class B okresla B jako klase.
 */
class B
{
private:
	int x;
public:
	B(int x) : x(x) {};
	friend class A;
};

void A::print(B b) { printf("%d\n", b.x); }

int main()
{
	B a(10);
	A b;
	b.print(a);

	return 0;
}