#include <iostream>

class Bazowa
{
public:
	int x;

	Bazowa(int x)
	{
		this->x = x;
	}

	void foo(int x) 
	{ 
		this->x = x;
		printf("%d\n", x);
	};

	void foo() 
	{ 
		this->x = -1;
		printf("%d\n", -1); 
	};

	//Bazowa& operator=(Bazowa& obj)
	//{
	//	this->x = x;
	//}

	void print()
	{
		printf("(%d)\n", x);
	}
};

class Pochodna : public Bazowa
{
public:
	int y;

	Pochodna(int x, int y) : Bazowa(x)
	{
		this->y = y;
	}

	void print()
	{
		printf("(%d,%d)\n", x, y);
	}

	Pochodna& operator=(const Pochodna& p)
	{
		y = p.y;
		Bazowa::operator=(p);
		return *this;
	}
};

int main()
{
	using namespace std;
	Bazowa a1(1);
	Bazowa a2(2);
	Pochodna b1(10, 100);
	Pochodna b2(20, 200);

	b1.print();
	b2.print();

	b2 = b1;

	b1.print();
	b2.print();

	return 0;
}