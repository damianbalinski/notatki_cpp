#include <iostream>
#include <functional>

int main()
{
	typedef int Type;
	
	// arytmetyczne
	std::plus<Type>;
	std::minus<Type>;
	std::multiplies<Type>;
	std::divides<Type>;
	std::modulus<Type>;
	std::negate<Type>;			// unarny
	
	// porownania
	std::equal_to<Type>;
	std::not_equal_to<Type>;
	std::greater<Type>;
	std::greater_equal<Type>;
	std::less<Type>;
	std::less_equal<Type>;

	// logiczne
	std::logical_and<Type>;
	std::logical_or<Type>;
	std::logical_not<Type>;		// unarny

	// bitowe
	std::bit_and<Type>;
	std::bit_or<Type>;
	std::bit_xor<Type>;
	std::bit_not<Type>;			// unarny
	
	return 0;
}