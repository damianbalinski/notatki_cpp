#include <iostream>

int main()
{
	int* ptr;
	int* tab;

	/*
	 * WERSJA NOTHROW
	 * w przypadku niepowodzenia zamiast zwracac wyjatek,
	 * zwraca wskaznik pusty.
	 */
	ptr = new (std::nothrow) int;
	tab = new (std::nothrow) int[100];

	if (ptr == nullptr) {
		return EXIT_FAILURE;
	}

	if (tab == NULL) {
		return EXIT_FAILURE;
	}

	return 0;
}