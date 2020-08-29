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
	C(int c) : c(c) { printf("init %d\n", c); }
	C() : c(-1) { printf("init def\n", c);  }
	~C() { printf("delete %d\n", c); }
};

unique_ptr<C> getPtr(C* c)
{
	unique_ptr<C> ptr(c);
	return ptr;
}

int main()
{
	{
		unique_ptr<C> ptr1(new C(1));					// wskaznik na obiekt
		unique_ptr<C> ptr2;
		unique_ptr<C[]> tab(new C[5]);					// wskaznik na tablice obiektow

		ptr1 = unique_ptr<C>(new C(2));

		//ptr2 = ptr1;									// ERROR, not temp rvalue
		ptr2 = std::move(unique_ptr<C>(new C(10)));		// OK, temp rvalue
		ptr2 = unique_ptr<C>(new C(10));				// OK, temp rvalue
		ptr2 = getPtr(new C(2));						// OK, temp rvalue
	}

	{
		int* ptr = new int(10);
		nullptr_t nul;
		auto_ptr<int> aut;
		unique_ptr<int> uni;
		shared_ptr<int> sha;
		weak_ptr<int> wea;

		unique_ptr<int> p1;							// DEFAULT
		unique_ptr<int> p2{ nul };					// NULLPTR
		unique_ptr<int> p3{ ptr };					// POINTER
		//unique_ptr<int> p4{ aut };				// AUTO LVALUE
		unique_ptr<int> p5{ auto_ptr<int>() };		// AUTO RVALUE
		//unique_ptr<int> p6{ uni };				// UNIQUE LVALUE
		unique_ptr<int> p7{ unique_ptr<int>()};		// UNIQUE RVALUE
		//unique_ptr<int> p8{ sha };				// SHARED LVALUE
		//unique_ptr<int> p9{ shared_ptr<int>() };	// SHARED RVALUE
		//unique_ptr<int> p10{ wea };				// WEAK LVALUE
		//unique_ptr<int> p11{ weak_ptr<int>() };	// WEAK RVALUE
	}

	return 0;
}