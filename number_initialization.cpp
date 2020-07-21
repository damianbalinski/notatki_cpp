#include <iostream>

int main()
{
	using namespace std;

	int x1 = 10;
	int y1(10);
	int y2 = (10);
	int z1{ 10 };	// nie zezwala na konwersje zawezajaca
	int z2 = { 10 };

	// int a1();
	// int a2 = ();
	int b1{};
	int b2 = {};	// inicjalizacja do wartosci zerowej


	cout << "x1 = " << x1 << endl;
	cout << "y1 = " << y1 << endl;
	cout << "y2 = " << y2 << endl;
	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;

	cout << "b1 = " << b1 << endl;
	cout << "b2 = " << b2 << endl;

	return 0;
}