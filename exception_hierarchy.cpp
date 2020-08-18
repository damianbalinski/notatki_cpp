#include <cstdio>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <new>

// HIERARCHIA WYJATKOW

int main()
{
	// klasa bazowa dla wszystkich wyjatkow biblioteki standardowej
	std::exception e1;

	// bledy logiczne
	std::logic_error e2("message");

	// bledna dziedzina w funkcjach matematycznych
	// exception ->
	std::domain_error e4("message");

	// niepoprawny argument
	// exception -> logic_error ->
	std::invalid_argument e5("message");

	// blad dlugosci, brak miejsca na przeprowadzenie operacji
	std::length_error e6("message");

	// nieprawidlowe indeksowanie tablicy
	std::out_of_range e7("message");

	// bledy w trakcie dzialania programu
	// exception ->
	std::runtime_error b1("message");

	// bledna przeciwdziedzina
	std::range_error b2("message");

	// blad nadmiaru, przekroczenie najwiekszej dopuszczalnej wartosci
	std::overflow_error b3("message");

	// blad niedomiaru w liczbach zmiennoprzecinkowych
	std::underflow_error b4("message");

	// brak mozliwosci alokacji pamieci
	// exception ->
	std::bad_alloc c1;

	// nieparawidlowy wyjatek
	std::bad_exception;

	///////////////////////////
	// RZUTOWANIE TYPOW / RTTI/
	///////////////////////////

	// nieprawidlowe rzutowanie, rzucane przez dynamic_cast
	// #include <typeinfo>
	std::bad_cast;

	// rzucany, jesli argumentem operatora typeid jest wskaznik pusty
	// #include <typeinfo>
	std::bad_typeid;
}