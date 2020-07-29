#include <iostream>

using namespace std;

// FUNKCJA NIESZABLONOWA
void foo(int c)
{
	cout << "funkcja nieszablonowa: int\n";
}

// SZABLON
template<typename T>
void foo(T t)
{
	cout << "szablon: " << typeid(T).name() << endl;
}


/*
 * JAWNA SPECJALIZACJA
 * musi sie pojawic za deklaracja szablonu, 
 * ale przed pierwszym uzyciem (przed niejawna konkretyzacja)
 * typ szablonu jest opcjonalny, moze byc wydedukowany z podanego parametru.
 * jawna specjalizacja nie moze miec parametrow domyslnych
 */
template <> void foo(float x)
{
	cout << "jawna specjalizacja: float\n";
}

template <> void foo<>(double x)
{
	cout << "jawna specjalizacja: double\n";
}

template <> void foo<long double>(long double x)
{
	cout << "jawna specjalizacja: long double\n";
}

/*
 * JAWNA KONKRETYZACJA
 * typ szablonu jest opcjonalny, moze byc wydedukowany z podanego parametru.
 */
template void foo(char x);
template void foo<>(unsigned char x);
template void foo<signed char>(signed char x);

int main()
{
	foo(10);

	foo(10.0F);
	foo(10.0);
	foo(10.0L);

	foo('A');
	foo((unsigned char)'A');
	foo((signed char)'A');

	foo(10L);

	foo(10);
	foo<>(10);
	foo<float>(10);

	return 0;
}
