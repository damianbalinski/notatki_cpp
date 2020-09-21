#include <iostream>

/*
 * sizeof...
 * liczba elementow w pakiecie parametrow
 */

using namespace std;

template<typename... Args>
void goo(Args... args)
{
	cout << sizeof...(args) << endl;
}

void hoo() {}

template<typename T, typename... Args>
void hoo(T t, Args... args)
{
	cout << t << ", ";
	hoo(args...);
}

template<typename... Args>
void foo(Args... args)
{
	hoo(args..., args...);
}


int main()
{
	foo(10, 20, 30, 40);

	return 0;
}