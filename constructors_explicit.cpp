#include <iostream>

class C
{
public:
	explicit C() {};
	explicit C(int) {};
};
int main()
{
	C c1;
	C c2 { 10 };
	C c3 = { 10 };

	return 0;
}