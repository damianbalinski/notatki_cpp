#include <iostream>
#include <exception>

// SPECYFIKACJA WYJATKOW

using std::cout;
using std::endl;

void func1() throw(int)
{
	cout << "func1" << endl;
	throw "stding";
}

void func2() throw(int)
{
	cout << "func2" << endl;
	throw 10;
}

int main()
{
	try {
		//func1();
		func2();
	}

	catch (int) {
		cout << "int" << endl;
	}
	catch (const char*) {
		cout << "const char*" << endl;
	}

	return 0;
}