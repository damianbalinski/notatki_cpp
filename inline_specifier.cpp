#include <iostream>

/*
 * SPECYFIKATOR INLINE
 * 
 * FUNKCJA / METODA
 * sugestia dla kompilatora aby przeprowadzil optymalizacje wywolania funkcji/metody
 * (np. poprzez wstawienie ciala metody/funkcji w miejscu wywolania), funkcja inline
 * ma automatycznie lacznosc wewnetrzna, moze byc zadeklarowana wielokrotnie, ale w
 * roznych jednostkach translacji, wszystkie deklaracje musza byc jednakowe

 * ZMIENNA POZA BLOKIEM
 * ma automatycznie lacznosc wewnetrzna, moze byc zadeklarowana wielokrotnie, ale w
 * roznych jednostkach translacji, wszystkie deklaracje musza byc jednakowe
 *
 * ZMIENNA WEWNATRZ BLOKU (TYLKO STATYCZNA W KLASIE)
 * ma automatycznie lacznosc wewnetrzna, moze byc zadeklarowana wielokrotnie, ale w
 * roznych jednostkach translacji, wszystkie deklaracje musza byc jednakowe
 */

// FUNKCJA INLINE
inline void func() {};

// METODA INLINE
// STATYCZNA ZMIENNA INLINE W KLASIE
class C
{
public:
	inline static int v = 10;
	inline void func();
};
void C::func() {}

// ZMIENNA INLINE
inline int val = 10;

using namespace std;

int main()
{
	// TEST
	C c;
	cout << c.v << endl;
	c.v = 20;
	cout << c.v << endl;

	return 0;
}