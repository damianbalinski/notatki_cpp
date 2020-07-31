#include <iostream>

namespace test1
{
	int TEST1 = 1;

	namespace test11
	{
		int TEST1_A = 11;
	}

	inline namespace
	{
		int TEST1_B = 12;
	}

	namespace
	{
		int TEST1_C = 13;
	}
}

inline namespace test2
{
	int TEST2 = 2;

	namespace test21
	{
		int TEST2_A = 21;
	}

	inline namespace
	{
		int TEST2_B = 22;
	}

	namespace
	{
		int TEST2_C = 23;
	}
}

namespace
{
	int TEST3 = 3;

	namespace test31
	{
		int TEST3_A = 31;
	}

	inline namespace
	{
		int TEST3_B = 32;
	}

	namespace
	{
		int TEST3_C = 33;
	}
}

//inline namespace
//{
//	int TEST4 = 4;
//
//	inline namespace
//	{
//		int TEST4_A = 41;
//	}
//
//	namespace
//	{
//		int TEST4_B = 42;
//	}
//}

int main()
{
	using std::cout;
	using std::endl;

	//cout << TEST1 << endl;
	//cout << TEST1_A << endl;
	//cout << TEST1_B << endl;
	//cout << TEST1_C << endl;
	cout << test1::TEST1 << endl;
	cout << test1::test11::TEST1_A << endl;
	cout << test1::TEST1_B << endl;
	cout << test1::TEST1_C << endl;
	cout << endl;

	cout << TEST2 << endl;
	//cout << TEST2_A << endl;
	cout << TEST2_B << endl;
	cout << TEST2_C << endl;
	cout << test2::TEST2 << endl;
	cout << test2::test21::TEST2_A << endl;
	cout << test2::TEST2_B << endl;
	cout << test2::TEST2_C << endl;
	cout << endl;

	cout << TEST3 << endl;
	// cout << TEST3_A << endl;
	cout << TEST3_B << endl;
	cout << TEST3_C << endl;
	//cout << test3::TEST3 << endl;
	cout << test31::TEST3_A << endl;
	//cout << test3::TEST3_B << endl;
	//cout << test3::TEST3_C << endl;
	cout << endl;

	//cout << TEST4 << endl;
	//cout << TEST4_A << endl;
	//cout << TEST4_B << endl;
	////cout << test4::TEST4 << endl;
	////cout << test4::TEST4_A << endl;
	////cout << test4::TEST4_B << endl;
	//cout << endl;

	return 0;
}