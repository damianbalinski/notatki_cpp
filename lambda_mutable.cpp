#include <iostream>
#define PRINT(N, V) cout << N << " " << V << endl

/*
 * LAMBDA MUTUJACA
 * pozwala na modyfikacje wartosci zmiennej tylko w obrebie lambdy
 */

using namespace std;

int main()
{
	int val = 10;

	PRINT(0, val);

	[=]() mutable
	{
		PRINT(1, val);
		val = -10;
		PRINT(2, val);
	}();

	PRINT(3, val);

	return 0;
}