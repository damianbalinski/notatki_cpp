#include <iostream>
#include <functional>

/*
 * BINDER - klasa, przeksztalca adaptowalny funktor dwuargumentowy
 * na adaptowalny funktor jednoargumentowy
 */

/*
 * BIND - funkcja, zwracajaca adaptowalny funktor jednoargumentowy z
 * podanego adaptowalnego funktora dwuargumentowego

 */

using std::multiplies;
using std::divides;
using std::cout;
using std::endl;

int main()
{
	// dane
	int lval = 10;
	int rval = 3;
	multiplies<int> mult;
	divides<int> div;

	// BINDER
	std::binder1st<multiplies<int>> multl(multiplies<int>(), lval);
	std::binder2nd<multiplies<int>> multr(multiplies<int>(), rval);

	cout << mult(lval, rval) << endl;
	cout << multl(rval) << endl;
	cout << multr(lval) << endl;

	// BIND
	auto divl = std::bind1st(divides<int>(), lval);
	auto divr = std::bind2nd(divides<int>(), rval);

	cout << div(lval, rval) << endl;
	cout << divl(rval) << endl;
	cout << divr(lval) << endl;

	return 0;
}