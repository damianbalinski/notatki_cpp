#include <iostream>

/*
 * ATRYBUT NORETURN
 */

using namespace std;

[[noreturn]] void func()
{
	cout << "hi" << endl;
}

int main()
{
	func();
	return 0;
}