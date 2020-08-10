#include <iostream>

class Base
{
public:
	~Base() { printf("base\n"); }
};

class Derived : public Base
{
public:
	~Derived() { printf("derived\n"); }
};

int main()
{
	{
		Base* b1 = new Base();
		Base* b2 = new Derived();

		delete b1;
		delete b2;
	}

	return 0;
}