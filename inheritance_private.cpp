#include <iostream>

class Test1
{
public:
	int x;
	void foo() { printf("test1\n"); };
};

class Test2 : private Test1
{
public:
	using Test1::foo;
	//Test1::foo;
};
int main()
{
	Test1 test1;
	Test2 test2;

	test2.foo();

	return 0;
}