#include <iostream>

class Test
{
private:
	int x;
public:
	int get();

	//konstruktory
	Test(int x_n = -1);			// zwykly
	Test(const Test& obj);		// kopiujacy

	// operatory
	Test& operator=(const Test& obj);
};

int Test::get()
{
	return x;

}

// KONSTRUKTOR ZWYKLY
Test::Test(int x_n)
{
	printf("> konstruktor %d\n", x_n);

	x = x_n;
}

// KONSTRUKTOR KOPIUJACY
Test::Test(const Test& obj)
{
	printf("> konstruktor kopiujacy %d\n", obj.x);

	x = obj.x;
}

Test& Test::operator=(const Test& obj)
{
	printf("przypisanie %d do %d!\n", obj.x, x);

	x = obj.x;
	return *this;
}
int main()
{
	Test t1;
	Test t2 = t1;
	Test t3 = 10;
	Test t4 = 20;

	t3 = -10;
	t4 = t1;
	
	//printf("%d\n", t1.get());
	//printf("%d\n", t2.get());

	return 0;
}