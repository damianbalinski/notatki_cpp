#include <iostream>

int main()
{
	using namespace std;

	int v1 = 10;
	int v2 = -10;

	int& r1 = v1;			// lvalue reference
	//int& r2 = 100;		// lvalue reference

	//int&& r3 = v1;		// rvalue reference
	int&& r4 = 100;			// rvalue reference

	cout << &v1 << endl;
	cout << &r1 << endl;
	cout << &r4 << endl;

	cout << v1 << endl;
	cout << r1 << endl;
	cout << r4 << endl;

	r1 = 20;
	r1 = v2;

	r4 = 30;
	r4 = v2;

	cout << &v1 << endl;
	cout << &r1 << endl;
	cout << &r4 << endl;

	cout << v1 << endl;
	cout << r1 << endl;
	cout << r4 << endl;

	return 0;
}