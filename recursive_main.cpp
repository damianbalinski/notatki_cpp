#include <iostream>

int COUNTER = 0;

int main()
{
	using namespace std;

	if (COUNTER < 10) {
		cout << COUNTER++ << endl;
		int res = main();
		cout << "res = " << res << endl;
	}

	return 0;
}