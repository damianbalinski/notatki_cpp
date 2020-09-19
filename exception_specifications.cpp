#include <iostream>

/*
 * SPECYFIKACJA WYJATKOW
 */

using namespace std;

// NIEOKRESLONE
void func1() {}						// STARY
void func2() {}						// NOWY

// ZGLASZA DOWOLNY
void func3() throw(...) {}			// STARY
void func4() noexcept(false) {}		// NOWY

// ZGLASZA KONKRETNY
void func5() throw(int) {}			// STARY

// NIE ZGLASZA
void func6() throw() {}				// STARY
void func7() noexcept {}			// NOWY
void func8() noexcept(true) {}		// NOWY

int main()
{
	cout << noexcept(func1()) << endl;
	cout << noexcept(func2()) << endl;
	cout << noexcept(func3()) << endl;
	cout << noexcept(func4()) << endl;
	cout << noexcept(func5()) << endl;
	cout << noexcept(func6()) << endl;
	cout << noexcept(func7()) << endl;
	cout << noexcept(func8()) << endl;

	/*
	 * STARY - stary standard
	 * NOWY - nowy standard
	 */

	return 0;
}