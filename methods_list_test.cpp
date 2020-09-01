#include <iostream>
#include <list>
#include <forward_list>

using std::endl;
using std::cout;

void print(const char* s, std::list<int> l)
{
	cout << s << " : ";
	for (auto i : l) cout << i << ", ";
	cout << endl;
}

void print(const char* s, std::forward_list<int> f)
{
	cout << s << " : ";
	for (auto i : f) cout << i << ", ";
	cout << endl;
}

bool pred1(int val)
{
	return val % 2 == 0;
}

bool pred2(const int val1, const int val2)
{
	return val1 == val2;
}

int main()
{
	std::list<int> l1 = { 0, 0, 1, 1, 0, 1, 2 };
	std::list<int> l2 = { 10, 11, 13 };
	int val = -1;
	auto iterl = l1.begin();
	auto iterl1 = l2.begin();
	auto iterl2 = l2.end();
	iterl2--;

	std::forward_list<int> f1 = { 0, 1, 2 };
	std::forward_list<int> f2 = { 10, 11, 13 };
	auto iterf = f1.begin();
	auto iterf1 = f2.begin();
	auto iterf2 = f2.end();

	//print("l1", l1);
	//print("l2", l2);
	//l1.splice(iterl, l2, iterl1, iterl2);
	//print("l1", l1);
	//print("l2", l2);

	//print("f1", f1);
	//print("f2", f2);
	//f1.splice_after(iterf, f2);
	//f1.splice_after(iterf, f2, iterf1);
	//f1.splice_after(iterf, f2, iterf1, iterf2);
	//print("f1", f1);
	//print("f2", f2);
	
	print("l1", l1);
	print("l2", l2);
	l1.unique();
	//l1.unique(pred2);
	print("l1", l1);
	print("l2", l2);

	return 0;
}