#include <iostream>
#include <cstdio>

template<typename T>
class A {};

template<typename T>
class A<T*> {};

template<typename T>
class A<const T*> {};

int main()
{
	return 0;
}