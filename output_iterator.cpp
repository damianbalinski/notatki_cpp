#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	int val;
	auto iter = std::ostream_iterator<int, char>(cout, ", ");
	//*iter++ = 30;		// OK
	//val = *iter++;	// ERROR
	//iter == ++iter;	// ERROR
	//iter != ++iter;	// ERROR

	return 0;
}