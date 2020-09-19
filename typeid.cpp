#include <iostream>
#include <typeinfo>

/*
 * TYPEID - sprawdza/porownuje typ obiektu/klasy/wyrazenia,
 * zwraca referencje do obiektu type_info, jednoznacznie reprezentujacego dany typ
 * zwraca wyjatek bad_typeid, jesli operand jest wskazinkiem pustym,
 *
 * typeid(val).name() - zwraca ciag znakow jednoznacznie reprezentujacy
 * dany typ
 */
class A {};

class B : public A {};

int main()
{
	using std::cout, std::endl;

	int val = 10;
	const char* str = "abc";
	A a;

	cout << "val" << " : " << typeid(val).name() << endl;		// zmienna
	cout << "str" << " : " << typeid(str).name() << endl;
	cout << "1 + 1" << " : " << typeid(1+1).name() << endl;		// wyrazenie
	cout << "abc" << " : " << typeid("abc").name() << endl;		// stala lancuchowa
	cout << "A" << " : " << typeid(A).name() << endl;			// klasa
	cout << "A" << " : " << typeid(a).name() << endl;			// obiekt
	cout << "A" << " : " << typeid(a).name() << endl;			// obiekt

	cout << (bool)(typeid(10) == typeid(100)) << endl;			// porownywanie wyrazen
	cout << (bool)(typeid(val) == typeid(str)) << endl;			// porownywanie obiektow
	cout << (bool)(typeid(A) == typeid(B)) << endl;				// porownywanie klas

	// TODO typy dla zwyklych zmiennych, wskaznikow, referencji
	// NP typeid(ref) oraz tpeid((ref))
	return 0;
}