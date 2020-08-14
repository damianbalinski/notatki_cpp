#include <iostream>
#include <cstdio>

template<typename T>
class A {};

template<typename T>
class B : A<T> {};

int main()
{
	B<int> b;
	A<int> a;

	return 0;
}