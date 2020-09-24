#include <iostream>

/*
 * ATRYBUT NORETURN
 */

using namespace std;

[[noreturn]] int func()
{
	cout << "hi" << endl;
	return 10;
}

int main()
{
	func();
	return 0;
}