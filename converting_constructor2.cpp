#include <iostream>
#include <cstdio>

class Test1
{
public:
	int x;
	Test1(int x_n);
};

class Test2
{
public:
	int x;
	explicit Test2(int x_n);
};

Test1::Test1(int x_n)
{
	x = x_n;
}

Test2::Test2(int x_n)
{
	x = x_n;
}

void show1(Test1 t)
{
	printf("test1 %d\n", t.x);
}

void show2(Test2 t)
{
	printf("test2 %d\n", t.x);
}

int main()
{
	Test1 a1 = 10;
	Test1 a2(10);
	Test1 a3 = Test1(10);

	//Test2 b1 = 20;
	Test2 b2(20);
	Test2 b3 = Test2(20);

	show1(a1);
	//show1(10);

	show2(b2);
	//show2(20);

	return 0;
}