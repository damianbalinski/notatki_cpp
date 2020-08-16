#include <iostream>
#include <cstdio>

class A;
class B;

class A
{
private:
	int a;
public:
	A(int a = -1) : a(a) {}
	void funcA(B b);
	friend void B::funcB(A a);
};

class B
{
private:
	int b;
public:
	B(int b = -1) : b(b) {}
	void funcB(A a);
	friend void A::funcA(B b);
};

void A::funcA(B b)
{
	printf("funcA: %d\n", b.b);
}

//void B::funcB(A a)
//{
//	printf("funcB: %d\n", a.a);
//}

int main()
{
	return 0;
}