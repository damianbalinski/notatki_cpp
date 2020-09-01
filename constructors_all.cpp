// konstruktory zdefiniowane dla kontenerow
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main()
{
	// data
	int a = 1;
	int n = 5;
	int tab[] = { 1, 2, 3, 4, 5 };
	int* iter1 = tab;
	int* iter2 = tab + 4;
	auto list = { 1, 2, 3, 4, 5 };

	// wszystkie (all)
	std::vector<int> v1;			// domyslny, pusty kontener
	std::vector<int>;				// domyslny, pusty kontener anonimowy
	std::vector<int> v2(v1);		// kopiujacy
	std::vector<int>{v1};			// TODO error kopiujacy anonimowy
	std::vector<int> v3 = v1;		// kopiujacy
	std::vector<int> v4(std::vector<int>{});	// przenoszacy
	std::vector<int> v5 = std::vector<int>();	// przenoszacy

	// sekwencyjne oprocz array (sequence other than array)
	std::vector<int> w1(n ,a);			// n kopii elementu a
	std::vector<int>(n, a);				// n kopii elementu a, anonimowy
	std::vector<int>(iter1, iter2);		// z zakresu [iter1, iter2)
	std::vector<int> w2(iter1, iter2);	// z zakresu [iter1, iter2), anonimowy
	std::vector<int> w3(list);			// z listy inicjalizujacej
	std::vector<int> (list);			// z listy inicjalizujacej, anonimowy

	return 0;
}