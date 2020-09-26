#include <iostream>

/*
 * ZMIENNA / WSKAZNIK / REFERENCJA DO SKLADOWEJ
 *
 * WSKAZNIK DO SKLADOWEJ - odnosi sie do polozenia skladowej wewnatrz obiektu,
 * nie wskazuje konkretnego miejsca w pamieci
 *
 * WSKAZNIK DO METODY
 */

using namespace std;

class C
{
public:
	int val = 10;
	C(int val) : val(val) {}
	void foo() { printf("foo %d\n", val); }
};

int main()
{
	// dane
	C c1(10);
	C c2(20);
	C* c3 = new C(30);
	C* c4 = new C(30);

	int C::* vptr;			// wskaznik do skladowej
	void (C:: * fptr)();	// wskaznik do metody

	vptr = &C::val;
	fptr = &C::foo;

	cout << c1.*vptr << endl;
	cout << c2.*vptr << endl;
	cout << c3->*vptr << endl;
	cout << c4->*vptr << endl;
	(c1.*fptr)();
	(c2.*fptr)();
	(c3->*fptr)();
	(c4->*fptr)();

	return 0;
}