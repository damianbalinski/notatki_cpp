// metody zdefiniowne dla kontenerow asocjacyjnych
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

#define list {1, 2, 3, 4, 5}

using std::cout;
using std::endl;

int main()
{
	/*
	 * OZNACZENIA
	 * s set					DONE
	 * S multiset				DONE
	 * m map					DONE
	 * M multimap				DONE
	 * us unordered_set			DONE
	 * uS unordered_multiset	DONE
	 * um unordered_map			DONE
	 * uM unordered_multimap	DONE
	 * - all

	 * (1) NIE wstawia, jesli element o takim samym kluczu juz istnieje
	 * (8) wstawia, nawet jesli element o takim samym kluczu juz istnieje
	 */

	// kontenery
	std::set<int> s = { 0, 2, 4, 6, 8 };
	std::set<int> set = { 0, 2, 4, 6, 8 };
	std::set<int> rset = { 0, 2, 4, 6, 8 };
	std::unordered_set<int> us = { 0, 2, 4, 6, 8 };
	std::unordered_set<int> uset = { 0, 2, 4, 6, 8 };
	std::multiset<int> ms = { 0, 1, 2, 3, 4, 5 };
	std::multiset<int> multiset = { 0, 1, 2, 3, 4, 5 };
	std::multiset<int> rmultiset = { 0, 1, 2, 3, 4, 5 };
	
	std::map<int, int> m;
	std::map<int, int> map;

	// dane
	int key = 3;
	int rkey = 3;
	int val = 3;
	int rval = 3;
	std::pair<int, int> pair(1, 1);
	auto args = { 1, 2, 3, 4, 5 };
	auto iters = set.begin();
	auto iterm = map.begin();
	auto iters1 = set.begin();
	auto iters2 = set.end();
	auto bucket = uset.bucket(key);
	int rnode = 10;
	int i = 0;
	int n = 10;
	float f = 10.0F;

	// ITERATORY
	// MODYFIKUJACY		// NIEMODYFIKUJACY
	// local_iterator	// const_local_iterator
	us.begin(i);		us.cbegin(i);		// [us uS um uM] do pierwszego elementu w i-tym kubelku
	us.end(i);			us.cend(i);			// [us uS um uM] za pstatmo element w i-tym kubelku
	// iterator			// const_iterator
	s.begin();			s.cbegin();			// [s S m M us uS um uM] do pierwszego elementu
	s.end();			s.cend();			// [s S m M us uS um uM] za ostatni element
	// reverse_iterator	// const_reverse_iterator
	s.rbegin();			s.crbegin();		// [s S m M] odwrotny do ostatniego elementu
	s.rend();			s.crend();			// [s S m M] odwrotny przed pierwszy element

	// ROZMIAR
	s.size();			// [s S m M us uS um uM] (size_type) liczba elementow
	s.max_size();		// [s S m M us uS um uM] (size_type) maksymalna liczba elementow
	s.empty();			// [s S m M us uS um uM] (bool) sprawdza, czy kontener jest pusty

	// DOSTEP
	m.at(key);			// [m um] (reference) referencja do elementu o podanym kluczu, sprawdza poprawnosc indeksowania

	// ROZNE
	s.swap(set);			// [s S m M us uS um uM] (void) zamienia miejscami kontenery tego samego typu
	s.get_allocator();		// [s S m M us uS um uM] (allocator_type) zwraca kopie alokatora
	
	// MODYFIKACJA
	// insert [s S m M us uS um uM] 
	// wstawia elemenet/elementy przed iter, dla nieuporzadkowanych iter jest sugestia
	// dla k. niepowtarzalnych zwraca pare zlozona z iteratora do wstawionego/juz 
	// istniejacego elementu oraz wartosci logicznej, okreslajacej, czy wstawienie mialo miejsce
	// dla k. powtarzalnych zwraca iterator do wstawionego elementu
	
	// UNIKALNY					// NIEUNIKALNY
	// pair<iterator, bool>		// iterator
	s.insert(val);		/*(1)*/	ms.insert(val);		/*(8)*/
	s.insert(rval);		/*(1)*/	ms.insert(rval);	/*(8)*/
	// iterator					// iterator
	s.insert(iters, val);		ms.insert(iters, val);
	s.insert(iters, rval);		ms.insert(iters, rval);
	// void						// void
	s.insert(iters1, iters2);	ms.insert(iters1, iters2);
	s.insert(list);				ms.insert(list);
	// insert_return_type		// iterator
	s.insert(rnode);			ms.insert(rnode);
	// iterator					// iterator
	s.insert(iters, rnode);		ms.insert(iters, rnode);

	// insert_or_assign [m um]
	// jesli element o podanym kluczu nie istnieje, wstawia go przed iter
	// jesli istnieje, zamienia jego wartosc
	// dla k. niepowtarzalnych zwraca pare zlozona z iteratora do wstawionego/zmodyfikowanego elementu oraz wartosci logicznej, okreslajacej, czy wstawienie mialo miejsce
	// dla k. powtarzalnych zwraca iterator do wstawionego elementu

	// UNIKALNY						// NIEUNIKALNY
	// pair<iterator, bool>
	m.insert_or_assign(key, val);
	// iterator
	m.insert_or_assign(iterm, key, val);

	// emplace [s S m M us uS um uM]
	// wstawia element, inicjalizuje go pakietem argumentow
	// dla k. niepowtarzalnych zwraca pare zlozona z iteratora do wstawionego/juz 
	// istniejacego elementu oraz wartosci logicznej, okreslajacej, czy wstawienie mialo miejsce
	// dla k. powtarzalnych zwraca iterator do wstawionego elementu
	
	// UNIKALNY						// NIEUNIKALNY
	// pair<iterator, bool>	/*(1)*/	// iterator	/*(8)*/
	s.emplace(args);				ms.emplace(args);
	
	// emplace_hint [s S m M us uS um uM] (iterator)
	// wstawia element przed iter, dla nieuporzadkowanych iter jest sugestia
	// inicjalizuje go pakietem argomentow, 
	// zwraca iterator do wstawionego lub juz istniejacego elementu
	s.emplace_hint(iters, args);	
	
	// try_emplace [m um]
	// jesli element o podanym kluczu nie istnieje, wstawia go przed iter,
	// inicjalizuje go pakietem argumentow
	// UNIKALNY						// NIEUNIKALNY
	// pair<iterator, bool>	/*(1)*/
	m.try_emplace(key, args);
	m.try_emplace(rkey, args);
	// iterator
	m.try_emplace(iterm, key, args);
	m.try_emplace(iterm, rkey, args);

	// iterator
	s.erase(iters);			// [s S m M us uS um uM] usuwa element iter lub elementy z zakresu [iter1, iter2)
	s.erase(iters1, iters2);// zwraca iterator za ostatni usuniety element
	// size_type
	s.erase(key);			// usuwa wszystkie elementy o podanym kluczu,
							// zwraca liczbe usunietych elementow

	s.clear();				// [s S m M us uS um uM] (void) usuwa wszystkie elementy

	// merge [s S m M us uS um uM]
	// przenosi elementy z kontenera tego samego typu
	// kopiowane sa wskazniki do elementow, a nie elementy

	// UNIKALNY				// NIEUNIKALNY
	// void					// void
	s.merge(set);	/*(1)*/	ms.merge(set);	/*(8)*/
	s.merge(rset);			ms.merge(rset);
	s.merge(multiset);		ms.merge(multiset);
	s.merge(rmultiset);		ms.merge(rmultiset);

	s.extract(iters);		// [s S m M us uS um uM] (node_type) wycina wezel z danej pozycji/o danym kluczu,
	s.extract(key);			// zwraca wyciety wezel

	// WYSZUKIWANIE
	s.find(key);			// [s S m M us uS um uM] (iterator) iterator powiazany z kluczem
	s.count(key);			// [s S m M us uS um uM] (size_type) liczba elementow powiazanych z kluczem
	s.contains(key);		// [s S m M us uS um uM] (bool) sprawdza, czy kontener zawiera element o podanym kluczu

	s.lower_bound(key);		// [s S m M] (iterator) iterator na pierwszy element, wiekszy/rowny od podanego klucza
	s.upper_bound(key);		// [s S m M] (iterator) iterator na pierwszy element, wiekszy od podanego klucza
	s.equal_range(key);		// [s S m M us uS um uM] (pair<iterator,iterator>) zwraca pair<lower_bound(), upper_bound()> 

	// OBSERWATORZY
	s.key_comp();			// [s S m M] (key_compare) obiekt funkcyjny porownujacy klucze
	s.value_comp();			// [s S m M] (value_compare) obiekt funkcyjny porownujacy elementy
	us.key_eq();			// [us uS um uM] (key_equal) funkcja sprawdzajaca rownosc kluczy
	us.hash_function();		// [us uS um uM] (hasher) funkcja haszujaca
	
	// KUBELKI
	us.bucket(key);			// [us uS um uM] (size_type) indeks kubelka, zawierajacy podany klucz
	us.bucket_size(i);		// [us uS um uM] (size_type) liczba elementow w kubelku o podanym indeksie
	us.bucket_count();		// [us uS um uM] (size_type) liczba kubelkow
	us.max_bucket_count();	// [us uS um uM] (size_type) maksymalna liczba kublekow
	
	// HASH
	us.load_factor();		// [us uS um uM] (float) srednia liczba elementow na kubelek
	
	// flaot
	us.max_load_factor();	// [us uS um uM] (float) zwraca maksymalna srednia liczbe elementow na kubelek
	// void
	us.max_load_factor(f);	// [us uS um uM] (void) ustawia maksymalna srednia liczbe lemenentow na kubelek na podana wartosc
	
	us.rehash(n);			// [us uS um uM] (void) ustawia liczbe kubelkow na co najmniej n, ponownie haszuje kontener
	us.reserve(n);			// [us uS um uM] (void) ustawia liczbe kubelkow na co najmniej type, aby pomiescic n elementow
							// nie przekraczajac maksymalnej sredniej liczby elementow na kubelek,
							// ponownie haszuje kontener

	return 0;
}