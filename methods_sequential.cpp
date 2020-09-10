// metody zdefiniowane dla kontenerow sekwencyjnych
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <list>
#include <forward_list>

//#define list {1, 2, 3, 4, 5}

bool pred(int a) { return a == 1; }
bool predb(int a, int b) { return a == b; }
bool compb(int a, int b) { return a < b; }

int main()
{
	/* 
	 * OZNACZENIA
	 * V vector
	 * A array
	 * D deque
	 * L list
	 * F forward_list
	 * - all
	 */

	// kontenery
	std::vector<int> v;
	std::vector<int> containerv;
	std::array<int, 10> a;
	std::array<int, 10> array;
	std::deque<int> d;
	std::deque<int> deque;
	std::list<int> l;
	std::list<int> cont;
	std::list<int> rcont;
	std::forward_list<int> f = { 1, 2, 3 };
	std::forward_list<int> forw_list = { 4, 5, 6 };
	std::forward_list<int> rforw_list = { 4, 5, 6 };

	// iteratory
	auto iterv = v.begin();
	auto iterl = l.begin();
	auto iterf = f.begin();
	auto iterv1 = v.begin();
	auto iterv2 = v.end();
	auto iterl1 = cont.begin();
	auto iterl2 = cont.end();
	auto iterf1 = forw_list.begin();
	auto iterf2 = forw_list.end();
	auto firstv = v.begin();
	auto lastv = v.end();
	auto firstf = f.begin();
	auto lastf = f.end();

	// dane
	int n = 2;
	int val = 10;
	int rval = 10;
	auto args = { 1, 2, 3, 4, 5 };
	

	// ITERATORY
	// MODYFIKUJACY		// NIEMODYFIKUJACY
	// iterator			// const_iterator
	f.before_begin();	f.cbefore_begin();	// OK F przed pierwszy element
	v.begin();			v.cbegin();			// OK - do pierwszego elementu
	v.end();			v.cend();			// OK - za ostatni element
	// reverse_iterator	// const_reverse_iterator
	v.rbegin();			v.crbegin();		// OK VADL odwrotny do ostatniego elementu
	v.rend();			v.crend();			// OK VADL odwrotny przed pierwszy element

	// ROZMIAR
	v.size();			// OK VADL	(size_type)	liczba elementow
	v.max_size();		// OK -		(size_type) maksymalna liczba elementow
	v.resize(n);		// OK VDLF	(void)		zwieksza/zmniejsza rozmiar kontenera, nowe pola wypelnia 
	v.resize(n, val);	// OK ^					elementem domyslnym lub, jesli podano, elementem val
	v.shrink_to_fit();	// OK VD	(void)		polecenie zwolnienia nie uzywanej pamieci
	v.reserve(n);		// OK V		(void)		polecenie zwolnienia/zaalokowania pamieci do podanego rozmiaru
	v.capacity();		// OK V		(size_type) liczba zaalokowanych elementow
	v.empty();			// OK -		(bool)		sprawdza, czy kontener jest pusty
	
	// DOSTEP
	v.front();			// OK -		(T&)	referencja do pierwszego elementu
	v.back();			// OK VADL	(T&) referencja do ostatniego elementu
	v.at(n);			// OK VAD	(T&) referencja do elementu o podanym indeksie, sprawdza poprawnosc indeksowania
	v.data();			// OK VA	(T*) niemodyfikowalna tablica elementow (wskaznik na pierwszy element)

	// ROZNE
	v.swap(containerv);		// OK - (void) zamienia miejscami elementy kontenerow tego samego typu
	a.fill(val);			// OK A (void) wypelnia kontener podanym elementem			
	v.get_allocator();		// OK VDLF (allocator_type) zwraca kopie alokatora

	// POP/PUSH
	v.push_back(val);		// OK VDL (void) wstawia element na koniec
	v.push_back(rval);
	f.push_front(val);		// OK DLF (void) wstawia element na poczatek
	f.push_front(rval);
	v.pop_back();			// OK VDL (void) usuwa ostatni element
	f.pop_front();			// OK DLF (void) usuwa pierwszy element
	
	// MODYFIKACJA
	v.assign(n, val);		// OK VDLF (void) zastepuje zawartosc kontenera podanymi elementami
	v.assign(firstv, lastv);
	//v.assign(list);

	v.insert(iterv, val);	// OK VDL (iterator) wstawia element/elementy przed pozycja iter
	v.insert(iterv, rval);	// zwraca iterator do pierwszego wstawionego elementu
	v.insert(iterv, n, val);
	v.insert(iterv, firstv, lastv);
	//v.insert(iterv, list);

	f.insert_after(iterf, val);		// OK F (iterator) wstawia element/elementy za pozycja iter
	f.insert_after(iterf, rval);	// zwraca iterator do ostatniego wstawionego elementu
	f.insert_after(iterf, n, val);
	f.insert_after(iterf, firstv, lastv);
	//f.insert_after(iterf, list);

	v.emplace(iterv, args);	// OK VDL (iterator) wstawia element przed pozycja iter, inicjalizuje go pakietem argumentow
							// zwraca iterator do wstawionego elementu

	f.emplace_after(iterf, args);	// OK F (iterator) wstawia element za pozycja iter, inicjalizuje go pakietem argumentow
							// zwraca referencje do wstawionego elemetnu

	d.emplace_back(args);	// OK VDL (T&) wstawia element na koniec, inicjalizuje go pakietem argumentow
							// zwraca referencje do wstawionego elementu

	d.emplace_front(args);	// OK DLF (T&) wstawia element na poczatek, inicjalizuje go pakietem argumentow
							// zwraca referencje do wstawionego elementu

	

	v.erase(iterv);			// OK VDL (iterator) usuwa element iter lub elementy z zakresu [iter1, iter2)
	v.erase(firstv, lastv);	// zwraca iterator za ostatni usuniety element

	f.erase_after(iterf);	// OK F (iterator) usuwa element za iter lub elementy zzakresu (iter1, iter2)
	f.erase_after(firstf, lastf);						// zwraca iterator za ostatni usuniety element

	v.clear();				// OK VDLF (void) usuwa wszystkie elementy

	// MODYFIKACJA LISTY
	l.splice(iterl, cont);					// OK L (void) przenosi wszystkie elementy z listy, wstawia ja przed iter
	l.splice(iterl, rcont);					// kopiowane sa wskazniki do elementow, a nie elementy, lista zrodlowa staje sie pusta
	l.splice(iterl, cont, iterl1);			// przenosi element iter1 z listy, wstawia go przed iter;
	l.splice(iterl, rcont, iterl1);
	l.splice(iterl, cont, iterl1, iterl2);	// przenosi elementy z zakresu [iter1, iter2) z listy, wstawia je przed iter
	l.splice(iterl, rcont, iterl1, iterl2);

	f.splice_after(iterf, forw_list);			// OK F (void) przenosi wszystkie elementy z listy, wstawia ja za iter
	f.splice_after(iterf, rforw_list);			// kopiowane sa wskazniki do elemenot, a nie elementy, lista zrodlowa staje sie pusta
	f.splice_after(iterf, forw_list, iterf1);	// przenosi ement iter1 z listy, wstawia go za iter;
	f.splice_after(iterf, rforw_list, iterf1);
	f.splice_after(iterf, forw_list, iterf1, iterf2);// przenosi elementy z zakresu (iter1, iter2) z listy, wstawia je za iter
	f.splice_after(iterf, rforw_list, iterf1, iterf2);

	l.remove(val);			// OK LF (size_type) usuwa wszystkie wystapienia val
							// zwraca liczbe usunietych elementow
	l.remove_if(pred);		// OK LF (size_type) usuwa wszystkie elementy i, spelniajace predykat unarny pred
							// zwraca liczbe usunietych elementow

	l.unique();				// OK LF (size_type) usuwa zduplikowane sasiednie elementy
							// zwraca liczbe usunietych elementow
	l.unique(predb);		// usuwa i, takie ze para(i, (i-1)) spelnia predykat binarny predb

	l.merge(cont);			// < OK LF (void) scala dwie posortowane rosnaco listy, po scaleniu list2 jest pusta
	l.merge(rcont);			// <
	l.merge(cont, compb);	// compb
	l.merge(rcont, compb);	// compb

	l.sort();				// < OK LF (void) sortuje liste
	l.sort(compb);			// compb
	
	l.reverse();			// OK LF (void )odwraca kolejnosc elementow

	return 0;
}