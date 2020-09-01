// typy zdefiniowane dla kontenerow
#include <iostream>
#include <vector>

int main()
{
	// wszystkie (all)
	std::vector<int>::value_type;		// element
	std::vector<int>::reference;		// referencja do elementu
	std::vector<int>::const_reference;	// referencja do elementu niemodyfikowalnego
	std::vector<int>::iterator;			// iterator
	std::vector<int>::const_iterator;	// iterator niemodyfikujacy
	std::vector<int>::difference_type;	// odleglosc pomiedzy iteratorami
	std::vector<int>::size_type;		// rozmiar danych

	// odwracalne (reversible)
	std::vector<int>::reverse_iterator;			// iterator odwrotny
	std::vector<int>::const_reverse_iterator;	// iterator odwrotny niemodyfikujacy

	return 0;
}