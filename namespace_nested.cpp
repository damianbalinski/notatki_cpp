#include <iostream>
#include <cstdio>

namespace A
{
	void funcA(){ printf("A->funcA\n"); }
	
	namespace B
	{
		void funcA() { printf("B->funcA\n"); }
		void funcB() { printf("B->funcB\n"); }
		
		namespace C
		{
			void funcA() { printf("C->funcA\n"); }
			void funcB() { printf("C->funcB\n"); }
			void funcC() { printf("C->funcC\n"); }
		}
	}
}

int main()
{
	A::funcA();
	//A::funcB();
	//A::funcC();

	A::B::funcA();
	A::B::funcB();
	//A::B::funcC();

	A::B::C::funcA();
	A::B::C::funcB();
	A::B::C::funcC();

	return 0;
}