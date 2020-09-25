#include <iostream>

/*
 * LITERALY LANCUCHOWE ZDEFINIOWANE PRZEZ UZYTKOWNIKA
 */

using namespace std;

int operator""_s(const char* s, size_t n) { return 1; }
int operator""_s(const char8_t* s, size_t n) { return 2; }
int operator""_s(const char16_t* s, size_t n) { return 3; }
int operator""_s(const char32_t* s, size_t n) { return 4; }
int operator""_s(const wchar_t* s, size_t n) { return 5; }


int main()
{
	int a1 = "abc"_s;
	int a2 = u8"abc"_s;
	int a3 = u"abc"_s;
	int a4 = U"abc"_s;
	int a5 = L"abc"_s;

	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;
	cout << a5 << endl;

	return 0;
}