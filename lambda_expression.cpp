#include <iostream>

/*
 * WYRAZENIE LAMBDA [](){}
 * funkcja anonimowa (nienazwana definicja funkcji),
 * moze byc zdefiniowana w ciele funkcji
 */

using namespace std;
int val = 10;

/*
 * LAMBDA 1 - BEZPARAMETROWA
 * nie przyjmuje parametrow
 */
void func1() { cout << "func1\n"; }				// FUNKCJA
auto lamb1 = [] {cout << "lamb1\n";  };			// WYRAZENIE LAMBDA
//auto lamb1 = []() {cout << "lamb1\n";  };		// WYRAZENIE LAMBDA

/*
 * LAMBDA 2 - PARAMETROWA
 * przyjmuje parametry
 */
void func2(int a) { cout << "func2\n"; }		// FUNKCJA
auto lamb2 = [](int a) { cout << "lamb2\n"; };	// WYRAZENIE LAMBDA

/*
 * LAMBDA 3 - NIEOKRESLONY TYP ZWRACANY
 * typ wartosci zwracanej jest okreslany automatycznie
 */
int func3() { return 10; }						// FUNKCJA
auto lamb3 = [] { return 10; };					// WYRAZENIE LAMBDA

/*
 * LAMBDA 4 - OKRESLONY TYP ZWRACANY
 * typ wartosci zwracanej jest podany przy uzyciu opoznionej deklaracji
 */
int func4() { return 10.0; }					// FUNKCJA
auto lamb4 = []()->int{ return 10.0; };		// WYRAZENIE LAMBDA

int main()
{
	int val = 20;
	int val2 = 2;

	/*
	 * LAMBDA 6 - WYWOLANIE W MIEJSCU DEKLARACJI
	 */
	int n = [=] { return val + val2; }();
	cout << n << endl;
	return 0;
}