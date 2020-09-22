#include <iostream>

/*
* LAMBDA GENERYCZNA
* tworzenie oddzielnej instancji dla kazdego typu argumentu
*/

using namespace std;

template<class T>
auto func1(T i)
{
	static int COUNT1 = 0;
	cout << ++COUNT1 << endl;

	return i;
};
auto lamb1 = [](auto i)
{
	static int COUNT2 = 0;
	cout << ++COUNT2 << endl;

	return i;
};

void foo() {}

template<class T, class... Args>
void foo(T& t, Args&... args)
{
	cout << t << ", ";
	t = -1;
	foo(args...);
}

template<class... Args>
void func2(Args... args)
{
	[args...]() { foo(args...); }();
}

int main()
{
	int a = 10, b = 20, c = 30;
	//foo(10, 20, 30);
	func2(a, b, c);

	return 0;
}