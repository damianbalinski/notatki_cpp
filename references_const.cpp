#include <iostream>
#include <cstdio>

/*
 * Jesli referencji uzyto z modyfikatorem const, w niektorych
 * przypadkach kompilator tworzy zmienna tymczasowa (anonimowa).
 * Poniewaz tworzona zmienna jest stala, funkcja ma do niej
 * dostep ale nie moze jej modyfikowac, co zgadza sie z const.
 */
void foo(const int &val)
{
	printf("-> %p\n", &val);
}

int main()
{
	using namespace std;

	int i = 1;
	double d = 1.0;

	// INTEGER
	printf("   %p\n", &i);
	foo(i);
	foo(i + 1);		// temp value (not lvalue)
	foo(1);			// temp value (not lvalue)
	
	// DOUBLE
	putchar('\n');
	printf("   %p\n", &d);
	foo(d);			// temp value (bad type)
	foo(d + 1);		// temp value (bad type/not lvalue)
	foo(10.0);		// temp value (bad type/not lvalue)

	const int& r1 = i;
	const int& r2 = d;
	const int& r3 = i + 10;
	const int& r4 = d + 10.0;
	const int& r5 = 1;
	const int& r6 = 1.0;

	printf("  %p\n", &i);
	printf("__%p\n", &r1);
	printf("__%p\n", &r2);
	printf("__%p\n", &r3);
	printf("__%p\n", &r4);
	printf("__%p\n", &r5);
	printf("__%p\n", &r6);

	return 0;
}