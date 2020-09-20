#include <iostream>
#include <functional>

/*
 * FUNCTION - ADAPTER FUNKCJI(FUNCTION WRAPPER)
 * zapewnia jednakowe traktowanie roznych odmian obiektow funkcyjnych
 * o jednakowej sygnaturze wywolania (funkcja, wskaznik na funkcje, obiekt
 * funkcyjny, wyrazenie lambda), przechowuje, przekopiowuje, wywoluje te 
 * obiekty
 */
function<double(char, int)> func;

using namespace std;

class Func
{
private:
	int val;
public:
	Func(int val) : val(val) {}
	double operator()(double val) { return val * 10; }
};

template<typename T>
void counter(T t)
{
	static int c1 = 0;
	c1++;

	cout << "c: " << c1 << "\t&c: " << &c1 << endl;
	t(10.0);
}

template<typename T>
void counter2(function<T(T)> t)
{
	static int c2 = 0;
	c2++;

	cout << "c: " << c2 << "\t&c: " << &c2 << endl;
	t(10.0);
}

// FUNKCJE
double func1(double val) { return val * 10; }
double func2(double val) { return val + 10; }

int main()
{
	// OBIEKTY FUNKCYJNE
	Func objf1{1};
	Func objf2{-1};

	// LAMBDY
	auto lamb1 = [](double val) { return val * 10; };
	auto lamb2 = [](double val) { return val + 10; };

	counter(func1);
	counter(func2);
	counter(objf1);
	counter(objf2);
	counter(lamb1);
	counter(lamb2);

	cout << endl;
	counter2<double>(func1);
	counter2<double>(func2);
	counter2<double>(objf1);
	counter2<double>(objf2);
	counter2<double>(lamb1);
	counter2<double>(lamb2);

	return 0;
}