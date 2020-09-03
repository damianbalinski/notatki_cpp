// konstruktory zdefiniowane dla kontenerow
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>

using std::cout;
using std::endl;

int main()
{
	/*
	 * OZNACZENIA
	 * A array			DONE
	 * V vector			DONE
	 * D deque			DONE
	 * L list			DONE
	 * F forward list	DONE
	 * Sp span			DONE
	 *
	 * s set			DONE
	 * S multiset		DONE
	 * m map			DONE
	 * M multimap		DONE
	 *
	 * us unordered_set			DONE
	 * uS unordered_multiset	DONE
	 * um unordered_map			DONE
	 * uM unordered_multimap	DONE
	 *
	 * St stack					DONE
	 * Q queue					DONE
	 * P priority_queue
	 * - all
	 */

	// kontenery
	std::set<int> set = { 1, 2, 3, 4, 5 };
	std::vector<int> vector;
	std::vector<int> rvector;
	std::array<int, 10> array;
	std::allocator<int> alloc;

	// dane
	int val = 1;
	int n = 5;
	int tab[] = { 1, 2, 3, 4, 5 };
	auto list = { 1, 2, 3, 4, 5 };
	int* iter1 = tab;
	int* iter2 = tab + 4;
	auto comp = std::less<int>();
	auto equal = std::equal_to<int>();
	auto hash = std::hash<int>();
	const std::deque<int> cont;
	const std::deque<int> rcont;
	const std::vector<int> cont2;
	const std::vector<int> rcont2;
	std::stack<int> stack;

	// wszystkie (all)
	std::vector<int> v1;				// [St Q P sSmM us uS um uM AVDLF] domyslny, pusty kontener
	std::vector<int> v2(alloc);			// [St Q P sSmM us uS um uM VDLF] domyslny, pusty kontener
	std::vector<int> v3(vector);		// [St Q P sSmM us uS um uM AVDLF] kopiujacy
	std::vector<int> v4(vector, alloc);	// [St Q P sSmM us uS um uM VDLF] kopiujacy
	std::vector<int> v5(rvector);		// [St Q P sSmM us uS um uM AVDLF] przenoszacy
	std::vector<int> v6(rvector, alloc);// [St Q P sSmM us uS um uM VDLF] przenoszacy

	// sekwencyjne oprocz array (sequence other than array)
	std::vector<int> w1(n ,val);				// [VDLF] n kopii elementu a
	std::vector<int> w2(n, val, alloc);			// [VDLF] n kopii elementu a
	std::vector<int> w3(n);						// [VDLF] zaalokowane n elementow
	std::vector<int> w4(n, alloc);				// [VDLF] zaalokowane n elementow
	std::vector<int> w5(iter1, iter2);			// [VDLF] z zakresu [iter1, iter2)
	std::vector<int> w6(iter1, iter2, alloc);	// [VDLF] z zakresu [iter1, iter2)
	std::vector<int> w7(list);					// [VDLF] z listy inicjalizujacej
	std::vector<int> w8(list, alloc);			// [VDLF] z listy inicjalizujacej

	// asocjacyjne uporzadkowane
	std::set<int> s1(comp);						// [sSmM] z predykatem binarnym comp
	std::set<int> s2(comp, alloc);				// [sSmM] z predykatem binarnym comp
	std::set<int> s3(iter1, iter2);				// [sSmM] z zakresu [iter1, iter2)
	std::set<int> s4(iter1, iter2, alloc);		// [sSmM]
	std::set<int> s5(iter1, iter2, comp);		// [sSmM]
	std::set<int> s6(iter1, iter2, comp, alloc);// [sSmM]
	std::set<int> s7(list);						// [sSmM] z listy inicjalizujacej
	std::set<int> s8(list, alloc);				// [sSmM] z listy inicjalizujacej
	std::set<int> s8(list, comp);				// [sSmM] z listy inicjalizujacej
	std::set<int> s9(list, comp, alloc);		// [sSmM] z listy inicjalizujacej
	
	// asocjacyjne nieuporzadkowane
	std::unordered_set<int> q2(n);						// [us uS um uM] n kubelkow
	std::unordered_set<int> q2(n, hash);				// [us uS um uM] n kubelkow
	std::unordered_set<int> q2(n, hash, equal);			// [us uS um uM] n kubelkow
	std::unordered_set<int> q2(n, hash, equal, alloc);	// [us uS um uM] n kubelkow
	std::unordered_set<int> q3(n, hash, alloc);			// [us uS um uM]
	std::unordered_set<int> q3(n, alloc);				// [us uS um uM]

	std::unordered_set<int> q3(iter1, iter2);							// [us uS um uM]
	std::unordered_set<int> q3(iter1, iter2, n);						// [us uS um uM]
	std::unordered_set<int> q3(iter1, iter2, n, hash);					// [us uS um uM]
	std::unordered_set<int> q3(iter1, iter2, n, hash, equal);			// [us uS um uM]
	std::unordered_set<int> q3(iter1, iter2, n, hash, equal, alloc);	// [us uS um uM]
	std::unordered_set<int> q3(iter1, iter2, n, hash, alloc);			// [us uS um uM]
	std::unordered_set<int> q3(iter1, iter2, n, alloc);					// [us uS um uM]

	std::unordered_set<int> q3(list);							// [us uS um uM]
	std::unordered_set<int> q3(list, n);						// [us uS um uM]
	std::unordered_set<int> q3(list, n, hash);					// [us uS um uM]
	std::unordered_set<int> q3(list, n, hash, equal);			// [us uS um uM]
	std::unordered_set<int> q3(list, n, hash, equal, alloc);	// [us uS um uM]
	std::unordered_set<int> q3(list, n, hash, alloc);			// [us uS um uM]
	std::unordered_set<int> q3(list, n, alloc);					// [us uS um uM]
	
	// wszystkie adaptatory
	std::stack<int> t(cont);			// [St Q]
	std::stack<int> t(cont, alloc);		// [St Q]
	std::stack<int> t(rcont);			// [St Q]
	std::stack<int> t(rcont, alloc);	// [St Q]

	// kolejka priorytetowa
	std::priority_queue<int> p(comp);						// [P]
	std::priority_queue<int> p(comp, alloc);				// [P]
	std::priority_queue<int> p(comp, cont2);				// [P]
	std::priority_queue<int> p(comp, cont2, alloc);			// [P]
	std::priority_queue<int> p(comp, rcont2);				// [P]
	std::priority_queue<int> p(comp, rcont2, alloc);		// [P]
	std::priority_queue<int> p(iter1, iter2);				// [P]
	std::priority_queue<int> p(iter1, iter2, comp);			// [P]
	std::priority_queue<int> p(iter1, iter2, comp, cont2);	// [P]
	std::priority_queue<int> p(iter1, iter2, comp, rcont2);	// [P]

	 /* OPIS
	 * n - rozmiar
	 * val - wartosc
	 * alloc - alokator
	 * vector - obiekt vector
	 * rvector - rwartosciowy obiekt vector
	 * cont - obiekt kontenerowy
	 * rcont - rwartosciowy obiekt konternerowy
	 * iter1, iter2 - iteratory
	 * list - lista inicjalizujaca
	 * comp - porownujacy obiekt fukcyjny
	 * equal - sprawdzajacy rownosc obietk funkcyjny
	 * hash - haszujacy obiekt funkcyjny
	 */

	return 0;
}