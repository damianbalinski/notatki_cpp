#include <iostream>

/*
 * SPECYFIKATOR ALIGNAS
 * alignas(type)
 * alignas(expr)		- expr(0) jest zawsze ignorowane
 * alignas(pack...)
 *
 * okreslone wyrownanie dla zmiennej (silniejsze niz podstawowe)
 */

using namespace std;

// ALIGNAS PACK...
template<class... Args>
void func(Args... args)
{
	alignas(args...) int val;
}

// ALIGNAS CLASS
class alignas(128) C {};

int main()
{
	// ALIGNAS TYPE
	alignas(int) int a = 10;

	// ALIGNAS EXPR
	alignas(16) int b = 10;

	// ALIGNAS ZERO
	alignas(0) int c = 10;

	return 0;
}