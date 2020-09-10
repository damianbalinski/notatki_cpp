#include <iostream>
#include <list>
#include <set>

using namespace std;

void print(list<int> l)
{
	for (auto i : l) cout << i << ", ";
	cout << endl;
}

void print(set<int> l)
{
	for (auto i : l) cout << i << ", ";
	cout << endl;
}

bool predb(int a, int b)
{
	return b == a + 1;
}

int main()
{
	set<int> s1 = { 1, 2, 3, 4 };
	set<int> s2 = { 5, 6, 7, 8 };

	print(s1);
	print(s2);
	s1.merge(s2);
	print(s1);
	print(s2);

	return 0;
}