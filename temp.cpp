// #include <cmath>
// #include <climits>
// #include <cfloat>
#include <iostream>

using namespace std;

int foo1(int* tab, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " = " << *tab++ << endl;
	}
}

int foo2(int tab[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " = " << *tab++ << endl;
	}
}

int main()
{
	EOF;
	true;
	false;
	int* ptr = NULL;

	int tab[] = { 1, 2, 3 };
	int n = 3;
	foo1(tab, n);
	foo2(tab, n);

	const int val = 100;
	const int* p1 = &val;
	//int* p2 = &val;		// ERROR


	return 0;
}