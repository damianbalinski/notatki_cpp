#include <iostream>
#include <set>
#include <vector>

using std::cout;
using std::endl;

void print(const char* str, std::set<int> set)
{
	cout << str << " : ";
	for (auto i : set) cout << i << ", ";
	cout << endl;
}

int main()
{
	std::set<int> s = { 1, 2, 3, 4, 5 };
	std::set<int> set = { 1, 2, 3, 4 };
	std::vector<int> vec = { 1, 2, 1, 2 };
	//std::set<int, std::less<int>> s2;

	print("s", s);
	print("set", set);
	auto pair = s.equal_range(3);
	cout << *pair.first << endl;
	cout << *pair.second << endl;
	print("s", s);
	print("set", set);
	return 0;
}