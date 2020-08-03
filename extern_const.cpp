// UWAGA - kompilowac razem z plikiem extern_const2.cpp
#include <cstdio>
void foo();

// LACZNOSC WEWNETRZNA
static int a1;
static int a2 = 10;
static const int a3;
static const int a4 = 10;
const int a5 = 10;

// LACZNOSC ZEWNETRZNA - deklaracja definujace
int b1;
int b2 = 10;
extern const int b3 = 10;

// LACZNOSC ZEWNETRZNA - deklaracja nawiazujaca
extern int c1;
extern int c2;
extern const int c3;

// TEST


int main() 
{ 
	foo();

	printf("%d\n", b3);
	printf("%d\n", c3);
}
