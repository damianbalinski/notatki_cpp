#include <iostream>
#include <cstdio>

void foo(int& a)		{ printf("foo1\n"); }
void foo(const int& a)	{ printf("foo2\n"); }
void foo(int&& a)		{ printf("foo3\n"); }

void goo(int& a)		{ printf("goo1\n"); }
void goo(const int& a)	{ printf("goo2\n"); }

void hoo(const int& a)	{ printf("hoo1\n"); }
void hoo(int&& a)		{ printf("hoo2\n"); }

void koo(int& a)		{ printf("koo1\n"); }
void koo(int&& a)		{ printf("koo3\n"); }

int main()
{
	int a = 10;
	const int b = 10;

	foo(a);
	foo(b);
	foo(a + b);
	putchar('\n');

	goo(a);
	goo(b);
	goo(a + b);
	putchar('\n');

	hoo(a);
	hoo(b);
	hoo(a + b);
	putchar('\n');

	koo(a);
	//koo(b);	// ERROR
	koo(a+b);
	putchar('\n');

	return 0;
}