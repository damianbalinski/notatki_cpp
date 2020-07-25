#include <iostream>

int main()
{
	using namespace std;

	/*
	 * POJEDYNCZE WYRAZENIE INICJALIZUJACE
	 * 
	 */
	int x1 = 10;

	/*
	 * LISTA WYRAZEN INICJALIZUJACYCH
	 * - lista wyrazen oddzielona przecinkami
	 */
	int y1(10);
	int y2 = (10);

	/*
	 * LISTA INICJALIZUJACA
	 * - jesli pusta, wartosc jest zerowana
	 */
	int z1{ 10 };	// nie zezwala na konwersje zawezajaca
	int z2 = { 10 };
	int b1{};
	int b2 = {};	// inicjalizacja do wartosci zerowej


	cout << "x1 = " << x1 << endl;
	cout << "y1 = " << y1 << endl;
	cout << "y2 = " << y2 << endl;
	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;

	cout << "b1 = " << b1 << endl;
	cout << "b2 = " << b2 << endl;

	return 0;
}