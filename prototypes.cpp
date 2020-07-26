#include <iostream>

int foo1(int* tab, int n);
int foo2(int tab[], int n);
int foo3(int tab[5], int n);


int main()
{
	using namespace std;

	int tab[] = { 1, 2, 3 };
	int n = 3;

	cout << foo1(tab, n) << endl;
	cout << foo2(tab, n) << endl;
	cout << foo3(tab, n) << endl;

	return 0;
}

int foo1(int* tab, int n) { return 1; };
int foo2(int tab[], int n) { return 2; };
int foo3(int tab[5], int n) { return 3; };