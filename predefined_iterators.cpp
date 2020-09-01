#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <algorithm>
#define BEGIN(X) printf(X " : ")
#define END() printf("\n")

using std::cout;
using std::endl;

int main()
{
	/*
	 * OSTREAM_ITERATOR - WYJSCIOWY
	 * iterator strumienia wyjsciowego
	 *
	 * SZABLON
	 * (1) - typ danych wysylanych do strumienia
	 * (2) - typ znakow uzywany przez strumien
	 *
	 * KONSTRUKTOR
	 * (1) - uzywany strumien wyjscia
	 * drugi arg - separator, odcdzielajacy kolejne drukowane elementy
	 */
	{
		BEGIN("OSTREAM_ITERATOR");
		std::vector<int> vec = { 1, 2, 3, 4, 5 };
		std::ostream_iterator<int, char> out_iter(cout, ", ");
		*out_iter++ = 10;		// cout << 10
		*out_iter++ = 20;		// cout << 20
		*out_iter = 30;
		*out_iter = 40;
		out_iter++;
		copy(vec.begin(), vec.end(), std::ostream_iterator<int, char>(cout, ","));
		END();
	}



	/*
	 * ISTREAM_ITERATOR - WEJSCIOWY
	 * iterator strumienia wejsciowego
	 *
	 * SZABLON
	 * (1) - typ danych pobieranych ze strumienia
	 * (2) - typ znakow uzywanych przez strumien
	 *
	 * KONSTRUKTOR
	 * (1) - uzywany strumien wejscia
	 */

	/*
	 * REVERSE ITERATOR - DWUKIERUNKOWY
	 * jego inkrementacja powoduje dekrementacje, a dekrementacja inkrementacje,
	 * aby iterator dzialal prawidlowo, jego wyluskanie powoduje dostep do elementu znajdu-
	 * jacego sie bezposrednio przed elementem, na ktory wskazuje iterator
	 */
	{
		BEGIN("REVERSE_ITERATOR");
		std::vector<int> vec = { 1, 2, 3, 4, 5 };
		std::vector<int>::g iter;
		std::reverse_iterator(vec.end());
		for (iter = vec.rbegin(); iter != vec.rend(); iter++)
			cout << *iter << ", ";
		END();
	}


	/*
	 * MOVE_ITERATOR - WEJSCIOWY
	 * przenosi element zamiast go kopiowac, automatycznie konwertuje przenony
	 * element na rwartosc, nie zwieksza automatycznie wielkosci kontenera,
	 * po przeniesieniu dostep do elementow z iteratora zrodlowego jest niezde-
	 * finiowany
	 */
	{
		BEGIN("MOVE_ITERATOR");
		std::vector<int> dest = { 10, 11, 12, 13 };
		std::vector<int> src = { 0, 1, 2 };
		typedef std::vector<int>::iterator iter;
		std::copy(
			std::move_iterator<iter>(src.begin()),
			std::move_iterator<iter>(src.end()),
			dest.begin());
		cout << endl;
		for (auto i : src) cout << i << ", ";
		cout << endl;
		for (auto i : dest) cout << i << ", ";
		END();
	}

	/*
	 * BACK_INSERT_ITERATOR - WYJSCIOWY
	 * wstawia elementy na koniec kontenera, nie nadpisuje istniejacych
	 * elementow, tylko dla kontenerow o stalym czasie wstawiania na koniec
	 * (posiadajacych metode push_back())
	 * SZABLON (1) - typ kontenera
	 * KONSTRUKTOR (1) - kontener
	 */
	{
		BEGIN("BACK_INSERT_ITERATOR");
		std::vector<int> dest = { 10, 11 };
		std::vector<int> src = { 1, 2, 3 };
		std::back_insert_iterator<std::vector<int>> back_iter(dest);
		std::copy(src.begin(), src.end(), back_iter);
		std::copy(dest.begin(), dest.end(), std::ostream_iterator<int, char>(cout, ", "));
		END();
	}

	/*
	 * FRONT_INSERT_ITERATOR - WYJSCIOWY
	 * wstawia elementy na poczatek kontenera, nie nadpisuje istniejacych
	 * elementow, tylko dla kontenerow o stalym czasie wstawiania na poczatek
	 */
	{
		//BEGIN("FRONT_INSERT_ITERATOR");
		//std::queue<int> dest;
		//std::vector<int> src = { 1, 2, 3 };
		//std::front_insert_iterator<std::queue<int>> front_iter(dest);
		//for (auto i : src) dest.push(i);
		//std::copy(dest.begin(), dest.end(), std::ostream_iterator<int, char>(cout, ","));
		//END();
	}
	/*
	 * INSERT_ITERATOR - WYJSCIOWY
	 * wstawia elementy przed okreslonym miejscem, nie nadpisuje istniejacych
	 * elementow
	 *
	 * KONSTRUKTOR
	 * (1) - kontener
	 * (2) - miejsce w kontenerze
	 */
	{
		BEGIN("INSERT_ITERATOR");
		std::vector<int> dest;
		std::vector<int> src = { 1, 2, 3 };
		std::insert_iterator<std::vector<int>> insert_iter(dest, dest.begin());
		std::copy(src.begin(), src.end(), insert_iter);
		for (auto i : dest) cout << i << ", ";
		END();
	}
	/*
	 * ITERATOR
	 */
	std::iterator<int, int, int, int, int> iter;
	
	return 0;
}


//int main() {
//	std::vector<std::string> foo(3);
//	std::vector<std::string> bar{ "one","two","three" };
//
//	typedef std::vector<std::string>::iterator Iter;
//
//	std::copy(std::move_iterator<Iter>(bar.begin()),
//		std::move_iterator<Iter>(bar.end()),
//		foo.begin());
//
//	// bar now contains unspecified values; clear it:
//	bar.clear();
//
//	std::cout << "foo:";
//	for (std::string& x : foo) std::cout << ' ' << x;
//	std::cout << '\n';
//
//	return 0;
//}