#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

/* BEFORE CLASS - JEDEN DO JEDNEGO
 * ZALEZNY SZABLON FUNKCJI ZAPRZYJAZNIONEJ
 * musi zostac zadeklarowany przed szablonem klasy
 * specjalizacja szablonu zaprzyjazniona z konkretna
 * specjalizacja klasy
 */
template<typename T>
void func3(T t)
{
	cout << "func3 " << t.t << endl;
}

template<typename T>
class A
{
private:
	T t;
public:
	/*
	 * konstruktor
	 */
	A(T t) { this->t = t; };
	A() {};


	friend void func1();
	friend void func2(A<T> a);

	/*
	 * jawna specjalizacja szablonu funkcji func3, automatyczna
	 * dedukcja typu dla parametru T
	 */
	friend void func3<>(A<T> a);

	/*
	 * niezalezny szablon zaprzyjazniony
	 * parametry szablonu funkcji zaprzyjaznionej sa inne niz 
	 * parametry szablonu klasy
	 */
	template<typename U>
	friend void func4(U u);
};

/* AFTER CLASS - JEDEN DO WIELU
 * NIEZALEZNA FUNKCJA ZAPRZYJAZNIONA
 * funkcja zaprzyjazniona ze wszystkimi konkretyzacjami
 * szablonu, moze miec dostep do konkretyzacji np. za 
 * pomoca zmiennej globalnej
 */
void func1()
{
	A<int> a;
	A<double> b;
	A<char> c;
}

/* AFTER CLASS - JEDEN DO JEDNEGO
 * ZALEZNA FUNKCJA ZAPRZYJAZNIONA
 * funkcja zaprzyjazniona z podana konkretyzacja sz-
 * ablonu
 * func1 nie jest szablonem, dlatego nalezy zdefiniowac
 * specjalizacje dla kazdego wariantu funkcji za-
 * przyjaznionej
 */
void func2(A<int> a)
{
	cout << "func1 " << a.t << endl;
}

/* AFTER CLASS - WIELE DO WIELU
 * NIEZALEZNY SZABLON FUNKCJI ZAPRZYJAZNIONEJ
 * kazda specjalizacja funkcji zaprzyjazniona z kazda specjalizacja
 * szablonu
 */
template<typename U>
void func4(U u)
{
	cout << "func4 " << u.t << endl;
}


class B
{
private:
	int b;
public:
	template<typename T>
	friend void func5(T t, B b);
};

/*
 * AFTER CLASS - WIELE DO JEDNEGO
 * kazda specjalizacja szablonu funkcji zaprzyjaznona z klasa
 */
template<typename T>
void func5(T t, B b)
{
	cout << "t" << t << " : b" << b.b << endl;
}

int main()
{
	A a1(10);
	A a2(10.0);
	B b = B();

	// FUNC 3
	func3(a1);
	func3(a2);

	// FUNC 2
	func2(a1);
	//func2(a2);	// ERROR - brak specjalizacji dla typu A<double>

	// FUNC 4
	func4(a1);
	func4(a2);

	// FUNC 5
	func5(5, b);

	return 0;
}