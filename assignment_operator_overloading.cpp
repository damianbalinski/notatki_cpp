#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

class Test
{
private:
	char* str;

public:
	Test(const char* str = "test");
	void print();

	Test& operator=(const Test& obj);
	Test& operator=(Test&& robj);
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

// PRZYPISANIE KOPIUJACE
Test& Test::operator=(const Test& obj)
{
	printf("kopiujace %s do %s!\n", obj.str, str);

	// ten sam obiekt
	if (this == &obj)
		return *this;

	// rozne obiekty
	delete[] str;
	str = new char[strlen(obj.str) + 1];
	strcpy(str, obj.str);
	return *this;
}

// PRZYPISANIE PRZENOSZACE
Test& Test::operator=(Test&& robj)
{
	printf("przenoszace %s do %s\n", robj.str, str);

	// ten sam obiekt
	if (this == &robj)
		return *this;

	// rozne obiekty
	delete[] str;
	str = robj.str;
	robj.str = nullptr;
	return *this;
}

Test spawn(const char* str)
{
	return Test(str);
}

int main()
{
	Test t1;
	Test t2 = "aaa";
	Test t3 = "bbb";

	t1.print();
	t2.print();
	t3.print();

	t2 = t1;
	t3.operator=(t1);

	t1.print();
	t2.print();
	t3.print();

	t2 = spawn("ccc");
	t3.operator=(spawn("ccc"));

	t1.print();
	t2.print();
	t3.print();

	return 0;
}