#include <iostream>

/*
 * LITERALY ZNAKOWE ZDEFINIOWANE PRZEZ UZYTKOWNIKA
 */

using namespace std;

int operator""_c(char c) { return 1; }
int operator""_c(char8_t c) { return 2; }
int operator""_c(char16_t c) { return 3; }
int operator""_c(char32_t c) { return 4; }
int operator""_c(wchar_t c) { return 5; }

int main()
{
	int a1 = 'A'_c;
	int a2 = u8'A'_c;
	int a3 = u'A'_c;
	int a4 = U'A'_c;
	int a5 = L'A'_c;

	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;
	cout << a5 << endl;

	return 0;
}