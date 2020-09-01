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
	auto iter = std::istream_iterator<int, char>(cin);
	//*iter++ = 30;		// ERROR
	//val = *iter++;	// OK
	auto iter1 = *iter++;
	auto iter2 = *iter++;
	cout << (iter1 != iter2) << endl;

	return 0;
}