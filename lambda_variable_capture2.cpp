#include <iostream>

using namespace std;

int main()
{
	int a = 20;
	int b = 2;

	auto func = [&a, b] { cout << a << ", " << b << endl; };

	a = 40;
	b = 4;

	func();

	return 0;
}