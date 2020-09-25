#include <iostream>

/*
 * LITERALY LANCUCHOWE
 * ZWYKLY nie moze zawierac znakow ", \ oraz nowej linii
 * RAW moze zawierac znaki ", \ oraz nowej linii
 */

using namespace std;

int main()
{
	// ZWYKLE	// SUROWE
	"abc";		R"(abc)";		// char*
	u8"abc";	u8R"(abc)";		// char8_t*		UTF-8
	u"abc";		UR"(abc)";		// char16_t*	UTF-16
	U"abc";		UR"(abc)";		// char32_t*	UTF-32
	L"abc";		LR"(abc)";		// wchar_t*

	// RAW STRING DELIMITER
	R"(---)";		// bez delimitera
	R"abc(---)abc";	// z delimiterem

	// TEST
	cout << sizeof("abc") << endl;
	cout << sizeof(u8"abc") << endl;
	cout << sizeof(u"abc") << endl;
	cout << sizeof(U"abc") << endl;
	cout << sizeof(L"abc") << endl;

	return 0;
}