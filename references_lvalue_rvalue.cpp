#include <iostream>

int func() { return 10; }

int main()
{
	using namespace std;

	int v1 = 10;
	int v2 = 0;

	// LVALUE REFERENCE
	//int& r1 = 10;			// ERROR
	int& r2 = v1;			// OK
	//int& r3 = v1 + v2;	// ERROR
	//int& r4 = func();		// ERROR

	// RVALUE REFERENCE
	int&& rr1 = 10;			// OK
	//int&& rr2 = v1;		// ERROR
	int&& rr3 = v1 + v2;	// OK
	int&& rr4 = func();		// OK

	cout << rr1 << endl;
	cout << r2 << endl;
	cout << rr3 << endl;
	cout << rr4 << endl;

	cout << &rr1 << endl;
	cout << &r2 << endl;
	cout << &rr3 << endl;
	cout << &rr4 << endl;

	return 0;
}