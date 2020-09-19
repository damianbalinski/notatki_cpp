#include <iostream>

/*
 * WYLICZENIE ZAKRESOWE
 * odwolania do stalych wyliczeniowych wymagaja jawnego okreslenia zasiegu
 */

using namespace std;

enum class MyEnum {
	ONE,
	TWO,
	THREE,
	FOUR,
};

int main()
{
	MyEnum::ONE;
	MyEnum::TWO;
	MyEnum::THREE;
	MyEnum::FOUR;

	return 0;
}