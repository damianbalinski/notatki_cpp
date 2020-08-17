#include <iostream>
#include <cstdio>
//#include <exception>

// WYJATEK NIEOCZEKIWANY

// FUNKCJA OBSLUGUJACA
void handler()
{
	printf("unexpected\n");
}

void func() throw(double)
{
	throw 10;
}

int main()
{
	// REJESTRACJA FUNKCJI OBSLUGUJACEJ
	std::set_unexpected(handler);

	// PRZYKLADOWE WYWOLANIE
	try {
		func();
	}
	catch (int) {

	}

	return 0;
}