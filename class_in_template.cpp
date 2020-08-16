#include <iostream>
#include <cstdio>

template<class T>
class A
{
public:
	class B;
};

template<typename T>
class A<T>::B
{
public:
	void func();
};

template<typename T>
void A<T>::B::func()
{
	printf("class in template\n");
}

int main()
{
	A<int> a;
	A<int>::B b;
	b.func();

	return 0;
}
