#include <iostream>
#define MAX 5

using namespace std;

/*
 * Szablon lepiej wyspecjalizowany dla typow prostych.
 */
template <typename T>
void func(T t)
{
	cout << "func1: ";
	cout << t << endl;
}

/*
 * Szablon lepiej wyspecjalizowany dla typow tablicowych/wskaznikowych.
 */
template <typename T>
void func(T* t)
{
	cout << "func2: ";
	for (int i = 0; i < MAX; i++)
		cout << t[i] << ", ";
	cout << endl;
}

int main()
{
	int val = 10;
	int tab[MAX] = { 1, 2, 3, 4, 5 };

	func(val);
	func(tab);

	return 0;
}