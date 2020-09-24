#include <iostream>

/*
 * SPECYFIKATOR CONSTEXPR
 * ZMIENNA - informacja dla kompilatora, ze wartosc zmiennej jest stala, moze
 * byc obliczona w trakcie kompilacji, zmienna constexpr jest const
 *
 * FUNKCJA - informacja dla kompilatora ze wartosc zwracana jest
 * stala, moze byc obliczona w trakcie kompilacji, funkcja constexpr jest inline
 */

using namespace std;

constexpr int func()
{
	return 10;
}

constexpr int val0 = 10;

int main()
{
	int v1 = 10;
	const int v2 = 10;
	constexpr int v3 = 10;

	constexpr int a1 = 10;
	//constexpr int a2 = v1;	// ERROR
	constexpr int a3 = v2;
	constexpr int a4 = v3;

	return 0;
}