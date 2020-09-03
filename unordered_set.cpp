#include <iostream>
#include <set>
#include <unordered_set>

using std::cout;
using std::endl;

void print(const char* str, std::unordered_set<int> uset)
{
	cout << str << " : ";
	for (auto i : uset) cout << i << ", ";
	cout << endl;
}

void print(const char* str, std::set<int> uset)
{
	cout << str << " : ";
	for (auto i : uset) cout << i << ", ";
	cout << endl;
}

int main()
{
	std::set<int> set;
	std::unordered_set<int> uset;

	print("set", set);
	print("uset", uset);

	uset.insert(5);		set.insert(5);
	uset.insert(1);		set.insert(1);
	uset.insert(10);	set.insert(10);

	print("set", set);
	print("uset", uset);

	return 0;
}