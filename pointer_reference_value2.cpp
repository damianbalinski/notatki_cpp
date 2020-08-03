#include <iostream>

int goo1(int a, int b)
{
	return a;
}

int* goo2(int* a, int* b)
{
	return a;
}

int& goo3(int& a, int& b)
{
	return a;
}

int main()
{
	using std::cout, std::endl;

	int a = 10;
	int b = 20;

	int x = goo1(a, b);
	int* y = goo2(&a, &b);
	int z = goo3(a, b);

	cout << x << endl;
	cout << *y << endl;
	cout << z << endl;

	//goo1(a, b) = 20;
	*goo2(&a, &b) = 20;
	goo3(a, b) = 20;

	return 0;
}