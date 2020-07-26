#include <iostream>

int main()
{
	using namespace std;

	int v1 = 10;
	const int v2 = 10;

	int* p1;
	const int* p2;

	int** pp1;
	const int** pp2;

	// przy jednym poziomie przekierowania, wskaznikowi const mozna przypisac
	// adres nie-const, ale nie na odwrot
	p1 = &v1;
	//p1 = &v2;	// ERROR
	p2 = &v1;
	p2 = &v2;

	// przy wiecej niz jednym poziomie przekierowania, wskaznikowi const nie 
	// mozna przypisac wartosci nie-const (wskaznikowi const nie mozna przypisac
	// wskaznika nie-const)
	pp1 = &p1;
	// pp1 = &p2;	// ERROR
	// pp2 = &p1;	// ERROR
	pp2 = &p2;


	return 0;
}