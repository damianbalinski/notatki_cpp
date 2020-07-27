#include <iostream>

struct test
{
	int a;
	int b;
	int c;
};

void test_set(test& t)
{
	t.a = 10;
	t.b = 20;
	t.c = 30;
}

void test_print(const test& t)
{
	printf("(%d,%d,%d)\n", t.a, t.b, t.c);
}

/*
 * Funkcja typu test zwraca kopie obiektu t1.
 * Funkcja typu test& zwraca orginalny obiekt bedacy parametrem funkcji.
 * Poniewaz zwracana zmienna referencyjna moze wystepowac po lewej stronie
 * operatora porownania, slowo kluczowe const uniemozliwia jej modyfikacje
 * w taki wlasnie sposob.
 */
const test& test_add_const(test& t1, const test& t2)
{
	t1.a += t2.a;
	t1.b += t2.b;
	t1.c += t2.c;
	return t1;
}

test& test_add(test& t1, const test& t2)
{
	t1.a += t2.a;
	t1.b += t2.b;
	t1.c += t2.c;
	return t1;
}

int main()
{
	test t1, t2;
	test_set(t1);
	test_set(t2);
	test_print(t1);
	test_print(t2);
	test_add_const(t1, t2);
	test_print(t1);
	test_print(t2);

	test_add(t1, t2) = t2;			// niepozadany efekt
	//test_add_const(t1, t2) = t2;	// blad, zwracana wartosc jest const	

	return 0;
}