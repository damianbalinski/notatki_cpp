#include <iostream>

/*
 * AUTOMATYCZNE WNIOSKOWANIE TYPU (type inference)
 * musi jawnie wystapic wartosc inicjalizujaca zmienna
 */

struct mystruct
{
	int a;
	float b;
};

int main()
{
	using namespace std;

	auto a1 = 100;
	auto a2 = 100U;
	auto a3 = 100L;
	auto a4 = 100UL;
	auto a5 = 100LL;
	auto a6 = 100ULL;

	auto b1 = 'A';
	auto b2 = u'A';
	auto b3 = U'A';
	auto b4 = L'A';

	auto c1 = 1.0F;
	auto c2 = 1.0;
	auto c3 = 1.0L;

	auto d1 = true;

	auto e1 = (void*)0;

	auto f1 = new mystruct{ 10, 10.0 };


	cout << typeid(a1).name() << endl;
	cout << typeid(a2).name() << endl;
	cout << typeid(a3).name() << endl;
	cout << typeid(a4).name() << endl;
	cout << typeid(a5).name() << endl;
	cout << typeid(a6).name() << endl;
	cout << endl;

	cout << typeid(b1).name() << endl;
	cout << typeid(b2).name() << endl;
	cout << typeid(b3).name() << endl;
	cout << typeid(b4).name() << endl;
	cout << endl;

	cout << typeid(c1).name() << endl;
	cout << typeid(c2).name() << endl;
	cout << typeid(c3).name() << endl;
	cout << endl;

	cout << typeid(d1).name() << endl;
	cout << endl;

	cout << typeid(e1).name() << endl;
	cout << endl;

	cout << typeid(f1).name() << endl;

	return 0;
}