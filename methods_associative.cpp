// metody zdefiniowne dla kontenerow asocjacyjnych
#include <iostream>
#include <vector>
#include <set>
#include <map>

#define list {1, 2, 3, 4, 5}

using std::cout;
using std::endl;

int main()
{
	/*
	 * OZNACZENIA
	 * s set
	 * S multiset
	 * m map
	 * M multimap
	 * - all
	 */

	// kontenery
	std::set<int> s = { 0, 2, 4, 6, 8 };
	std::set<int> set = { 0, 2, 4, 6, 8 };
	std::set<int> rset = { 0, 2, 4, 6, 8 };
	std::map<int, int> m;
	std::map<int, int> map;

	// dane
	int key = 3;
	std::pair<int, int> pair(1, 1);
	int val = 1;
	int rval = 1;
	auto args = { 1, 2, 3, 4, 5 };
	auto iters = set.begin();
	auto iters1 = set.begin();
	auto iters2 = set.end();
	int rnode = 10;

	// ITERATORY
	// MODYFIKUJACY		// NIEMODYFIKUJACY
	// iterator			// const_iterator
	s.begin();			s.cbegin();			// s do pierwszego elementu
	s.end();			s.cend();			// s za ostatni element
	// reverse_iterator	// const_reverse_iterator
	s.rbegin();			s.crbegin();		// s odwrotny do ostatniego elementu
	s.rend();			s.crend();			// s odwrotny przed pierwszy element

	// ROZMIAR
	s.size();			// s (size_type) liczba elementow
	s.max_size();		// s (size_type) maksymalna liczba elementow
	s.empty();			// s (bool) sprawdza, czy kontener jest pusty

	// DOSTEP
	s.lower_bound(key);		// SM zwraca iterator na pierwszy element, wiekszy/rowny od podanego klucza
	s.upper_bound(key);		// SM zwraca iterator na pierwszy element, wiekszy od podanego klucza
	
	// ROZNE
	s.swap(set);			// s (void) zamienia miejscami kontenery tego samego typu
	s.get_allocator();		// s (allocator_type) zwraca kopie alokatora
	
	// MODYFIKACJA
	//std::pair<iterator, bool>
	s.insert(val);			// s wstawia elemenet/elementy przed iter, tak blisko jak to mozliwe
	s.insert(rval);
	// iterator
	s.insert(iters, val);
	s.insert(iters, rval);
	// void
	s.insert(iters1, iters2);
	s.insert(list);
	// insert_return_type
	s.insert(rnode);
	// iterator
	s.insert(iters, rnode);

	s.emplace(args);		// s (std::pair<iterator, bool>) wstawia element, inicjalizuje go pakietem argumentow
							// zwraca pare zlozona z iteratora do wstawionego lub juz istniejacego elementu oraz wartosci logicznej
							// okreslajacej, czy wstawienie mialo miejsce
	
	s.emplace_hint(iters, args);	// s (iterator) wstawia element przed iter, tak blisko jak to mozliwe, inicjalizuje
									// go pakietem argomentow, zwraca iterator do wstawionego lub juz istniejacego elementu
	// iterator
	s.erase(iters);			// s (void) usuwa element iter lub elementy z zakresu [iter1, iter2)
	s.erase(iters1, iters2);
	// size_type
	s.erase(key);			// usuwa wszystkie elementy o podanym kluczu,
							// zwraca liczbe usunietych elementow

	s.clear();				// s (void) usuwa wszystkie elementy

	// MODYFIKUJACE 2
	s.merge(set);			// s (void) przenosi elementy ze zbioru set, jesli element juz istnieje, nie przenosi go
	s.merge(rset);		// kopiowane sa wskazniki do elemenot, a nie elementy,
	// s.merge(multiset);
	s.merge(rmultiset);

	s.extract(
	// TEST
	m.insert(pair);			// wstawia obiekt pair

	m.count(key);			// liczba elementow powiazanych z kluczem
	m.equal_range(key);		// zwraca iteratory na zakres elementow o podanym kluczu, obywda iteratory sa skladowymi obiektu pair

	auto iter1 = s.lower_bound(1);
	auto iter2 = s.upper_bound(1);
	cout << *iter1 << endl;
	cout << *iter2 << endl;

	return 0;
}