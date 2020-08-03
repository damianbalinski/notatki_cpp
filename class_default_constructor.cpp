#include <iostream>

class Test
{
public:
	Test(int a, int b);
};

Test::Test(int a, int b) {}

int main()
{
	// Test test1 = Test();
	Test test2 = Test(10, 20);
	return 0;
}