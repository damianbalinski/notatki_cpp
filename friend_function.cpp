#include <iostream>

class Test
{
private:
	int x;
//public:
public:
	void func1();
	friend void func2(Test& obj);
	friend void func3(Test& obj) { obj.x = 30; };
};

void Test::func1()
{
	x = 10;
}

void func2(Test& obj)
{
	obj.x = 20;
}

int main()
{
	using namespace std;

	Test t;
	func2(t);
	func3(t);
	t.func1();
	return 0;
}