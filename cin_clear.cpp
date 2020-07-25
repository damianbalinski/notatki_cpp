#include <iostream>

#define MAX 5

int main()
{
	using namespace std;
	
	int count = 0;
	int val[MAX];

	while (count < MAX)
	{
		printf("num %d: ", count);

		while (!(cin >> val[count]))
		{
			cin.clear();
			while (cin.get() != '\n')
				;
			printf("one more: ");
		}

		count++;
	}

	cout << "values:\n";
	for (int i : val)
		cout << i << endl;

	return 0;
}