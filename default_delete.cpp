#include <iostream>

/*
 * METODY DOMYSLNE/USUNIETE
 * = default - syntetyzacja metody przez kompilator (tylko metody specjalne)
 * = delete - brak systetyzacji metody przez kompilator, brak mozliwosci uzywania istniejacej metody/funkcji (kazda metoda lub funkcja)
 * = 0 - metoda czysto wirtualna (wszystkie metody oprocz konstruktora)
 */

class C
{
public:
	C() = default;						// KONSTRUKTOR DOMYSLNY
	C(const C& c) = default;			// KONSTRUKTOR KOPIUJACY
	C(C&& c) = default;					// KONSTRUKTOR PRZENOSZACY
	~C() = default;						// DESTRUKTOR

	C& operator=(const C& c) = default;	// PRZYPISANIE KOPIUJACE
	C& operator=(C&& c) = default;		// PRZYPISANIE PRZENOSZACE

	//operator int() = default;			// FUNKCJA KONWERSJI - ERROR
	//void func() = default;			// METODA - ERROR
};

class D
{
	D() = delete;
	D(const D& d) = delete;
	D(D&& d) = delete;
	~D() = delete;

	D& operator=(const D& d) = delete;
	D& operator=(D && d) = delete;
	D& operator[](int) = delete;

	operator int() = delete;
	void func() = delete;
};

class E
{
public:
	virtual ~E() = 0;
	virtual void foo() = 0;
	virtual operator int() = 0;
	virtual void operator[](int i) = 0;
};

void func() {};

void func2() = delete;

int main()
{
	// TODO default, delete, 0
	// Class(Class& c) = default;
	// Class(Class& c) = delete;
	// Class(Class& c) = 0;

	func();

	/*
	 * konstruktor
	 * destruktor
	 * operator
	 * funkcja konwersji
	 * inne metody
	 * funkcja
	 */
	return 0;
}