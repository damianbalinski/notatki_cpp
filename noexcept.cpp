#include <iostream>

/*
 * NOEXCEPT(expr)
 * sprawdza, czy podane wyrazenie moze zwrocic wyjatek
 */

void func1() {}
void func2() noexcept {}
void func3() noexcept(true) {}
void func4() noexcept(false) {}

using namespace std;

int main()
{
	//cout << noexcept() << endl;
	cout << noexcept(true) << endl;
	cout << noexcept(throw 5) << endl;
	cout << noexcept(func1()) << endl;
	cout << noexcept(func2()) << endl;
	cout << noexcept(func3()) << endl;
	cout << noexcept(func4()) << endl;

	return 0;
}