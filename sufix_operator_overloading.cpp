#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

const int MAX = 100;
char buff[MAX];

class MyClass
{
private:
	int x;
public:
	MyClass(int x_n = 0);
	char* repr();

	// member functions
	const MyClass operator++(int n);
	const MyClass operator--(int n);

	// non-member functions
	friend const MyClass operator++(MyClass& obj, int n);
	friend const MyClass operator--(MyClass& obj, int n);
};

MyClass::MyClass(int x_n)
{
	x = x_n;
}

char* MyClass::repr()
{
	sprintf(buff, "(%d)", x);
	return buff;
}

/*
 * przeciazanie wewnatrz klasy
 */
const MyClass MyClass::operator++(int n)
{
	printf("n = %d\n", n);
	return MyClass(x++);
}

const MyClass MyClass::operator--(int n)
{
	printf("n = %d\n", n);
	return MyClass(x--);
}

/*
 * przeciazanie poza klasa
 */
const MyClass operator++(MyClass& obj, int n)
{
	printf("n = %d\n", n);
	return MyClass(obj.x++);
}

const MyClass operator--(MyClass& obj, int n)
{
	printf("n = %d\n", n);
	return MyClass(obj.x--);
}
int main()
{
	MyClass obj1 = 100;
	MyClass obj2 = 100;
	MyClass obj3 = 100;
	MyClass inc1;
	MyClass inc2;
	MyClass inc3;
	MyClass dec1;
	MyClass dec2;
	MyClass dec3;

	printf("%s\n", obj1.repr());
	printf("%s\n", obj2.repr());
	printf("\n");

	//inc1 = obj1++;		// ambigous
	inc2 = obj2.operator++(10);
	inc3 = operator++(obj3, 10);

	printf("obj %s\n", obj1.repr());
	printf("obj %s\n", obj2.repr());
	printf("obj %s\n", obj3.repr());
	printf("inc %s\n", inc1.repr());
	printf("inc %s\n", inc2.repr());
	printf("inc %s\n", inc3.repr());

	//dec1 = obj1--;		// ambigous
	dec2 = obj2.operator--(10);
	dec3 = operator--(obj3, 10);

	printf("obj %s\n", obj1.repr());
	printf("obj %s\n", obj2.repr());
	printf("obj %s\n", obj3.repr());
	printf("dec %s\n", dec1.repr());
	printf("dec %s\n", dec2.repr());
	printf("dec %s\n", dec3.repr());
	return 0;
}