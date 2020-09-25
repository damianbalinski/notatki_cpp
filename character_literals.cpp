#include <iostream>

/*
 * LITERALY ZNAKOWE
 */

using namespace std;

int main()
{
	// LITERALY ZNAKOWE
	'A';		// char
	u8'A';		// char8_t		UTF-8
	u'A';		// char16_t		UTF-16
	U'A';		// char32_t		UTF-32
	L'A';		// wchar_t

	// LITERALY MULTIZNAKOWE
	'ABCD';		// int
	L'ABCD';	// wchar_t

	return 0;
}