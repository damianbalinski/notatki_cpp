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
	int x, y;
	Test2(int x_n, int y_n = 200);
};

class Test3
{
public:
	int x, y, z;
	Test3(int x_n, int y_n = 300, int z_n = 300);
};

Test1::Test1(int x_n)
{
	x = x_n;
}

Test2::Test2(int x_n, int y_n)
{
	x = x_n;
	y = y_n;
}

Test3::Test3(int x_n, int y_n, int z_n)
{
	x = x_n;
	y = y_n;
	z = z_n;
}

int main()
{
	Test1 test1 = 100;
	Test2 test2 = 200;
	Test3 test3 = 300;

	printf("(%d)\n", test1.x);
	printf("(%d,%d)\n", test2.x, test2.y);
	printf("(%d,%d,%d)\n", test3.x, test3.y, test3.z);

	return 0;
}