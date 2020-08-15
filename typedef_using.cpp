#include <iostream>
#include <cstdio>
#include <array>

using std::array;

void test() {}

// USING ALIAS TEMPLATE
template<typename T>
using temp = array<T, 10>;


typedef int max;
int main()
{
	// TYPEDEF
	typedef char byte;			// char
	typedef int tab[10];		// talblica int
	typedef int* ptr;			// wskaznik na int
	typedef void (*func)();		// wksznik na funkcje void

	// USING =
	using byte2 = char;
	using tab2 = int[10];
	using ptr2 = int*;
	using func2 = void(*)();

	// USAGE
	byte b1 = 'a';
	byte2 b2 = 'a';

	tab t1; t1[9] = 9;
	tab2 t2; t2[9] = 9;

	int z1 = 0, z2 = 1;
	ptr p1 = &z1;
	ptr2 p2 = &z2;

	func f1 = test;
	func2 f2 = test;

	temp<int> t3;

	return 0;
}