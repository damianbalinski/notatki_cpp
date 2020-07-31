#include <iostream>
#include <new>
#define MAX 1024
#define INIT_LIST1 {1, 2, 3, 4, 5}
#define INIT_LIST2 {6, 7, 8, 9, 10}
#define N 5

char BUFF[MAX];

void print_list(int* tab, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << tab[i] << ", ";
	std::cout << std::endl;
}

int main()
{
	int* tab1 = new int[N] INIT_LIST1;
	int* tab2 = new(BUFF) int[N] INIT_LIST1;
	int* tab3;
	int* tab4;

	print_list(tab1, N);
	print_list(tab2, N);
	std::cout << std::endl;

	tab3 = new int[N] INIT_LIST2;
	tab4 = new(BUFF) int[N] INIT_LIST2;

	print_list(tab1, N);
	print_list(tab2, N);
	print_list(tab3, N);
	print_list(tab4, N);

	std::cout << tab1 << std::endl;
	std::cout << tab2 << std::endl;
	std::cout << tab3 << std::endl;
	std::cout << tab4 << std::endl;

	return 0;
}