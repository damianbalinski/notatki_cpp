#include <iostream>

/*
 * DELEGOWANIE KONSTRUKTOROW
 */

using namespace std;

class C
{
public:
	C() : C(0, 0.0) { cout << "()\n"; };
	C(int v1, double v2) { cout << "(int, double)\n"; }
	C(int v1) : C(v1, 0.0) { cout << "(int)\n"; }
	C(double v2) : C(0, v2) { cout << "(double)\n"; }
};
int main()
{
	C();
	C(10);
	C(10.0);
	C(10, 10.0);

	return 0;
}