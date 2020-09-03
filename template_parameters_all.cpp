#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <span>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

int main()
{
	// dane
	const int NUM = 10;
	typedef int Type;
	typedef int Key;
	typedef std::hash<int> Hash;
	typedef std::allocator<int> Alloc;
	typedef std::less<int> Comp;
	typedef std::equal_to<int> Equal;
	typedef std::vector<int> Cont;

	// 1
	std::array<Type, NUM>;

	// 2
	std::vector<Type>;
	std::vector<Type, Alloc>;

	// 3
	std::deque<Type>;
	std::deque<Type, Alloc>;

	// 4
	std::list<Type>;
	std::list<Type, Alloc>;

	// 5
	std::forward_list<Type>;
	std::forward_list<Type, Alloc>;
	
	// 6
	std::span<Type>;
	std::span<Type, NUM>;

	// 7
	std::set<Type>;
	std::set<Type, Comp>;
	std::set<Type, Comp, Alloc>;

	// 8
	std::multiset<Type>;
	std::multiset<Type, Comp>;
	std::multiset<Type, Comp, Alloc>;

	// 9
	std::map<Key, Type>;
	std::map<Key, Type, Comp>;
	std::map<Key, Type, Comp, Alloc>;

	// 10
	std::multimap<Key, Type>;
	std::multimap<Key, Type, Comp>;
	std::multimap<Key, Type, Comp, Alloc>;
	
	// 11
	std::unordered_set<Type>;
	std::unordered_set<Type, Hash>;
	std::unordered_set<Type, Hash, Equal>;
	std::unordered_set<Type, Hash, Equal, Alloc>;
	
	// 12
	std::unordered_multiset<Type>;
	std::unordered_multiset<Type, Hash>;
	std::unordered_multiset<Type, Hash, Equal>;
	std::unordered_multiset<Type, Hash, Equal, Alloc>;

	// 13
	std::unordered_map<Key, Type>;
	std::unordered_map<Key, Type, Hash>;
	std::unordered_map<Key, Type, Hash, Equal>;
	std::unordered_map<Key, Type, Hash, Equal, Alloc>;

	// 14
	std::unordered_multimap<Key, Type>;
	std::unordered_multimap<Key, Type, Hash>;
	std::unordered_multimap<Key, Type, Hash, Equal>;
	std::unordered_multimap<Key, Type, Hash, Equal, Alloc>;

	// 15
	std::stack<Type>;
	std::stack<Type, Cont>;

	// 16
	std::queue<Type>;
	std::queue<Type, Cont>;

	// 17
	std::priority_queue<Type>;
	std::priority_queue<Type, Cont>;
	std::priority_queue<Type, Cont, Comp>;
	
	/* OPIS
	 * NUM - stala calkowita
	 * Type - wartosc
	 * Key - klucz
	 * Alloc - alokator
	 * Cont - kontener
	 * Comp - porownujacy obiekt funkcyjny
	 * Equal - sprawdzajacy rownosc obiekt funkcyjny
	 * Hash - haszujacy obiekt funkcyjny
	 */

	return 0;
}