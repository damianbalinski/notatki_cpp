#include <iostream>

/*
 * LEKSEMY ALTERNATYWNE
 * alternatywne nazwy dla operatorow
 */

int main()
{
	// DANE
	bool b1 = true;
	bool b2 = false;

	// LOGICZNE
	1 and 0;			1 && 1;
	1 or 0;				1 || 0;
	not 1;				!1;

	// BITOWE
	1 bitand 0;			1 & 0;
	1 bitor 0;			1 | 0;
	1 xor 0;			1 ^ 0;
	compl 1;			~1;

	// PRZYPISANIE BITOWE
	b1 and_eq b2;		b1 &= b2;
	b1 xor_eq b2;		b1 ^= b2;
	b1 or_eq b2;		b1 |= b2;
	b1 not_eq b2;		b1 != b2;

	return 0;
}