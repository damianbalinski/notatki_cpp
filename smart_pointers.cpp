#include <iostream>
#include <cstdio>
#include <memory>

//using std::auto_ptr;		// DEPRECATED
using std::unique_ptr;		// OK
using std::shared_ptr;		// OK
using std::weak_ptr;	

class C
{
private:
	int i;
public:
	C(int i) : i(i) { printf("init %d\n", i); }
	~C() { printf("delete %d\n", i); }
};

int main()
{
	// INICJALIZACJA

	// AUTO_PTR - ZMIENNE OK|TABLICE NOT
	// wlascicielem danego obiektu moze byc tylko jeden inteligentny wskaznik,
	// przypisanie zmienia wlasciciela, wywoluje destruktor obiektu tylko jesli inteligentny
	// wskaznik jest wlascicielem, dostep nie wlasciciela do obiektu jest niezdefiniowany
	//{	// DEPRECATED
	//	std::auto_ptr<C> ptr(new C(0));
	//}

	// UNIQUE_PTR - ZMIENNE OK|TABLICE OK
	// wlascicielem danego obiektu moze byc tylko jeden inteligentny wskaznik,
	// przypisanie zmienia wlasciciela, wywoluje destruktor obiektu tylko jesli inteligentny
	// wskaznik jest wlascicielem, wywoluje destruktor w momencie wyjscia z bloku, przypisania lub wywolania funkcji reset()
	{
		unique_ptr<C> ptr(new C(1));
	}

	// SHARED_PTR - ZMIENNE OK|TABLICE NO
	// zlicza referencje do obiektu, przypisanie zwieksza liczbe referencji
	// a usuwanie ja zmniejsza, wywoluje destruktor obiektu tylko wtedy, gdy usuwany jest ostatni
	// inteligentny wskaznik, mozliwy wspoldzielony dostep wielu inteligentnych wskaznikow do
	// tego samego obiektu
	{
		shared_ptr<C> ptr(new C(2));
	}

	// WEAK_PTR
	//weak_ptr<int> p4(new int);

	// PRZYPISANIE

	//{	// DEPRECATED
	//	auto_ptr<C> ptr;
	//	C* data = new C(-0);
	//	ptr = auto_ptr<C>(data);
	//}
	{
		unique_ptr<C> ptr;
		C* data = new C(-1);
		ptr = unique_ptr<C>(data);
	}
	{
		shared_ptr<C> ptr;
		C* data = new C(-2);
		ptr = shared_ptr<C>(data);
	}


	// TEST
	using std::auto_ptr;
	auto_ptr<int> ptr(new int);
	auto_ptr<int> ptr2;
	ptr2 = ptr;

	return 0;
}