#include <iostream>
#include <cstdio>
#include <exception>
using std::cout, std::endl;

// TWORZENIE WLAZNEGO WYJATKU
// wyjatek uzytkownika moze, ale nie musi dziedziczyc po
// klasie exception
class MyException : public std::exception
{};

void func()
{
	try {
		// RZUCANIE WYJATKU
		//throw "exception";
		//throw 123;
		throw MyException();
	}
	catch (const char* str) {
		// PRZERZUCANIE WYJATKU
		cout << "const char* (1)" << endl;
		throw;
	}
	catch (int val) {
		cout << "int (1)" << endl;
		throw;
	}
	catch (MyException exc) {
		cout << "MyException (1)" << endl;
		throw;
	}
}
int main()
{
	// OBSLUGA WYJATKU
	try {
		func();
	}
	catch (const char* str) {
		cout << "const char* (2)" << endl;
	}
	catch (int a) {
		cout << "int (2)" << endl;
	}
	catch (MyException exc) {
		cout << "MyException (2)" << endl;
	}

	return 0;
}