#include <iostream>

/*
 * UDOSTEPNIANIE METOD
 * udostepnienie klasie pochodnej wszystkich przeciazonych wersji
 * podanej metody z klasy bazowej
 */

using namespace std;

namespace Box
{
	void func(int val) { cout << "int\n"; }
	void func(double val) { cout << "double\n"; }
	void func(char val) { cout << "char\n"; }
}

class A
{
private:
	int val;
public:
	void func2(int val) {};
	void func2(double val) {};
	void func2(char val) {};
};

class B : protected A
{
	using A::func2;
	A::func2;
};

int main()
{
	// 
	using Box::func;

	func(10);
	func(10.0);
	func('A');

	C2();
	C2(10);
	C2(10.0);
	return 0;
}