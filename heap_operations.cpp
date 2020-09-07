#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
#include <functional>
#include <random>

/*
 * KOPIEC MAKSYMALNY
 */

using namespace std;

bool pred(int a) { return true; }
bool predb(int a, int b) { return a < b; }
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
	 * make_heap		DONE	DONE	DONE
	 * is_heap			DONE	DONE	DONE
	 * is_heap_until	DONE	DONE	DONE
	 * push_heap		DONE	DONE	DONE
	 * pop_heap			DONE	DONE	DONE
	 * sort_heap		DONE	DONE	DONE
	 */

	 // kontenery
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<int> vec2 = { 1, 2, 3, 4, 5 };
	vector<int> vec3 = { 1, 2, 3, 4, 5 };

	// iteratory
	auto first = vec.begin();
	auto last = vec.end();
	auto middle = vec.begin() + 2;
	auto first2 = vec2.begin();
	auto last2 = vec2.end();
	auto first3 = vec3.begin();
	auto last3 = vec3.end();

	// dane
	auto policy = std::execution::par;
	int n = 2;
	int val = 3;

	// make_heap()
	// przeksztalca [first, last) w kopiec maksymalny (rodzic wiekszy od dziecka)
	make_heap(first, last);						// (R, R)		void		<
	make_heap(first, last, predb);				// (R, R)		void		predb (2)

	// is_heap()
	// sprawdza czy [first, last) jest kopcem maksymalnym
	is_heap(first, last);						// (R, R)		bool		<
	is_heap(policy, first, last);				// (-, R, R)	bool		<
	is_heap(first, last, predb);				// (R, R)		bool		predb (2)
	is_heap(policy, first, last, predb);		// (-, R, R)	bool		predb (2)

	// is_heap_until()
	// zwraca iterator iter, taki ze [first, iter) jest najwiekszym
	// mozliwym kopcem maksymalnym
	is_heap_until(first, last);					// (R, R)		iterator	<
	is_heap_until(policy, first, last);			// (-, R, R)	iterator	<
	is_heap_until(first, last, predb);			// (R, R)		iterator	predb (2)
	is_heap_until(policy, first, last, predb);	// (-, R, R)	iterator	predb (2)

	// push_heap() HEAP
	// dodaje element do kopca, 
	// umieszcza w kopcu [first, last-1) element z pozycji last-1
	push_heap(first, last);						// (R, R)		void		<
	push_heap(first, last, predb);				// (R, R)		void		predb (2)

	// pop_heap() HEAP
	// zdejmuje najwiekszy element z kopca
	// zamienia miejscami elementy z pozycji first oraz last-1,
	// przeksztalca [first, last-1) w kopiec maksymalny
	pop_heap(first, last);				// (R, R)	void	<
	pop_heap(first, last, predb);		// (R, R)	void	predb (2)

	// sort_heap() HEAP
	// zamienia kopiec [first, last) na posortowany rosnaco ciag,
	// posortowany ciag przestaje byc kopcem
	//sort_heap(first, last);				// (R, R)	void	<
	//sort_heap(first, last, predb);		// (R, R)	void	predb (2)

	// TEST
	vector<int> v1 = { 1, 2, 3, -1, -2, -3, 30, 31, 7, 8, 9, 11 };
	print(v1);
	cout << is_heap(v1.begin(), v1.end()) << endl;
	make_heap(v1.begin(), v1.end());
	cout << is_heap(v1.begin(), v1.end()) << endl;
	sort_heap(v1.begin(), v1.end());
	cout << is_heap(v1.begin(), v1.end()) << endl;
	print(v1);

	return 0;
}