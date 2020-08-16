#include <iostream>

/*
 * Konieczna jest deklaracja wyprzedzajaca.
 */
class B;

/*
 * W momencie napotkania metody zaprzyjaznionej,
 * kompilator musi znac deklaracje B oraz deklaracje jej metod.
 */
class A 
{
public:
	void print(B a);
};

class B
{
private:
	int x;
public:
	B(int x) : x(x) {};
	friend void A::print(B a);
};

void A::print(B a) 
{
	printf("%d\n", a.x);
}


int main()
{
	using namespace std;

	return 0;
}