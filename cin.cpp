#include <iostream>

/*
 * cin.get(c) - pobiera ze strumienia znak po znaku, nawet jesli
 * sa to znaki biale.
 */
int main()
{
	using namespace std;

	int k = 0;
	char c;

	cin >> c;

	while (c != '#')
	{
		cout << c;
		k++;
		cin >> c;
	}

	return 0;
}