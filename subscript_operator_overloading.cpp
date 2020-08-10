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
	void print() const;

	char& operator[](int n);
	const char& operator[](int n) const;
};

Test::Test(const char* str_n)
{
	str = new char[std::strlen(str_n) + 1];
	strcpy(str, str_n);
}

void Test::print() const
{
	printf("%s\n", str);
}

/*
 * Przeciazanie operatora indeksowania.
 */
char& Test::operator[](int n)
{
	return str[n];
}

const char& Test::operator[](int n) const
{
	return str[n];
}

int main()
{
	Test t1 = "abc";
	const Test t2 = "xyz";

	t1.print();
	printf("%c\n", t1[0]);
	printf("%c\n", t1.operator[](0));

	t2.print();
	printf("%c\n", t2[0]);
	printf("%c\n", t2.operator[](0));
	putchar('\n');

	t1[0] = 'z';
	t1.operator[](0) = 'z';

	//t2[0] = 'z';			// ERROR - assignment to const
	//t2.operator[](0) = 'a';	// ERROR - assignment to const

	t1.print();
	printf("%c\n", t1[0]);

	t2.print();
	printf("%c\n", t2[0]);

	return 0;
}