#include <iostream>

using std::cout;
using std::endl;

void func(int a = 10)
{
	cout << "func1" << endl;
}

void func(int a = 20, int b = 20)
{
	cout << "func2" << endl;
}

int main()
{	
	// ERROR - ambigious calling
	// func();

	return 0;
}