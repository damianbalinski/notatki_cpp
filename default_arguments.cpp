// PARAMETRY DOMYSLNE FUNKCJI
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
void func5(int a, int b);
void func5(int a, int b = 20);
void func5(int a = 30, int b);		// ok, parametr domyslny dla b zadeklarowany wczesniej

// void func5(int = 10, int=20);
void func5(int a, int b)
{
	printf("fucn 5 [%d,%d]\n", a, b);
}

int main()
{
	func(10);
	func(10, 20);
	func(10, 20, 30);

	func5(-10);

	return 0;
}