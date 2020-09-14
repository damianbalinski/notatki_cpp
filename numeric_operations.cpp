#include <iostream>
#include <vector>
#include <numeric>
#include <execution>

/*
 * NUMERYCZNE
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
	 * accumulate				DONE	DONE	DONE
	 * inner_product			DONE	DONE	DONE
	 * partial_sum				DONE	DONE	DONE
	 * adjacent_difference		DONE	DONE	DONE
	 * iota						DONE	DONE	DONE
	 * reduce					DONE	DONE	DONE
	 * transform_reduce			DONE	DONE	DONE
	 * inclusive_scan			DONE	DONE	DONE
	 * excelusive_scan			DONE	DONE	DONE
	 * transform_inclusive_scan	DONE	DONE	DONE
	 * transform_exclusive_scan	DONE	DONE	DONE
	 */

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
	
	// iota()
	// zapisuje w [first, last) kolejne inkrementacje wartosci poczatkowej
	iota(first, last, val);						// (F, F)			void	V

	// adjacent_difference() COPY-OK
	// zapisuje roznice elementow sasiednich z [first, last) w [first2, ...)
	// na pozycji first2 zapisuje wartosc pod first, odejmuje element dalszy od blizszego
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	adjacent_difference(first, last, first2);					// (I, I, O)	iterator	-
	adjacent_difference(policy, first, last, first2);			// (-, F, F, F)	iterator	-
	adjacent_difference(first, last, first2, diffb);			// (I, I, O)	iterator	diffb
	adjacent_difference(policy, first, last, first2, diffb);	// (-, F, F, F)	iterator	diffb

	// inner_product()
	// zwraca iloczyn skalarny [first, last) oraz [first2, last2)
	inner_product(first, last, first2, val);				// (I, I, I)	T	V acc = acc + iter1*iter2
	inner_product(first, last, first2, val, sumb, multb);	// (I, I, I)	T	V acc = sumb(acc, multb(iter1, iter2)

	// accumulate() STABLE
	// zwraca sume elementow z [first, last)
	accumulate(first, last, val);				// (I, I)		T		V +
	accumulate(first, last, val, sumb);			// (I, I)		T		V sumb

	// reduce() STABLE-NOT
	// redukuje elementy z [first, last) za pomoca sumb,
	// zwraca zredukowana sume
	reduce(first, last);						// (I, I)			T	0	plus<>()
	reduce(policy, first, last);				// (-, F, F)		T	0	plus<>()
	reduce(first, last, val, sumb);				// (I, I)			T	V	sumb
	reduce(policy, first, last, val, sumb);		// (-, F, F)		T	V	sumb

	// transform_reduce()1 STABLE-NOT
	// wywoluje multb dla kazdej pary odpowiadajacych sobie elementow z
	// [first, last) oraz [first2, ...),
	// redukuje otrzymane wartosci za pomoca sumb,
	// zwraca zredukowana sume
	transform_reduce(first, last, first2, val);						// T	V	plus<>() multiplies<>()
	transform_reduce(policy, first, last, first2, val);				// T	V	plus<>() multiplies<>()
	
	transform_reduce(first, last, first2, val, sumb, multb);		// T	V	sumb multb
	transform_reduce(policy, first, last, first2, val, sumb, multb);// T	V	sumb multb
	
	// transform_reduce()2 STABLE-NOT
	// stosuje func dla kazdego elementu z [first, last)
	// redukuje otrzymane wartosci za pomoca sumb,
	// zwraca zredukowana sume
	// funktor nie modyfikuje wartosci val
	transform_reduce(first, last, val, sumb, func);				// T	V	sumb
	transform_reduce(policy, first, last, val, sumb, func);		// T	V	sumb

	// partial_sum() COPY-OK
	// zapisuje sumy czesciowe elementow z [first, last) w [first2, ...)
	// tak ze first2+n jest rowne sumie elementow z [first, first+n)
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	partial_sum(first, last, first2);			// (I, I, O)	iterator	+	
	partial_sum(first, last, first2, sumb);		// (I, I, O)	iteraotr	sumb

	// inclusive_scan() STABLE-NOT
	// zapisuje zawierajace prefiksowe sumy czesciowe elementow z [first, last) w [first2, ...)
	// tak ze first2+n jest rowne sumie [first, first+n]
	// (n-ty element jest uwzgledniany w n-tej sumie)
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	inclusive_scan(first, last, first2);					// (I, I, O)		iterator		0	plus<>()
	inclusive_scan(policy, first, last, first2);			// (-, F, F, F)		iterator		0	plus<>()
	inclusive_scan(first, last, first2, sumb);				// (I, I, O)		iterator		0	sumb
	inclusive_scan(policy, first, last, first2, sumb);		// (-, F, F, F)		iterator		0	sumb
	inclusive_scan(first, last, first2, sumb, val);			// (I, I, O)		iterator		V	sumb
	inclusive_scan(policy, first, last, first2, sumb, val);	// (-, F, F, F)		iterator		V	sumb

	// exclusive_scan() STABLE-NOT
	// zapisuje niezawierajace prefiksowe sumy czesciowe elementow z [first, last) w [first2, ...)
	// tak ze first2+n jest rowne sumie [first, first+n)
	// (n-ty element nie jest uwzgledniany w n-tej sumie)	
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	exclusive_scan(first, last, first2, val);				// (I, I, O)	iterator	V	plus<>
	exclusive_scan(policy, first, last, first2, val);		// (- F, F, F)	iterator	V	plus<>
	exclusive_scan(first, last, first2, val, sumb);			// (I, I, O)	iterator	V	sumb
	exclusive_scan(policy, first, last, first2, val, sumb);	// (- F, F, F)	iterator	V	sumb

	// transform_inclusive_scan() STABLE-NOT
	// stosuje func do kazdego elementu z [first, last)
	// nastepnie wywoluje inclusive_scan(), 
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	// funktor nie modyfikuje wartosci val
	transform_inclusive_scan(first, last, first2, sumb, func);				// (I, I, O)	iterator	sumb func
	transform_inclusive_scan(policy, first, last, first2, sumb, func);		// (-, F, F, F)	iterator	sumb func
	transform_inclusive_scan(first, last, first2, sumb, func, val);			// (I, I, O)	iterator	sumb func
	transform_inclusive_scan(policy, first, last, first2, sumb, func, val);	// (-, F, F, F)	iterator	sumb func
	
	// transform_exclusive_scan() STABLE-NOT
	// stosuje func do kazdego elementu z [first, last)
	// nastepnie wywoluje exclusive_scan()
	// zwraca iterator za ostatni zapisany element w zakresie docelowym
	// funktor nie modyfikuje wartosci val
	transform_exclusive_scan(first, last, first2, val, sumb, func);			// (I, I, O)	iteraotor		sumb func
	transform_exclusive_scan(policy, first, last, first2, val, sumb, func);	// (-, F, F, F)	iterator	sumb func

	// TEST
	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v2 = { 7, 7, 7, 7, 7, 7, 7 };
	vector<int> v3 = { 7, 7, 7, 7, 7, 7, 7 };
	vector<int> v4 = { 7, 7, 7, 7, 7, 7, 7 };
	vector<int> v5 = { 7, 7, 7, 7, 7, 7, 7 };
	vector<int> v6 = { 7, 7, 7, 7, 7, 7, 7 };

	partial_sum(v1.begin(), v1.end(), v2.begin());
	
	inclusive_scan(v1.begin(), v1.end(), v3.begin());
	exclusive_scan(v1.begin(), v1.end(), v4.begin(), 0);

	transform_inclusive_scan(v1.begin(), v1.end(), v5.begin(), sumb, func);
	transform_exclusive_scan(v1.begin(), v1.end(), v6.begin(), 0, sumb, func);

	print(v2);
	print(v3);
	print(v4);
	print(v5);
	print(v6);

	return 0;
}