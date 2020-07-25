#include <iostream>

int main()
{
	using namespace std;

	int i = 0;

	do {
		cout << i++ << ',';
	} while (i < 10);
	cout << endl;

	// petla nieskonczona
	//do {
	//	cout << '1';
	//} while (true);

	return 0;
}