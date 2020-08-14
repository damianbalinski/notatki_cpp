#include <iostream>
#include <cstdio>

template<typename T = int>
class A
{
public:
	T t;
public:
	A()
	{
		printf("(1)\n");
		this->t = NULL;
	}

	A(T t)
	{
		printf("(2)\n");
		this->t = t;
	}
};
int main()
{
	using std::cout, std::endl;

	A a1 = A(10);
	A<int> a2 = A(10);
	A a3 = A();
	A<A<int> > a4 = A< A<int>>();

	A a5("xyz");

	cout << a1.t << endl;
	cout << a2.t << endl;
	cout << a3.t << endl;
	//cout << a4.t << endl;
	cout << a5.t << endl;

	return 0;
}