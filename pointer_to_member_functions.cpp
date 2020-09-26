#include <iostream>

/*
 * DEREFERENCJA FUNKCJI SKLADOWEJ
 * POSREDNIA DEREFERENCJA FUNKCJI SKLADOWEJ
 *
 * E1->*E1  === (*E1).*E2
 */

using namespace std;

struct S
{
	void foo() { cout << "foo" << endl; }
	void goo() { cout << "goo" << endl; }
};
int main()
{
	S s{};				// object
	S* sp = new S{};	// ptr to object
	void (S::*ptr)();

	ptr = &S::foo;
	(s.*ptr)();

	ptr = &S::goo;
	(s.*ptr)();

	ptr = &S::foo;
	(sp->*ptr)();

	ptr = &S::goo;
	(sp->*ptr)();

	return 0;
}