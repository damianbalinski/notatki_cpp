// typy zdefiniowane dla kontenerow
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <span>

int main()
{
	/*
	 * OZNACZENIA
	 * V vector			DONE	DONE
	 * A array			DONE	DONE
	 * D deque			DONE	DONE
	 * L list			DONE	DONE
	 * F forward list	DONE	DONE
	 * Sp span			DONE	DONE
	 *
	 * s set			DONE	DONE
	 * S multiset		DONE	DONE
	 * m map			DONE	DONE
	 * M multimap		DONE	DONE
	 *
	 * us unordered_set			DONE	DONE
	 * uS unordered_multiset	DONE	DONE
	 * um unordered_map			DONE	DONE
	 * uM unordered_multimap	DONE	DONE
	 *
	 * St stack			DONE	DONE	
	 * Q queue			DONE	DONE
	 * P priority_queue	DONE
	 * - all
	 */

	// adaptatory
	std::stack<int>::container_type;	// [St Q P] kontener

	// span
	std::span<int>::element_type;		// [Sp] element

	// prawie wszystkie [s S us uS m M um uM VADLF]
	std::vector<int>::value_type;		// [St Q P Sp] element
	std::vector<int>::size_type;		// [St Q P Sp] rozmiar
	std::vector<int>::difference_type;	// [Sp] odleglosc pomiedzy iteratorami
	std::vector<int>::reference;		// [St Q P Sp] referencja do elementu
	std::vector<int>::const_reference;	// [St Q P Sp] referencja do elementu niemodyfikowalnego
	std::vector<int>::pointer;			// [Sp] wskaznik do elemetnu
	std::vector<int>::const_pointer;	// [Sp] wskaznik do elementu niemodyfikowalnego
	std::vector<int>::iterator;			// [Sp] iterator
	std::vector<int>::const_iterator;	// [Sp] niemodyfikujacy iterator

	// odwracalne
	std::vector<int>::reverse_iterator;			// [s S m M VADL Sp] odwrotny iterator postepujacy
	std::vector<int>::const_reverse_iterator;	// [s S m M VADL Sp] niemodyfikujacy odwrotny iterator postepujacy

	// prawie wszystkie porocz array [s S us uS m M um uM VDLF]
	std::vector<int>::allocator_type;	// [VDLF] alokator

	// asocjacyjne uporzadkowane
	std::set<int>::key_type;				// [s S us uS m M um uM] klucz
	std::set<int>::node_type;				// [s S us uS m M um uM] wezel
	std::set<int>::key_compare;				// [s S m M] obiekt funkcyjny do porownywania kluczy
	std::set<int>::value_compare;			// [s S m M] predykat dwuargumentowydo porownywania elementow, 
											// dla zbiorow = key_compare, dla map = pair<const Key, T>
	std::set<int>::insert_return_type;		// [s us m um] wartosc zwracana podczas wstawia wezla
	std::map<int, int>::mapped_type;		// [m M um uM] dane skojarzone z kluczem

	// asocjacyjne nieuporzadkowane
	std::unordered_set<int>::key_equal;				// [us uS um uM] binarny predykat sprawdzajacy rownosc elementow
	std::unordered_set<int>::hasher;				// [us uS um uM] haszujacy obiekt funkcyjny
	std::unordered_set<int>::local_iterator;		// [us uS um uM] iterator do elementow kubelka
	std::unordered_set<int>::const_local_iterator;	// [us uS um uM] niemodyfikujacy iterator do elementow kubelka 

	return 0;
}