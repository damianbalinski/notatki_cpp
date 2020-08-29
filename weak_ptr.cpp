#include <iostream>

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::auto_ptr;

int main()
{
	{
		int* ptr = new int(10);
		nullptr_t nul;
		auto_ptr<int> aut;
		unique_ptr<int> uni;
		shared_ptr<int> sha;
		weak_ptr<int> wea;

		weak_ptr<int> p1;							// DEFAULT
		//weak_ptr<int> p2{ nul };					// NULLPTR
		//weak_ptr<int> p3{ ptr };					// POINTER
		//weak_ptr<int> p4{ aut };					// AUTO LVALUE
		//weak_ptr<int> p5{ auto_ptr<int>() };		// AUTO RVALUE
		//weak_ptr<int> p6{ uni };					// UNIQUE LVALUE
		//weak_ptr<int> p7{ unique_ptr<int>() };	// UNIQUE RVALUE
		weak_ptr<int> p8{ sha };					// SHARED LVALUE
		weak_ptr<int> p9{ shared_ptr<int>() };	// SHARED RVALUE
		weak_ptr<int> p10{ wea };					// WEAK LVALUE
		weak_ptr<int> p11{ weak_ptr<int>() };		// WEAK RVALUE
	}

	return 0;
}