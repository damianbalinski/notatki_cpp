#include <cstdio>

/*
 * Rozpoznawanie funkcji umozliwia przeciazenie 
 * funkcj z parametrami:
 * -wskaznik do zmiennej
 * -wskaznik do stalej
 * Nie rozpoznawane sa stale lub zmienne niebed-
 * ace wskaznikami
 */
void foo(char* str)			{ printf("foo1\n"); }
void foo(const char* str)	{ printf("foo2\n"); }

void goo(int* a)			{ printf("goo1\n"); }
void goo(const int* a)		{ printf("goo2\n"); }

// ERROR
// void hoo(int a)				{ printf("hoo1\n"); }
// void hoo(const int a)		{ printf("hoo2\n"); }

int main()
{
	char str1[] = "abc";
	const char str2[] = "abc";

	int* ptr1 = NULL;
	const int* ptr2 = NULL;

	int val1 = 10;
	const int val2 = 10;

	foo(str1);
	foo(str2);

	goo(ptr1);
	goo(ptr2);

	//hoo(val1);
	//hoo(val2);

	return 0;
}