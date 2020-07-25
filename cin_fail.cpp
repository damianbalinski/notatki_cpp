#include <iostream>

/*
 * fail zwraca true, jesli ustawiono bit eifbit lub failbit
 */
int main()
{
	using namespace std;

	char c;

	//cin.get(c);
	//while (!cin.fail()) {
	//	cout << c;
	//	cin >> c;
	//}

	while (cin.get(c)) {
		cout << c;
	}

	cout << endl << "end" << endl;

	return 0;
}