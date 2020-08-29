#include <iostream>

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::auto_ptr;

int main()
{
	{
		shared_ptr<int> s1(new int);		// wskaznik na zmienna
		shared_ptr<int[]> tab1(new int[5]);	// TODO ERROR wskaznik na tablice

		unique_ptr<int> u1(new int);
		//unique_ptr<int> u2(s1);						// ERROR
		shared_ptr<int> ptr(unique_ptr<int>(new int));	// OK
	}

	{
		int* ptr = new int(10);
		nullptr_t nul;
		auto_ptr<int> aut;
		unique_ptr<int> uni;
		shared_ptr<int> sha;
		weak_ptr<int> wea;

		shared_ptr<int> p1;							// DEFAULT
		shared_ptr<int> p2{ nul };					// NULLPTR
		shared_ptr<int> p3{ ptr };					// POINTER
		//shared_ptr<int> p4{ aut };					// AUTO LVALUE
		shared_ptr<int> p5{ auto_ptr<int>() };		// AUTO RVALUE
		//shared_ptr<int> p6{ uni };					// UNIQUE LVALUE
		shared_ptr<int> p7{ unique_ptr<int>() };	// UNIQUE RVALUE
		shared_ptr<int> p8{ sha };					// SHARED LVALUE
		shared_ptr<int> p9{ shared_ptr<int>() };	// SHARED RVALUE
		shared_ptr<int> p10{ wea };					// WEAK LVALUE
		shared_ptr<int> p11{ weak_ptr<int>() };		// WEAK RVALUE
	}

	return 0;
}