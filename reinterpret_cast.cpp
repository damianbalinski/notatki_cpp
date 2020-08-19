#include <iostream>

using std::cout;
using std::endl;

/*
 * REINTERPRET_CAST - COMPILE-TIME
 * reinterpret_cast<nazwa_typu>(wyrazenie)
 * rzutowanie ryzykowne, np. na calkem inny typ
 *
 * rzutujac wskaznik na typ liczbowy, typ calkowity musi byc dostatecznie pojemny, aby
 * pomiescic reprezentacje wskaznika
 * wartosc oraz wyrazenie calkowitoliczbowe moze byc rzutowane tylko do tego samego typu,
 * brak mozliwosci zmiany wskaznika na funkcje na wksaznik na dane
 * mozliwe rzutowanie do typu tak samo/bardziej wykwalifikowanego (const/volatile)
 * bezpieczny dla wskaznikow zerowych,
 */
int main()
{
	struct dat { short a; short b; };
	long val = 0xAAAABBBB;

	dat* ptr = reinterpret_cast<dat*>(&val);

	printf("%X\n", ptr->a);
	printf("%X\n", ptr->b);

	// EXPRESSION
	val = reinterpret_cast<int>(10);
	val = reinterpret_cast<int>(10 + 10);
	//val = reinterpret_cast<int>(1.0);				// ERROR
	//val = reinterpret_cast<double)(1.0 + 1.0);	// ERROR

	// RESTRICTIONS
	int a1 = 10;
	const int a2 = 20;

	reinterpret_cast<int>(a1);
	reinterpret_cast<int>(a2);
	reinterpret_cast<const int>(a1);
	reinterpret_cast<const int>(a2);

	// CHANGE CV QUALIFIERS IN POINTERS
	int* p1 = new int(10);
	const int* p2 = new int(10);

	//p1 = reinterpret_cast<int*>(p2);
	//p1 = reinterpret_cast<const int*>(p2);
	p2 = reinterpret_cast<int*>(p1);
	p2 = reinterpret_cast<const int*>(p1);

	// CHANGE CV QUALIFIERS IN REFERENCES
	int& r1 = *new int(10);
	const int& r2 = *new int(10);
	//int& r11 = reinterpret_cast<int&>(r2);
	//int& r12 = reinterpret_cast<const int&>(r2);
	const int& r21 = reinterpret_cast<int&>(r1);
	const int& r22 = reinterpret_cast<const int&>(r1);

	// VALUE
	int val;
	int res;
	res = reinterpret_cast<int>(val);

	return 0;
}