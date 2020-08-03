#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

const int MAX = 100;
static char buff[MAX];

class MyClass
{
private:
	int x;
	int y;

public:
	MyClass(int x_n = 0, int y_n = 0);
	char* repr();
	MyClass& operator+=(MyClass& obj);
	MyClass& operator-=(MyClass& obj);
	MyClass& operator*=(MyClass& obj);
	MyClass& operator/=(MyClass& obj);
};

MyClass::MyClass(int x_n, int y_n)
{
	x = x_n;
	y = y_n;
}

char* MyClass::repr()
{
	sprintf(buff, "(%d,%d)", x, y);
	return buff;
}

/*
 * Przeciazanie wewnatrz klasy operatora przypisania.
 */
MyClass& MyClass::operator+=(MyClass& obj)
{
	x += obj.x;
	y += obj.y;
	return *this;
}

MyClass& MyClass::operator-=(MyClass& obj)
{
	x -= obj.x;
	y -= obj.y;
	return *this;
}

MyClass& MyClass::operator*=(MyClass& obj)
{
	x *= obj.x;
	y *= obj.y;
	return *this;
}

MyClass& MyClass::operator/=(MyClass& obj)
{
	x /= obj.x;
	y /= obj.y;
	return *this;
}

int main()
{
	MyClass obj1(10, 20);
	MyClass obj2(1, 2);

	MyClass sum1 = obj1;
	MyClass sum2 = obj1;
	MyClass dif1 = obj1;
	MyClass dif2 = obj1;
	MyClass mul1 = obj1;
	MyClass mul2 = obj1;
	MyClass div1 = obj1;
	MyClass div2 = obj1;

	sum1 += obj2;
	sum2.operator+=(obj2);

	dif1 -= obj2;
	dif2.operator-=(obj2);

	mul1 *= obj2;
	mul2.operator*=(obj2);

	div1 /= obj2;
	div2.operator/=(obj2);

	printf("TEST 2\n");
	printf("%s\n", obj1.repr());
	printf("%s\n", obj2.repr());

	printf("sum: %s\n", sum1.repr());
	printf("sum: %s\n", sum2.repr());

	printf("dif: %s\n", dif1.repr());
	printf("dif: %s\n", dif2.repr());

	printf("mul: %s\n", mul1.repr());
	printf("mul: %s\n", mul2.repr());

	printf("div: %s\n", div1.repr());
	printf("div: %s\n", div2.repr());

	return 0;
}