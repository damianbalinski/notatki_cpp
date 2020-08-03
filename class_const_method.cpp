#include <iostream>

class TestA
{
public:
	void test();
};

class TestB
{
public:
	void test() const;
};

void TestA::test() {}
void TestB::test() const {}

int main()
{
	TestA test1;
	const TestA test2;

	TestB test3;
	const TestB test4;

	test1.test();
	// test2.test();	// ERROR
	test3.test();
	test4.test();

	return 0;
}