#include <iostream>

class A
{
public:
	template<typename T>
	class B;
};

template<typename T>
class A::B
{
public:
	void func();
};

template<typename T>
void A::B<T>::func()
{
	printf("template in class");
}

int main()
{
	A a;
	A::B<int> b;
	b.func();
	return 0;
}