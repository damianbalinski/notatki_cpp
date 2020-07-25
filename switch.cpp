#include <iostream>

int foo() { return 1; }

int main()
{
	using namespace std;

	// SWITCH
	switch (0) {
	case 0:	
		cout << 0;
		break;
	case 1:
		cout << 1;
		break;
	default:
		cout << "def";
		break;
	}

	// SWITCH Z INICJALIZACJA
	switch (int s = foo(), s1 = foo();  ++s1) {
	case 0:
		cout << 0;
		break;
	case 1:
		cout << 1;
		break;
	default:
		cout << "def";
		break;
	}

	return 0;
}