#include <iostream>
#include <cstdio>

template<typename T>
class A
{
public:
	template<typename U>
	class B;
};

template<typename T>
	template<typename U>
	class A<T>::B
	{
	public:
		void func();
	};

template<typename T>
	template<typename U>
	void A<T>::B<U>::func()
	{
		printf("template in template\n");
	}

int main()
{
	A<int> a;
	A<int>::B<int> b;
	b.func();

	return 0;
}