#include <iostream>

using std::cout;
using std::endl;

class Test
{
private:
	const char* str;

public:
	Test(const char* str);
	~Test();
};

Test::~Test() 
{
	cout << "bye" << str << endl;
}

Test::Test(const char* str_n)
{
	str = str_n;
	cout << "hello" << str << endl;
}

int main()
{
	/*
	 * Obiekty sa odkladane na stosie, dlatego sa zwalniane w odwrotnej
	 * kolejnosci niz przebiega alokacja.
	 */
	{
		Test test1 = Test("test1");
		{
			Test test2 = Test("test2");
		}
		Test test3 = Test("test3");
	}

	return 0;
}