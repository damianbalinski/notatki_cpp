#include <iostream>

namespace
{
	int MAX = 100;
	int MIN = -100;
}

namespace test
{
	int TEST = 10;
	namespace
	{
		//TEST = 20;	// ERROR
	}
}
int main()
{
	std::cout << MIN << std::endl;
	std::cout << MAX << std::endl;

	return 0;
}