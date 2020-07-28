#include <iostream>
#include <cstdio>

/*
 * Parametry domyslne musza wystepowac za parametrami
 * niedomyslnymi. Argumenty sa przypisywane parametrom
 * od lewej do prawej.
 */
void func(int x, int y = 2, int z = 3)
{
	printf("(%d,%d,%d)\n", x, y, z);
}

void func2(int a, int = -1);
void func2(int a, int b)
{
	printf("a=%d  b=%d\n", a, b);
}

void func3(int a, int b);
void func3(int a, int b = -1)
{
	printf("a=%d  b=%d\n", a, b);
}

/*
 * Elipsa nie jest parametrem formalnym, dlatego moze
 * wystapic za parametrem domylsmym.
 */
int func4(int a, int b = -100, ...);


/*
 * Nie mozna pononie deklarowac parametru domyslnego dla funkcji
 * tego samego zasiegu, nawet jezeli parametr ten jest taki sam 
 * jak poprzedni.
 */
void func5(int, int);
void func5(int, int = 20);
// void func5(int = 10, int=20);
void func5(int a, int b)
{
	printf("[%d,%d]\n", a, b);
}

int main()
{
	func(10);
	func(10, 20);
	func(10, 20, 30);

	func2(10);
	func2(10, 20);

	func3(10);
	func3(10, 20);

	func5(-10);

	return 0;
}