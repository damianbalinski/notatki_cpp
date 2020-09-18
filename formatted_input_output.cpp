#include <iostream>
#define MAX 100

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
	int* ptr = new int{ 10 };
	nullptr_t nul{};

	char c = 'A';
	unsigned char uc = 'A';
	signed char sc = 'A';
	const char* str = "abc";
	char str2[MAX];
	const unsigned char* ustr = (unsigned char*)"abc";
	unsigned char ustr2[MAX];
	const signed char* sstr = (signed char*)"abc";
	signed char sstr2[MAX];

	// OPERATORY (MEMBER FUNCTIONS)
	cin >> sh;		cout << sh;			// short
	cin >> ush;		cout << ush;		// unsigned short
	cin >> i;		cout << i;			// int
	cin >> ui;		cout << ui;			// unsigned int
	cin >> l;		cout << l;			// long
	cin >> ul;		cout << ul;			// unsigned long
	cin >> ll;		cout << ll;			// long long
	cin >> ull;		cout << ull;		// unsigned long long
	cin >> f;		cout << f;			// float
	cin >> d;		cout << d;			// double
	cin >> ld;		cout << ld;			// long double
	cin >> b;		cout << b;			// bool
	//cin >> ptr;		cout << ptr;		// void*
					cout << nul;		// nullptr_t
	// TODO basic_streambuf
	// TODO ios_base
	// TODO basic_ios
	// TODO basic_ostream

	// OPERATORY (NON-MEMBER FUNCTIONS)
	cin >> c;		cout << c;		// char
	cin >> uc;		cout << uc;		// unsigned char
	cin >> sc;		cout << sc;		// signed char
	cin >> str2;	cout << str;	// char[SIZE] / const char*
	cin >> ustr2;	cout << ustr;	// unsigned char[SIZE] / const unsigned char*
	cin >> sstr2;	cout << sstr;	// signed char[SIZE] / const signed char*

	// TEST
	//char* buff1 = new char[100];
	//char buff2[100];
	//cin >> buff;										// BAD
	//cin >> buff2;										// OK
	//cin >> reinterpret_cast<char (&)[100]>(buff1);	// OK

	return 0;
}