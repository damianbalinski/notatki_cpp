#include <iostream>
#include <memory>

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::auto_ptr;

using std::cout;
using std::endl;

class C
{
public:
	int c;
	C(int c) : c(c) {}
	C() : c(-1) {}
};

int main()
{
	{
		auto_ptr<C> ptr1(new C(1));			// wskaznik na obiekt
		auto_ptr<C> ptr2;
		//auto_ptr<C[]> tab(new C[5]);		// ERROR wskaznik na tablice obiektow
		
		cout << ptr1->c << endl;

		ptr2 = ptr1;
		auto_ptr<C> ptr3 = ptr1;

		cout << ptr2->c << endl;
		cout << ptr1->c << endl;
	}

	{
		int* ptr = new int(10);
		nullptr_t nul;
		auto_ptr<int> aut;
		unique_ptr<int> uni;
		shared_ptr<int> sha;
		weak_ptr<int> wea;

		auto_ptr<int> p1;							// DEFAULT
		auto_ptr<int> p2{ nul };					// NULLPTR
		auto_ptr<int> p3{ ptr };					// POINTER
		auto_ptr<int> p4{ aut };					// AUTO LVALUE
		auto_ptr<int> p5{ auto_ptr<int>() };		// AUTO RVALUE
		//auto_ptr<int> p6{ uni };					// UNIQUE LVALUE
		//auto_ptr<int> p7{ unique_ptr<int>() };	// UNIQUE RVALUE
		//auto_ptr<int> p8{ sha };					// SHARED LVALUE
		//auto_ptr<int> p9{ shared_ptr<int>() };	// SHARED RVALUE
		//auto_ptr<int> p10{ wea };					// WEAK LVALUE
		//auto_ptr<int> p11{ weak_ptr<int>() };		// WEAK RVALUE
	}
	return 0;
}