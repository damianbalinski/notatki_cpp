#include <iostream>

/*
 * WYRAZENIE LAMBDA - funkcja anonimowa (nienazwana definicja funkcji),
 * moze byc zdefiniowana w ciele funkcji
 */

using namespace std;
int val = 10;

/*
 * LAMBDA 1 - BEZPARAMETROWA
 * nie przyjmuje parametrow
 */
void func1() { cout << "func1\n"; }			// FUNKCJA
auto lamb1 = [] {cout << "lamb1\n";  };		// WYRAZENIE LAMBDA
//auto lamb1 = []() {cout << "lamb1\n";  };	// WYRAZENIE LAMBDA

/*
 * LAMBDA 2 - PARAMETROWA
 * przyjmuje parametry
 */
void func2(int a) { cout << "func2\n"; }			// FUNKCJA
auto lamb2 = [](int a) { cout << "lamb2\n"; };		// WYRAZENIE LAMBDA

/*
 * LAMBDA 3 - NIEOKRESLONY TYP ZWRACANY
 * typ wartosci zwracanej jest okreslany automatycznie
 */
void func3() { cout << "func3\n"; }			// FUNKCJA
auto lamb3 = [] {cout << "lamb3\n";  };		// WYRAZENIE LAMBDA

/*
 * LAMBDA 4 - OKRESLONY TYP ZWRACANY
 * typ wartosci zwracanej jest podany przy uzyciu opoznionej deklaracji
 */
int func4() { return 10.0; }				// FUNKCJA
auto lamb4 = []()->double{ return 10.0; };	// WYRAZENIE LAMBDA

/*
 * LAMBDA 5 - LAMBDA GENERYCZNA
 * 
 */
template<typename T>
auto func5(T i) { return i; };
auto lamb5 = [](auto i) { return i; };

int main()
{
	// dane
	int val = 10;
	int val2 = 20;

	func1();
	lamb1();
	
	func2(10);
	lamb2(10);

	func3();
	lamb3();

	func4();
	lamb4();

	func5(10);
	lamb5(10);

	cout << typeid(lamb1).name() << endl;
	cout << typeid(lamb5).name() << endl;

	return 0;
}