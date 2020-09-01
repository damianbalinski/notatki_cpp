// operatory zdefiniowane dla kontenerow
#include <iostream>
#include <vector>

int main()
{
	// kontenery
	std::vector<int> v1;
	std::vector<int> v2;

	// dane
	int n = 0;
	auto list = { 1, 2, 3, 4, 5 };
	auto args = { 1, 2, 3, 4, 5 };

	// wszystkie (all)
	v2 = v1;					// przypisanie
	v2 = std::vector<int>();	// przypisanie rwartosciowe
	v1 == v2;					// true, jesli dwa kontenery sa tego samego rozmiaru i zawieraja takie same elemtny w tej samej kolejnosci
	v1 != v2;					// true, jesli dwa kontenery sa rozne
	
	// wszystkie poza unordered_map, unordered_set
	v1 < v2;					// mniejszy leksykograficznie
	v1 <= v2;					// mniejszy/rowny leksykograficznie
	v1 > v2;					// wiekszy leksykograficznie
	v1 >= v2;					// wiekszy/rowny leksykograficznie
	
	// sekwencyjne oprocz array (sequence other than array)
	v1 = list;					// przypisanie listy inicjalizujacej
	
	// vector, deque, array
	v1[n];						// referencja do elementu o podanym indeksie, NIE sprawdza poprawnosc indeksowania

	return 0;
}