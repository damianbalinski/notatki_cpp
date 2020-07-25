#include <iostream>

using namespace std;

struct S
{
	int x;
	int y;
	int z = 200;
};

struct T
{
	void test1() { cout << "test1" << endl; };
	void test2() { cout << "test2" << endl; };
};

void print_s(S s)
{
	printf("(%d,%d,%d)\n", s.x, s.y, s.z);
}

int main()
{
	S s1 = { 10, 20, 30 };
	S s2 = { 10, 20 };

	T t1 = {};
	t1.test1();
	t1.test2();

	print_s(s1);
	print_s(s2);

	return 0;
}