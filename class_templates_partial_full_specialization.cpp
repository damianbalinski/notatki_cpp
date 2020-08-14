#include <cstdio>
#include <cstdio>

template<typename T, typename U>
class A {};

template<typename T>
class A<T, int>{};

template<>
class A<int, int> {};

int main()
{
	return 0;
}