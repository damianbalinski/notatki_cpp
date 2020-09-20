#include <iostream>
#include <functional>

using namespace std;

int main()
{
	using namespace std::placeholders;

	cout << typeid(_1).name() << endl;
	cout << typeid(_2).name() << endl;
	cout << typeid(_3).name() << endl;
	cout << typeid(_4).name() << endl;
	cout << typeid(_5).name() << endl;
	cout << typeid(_6).name() << endl;
	cout << typeid(_7).name() << endl;
	cout << typeid(_8).name() << endl;
	cout << typeid(_9).name() << endl;
	cout << typeid(_10).name() << endl;
	cout << typeid(_11).name() << endl;
	cout << typeid(_12).name() << endl;
	cout << typeid(_13).name() << endl;
	cout << typeid(_14).name() << endl;
	cout << typeid(_15).name() << endl;
	cout << typeid(_16).name() << endl;
	cout << typeid(_17).name() << endl;
	cout << typeid(_18).name() << endl;
	cout << typeid(_19).name() << endl;
	cout << typeid(_20).name() << endl;

	return 0;
}