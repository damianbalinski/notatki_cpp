#include <iostream>
#include <cstdio>

/*
 * ZAPRZYJAZNIENIE WZAJEMNE
 */

class B;	// MUSI
class A;	// NIE MUSI

/*
 * Deklaracja metody musi byc poprzedzona deklaracja obiektu,
 * definicja metody musi byc poprzedzona definicja obiektu.
 */
class A
{
private:
	int a;
public:
	A(int a = -1) : a(a) {}
	friend class B;
	void getB(B b);
};

class B
{
private:
	int b;
public:
	B(int b = -1) : b(b) {}
	friend class A;
	void getA(A a);
};

void A::getB(B b) { printf("getsB %d\n", b.b); }
void B::getA(A a) { printf("getsA %d\n", a.a); }


int main()
{
	A a = A();
	B b = B();
	
	a.getB(b);
	b.getA(a);

	return 0;
}