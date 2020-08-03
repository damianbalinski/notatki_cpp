#include <iostream>
#define MAX 100

class Test
{
public:
	int val;

public:
	void setVal(int newVal);
	int getVal();
};

void Test::setVal(int newVal)
{
	val = newVal;
}

int Test::getVal()
{
	return val;
}

int main()
{
	using std::cout, std::endl;

	Test test1, test2;
	test1.setVal(10);
	test2.setVal(20);

	cout << test1.getVal() << endl;
	cout << test2.getVal() << endl;
	cout << endl;

	cout << &test1.val << endl;
	cout << &test2.val << endl;
	//cout << test1.getVal << endl;
	//cout << test2.getVal << endl;

	return 0;
}