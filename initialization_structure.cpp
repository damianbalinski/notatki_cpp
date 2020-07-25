#include <iostream>

struct S
{
	int x;
	int y;
	int z;
};

void print_s(S s)
{
	printf("(%d,%d,%d)\n", s.x, s.y, s.z);
}

int main()
{
	using namespace std;

	// ZEROWANIE
	//S a0 = S(1, 2, 3);
	//S a2();
	//S b1 = (1, 2, 3);
	//S b2(1, 2, 3);
	S a1 = S();
	S a2 = S{};
	S a3 = {};
	S a4{};

	// INICJALIZACJA NORMALNA
	S b1 = { 1, 2,3 };
	S b2{ 1, 2, 3 };

	// INICJALIZACJA OZNACZONA
	S c1 = { .x = 1, .y = 2, .z = 3 };
	S c2 { .x = 1, .y = 2, .z = 3 };
	//S c3 { .x = 1, .z = 2, .z = 3 };

	// PRZYPISANIE WARTOSCI
	S d1 = a1;

	// INICJALIZACJA OZNACZONA G++
	//S e1 = { x:10, y: 20, z: 30 };
	//S e2 { x:10, y: 20, z: 30 };

	print_s(a1);
	print_s(a2);
	print_s(a3);
	print_s(a4);
	print_s(b1);
	print_s(b2);
	print_s(c1);
	print_s(c2);
	print_s(d1);
	// print_s(e1);	G++
	// print_s(e2);	G++

	return 0;
}