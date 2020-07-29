#include <iostream>

template<typename T, typename U>
auto foo(T t, U u) -> decltype(t + u)
{
	return t + u;
}

int main()
{
	using namespace std;

	auto a1 = foo(10, 10);
	auto a2 = foo(10, 10.);
	auto a3 = foo(10., 10);
	auto a4 = foo(10., 10.);

	auto b1 = foo(NULL, 1);
	auto b2 = foo((int*)NULL, 1);
	auto b3 = foo((char*)NULL, 1);
	auto b4 = foo((double*)NULL, 1);

	cout << typeid(a1).name() << endl;
	cout << typeid(a2).name() << endl;
	cout << typeid(a3).name() << endl;
	cout << typeid(a4).name() << endl;

	cout << typeid(b1).name() << endl;
	cout << typeid(b2).name() << endl;
	cout << typeid(b3).name() << endl;
	cout << typeid(b4).name() << endl;

	return 0;
}