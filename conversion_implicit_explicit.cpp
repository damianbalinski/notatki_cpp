#include <iostream>
#include <cstdio>

class MyClass1
{
public:
	operator int() const;
	operator double() const;
};

class MyClass2
{
public:
	explicit operator int() const;
	explicit operator double() const;
};

MyClass1::operator int() const { return 10; }
MyClass1::operator double() const { return 9.99; }

MyClass2::operator int() const { return 100; }
MyClass2::operator double() const { return 99.99; }


int main()
{
	MyClass1 a;
	MyClass2 b;

	int i1 = a;
	int i2 = int(a);
	int i3 = (int)a;

	//int j1 = b;			// implicit conversion
	int j2 = int(b);
	int j3 = (int)b;

	double d1 = a;
	double d2 = double(a);
	double d3 = (double)a;

	//double e1 = b;		// implicit conversion
	double e2 = double(b);
	double e3 = (double)b;

	printf("(%d,%d,%d)\n", i1, i2, i3);
	printf("(%d,%d,%d)\n", -1, j2, j3);

	printf("(%f,%f,%f)\n", d1, d2, d3);
	printf("(%f,%f,%f)\n", -1., e2, e3);

	return 0;
}