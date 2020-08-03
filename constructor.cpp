#include <iostream>
#include <cstdio>

class Test
{
private:
	int val1;
	int val2;

public:
	Test(int val1, int val2);
	void print();
};

Test::Test(int newVal1, int newVal2)
{
	val1 = newVal1;
	val2 = newVal2;
}

void Test::print()
{
	printf("(%d,%d)\n", val1, val2);
}

int main()
{
	Test test1(10, 20);
	Test test2 = Test(-10, -20);
	test1.print();

	return 0;
}