#include <iostream>
#include <cstdlib>

/*
 * LITERALY GOTOWANE / SUROWE
 * GOTOWANE - przekazuja iteraly w postaci numetycznej
 * SUROWE - przekazuja iteraly w postaci lancucha znakowego
 *
 * jesli zaimplementowano obydwie formy, kompilator wybierze forme ugotowana
 */

using namespace std;

class Distance
{
private:
	double d;
	explicit Distance(double d) : d(d) {}
	void print() { cout << d << " m"; }
public:
	friend ostream& operator<<(ostream& stream, Distance& dist);
	friend Distance operator""_int(unsigned long long int d);		// INTEGER COOKED
	friend Distance operator""_int(const char* str);				// INTEGER RAW
	friend Distance operator""_doub(long double d);					// FLOATINGPOINT COOKED
	friend Distance operator""_doub(const char* str);				// FLOATINGPOINT RAW
};

// PRINT DISTANCE
ostream& operator<<(ostream& stream, Distance& dist) {
	stream << dist.d << " m";
	return stream;
}

// INTEGER COOKED
Distance operator""_int(unsigned long long int d) {
	cout << "integer COOKED\n";
	return Distance(d);
}

// INTEGER RAW
Distance operator""_int(const char* str) {
	cout << "integer RAW\n";
	return Distance(atoi(str));
}

// FLOATINGPOINT COOKED
Distance operator""_doub(long double d) {
	cout << "floatingpoint COOKED\n";
	return Distance(d);
}

// FLOATINGPOINT RAW
Distance operator""_doub(const char* str) {
	cout << "floatingpoint RAW\n";
	return Distance(atof(str));
}

int main()
{
	auto d1 = 100_int;
	auto d2 = 10.0_doub;

	return 0;
}