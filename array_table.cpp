#include <iostream>
#include <array>
#define SIZE 5

void fill(std::array<int, SIZE> *nums);
void show(std::array<int, SIZE> nums);

void fill(std::array<int, SIZE>* nums)
{
	for (int i = 0; i < SIZE; i++)
		(*nums)[i] = 100 * i;
}

void show(std::array<int, SIZE> nums)
{
	for (int i = 0; i < SIZE; i++)
		std::cout << i << ": " << nums[i] << std::endl;
}

int main()
{
	std::array<int, SIZE> numbers;
	fill(&numbers);
	show(numbers);

	return 0;
}