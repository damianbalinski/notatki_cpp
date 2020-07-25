#include <iostream>

int main()
{
	using namespace std;

	int i = 0;

	while (i < 10)
		cout << i++ << ',';
	cout << endl;

	// petla nieskonczona
	//while (true)
	//{
	//	cout << '0';
	//}
	return 0;
}