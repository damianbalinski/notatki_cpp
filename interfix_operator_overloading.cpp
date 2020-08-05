#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

const int MAX = 100;
static char buff[MAX];

class MyClass
{
private:
	int x;
public:
	MyClass(int x_n = 0);
	char* repr();

	// member function
	MyClass operator+(const MyClass& obj) const;
	MyClass operator-(const MyClass& obj) const;
	MyClass operator*(const MyClass& obj) const;
	MyClass operator/(const MyClass& obj) const;

	MyClass& operator+=(const MyClass& obj);
	MyClass& operator-=(const MyClass& obj);
	MyClass& operator*=(const MyClass& obj);
	MyClass& operator/=(const MyClass& obj);

	// non member function
	friend MyClass operator+(const MyClass& obj1, const MyClass& obj2);
	friend MyClass operator-(const MyClass& obj1, const MyClass& obj2);
	friend MyClass operator*(const MyClass& obj1, const MyClass& obj2);
	friend MyClass operator/(const MyClass& obj1, const MyClass& obj2);
	
	friend MyClass& operator+=(MyClass& obj1, const MyClass& obj2);
	friend MyClass& operator-=(MyClass& obj1, const MyClass& obj2);
	friend MyClass& operator*=(MyClass& obj1, const MyClass& obj2);
	friend MyClass& operator/=(MyClass& obj1, const MyClass& obj2);

};

// construtor
MyClass::MyClass(int x_n)
{
	x = x_n;
}

// char representation
char* MyClass::repr()
{
	sprintf(buff, "<%d>", x);
	return buff;
}

/*
 * przeciazanie wewnatrz klasy
 * *this - lewy operand, obj - prawy operand
 */
MyClass MyClass::operator+(const MyClass& obj) const
{
	return MyClass(x + obj.x);
}

MyClass MyClass::operator-(const MyClass& obj) const
{
	return MyClass(x - obj.x);
}

MyClass MyClass::operator*(const MyClass& obj) const
{
	return MyClass(x * obj.x);
}

MyClass MyClass::operator/(const MyClass& obj) const
{
	return MyClass(x / obj.x);
}

MyClass& MyClass::operator+=(const MyClass& obj)
{
	x += obj.x;
	return *this;
}

MyClass& MyClass::operator-=(const MyClass& obj)
{
	x -= obj.x;
	return *this;
}

MyClass& MyClass::operator*=(const MyClass& obj)
{
	x *= obj.x;
	return *this;
}

MyClass& MyClass::operator/=(const MyClass& obj)
{
	x /= obj.x;
	return *this;
}

/*
 * przeciazanie poza klasa
 * obj1 - lewy operand, obj2 - prawy operand
 */
MyClass operator+(const MyClass& obj1, const MyClass& obj2)
{
	return MyClass(obj1.x + obj2.x);
}

MyClass operator-(const MyClass& obj1, const MyClass& obj2)
{
	return MyClass(obj1.x - obj2.x);
}

MyClass operator*(const MyClass& obj1, const MyClass& obj2)
{
	return MyClass(obj1.x * obj2.x);
}

MyClass operator/(const MyClass& obj1, const MyClass& obj2)
{
	return MyClass(obj1.x / obj2.x);
}

MyClass& operator+=(MyClass& obj1, const MyClass& obj2)
{
	obj1.x += obj2.x;
	return obj1;
}

MyClass& operator-=(MyClass& obj1, const MyClass& obj2)
{
	obj1.x -= obj2.x;
	return obj1;
}

MyClass& operator*=(MyClass& obj1, const MyClass& obj2)
{
	obj1.x *= obj2.x;
	return obj1;
}

MyClass& operator/=(MyClass& obj1, const MyClass& obj2)
{
	obj1.x /= obj2.x;
	return obj1;
}

int main()
{
	MyClass obj1 = 200;
	MyClass obj2 = 100;

	MyClass sum1;
	MyClass sum2;
	MyClass sum3;
	MyClass dif1;
	MyClass dif2;
	MyClass dif3;
	MyClass mul1;
	MyClass mul2;
	MyClass mul3;
	MyClass div1;
	MyClass div2;
	MyClass div3;

	MyClass obj = 10;
	MyClass asum1 = 100;
	MyClass asum2 = 100;
	MyClass asum3 = 100;
	MyClass adif1 = 100;
	MyClass adif2 = 100;
	MyClass adif3 = 100;
	MyClass amul1 = 100;
	MyClass amul2 = 100;
	MyClass amul3 = 100;
	MyClass adiv1 = 100;
	MyClass adiv2 = 100;
	MyClass adiv3 = 100;

	// sum1 = obj1 + obj2;	// ambigious
	sum2 = obj1.operator+(obj2);
	sum3 = operator+(obj1, obj2);

	//dif1 = obj1 - obj2;	// ambigious
	dif2 = obj1.operator-(obj2);
	dif3 = operator-(obj1, obj2);

	//mul1 = obj1 * obj2;	// ambigious
	mul2 = obj1.operator*(obj2);
	mul3 = operator*(obj1, obj2);

	//div1 = obj1 / obj2;	// ambigious
	div2 = obj1.operator/(obj2);
	div3 = operator/(obj1, obj2);

	//asum1 += obj;			// ambigious
	asum2.operator+=(obj);
	operator+=(asum3, obj);

	//adif1 -= obj;			// ambigious
	adif2.operator-=(obj);
	operator-=(adif3, obj);

	//amul1 *= obj;			// ambigious
	amul2.operator*=(obj);
	operator*=(amul3, obj);

	//adiv1 /= obj;			// ambigious
	adiv2.operator/=(obj);
	operator/=(adiv3, obj);

	printf("obj %d\n", obj1);
	printf("obj %d\n", obj2);

	printf("sum %d\n", sum1);
	printf("sum %d\n", sum2);
	printf("sum %d\n", sum3);

	printf("dif %d\n", dif1);
	printf("dif %d\n", dif2);
	printf("dif %d\n", dif3);

	printf("mul %d\n", mul1);
	printf("mul %d\n", mul2);
	printf("mul %d\n", mul3);

	printf("div %d\n", div1);
	printf("div %d\n", div2);
	printf("div %d\n", div3);
	printf("\n");

	printf("asum %d\n", asum1);
	printf("asum %d\n", asum2);
	printf("asum %d\n", asum3);

	printf("adif %d\n", adif1);
	printf("adif %d\n", adif2);
	printf("adif %d\n", adif3);

	printf("amul %d\n", amul1);
	printf("amul %d\n", amul2);
	printf("amul %d\n", amul3);

	printf("adiv %d\n", adiv1);
	printf("adiv %d\n", adiv2);
	printf("adiv %d\n", adiv3);

	return 0;
}