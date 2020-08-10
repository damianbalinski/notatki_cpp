#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

class Test
{
private:
	char* str;

public:
	Test(const char* str_n = "test");
	void print();

	Test& operator=(const Test& obj);
};

Test::Test(const char* str_n)
{
	str = new char[std::strlen(str_n) + 1];
	strcpy(str, str_n);
}

void Test::print()
{
	printf("%s\n", str);
}

/*
 * Przeciazanie operatora przypisania.
 */
Test& Test::operator=(const Test& obj)
{
	printf("przypisanie %s do %s!\n", obj.str, str);

	// jezeli obiekty sa rowne
	if (this == &obj)
		return *this;

	// jezeli obiekty nie sa rowne
	delete[] str;
	str = new char[strlen(obj.str) + 1];
	strcpy(str, obj.str);
	return *this;
}
int main()
{
	Test t1;
	Test t2 = "abc";
	Test t3 = "qwerty";

	t1.print();
	t2.print();
	t3.print();

	t2 = t1;
	t3.operator=(t1);

	t1.print();
	t2.print();
	t3.print();

	return 0;
}