#include <iostream>
#include <iterator>

int main()
{
	/*
	 * OSTREAM_ITERATOR - WYJSCIOWY
	 *
	 * SZABLON
	 * -pierwszy argument - dane przesylane do strumienia
	 * -drugi argument - typ znakow uzywany przez strumien
	 *
	 * KONSTRUKTOR
	 * pierwszy argument - uzywany strumien wyjscia
	 * drugi arg - separator, odcdzielajacy kolejne drukowane elementy
	 */
	std::ostream_iterator<int, char> out_iter(std::cout, " ");
	*out_iter++ = 10;		// cout << 10
	*out_iter++ = 20;		// cout << 20
	*out_iter = 30;

	return 0;
}