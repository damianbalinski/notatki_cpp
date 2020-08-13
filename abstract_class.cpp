#include <iostream>

class Test1
{
public:
	virtual void test() = 0;
	virtual ~Test1() = 0;
};

class Test2 : public Test1
{
public:
	virtual void test();
};

void Test1::test()
{
	std::cout << "test1" << std::endl;
}

void Test2::test()
{
	std::cout << "test2" << std::endl;
}

Test1::~Test1() {}

int main()
{
	//Test test;
	Test2 test2;

	Test1* p1 = &test2;
	Test2* p2 = &test2;

	Test1& r1 = test2;
	Test2& r2 = test2;

	return 0;
}