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
	const MyClass operator++();
	const MyClass operator--();

	// non-member functions
	friend const MyClass operator++(MyClass& obj);
	friend const MyClass operator--(MyClass& obj);
};

// construcotor
MyClass::MyClass(int x_n)
{
	x = x_n;
}

// string representation
char* MyClass::repr()
{
	sprintf(buff, "(%d)", x);
	return buff;
}

/*
 * przeciazanie wewnatrz klasy
 */
const MyClass MyClass::operator++()
{
	return MyClass(++x);
}

const MyClass MyClass::operator--()
{
	return MyClass(--x);
}

/*
 * przeciazanie poza klasa
 */
const MyClass operator++(MyClass& obj)
{
	return MyClass(++obj.x);
}

const MyClass operator--(MyClass& obj)
{
	return MyClass(--obj.x);
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

	//inc1 = ++obj1;		// ambigious
	inc2 = obj2.operator++();
	inc3 = operator++(obj3);

	//dec1 = --obj1;		// ambigous
	dec2 = obj2.operator--();
	dec3 = operator--(obj3);

	printf("%s\n", obj1.repr());
	printf("%s\n", obj2.repr());
	printf("\n");

	printf("inc %s\n", inc1.repr());
	printf("inc %s\n", inc2.repr());
	printf("inc %s\n", inc3.repr());

	printf("dec %s\n", dec1.repr());
	printf("dec %s\n", dec2.repr());
	printf("dec %s\n", dec3.repr());

	return 0;
}