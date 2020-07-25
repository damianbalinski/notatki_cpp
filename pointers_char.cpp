#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

	char* a1 = (char*)"abc";
	char a2[] = "abc";

	char* a3 = new char[4];
	strcpy(a3, "abc");

	char* a4 = new char;
	*a4 = 'Z';

	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;

	return 0;
}