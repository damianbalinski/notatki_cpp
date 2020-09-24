#include <iostream>

/*
 * LITERALY UZYTKOWNIKA
 * poza literalami z biblioteki standardowej, wszystkie literaly
 * zdefiniowane przez uzytkownika musza sie rozpoczynac znakiem podlogi
 // TODO nie wolno czy raczej nie powinno sie???
 */

using namespace std;

class Distance
{
private:
	double val;
	explicit Distance(long double val) : val(val) {}
public:
	friend Distance operator "" _km(long double val);
	friend Distance operator "" _m(long double val);
	friend Distance operator "" _cm(long double val);
	friend Distance operator "" _mm(long double val);
	void print() { cout << val << " m" << endl; }
};

Distance operator "" _km(long double val) { return Distance(1000 * val); };
Distance operator "" _m(long double val) { return Distance(val); };
Distance operator "" _cm(long double val) { return Distance(0.01 * val); };
Distance operator "" _mm(long double val) { return Distance(0.001 * val); };

// TODO
//template<char...>
//int operator "" _t();

int main()
{
	auto km = 1.0_km;
	auto m = 1.0_m;
	auto cm = 1.0_cm;
	auto mm = 1.0_mm;

	km.print();
	m.print();
	cm.print();
	mm.print();

	return 0;
}