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
	void print();
	char* repr();
	MyClass operator+(MyClass& obj) const;
	MyClass operator-(MyClass& obj) const;
	MyClass operator*(MyClass& obj) const;
	MyClass operator/(MyClass& obj) const;
};



/*
 * Przeciazanie wewnatrz klasy operatora arytmetycznego.
 * Jedyny przypadek, gdzie w nazwie metody moze wystapic 
 * znak niealfanumeryczny.
 */
MyClass MyClass::operator+(MyClass& obj) const
{
	MyClass temp;
	temp.x = x + obj.x;
	temp.y = y + obj.y;
	return temp;
}

MyClass MyClass::operator-(MyClass& obj) const
{
	MyClass temp;
	temp.x = x - obj.x;
	temp.y = y - obj.y;
	return temp;
}

MyClass MyClass::operator*(MyClass& obj) const
{
	MyClass temp;
	temp.x = x * obj.x;
	temp.y = y * obj.y;
	return temp;,
}

MyClass MyClass::operator/(MyClass& obj) const
{
	MyClass temp;
	temp.x = x / obj.x;
	temp.y = y / obj.y;
	return temp;
}

void MyClass::print()
{
	printf("(%d,%d)\n", x, y);
}

char* MyClass::repr()
{
	sprintf(buff, "(%d,%d)", x, y);
	return buff;
}

int main()
{
	MyClass obj1(10, 20);
	MyClass obj2(1, 2);
	MyClass sum1;
	MyClass sum2;
	MyClass dif1;
	MyClass dif2;
	MyClass mul1;
	MyClass mul2;
	MyClass div1;
	MyClass div2;

	sum1 = obj1 + obj2;
	sum2 = obj1.operator+(obj2);

	dif1 = obj1 - obj2;
	dif2 = obj1.operator-(obj2);

	mul1 = obj1 * obj2;
	mul2 = obj1.operator*(obj2);

	div1 = obj1 / obj2;
	div2 = obj1.operator*(obj2);

	printf("TEST 1\n");
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