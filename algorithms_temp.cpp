#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cout;
using std::endl;

void print(std::vector<int> vec)
{
	cout << "vec: ";
	for (auto i : vec)
		cout << i << ", ";
	cout << endl;
}


bool predb(int a, int b)
{
	return a > b;
}

int func(int a)
{
	return 10 * a;
}

int funcb(int a, int b)
{
	return a + b;
}

int main()
{
	/*
	 * DONE
	 *
	 * PEND
	 * random_shuffle		PEND
	 * sort					PEND
	 * transform			PEND
	 *
	 * set_union			TODO
	 * set_intersection		TODO
	 * set_differebce		TODO
	 * copy
	 * find
	 * for_each
	 * replace
	 */

	/*
	 * SEKWENCYJNE NIEMODYFIKUJACE
	 * for_each			TODO
	 * find				TODO
	 *
	 * SEKWENCYJNE MODYFIKUJACE
	 * transform
	 * random_shuffle
	 * copy
	 * 
	 * SORTOWANIE I POKREWNE
	 * sort
	 *
	 * NUMERYCZNE
	 *
	 *
	 */
	// kontenery
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::vector<int> vec2 = { 1, 2, 3, 4, 5 };
	std::vector<int> rvec = { 1, 2, 3, 4, 5 };

	// iteratory
	auto first = vec.begin();
	auto last = vec.begin();
	auto first2 = vec2.begin();
	auto lasat2 = vec2.end();
	auto rfirst = rvec.begin();
	auto rlast = rvec.end();

	// dane

	// FOR_EACH - kazdy kontener
	// stosuje podany funktor dla kazdego elementu z zakresu [first, last)
	std::for_each(first, last, func);

	// RANDOM_SHUFFLE - kontenery o dostepie swobownym do elementow
	// losowo zmienia kolejnosc elementow w zakresie [first, last)
	 // std::random_shuffle(iter1, iter2);


	// SORT M (I,I,O) - kontenery o dostepie swobodnym do elementow
	// sortuje elementy w zakresie[first, last)
	// do porownywania elementow kozysta z operatora
	std::sort(first, last);
	// do porownywania elemetow kozysta z funkcji/obiektu funkcyjego, funkcja musi zwracac wartosc, ktora da sie przeko-
	// nwertowac na typ bool
	std::sort(first, last, predb);

	// TRANSFORM
	// dla kazdego elementu i z zakresu [first, last) wywoluje funktor func(i), zwracana wartosc umieszcza zaczynajc od rfirst
	// jesli first == rfirst, modyfikuje elementy w kontenerze zrodlowym
	std::transform(first, last, rfirst, func);
	// dla kazdego elementu i z zakresu [first, last) oraz kazdego elementu j z zakresu [first2, ...) wywoluje funktor funcb(i, j)
	// zwracana wartosc umieszcza zaczynajac od rfirst
	std::transform(first, last, first2, rfirst, funcb);
	
	/*
	 * SLOWNIK
	 * first, last - iteratory wejsciowe
	 * rfirst - iterator wyjsciowy
	 * pred - predykat
	 * predb - predykat binarny
	 * func - funktor jednoargumentowy
	 * funcb - funktor dwuargumentowy
	 *
	 */

	/*
	 * SYMBOLE / ITERATORY
	 * M - funkcja dzialajaca w miejscu
	 * K - funkcja kopiujaca
	 * I - wejsciowy
	 * O - wyjsciowy
	 * F - postepujacy
	 * B - dwukierunkowy
	 * R - dostepu swobodnego
	 * C - ciagly
	 */

	return 0;
}