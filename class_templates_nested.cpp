#include <iostream>
#include <cstdio>

template<typename T>
class A
{
public:
	void func1(T t);

	class B;
	
	template<typename U>
	void func2(T t, U u);

	template<typename U>
	class C;
};

template<typename T>
void A<T>::func1(T t)
{
	printf("func1\n");
}

template<typename T>
	template<typename U>
		void A<T>::func2(T t, U u)
		{
			printf("func2\n");
		}

template<typename T>
class A<T>::B
{
};

template<typename T>
	template<typename U>
	class A<T>::C
	{
	};

int main()
{
	return 0;
}