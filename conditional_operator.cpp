#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

#define MAXIMUM(X,Y) (X>Y) ? X : Y
#define MAX 10

int main()
{
	using namespace std;

	// const char str[MAX] = (5 > 1) ? "abc" : "abcdef";	// ERROR
	const char* str2 = (5 > 1) ? "abc" : "abcdef";
	char str3[MAX];
	strcpy(str3, (5 > 1) ? "abc" : "abcdef");


	int val = (5 > 1) ? 1 : 0;

	int x = 10, y = 20, z = 30;
	(x > y) ? x : y = z;

	printf("%d\n", val);
	printf("(%d,%d,%d)\n", x, y, z);
	printf("MAX(10,20) = %d\n", MAXIMUM(10, 20));
	printf("MAX(20,10) = %d\n", MAXIMUM(20, 10));

	return 0;
}