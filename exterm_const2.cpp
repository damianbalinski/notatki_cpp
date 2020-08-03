#include <cstdio>

// LACZNOSC WEWNETRZNA
static int a1;
static int a2 = 20;
static int a3;
static int a4 = 20;
const int a5 = 10;

// DO LACZNOSCI ZEWNETRZNEJ - deklaracja nawiazujaca
extern int b1;
extern int b2;
extern const int b3;

// DO LACZNOSCI ZEWNETRZNEJ - deklaracja definiujace
int c1;
int c2 = 20;
extern const int c3 = 20;

// TEST

void foo()
{
	printf("%d\n", b3);
	printf("%d\n", c3);
	printf("\n");
}