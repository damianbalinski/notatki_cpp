#include <iostream>
#define MAX 5

using namespace std;

/*
 * Szablon lepiej wyspecjalizowany dla typow prostych.
 */
template<typename T>
void func(T t)
{
	cout << "func1: ";
	cout << t << endl;
}

/*
 * Szablon lepiej wyspecjalizowany dla typow tablicowych/wskaznikowych.
 */
template<typename T>
void func(T* t)
{
	cout << "func2: ";
	for (int i = 0; i < MAX; i++)
		cout << t[i] << ", ";
	cout << endl;
}

/*
 * Szablon lepiej wyspecjalizowany dla typow tablicowych/wskaznikowych do staluch
 */
template<typename T>
void func(const T t[])
{
	cout << "func3: ";
	for (int i = 0; i < MAX; i++)
		cout << t[i] << ", ";
	cout << endl;
}
int main()
{
	int val = 10;
	int tab[MAX] = { 1, 2, 3, 4, 5 };
	const int tab2[MAX] = { 5, 4, 3, 2, 1 };

	func(val);
	func(tab);
	func(tab2);

	return 0;
}
