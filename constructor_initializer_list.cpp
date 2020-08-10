/*
 * LISTA INICJALIZACYJNA KONSTRUKTORA (CONSTRUCTOR INITIALIZER LIST)
 * oddzielona przecinkami lista inicjalizatorow.
 * ma pierwszenstwo przed inicjalizacja w deklaracji klasy.
 */
#include <iostream>
#include <cstdio>

class Temp {};

Temp temp_global;

class Test
{
private:
	int val;
	const int con;
	Temp& ref;

public:
	Test(int val_n, int con_n, Temp& ref_n);
};

//// ERROR
//Test::Test(int val_n, int con_n, Temp& ref_n)
//{
//	val = val_n;
//	//con = con_n;		// ERROR
//	//ref = ref_n;		// ERROR
//}

//// ERROR
//Test::Test::Test(int val_n, int con_n, Temp& ref_n) : val(val_n)
//{
//	//con = con_n;		// ERROR
//	//ref = ref_n;		// ERROR
//}

//// ERROR
//Test::Test(int val_n, int con_n, Temp& ref_n) : con(con_n)
//{
//	val = val_n;
//	//ref = ref_n;		// ERROR
//}

//// ERROR
//Test::Test(int val_n, int con_n, Temp& ref_n) : ref(ref_n)
//{
//	val = val_n;
//	//con = con_n;		// ERROR
//}

// OK
Test::Test(int val_n, int con_n, Temp& ref_n) : val(val_n), con(con_n), ref(ref_n)
{
	std::printf("(%d, c%d, p%p)\n", val, con, &ref);
}

int main()
{
	Temp temp;

	printf("temp      p%p\n", &temp);
	printf("global    p%p\n", &temp_global);

	Test t1(10, 20, temp);

	return 0;
}