#include <iostream>

using std::cout;
using std::endl;

class Test
{
private:
	int x;
	int y;

public:
	Test();
	//Test(int x = 10);
	Test(int x, int y);
};

Test::Test()
{
	cout << "konstruktor 1" << endl;
	x = 1;
	y = 1;
}

//Test::Test(int x_new = 10)
//{
//	cout << "konstruktor 2" << endl;
//	x = x_new;
//	y = 10;
//}

Test::Test(int x_new, int y_new)
{
	cout << "konstruktor 3" << endl;
	x = x_new;
	y = y_new;
}

int main()
{
	Test test1 = Test();
	//Test test2 = Test(10);
	Test test3 = Test(100, 200);

	return 0;
}