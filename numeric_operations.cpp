#include <iostream>
#include <vector>
#include <numeric>
#include <execution>

/*
 * NUMERYCZNE	#include <numeric>
 */

using namespace std;

bool compb(int& a, int& b) { return a < b; }
int sumb(int a, int b) { return a + b; }
int multb(int a, int b) { return a * b; }
int diffb(int a, int b) { return a - b; }
int func(int a) { return 10 * a; }

void print(vector<int> vec)
{
	for (auto i : vec) cout << i << ", ";
	cout << endl;
}

int main()
{
	/*
	 * accumulate				DONE	DONE	DONE	1
	 * inner_product			DONE	DONE	DONE	2
	 * partial_sum				DONE	DONE	DONE	3
	 * adjacent_difference		DONE	DONE	DONE	8
	 * iota						DONE	DONE	DONE	9
	 * reduce					DONE	DONE	DONE	10
	 * transform_reduce									11
	 * inclusive_scan			DONE	DONE	DONE	4
	 * excelusive_scan			DONE	DONE	DONE	5
	 * transform_inclusive_scan	DONE	DONE	DONE	6
	 * transform_exclusive_scan	DONE	DONE	DONE	7
	 */

	// TODO
	auto funcb = sumb;

	 // kontenery
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<int> vec2 = { 1, 2, 3, 4, 5 };

	// iteratory
	auto first = vec.begin();
	auto last = vec.end();
	auto first2 = vec2.begin();
	auto last2 = vec2.end();
	
	// dane
	int n = 2;
	int val = 3;
	auto policy = std::execution::par;

	// accumulate() STABLE
	// zwraca sume elementow z [first, last)
	// ustawia wartosc poczatkowa na val
	accumulate(first, last, val);				// (I, I)		T		+
	accumulate(first, last, val, sumb);			// (I, I)		T		sumb
	
	// inner_product()
	// zwraca iloczyn skalarny [first, last) oraz [first2, last2)
	// ustawia wartosc poczatkowa na val
	inner_product(first, last, first2, val);				// (I, I, I)	T	acc = acc + iter1*iter2
	inner_product(first, last, first2, val, sumb, multb);	// (I, I, I)	T	acc = sumb(acc, multb(iter1, iter2)

	// partial_sum() COPY-OK
	// zapisuje sumy czesciowe elementow z [first, last) w [first2, ...)
	// tak ze first2+n jest rowne sumie elementow z [first, first+n)
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	partial_sum(first, last, first2);			// (I, I, O)	iterator	+	
	partial_sum(first, last, first2, sumb);		// (I, I, O)	iteraotr	sumb

	// inclusive_scan()
	// zapisuje zawierajace prefiksowe sumy czesciowe elementow z [first, last) w [first2, ...)
	// tak ze first2+n jest rowne sumie [first, first+n) + val
	// (n-ty element jest uwzgledniany w n-tej sumie)
	// jesli podano, ustawia wartosc poczatkowa na val
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	inclusive_scan(first, last, first2);				// (I, I, O)		iterator
	inclusive_scan(policy, first, last, first2);		// (-, F, F, F)		iterator
	inclusive_scan(first, last, first2, sumb);			// (I, I, O)		iterator
	inclusive_scan(policy, first, last, first2, sumb);	// (-, F, F, F)		iterator
	inclusive_scan(first, last, first2, sumb, val);			// (I, I, O)		iterator
	inclusive_scan(policy, first, last, first2, sumb, val);	// (-, F, F, F)		iterator

	// exclusive_scan()
	// zapisuje niezawierajace prefiksowe sumy czesciowe elementow z [first, last) w [first2, ...)
	// tak ze first2+n jest rowne sumie [first, first+n-1) + val
	// (n-ty element nie jest uwzgledniany w n-tej sumie)
	// ustawia wartosc poczatkowa na val	
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	exclusive_scan(first, last, first2, val);				// (I, I, O)	iterator	plus<>
	exclusive_scan(policy, first, last, first2, val);		// (- F, F, F)	iterator	plus<>
	exclusive_scan(first, last, first2, val, sumb);			// (I, I, O)	iterator	sumb
	exclusive_scan(policy, first, last, first2, val, sumb);	// (- F, F, F)	iterator	sumb

	// transform_inclusive_scan()
	// stosuje funktor func do kazdego elementu w [first, last)
	// nastepnie wywoluje inclusive_scan(), nie modyfikuje zakresu zrodlowego
	// funktor nie modyfikuje elementu val
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	transform_inclusive_scan(first, last, first2, sumb, func);				// (I, I, O)	iterator	sumb func
	transform_inclusive_scan(policy, first, last, first2, sumb, func);		// (-, F, F, F)	iterator	sumb func
	transform_inclusive_scan(first, last, first2, sumb, func, val);			// (I, I, O)	iterator	sumb func
	transform_inclusive_scan(policy, first, last, first2, sumb, func, val);	// (-, F, F, F)	iterator	sumb func
	
	// transform_exclusive_scan()
	// stosuje funktor func do kazdego elementu w [first, last)
	// nastepnie wywoluje exclusive_scan(), nie modyfikuje zakresu zrodlowego
	// funktor nie modyfikuje elementu val
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	transform_exclusive_scan(first, last, first2, val, sumb, func);			// (I, I, O)	iteraotor		sumb func
	transform_exclusive_scan(policy, first, last, first2, val, sumb, func);	// (-, F, F, F)	iterator	sumb func
																		
	// adjacent_difference() COPY-OK
	// zapisuje roznice elementow sasiednich z [first, last) w [first2+1, ...)
	// na pozycji first2 zapisuje wartosc first, odejmuje element dalszy od blizszego
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	adjacent_difference(first, last, first2);					// (I, I, O)	iterator	-
	adjacent_difference(policy, first, last, first2);			// (-, F, F, F)	iterator	-
	adjacent_difference(first, last, first2, diffb);			// (I, I, O)	iterator	diffb
	adjacent_difference(policy, first, last, first2, diffb);	// (-, F, F, F)	iterator	diffb

	// iota()
	// zapisuje w [first, last) kolejne inkrementowane wartosci
	// ustawia wartosc poczatkowa na val
	iota(first, last, val);						// (F, F)			void

	// reduce()
	// zwraca sume elementow z [first, last)
	// ustawia wartosc poczatkowa na wartosc domyslna lub, jesli podano na val
	// moze zamieniac kolejnosc elementow
	reduce(first, last);						// (I, I)			T	plus<>
	reduce(policy, first, last);				// (-, F, F)		T	plus<>
	reduce(first, last, val, sumb);				// (I, I)			T	sumb
	reduce(policy, first, last, val, sumb);		// (-, F, F)		T	sumb
	
	// transform_reduce()

	// TEST
	vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
	vector<int> v2 = { 7, 7, 7, 7, 7, 7 };
	vector<int> v3 = { 7, 7, 7, 7, 7, 7 };
	vector<int> v4 = { 7, 7, 7, 7, 7, 7 };
	print(v1);
	print(v2);
	print(v3);
	print(v4);
	cout << endl;
	transform_inclusive_scan(v1.begin(), v1.end(), v2.begin(), sumb, func);
	transform_exclusive_scan(v1.begin(), v1.end(), v3.begin(), 0, sumb, func);
	transform(v1.begin(), v1.end(), v1.begin(), func);
	partial_sum(v1.begin(), v1.end(), v4.begin());
	print(v1);
	print(v2);
	print(v3);
	print(v4);

	return 0;
}