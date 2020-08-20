#include <iostream>
//#include <string>
#include <xstring>

using std::string;
using std::cout;
using std::endl;

int main()
{
	cout << typeid(std::basic_string<char>::traits_type).name() << endl;
	cout << typeid(std::basic_string<char>::value_type).name() << endl;
	cout << typeid(std::basic_string<char>::allocator_type).name() << endl;
	cout << typeid(std::basic_string<char>::size_type).name() << endl;
	cout << typeid(std::basic_string<char>::difference_type).name() << endl;
	cout << typeid(std::basic_string<char>::pointer).name() << endl;
	cout << typeid(std::basic_string<char>::const_pointer).name() << endl;
	cout << typeid(std::basic_string<char>::reference).name() << endl;
	cout << typeid(std::basic_string<char>::const_reference).name() << endl;
	cout << typeid(std::basic_string<char>::iterator).name() << endl;
	cout << typeid(std::basic_string<char>::const_iterator).name() << endl;
	cout << typeid(std::basic_string<char>::reverse_iterator).name() << endl;
	cout << typeid(std::basic_string<char>::const_reverse_iterator).name() << endl;

	return 0;
}