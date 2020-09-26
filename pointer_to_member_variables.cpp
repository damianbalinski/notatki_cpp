#include <iostream>

/*
 * DEREFERENCJA ZMIENNEJ SKLADOWEJ
 * POSREDNIA DEREFERENCJA ZMIENNEJ SKLADOWEJ
 *
 * E1->*E1  === (*E1).*E2
 */

using namespace std;

struct S
{
	int a;
	int b;
};

void PRINT(S s)
{
	printf("(%d,%d)\n", s.a, s.b);
}

int main()
{
	// OBJECT
	S s{};				// object
	S* sp = new S{};	// ptr to object
	int S::* ptr;

	PRINT(s);
	ptr = &S::a;
	s.*ptr = 100;

	ptr = &S::b;
	s.*ptr = 200;
	PRINT(s);

	PRINT(*sp);
	ptr = &S::a;
	sp->*ptr = 300;

	ptr = &S::b;
	sp->*ptr = 400;
	PRINT(*sp);

	return 0;
}