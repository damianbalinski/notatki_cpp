#include <iostream>

int main()
{
	using namespace std;

	int v1 = 10;
	const int v2 = 10;
	int& r1 = v1;
	// int& r2 = v2;
	const int& r3 = v1;
	const int& r4 = v2;

	int const& r5 = v1;
	int const& r6 = v2;

	cout << v1 << endl;
	cout << v2 << endl;
	cout << r1 << endl;
	// cout << r2 << endl;
	cout << r3 << endl;
	cout << r4 << endl;
	cout << r5 << endl;
	cout << r6 << endl;

	return 0;
}