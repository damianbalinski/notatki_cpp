#include <iostream>
#include <utility>

/*
 * MOVE
 * informacja dla kompilatora o mozliwosci zastosowania semantyki przeniesienia,
 * zamienia argument na referencje rwartosciowa
 */
using namespace std;

class C 
{
private:
	int val;
public:
	C(int val = 1) : val(val) {};
	C(const C& c);
	C(C&& c);
	void print() { cout << val << endl; }
};

C::C(const C& c)
{
	cout << "kopiujacy\n";
	this->val = c.val;
}

C::C(C&& c)
{
	cout << "przenoszacy\n";
	this->val = c.val;
	c.val = -1;
}

int main()
{
	C c1(10);

	// KOPIOWANIE
	C c2(c1);
	c1.print();
	c2.print();

	// PRZYPISANIE WYMUSZONE
	C c3(move(c1));
	c1.print();
	c3.print();

	return 0;
}