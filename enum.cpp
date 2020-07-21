#include <iostream>

enum kolory
{
	CZERWONY,
	ZIELONY,
	NIEBIESKI,
};

enum values
{
	A1 = 0,
	A2 = 1,
	A3 = 0,
};

int main()
{
	using namespace std;

	kolory k1 = NIEBIESKI;
	kolory k2 = (kolory)2;
	kolory k3 = (kolory)200;

	cout << CZERWONY << endl;
	cout << ZIELONY << endl;
	cout << NIEBIESKI << endl;
	cout << "k1 = " << k1 << endl;
	cout << "k2 = " << k2 << endl;
	cout << "k3 = " << k3 << endl;

	cout << "A1 = " << A1 << endl;
	cout << "A2 = " << A2 << endl;
	cout << "A3 = " << A3 << endl;

	return 0;
}