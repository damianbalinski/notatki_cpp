#include <iostream>

using namespace std;

// SZABLON
template<typename T, typename U>
void foo(T t, U u)
{
	cout << "T = " << t << endl;
	cout << "U = " << u << endl;
	cout << endl;
}

template<typename T>
void foo(T t, int y)
{
	cout << "T = " << t << endl;
	cout << "int = " << y << endl;
	cout << endl;
}

//template<typename U>
//void foo(int x, U u)
//{
//	cout << "int = " << x << endl;
//	cout << "U = " << u << endl;
//	cout << endl;
//}

template<>
void foo(int x, int y)
{
	cout << "int = " << x << endl;
	cout << "int = " << y << endl;
	cout << endl;
}

int main()
{
	foo(5., 5.);
	foo(10, 5.);
	foo(5., 10);
	foo(10, 10);

	return 0;
}