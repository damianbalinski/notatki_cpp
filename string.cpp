#include <iostream>

int main()
{
	using std::cout;
	using std::endl;
	using std::string;
	using std::ios_base;

	string str1 = "abc";
	string str2 = "abc";

	cout.setf(ios_base::boolalpha);

	cout << (str1 < str2) << endl;
	cout << (str1 == str2) << endl;
	cout << (str1 > str2) << endl;
	cout << (str1 != str2) << endl;

	return 0;
}