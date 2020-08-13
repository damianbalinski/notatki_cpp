#include <iostream>

class Base 
{
public:
	void hello() { printf("hello\n"); }
};

class Test1 : public Base {};

class Test2 : public Base {};

class Test : public Test1, public Test2 {};

int main()
{
	Test test;

	// PRZYPISANIE - niejednoznacznosc klasy bazowej
	Base b1 = (Test1)test;
	Base b2 = (Test2)test;

	Base* b3 = (Test1*)&test;
	Base* b4 = (Test2*)&test;

	Base& b5 = (Test1&)test;
	Base& b6 = (Test2&)test;

	// WYWOLANIE METODY - niejednoznacznosc metody
	((Test1)test).hello();
	((Test2)test).hello();

	test.Test1::hello();
	test.Test2::hello();
}