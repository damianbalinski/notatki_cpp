// typy zdefiniowane dla kontenerow
#include <iostream>
#include <vector>
#include <set>
#include <map>

int main()
{
	// wszystkie (all)
	std::vector<int>::value_type;		// element
	std::vector<int>::reference;		// referencja do elementu
	std::vector<int>::const_reference;	// referencja do elementu niemodyfikowalnego
	std::vector<int>::pointer;			// wskaznik do elemetnu
	std::vector<int>::const_pointer;	// wskaznik do elementu niemodyfikowalnego
	std::vector<int>::iterator;			// iterator postepujacy
	std::vector<int>::const_iterator;	// niemodyfikujacy iterator postepujacy
	std::vector<int>::difference_type;	// odleglosc pomiedzy iteratorami
	std::vector<int>::size_type;		// rozmiar danych
	std::vector<int>::allocator_type;	// TODO alokator

	// odwracalne (reversible)
	std::vector<int>::reverse_iterator;			// odwrotny iterator postepujacy
	std::vector<int>::const_reverse_iterator;	// niemodyfikujacy odwrotny iterator postepujacy

	// asocjacyjne (associative)
	std::set<int>::key_type;					// S klucz
	std::set<int>::key_compare;					// S obiekt funkcyjny do porownywania kluczy
	std::set<int>::value_compare;				// S predykat dwuargumentowydo porownywania elementow, 
												// dla zbiorow = key_compare, dla map = pair<const Key, T>
	// std::set<int>::node_type;		  c++17
	//std::set<int>::insert_return_type;  c++17
	
	
	std::map<int, int>::mapped_type;			// MMu typ skojarzonych danych
	
	return 0;
}