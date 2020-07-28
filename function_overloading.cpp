#include <cstdio>

void foo()				{ printf("DEFAULT\n"); }
void foo(char a)		{ printf("foo1\n"); }
void foo(short a)		{ printf("foo2\n"); }
void foo(int a)			{ printf("foo3\n"); }
void foo(long a)		{ printf("foo4\n"); }
void foo(long long a)	{ printf("foo5\n"); }
void foo(float a)		{ printf("foo6\n"); }
void foo(double a)		{ printf("foo7\n"); }
void foo(long double a)	{ printf("foo8\n"); }


int main()
{
	foo();
	foo('A');
	foo((short)10);
	foo(10);
	foo(10L);
	foo(10LL);
	foo(10.0F);
	foo(10.0);
	foo(10.0L);

	// ERROR - brak jednoznacznej definicji
	// foo(10U);

	return 0;
}