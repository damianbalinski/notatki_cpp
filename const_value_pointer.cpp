#include <iostream>

int main()
{
	// NO CONSTANT
	int* p1;

	// CONSTANT VALUE
	const int* q1;
	int const* q2;
	//*q1 = 10;

	// CONSTANT POINTER
	int* const r1 = NULL;
	//r1 = NULL;

	// CONSTANT VALUE AND POINTER
	const int* const s1 = NULL;
	int const* const s2 = NULL;
	//*s1 = 10;
	//s1 = NULL;

	return 0;
}