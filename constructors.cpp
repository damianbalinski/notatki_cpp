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
	Test operator=(Test& t) { printf("przypisanie\n"); this->x = t.x; };
public:
	Test(int x_n = 0);				// DOMYSLNY
public:
	Test(const Test& t);			// KOPIUJACY
public:
	Test(const Test&& t);			// PRZENOSZACY (MOVE CONSTS.)
public:
	Test(double x_n);				// KONWERTUJACY
public:
	Test(double x_n, double y_n);	// KONWERTUJACY WIELOPARAMETROWY
public:
	~Test();						// DESTRUKTOR
};


/*
 * DOMYSLNY (DEFAULT CONSTR.) - brak parametrow lub wszystkie parametry domyslne.
 * AUTO - nic
 */
Test::Test(int x_n)
{
	printf("domyslny %d\n", x_n);
	x = x_n;
}

/*
 * KOPIUJACY (COPY CONSTR.) - przypisanie lwartosci do obiektu podczas inicjalizacji
 * AUTO* - kopiowanie plytkie
 * pierwszy parametr - referencja do obiektu tej samej klasy/podklasy
 * reszta parametrow - brak lub domyslne
 * (kopiowanie parametrow/zwracanej wartosci)
 */
Test::Test(const Test& t)
{
	printf("kopiujacy %d\n", t.x);
	x = t.x;
}

/*
 * PRZENOSZACY (MOVE CONSTR.)- przypisanie rwartosci do obiektu podczas inicjalizacji
 * AUTO* - kopiowanie plytkie
 * pierwszy parametr - referencja do rwartosci tej samej klasy/podklasy
 * reszta parametrow - brak lub domyslne
 * (kopiowanie parametrow/zwracanej wartosci)
 */
Test::Test(const Test&& t)
{
	printf("przenoszacy %d\n", t.x);
	x = t.x;
}

/*
 * KONWERTUJACY (CONVERTING CONSTR.)
 * pierwszy parametr - wartosc dowolnego typu
 * reszta parametrow - brak/domyslne
 * umozliwia konwersje wartosci dowolnego typu na obiekt klasy,
 * (konwersja parametrow/zwracanych wartosci),
 */
Test::Test(double val)
{
	printf("konwertujacy %f\n", val);
	x = (int)val;
}

/*
 * KONWERTUJACY WIELOPARAMETROWY
 */
Test::Test(double x_n, double y_n)
{
	printf("konwertujacy wieloargumentowy %f %f\n", x_n, y_n);
	x = (int)(x_n + y_n);
}

/*
 *DESTRUKTOR
 */
Test::~Test()
{
	printf("destruktor\n");
}

void foo(Test test)
{
	printf("OK\n");
}

int main()
{
	//Test t = 10;
	//static const Test t2;

	// WIAZANIE STATYCZNE

	// DOMYSLNY
	//Test a1;
	////Test a2();		// ERROR - function declaration
	//Test a3{};
	//Test a4 = {};
	//Test a5 = Test();
	//Test a6 = Test{};

	// KOPIUJACY
	//Test b1(t);
	//Test b2{ t };
	//Test b3 = Test(t);
	//Test b4 = Test{ t };
	//Test b5 = t;
	//Test b6 = { t };

	// PRZENOSZACY
	Test e1(Test());
	//Test t1;
	Test t1{ Test() };
	Test t2 = {Test() };
	Test t3 = Test();
	//Test e2{ Test() };
	//Test e3 = Test(t2);
	//Test e4 = Test{ t2 };
	//Test e5 = t2;
	cout << "test" << endl;

	// KOWERTUJACY
	//Test c1(10.0);
	//Test c5{ 10.0 };
	//Test c3 = Test(10.0);
	//Test c6 = Test{ 10.0 };
	//Test c2 = 10.0;
	//Test c9 = (10.0);
	//Test c4 = { 10.0 };

	// KONWERTUJACY WIELOPARAMETROWY
	//Test f1(1.0, 2.0);
	//Test f2{ 1.0, 2.0 };
	//Test f3 = Test(1.0, 2.0);
	//Test f4 = Test{ 1.0, 2.0 };
	//Test f5 = { 1.0, 2.0 };

	// TEST
	//Test h1 = { .x_n = 20 };

	// TODO WIAZANIE DYNAMICZNE

	return 0;
}