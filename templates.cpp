#include <iostream>
#include <cstdio>

using namespace std;

template<typename T>
void foo(T t)
{
	cout << t << " : " << typeid(T).name() << endl;
}

int main()
{
	int* ptr = NULL;

	foo('A');
	foo((short)10);
	foo(10);
	foo(10L);
	foo(10LL);
	putchar('\n');

	foo((signed char)'A');
	putchar('\n');

	foo((unsigned char)'A');
	foo((unsigned short)10);
	foo(10U);
	foo(10UL);
	foo(10ULL);
	putchar('\n');

	foo(10.0F);
	foo(10.0);
	foo(10.0L);
	putchar('\n');
	
	foo("abcdef");
	foo(ptr);

	return 0;
}