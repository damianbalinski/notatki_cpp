#include <iostream>

int goo1(int a, int b)
{
	return a;
}

const int goo11(int a, int b)
{
	return a;
}

int* goo2(int* a, int* b)
{
	return a;
}

const int* goo22(int* a, int* b)
{
	return a;
}

int& goo3(int& a, int& b)
{
	return a;
}

const int& goo33(const int& a, int& b)
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
	int& z = goo3(a, b);

	int x2 = goo11(a, b);
	const int* y2 = goo22(&a, &b);
	const int& z = goo33(a, b);

	cout << x << endl;
	cout << *y << endl;
	cout << z << endl;

	//goo1(a, b) = 20;
	*goo2(&a, &b) = 20;
	goo3(a, b) = 20;
	//goo11(a, b) = 20;
	//*goo22(&a, &b) = 20;
	//goo33(a, b) = 20;

	return 0;
}