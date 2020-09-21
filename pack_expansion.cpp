#include <iostream>

/*
 * ROZPAKOWYWANIE PAKIETU
 *
 * PARAMETRY SZABLONU
 * Args...		int E1, double E2, char E3
 * <Args,Args>...
 *
 * PARAMETRY FUNKCJI
 * args...		E1, E2, E3
 * &args...		&E1, &E2, &E3
 * *args...		*E1, *E2, *E3
 * ++args...	++E1, ++E2, ++E3
 * args++...	E1++, E2++, E3++
 * n * args...	n*E1, n*E2, n*E3
 * args..., n	E1, E2, E3, n
 * n, args...	n, E1, E2, E3
 * args..., args...			E1, E2, E3, E1, E2, E3
 * h(args...) * args...		h(E1,E2,E3)*E1, h(E1,E2,E3)*E2, h(E1,E2,E3)*E3
 * args(n)					E1(n), E2(n), E3(n)
 */

int h(int v1, int v2, int v3)
{
	return 100;
}

template<class T, class... Args>
void goo(T t, Args... args);

using namespace std;

void foo() {}
void goo() {}


template<class... Args>
void foo(Args... args)
{
	goo(args(10)...);
}

template<class T, class... Args>
void goo(T t, Args... args)
{
	cout << t << ", ";
	goo(args...);
}

int temp(int val) { return 10; };

int main()
{
	//foo(1, 2, 3);

	foo(temp, temp, temp);

	return 0;
}