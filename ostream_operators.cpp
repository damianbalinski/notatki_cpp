#include <iostream>

using namespace std;

int main()
{
	// DANE
	short sh = 10;
	unsigned short ush = 10;
	int i = 10;
	unsigned int ui = 10;
	long l = 10;
	unsigned long ul = 10;
	long long ll = 10;
	unsigned long long ull = 10;
	float f = 10.0;
	double d = 10.0;
	long double ld = 10.0;
	bool b = true;
	int* ptr = &i;
	nullptr_t nul{};

	char c = 'A';
	unsigned char uc = 'A';
	signed char sc = 'A';
	const char* str = "abc";
	const unsigned char* ustr = (unsigned char*)"abc";
	const signed char* sstr = (signed char*)"abc";

	// STRUMIENIE

	
	// OPERATORY (MEMBER FUNCTIONS)
	cout << sh;		// short
	cout << ush;	// unsigned short
	cout << i;		// int
	cout << ui;		// unsigned int
	cout << l;		// long
	cout << ul;		// unsigned long
	cout << ll;		// long long
	cout << ull;	// unsigned long long
	cout << f;		// float
	cout << d;		// double
	cout << ld;		// long double
	cout << b;		// bool
	cout << ptr;	// void*
	cout << nul;	// nullptr_t
	// TODO basic_streambuf
	// TODO ios_base
	// TODO basic_ios
	// TODO basic_ostream


	// OPERATORY (NON-MEMBER FUNCTIONS)
	cout << c;		// char
	cout << uc;		// unsigned char
	cout << sc;		// signed char
	cout << str;	// const char*
	cout << ustr;	// const unsigned char*
	cout << sstr;	// const signed char*

	// TEST
	cout << endl;

	for(int i = 0; i < 10; i++)
		cout << nul << endl;

	return 0;
}