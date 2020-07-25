#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << std::setprecision(25);

	float a1 = 1.0 / 3.0;
	double a2 = 1.0 / 3.0;
	long double a3 = 1.0 / 3.0;

	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;

	return 0;
}