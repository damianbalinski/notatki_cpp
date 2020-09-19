/*
 * KONSTRUKTORY (CONSTRUCTORS)
 * brak - kompilator tworzy konstruktor domyslny
 * prywatny - brak mozliwosci kozystania z konstruktora
 * publiczny - mozliwosc kozystania z konstruktora
 *
 * konstruktor nie posiada typu wartosci zwracanej
 * AUTO - generowany automatycznie przez kompilator
 * AUTO* - jesli potrzebny, generowany automatycznie przez kompilator
 */
#include <iostream>

using std::cout;
using std::endl;

class Test
{
private:
	int x;
public:
	void operator=(Test& t) { printf("przypisanie\n"); this->x = t.x; };
public:
	Test();						// DOMYSLNY
public:
	Test(const Test& t);		// KOPIUJACY
public:
	Test(Test&& t);				// PRZENOSZACY
public:
	Test(int x1);				// KONWERTUJACY JEDNOPARAMETROWY
public:
	Test(int x1, int x2);		// KONWERTUJACY WIELOPARAMETROWY
public:
	~Test();					// DESTRUKTOR
};


/*
 * DOMYSLNY (DEFAULT CONSTRUCTOR)
 * AUTO - nic
 * (1) - brak/domyslny
 * (2) - brak/domyslny
 */
Test::Test()
{
	x = 1;
	printf("domyslny %d\n", x);
}

/*
 * KOPIUJACY (COPY CONSTRUCTOR)
 * przypisanie lwartosci do obiektu podczas inicjalizacji, nie modyfikuje obiektu zrodlowego
 * AUTO* - kopiowanie plytkie
 * (1) - referencja do obiektu tej samej klasy/podklasy
 * (2) - brak/domyslny
 * (kopiowanie parametrow/zwracanej wartosci)
 */
Test::Test(const Test& t)
{
	printf("kopiujacy %d\n", t.x);
	x = t.x;
}

/*
 * PRZENOSZACY (MOVE CONSTRUCTOR)
 * przypisanie tymczasowych rwartosci do obiektu podczas inicjalizacji, moze modyfikowac obiekt zrodlowy
 * AUTO* - kopiowanie plytkie
 * (1) - referencja do rwartosci tej samej klasy/podklasy
 * (2) - brak/domyslny
 * (kopiowanie parametrow/zwracanej wartosci)
 */
Test::Test(Test&& t)
{
	printf("przenoszacy %d\n", t.x);
	x = t.x;
	t.x = -1;
}

/*
 * KONWERTUJACY (CONVERTING CONSTRUCTOR) 
 * konwersja pojedynczej wartosci na obiekt klasy,
 * (1) - wartosc dowolnego typu
 * (2) - brak/domyslny
 * (konwersja parametrow/zwracanych wartosci),
 */
Test::Test(int x1)
{
	printf("konwertujacy %d\n", x1);
	x = x1;
}

/*
 * KONWERTUJACY WIELOPARAMETROWY
 * konwersja ciagu wartosci na obiekt klasy
 * (1) - wartosc dowolnego typu
 * (2) - wartosc dowolnego typu
 */
Test::Test(int x1, int x2)
{
	printf("konwertujacy wieloargumentowy %d %d\n", x1, x2);
	x = x1 + x2;
}

/*
 *DESTRUKTOR
 */
Test::~Test()
{
	printf("destruktor %d\n", x);
}

void foo(Test test)
{
	printf("OK\n");
}

Test spawn(int val) {
	Test temp(val);
	return temp;
}

int main()
{
	//Test t = 10;
	//static const Test t2;

	// WIAZANIE STATYCZNE

	//// DOMYSLNY
	//Test a1;					Test a4 = {};					/**/
	///**/						Test a5 = Test();				/**/
	//Test a3{};				Test a6 = Test{};				/**/
	
	// KOPIUJACY
	//Test b1(t);				Test b3 = Test(t);				Test b5 = t;
	//Test b2{ t };				Test b4 = Test{ t };			Test b6 = { t };

	// PRZENOSZACY
	//Test t1(spawn(1));		Test t3 = Test(spawn(3));		Test t5 = spawn(5);
	//Test t2{ spawn(2) };		Test t4 = Test{ spawn(3) };		Test t6 = { spawn(6) };

	// KOWERTUJACY
	//Test c1(10);				Test c3 = Test(10);				Test c5 = 10;
	//Test c2{ 10 };			Test c4 = Test{ 10 };			Test c6 = { 10 };

	// KONWERTUJACY WIELOPARAMETROWY
	//Test f1(1, 2);			Test f3 = Test(1, 2);			/**/
	//Test f2{ 1, 2 };			Test f4 = Test{ 1, 2 };			Test f5 = { 1, 2 };
	

	// TEST
	//Test h1 = { .x_n = 20 };

	// TODO WIAZANIE DYNAMICZNE

	/*
	 * (1)     - pierwszy parametr
	 * (2,...) - pozostale parametry
	 */

	return 0;
}