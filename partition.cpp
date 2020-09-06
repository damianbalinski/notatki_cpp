#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>

/*
 * PARTYCJE
 */
using namespace std;

bool pred(int a) { return a < 3; }
bool predb(int a, int b) { return true; }
int func(int& a) { return a * 10; }
int funcb(int& a, int& b) { return a + b; }
int gener_rand() { return rand() % 6; }
int gener() { return 9; }

void print(vector<int> vec)
{
	for (auto i : vec) cout << i << ", ";
	cout << endl;
}

int main()
{
	/*
	 * is_partitioned		DONE	DONE	DONE
	 * partition			DONE	DONE	DONE
	 * stable_partition		DONE	DONE	DONE
	 * partition_copy		DONE	DONE	DONE
	 * partition_point		DONE	DONE	DONE
	 */

	// kontenery
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<int> vec2 = { 1, 2, 3, 4, 5 };
	vector<int> vec3 = { 1, 2, 3, 4, 5 };

	// iteratory
	auto first = vec.begin();
	auto last = vec.end();
	auto first2 = vec2.begin();
	auto last2 = vec2.end();
	auto first3 = vec3.begin();
	auto last3 = vec3.end();
	auto iter1 = vec.begin();
	auto iter2 = vec.begin() + 1;

	// dane
	auto policy = std::execution::par;

	// is_partitioned()
	// zwraca true jesli zakres [first, last) jest pusty
	// lub jest podzielony na bazie predykatu pred,
	// wszystkie elementy spelniajace predykat znajduja sie
	// przed wszystkimi elementami nie spelniajacymi predykatu
	is_partitioned(first, last, pred);			// (I, I, 1)	bool
	is_partitioned(policy, first, last, pred);	// (-, F, F, 1)	bool

	// partition()
	// umieszcza wszystkie elementy z [first, last) spelniajace predykat pred
	// przed wszystkimi elementami nie spelniajacymi tego predykatu,
	// zwraca iterator za ostatni element spelniajacy predykat
	partition(first, last, pred);				// (F, F, 1)	iterator
	partition(policy, first, last, pred);		// (-, F, F, 1)	iterator
	
	// stable_partition()
	// umieszcza wszystkie elementy z [first, last) spelniajaca predykat pred
	// przed wszystkimi elementami nie spelniajacymi tego predykatu,
	// zachowuje porzadek obydwu grup elementow
	// zwraca iterator za ostatni element spelniajacy predykat
	stable_partition(first, last, pred);			// (B, B, 1)	iterator
	stable_partition(policy, first, last, pred);	// (-, B, B, 1)	iterator

	// pratition_copy()
	// kopiuje wszystkie elementy z [first, last) spelniajace predykat pred
	// w [first2, ...) oraz wszystkie elementy z [first, last) nie
	// spelniajace tego predykatu w [first3, ...),
	// zwraca pare zlozona z iteratorow za ostatnie kopiowane elemeny
	// z zakresow docelowych [first2, ...) oraz [first3, ...)
	partition_copy(first, last, first2, first2, pred);			// (I, I, O, O, 1)		pair<iterator, iterator>
	partition_copy(policy, first, last, first2, first3, pred);	// (-, F, F, F, F, 1)	pair<iterator, iterator>

	// partition_point()
	// jesli [first, last) jest partycjonowany na bazie predykatu pred,
	// zwraca iterator za ostatni element spelniajacy predykat pred
	// (za ostatni element pierwszej partycji)
	partition_point(first, last, pred);				// (F, F, 1)	iterator

	// TEST
	vector<int> v1 = { 1, 4, 1, 5, 1, 6 };
	vector<int> v2 = { 7, 7, 7, 7 };
	print(v1);
	auto it = partition_point(v1.begin(), v1.end(), pred);
	print(v1);

	cout << *it << endl;

	return 0;
}