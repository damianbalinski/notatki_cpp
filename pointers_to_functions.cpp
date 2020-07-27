#include <iostream>
#include <cstdio>

using namespace std;

void func1()
{
	printf("func0 NULL\n");
	return;
}

int func2(int a1)
{
	printf("func1 %d\n", a1);
	return a1;
}

int* func3(int a1, int a2)
{
	printf("func2 %d %d\n", a1, a2);
	return NULL;
}
int main()
{
	// FUNCTION
	func1();
	func2(2);
	func3(3, 3);
	cout << endl;

	// POINTER TO FUNCTION
	void (*pf1)() = func1;
	int (*pf2)(int) = func2;
	int* (*pf3)(int, int) = func3;
	pf1();
	pf2(20);
	pf3(30, 30);
	(*pf1)();
	(*pf2)(20);
	(*pf3)(30, 30);
	cout << endl;

	// POINTER TO POINTER TO FUNCTION
	void (**ppf1)() = &pf1;
	int (**ppf2)(int) = &pf2;
	int* (**ppf3)(int, int) = &pf3;
	(*ppf1)();
	(*ppf2)(200);
	(*ppf3)(300, 300);
	cout << endl;

	// ARRAY OF POINTERS TO FUNCTIONS
	void (*arr1[3])() = { func1, func1, func1 };
	int (*arr2[3])(int) = { func2, func2, func2 };
	int* (*arr3[3])(int, int) = { func3, func3, func3 };
	arr1[2]();
	arr2[2](2000);
	arr3[2](3000, 3000);
	(*(arr1[2]))();
	(*(arr2[2]))(2000);
	(*(arr3[2]))(3000, 3000);
	cout << endl;

	// POINTER TO ARRAY OF POINTERS TO FUNCTIONS
	void(*(*parr1)[3])() = &arr1;
	int (*(*parr2)[3])(int) = &arr2;
	int* (*(*parr3)[3])(int, int) = &arr3;
	(*parr1)[2]();
	(*parr2)[2](20000);
	(*parr3)[2](30000, 30000);

	return 0;
}