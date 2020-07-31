// KWALIFIKATOR TYPU - MUTABLE
#include <iostream>
#include <cstdio>

/*
 * Moze wystapic tylko w strukturze/klasie.
 * Pozwala omdyfikowac odpowiednie pola struktury, ktora zostala zadeklarowana jako stala.
 */
const struct S
{
	int a;
	int b;
	mutable int c;
};

int main()
{
	using namespace std;

	const S s1 = { 1, 2, 3 };

	printf("(%d,%d,%d)\n", s1.a, s1.b, s1.c);

	// s1.a = 10;	// ERROR
	// s1.b = 20;	// ERROR
	s1.c = 30;

	printf("(%d,%d,%d)\n", s1.a, s1.b, s1.c);

	return 0;
}