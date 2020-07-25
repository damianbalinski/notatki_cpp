#include <iostream>

int main()
{
	using namespace std;

	int k = 0;
	char c;

	cin.get(c);
	while (c != '#')
	{
		cout << c;
		k++;
		cin.get(c);
	}

	cout << endl << "k = " << k << endl;

	return 0;
}