#include <iostream>
#include <cstdio>

/*
 * KLASA ZAGNIEZDZONA.
 */

class A
{
// VALUES
public:
	int a1;
private:
	int a2;

// NESTED CLASSES
private:
	class B
	{
	public:
		int b1;
	private:
		int b2;
	public:
		void funcB1(A a) { a.a1; };
		void funcB2(A a) { a.a2; };
	};

public:
	class C
	{
	public:
		int c1;
	private:
		int c2;
	public:
		void funcC1(A a) { a.a1; };
		void funcC2(A a) { a.a2; };
	};

public:
	class D;
	//{
	//	void funcD();
	//};

// METHODS
public:
	void funcA1(B b) { b.b1; };
	//void funcA2(B b) { b.b2; };		// BRAK DOSTEPU
	void funcA3(C c) { c.c1; };
	//void funcA4(C c) { c.c2; };		// BRAK DOSTEPU
};

// IMPLEMENTATION
class A::D
{
	void funcD();
};

void A::D::funcD() {}

int main()
{
	A a;
	//A::B b;							// BRAK DOSTEPU
	A::C c;

	return 0;
}