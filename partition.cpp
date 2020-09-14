#include <iostream>
//#include <algorithm>
#include <vector>
#include <execution>

/*
 * PARTYCJE
 */
using namespace std;

bool pred(int a) { return a < 3; }

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
	// sprawdza czy zakres [first, last) jest podzielony na bazie 
	// predykatu pred lub jest zakresem pustym
	// wszystkie elementy spelniajace predykat znajduja sie
	// przed wszystkimi elementami nie spelniajacymi predykatu
	is_partitioned(first, last, pred);			// (I, I, 1)	bool
	is_partitioned(policy, first, last, pred);	// (-, F, F, 1)	bool

	// partition()
	// umieszcza wszystkie elementy z [first, last) spelniajace predykat pred
	// przed wszystkimi elementami nie spelniajacymi predykatu,
	// zwraca iterator za ostatni element spelniajacy predykat
	// (za ostatni element pierwszej partycji)
	partition(first, last, pred);				// (F, F, 1)	iterator
	partition(policy, first, last, pred);		// (-, F, F, 1)	iterator
	
	// stable_partition() STABLE
	// umieszcza wszystkie elementy z [first, last) spelniajaca predykat pred
	// przed wszystkimi elementami nie spelniajacymi predykatu,
	// zachowuje porzadek obydwu grup elementow
	// zwraca iterator za ostatni element spelniajacy predykat
	// (za ostatni element pierwszej partycji)
	stable_partition(first, last, pred);			// (B, B, 1)	iterator
	stable_partition(policy, first, last, pred);	// (-, B, B, 1)	iterator

	// pratition_copy()
	// kopiuje wszystkie elementy z [first, last) spelniajace predykat pred
	// w [first2, ...) oraz wszystkie elementy nie
	// spelniajace predykatu w [first3, ...),
	// zwraca pare zlozona z iteratorow za ostatnie kopiowane elemeny
	// z zakresow docelowych
	partition_copy(first, last, first2, first3, pred);			// (I, I, O, O, 1)		pair<iterator, iterator>
	partition_copy(policy, first, last, first2, first3, pred);	// (-, F, F, F, F, 1)	pair<iterator, iterator>

	// partition_point() PARTITION
	// zwraca iterator za ostatni element spelniajacy predykat pred
	// (za ostatni element pierwszej partycji)
	partition_point(first, last, pred);				// (F, F, 1)	iterator

	// TEST
	//vector<int> v1 = { 1, 4, 1, 5, 1, 6 };
	//vector<int> v2 = { 7, 7, 7, 7 };
	//print(v1);
	//auto it = partition_point(v1.begin(), v1.end(), pred);
	//print(v1);

	//cout << *it << endl;

	return 0;
}