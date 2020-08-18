#include <iostream>
#include <cstdio>

/*
 * DYNAMIC CAST - RUN-TIME
 * dynamic_cast<Type*>(ptr)
 * probuje bezpiecznie zrzutowac wskaznik ptr* na typ Type*
 *
 * konwersja jest mozliwa po drzewie dziedziczenia w gore/dol/na boki
 * rzutowanie w dol mozliwe tylko dla klas polimorficznych
 * w przypadku porazki dla wskaznika zwraca wskaznik zerowy,
 * w przypadku porazki dla referencji rzuca wyjatek bad_cast,
 * mozliwe zutowanie do typu tak samo/bardziej wykwalifikowanego (const/volatile)
 */

class A { public: virtual ~A() = default; };
class B : public A { public: virtual ~B() = default; };
class C : public A { public: virtual ~C() = default; };

void print(void* p1, void* p2, void* p3)
{
	printf("(%p,%p,%p)\n", p1, p2, p3);
}

int main()
{

	// POINTER
	A* a = new A();
	B* b = new B();
	C* c = new C();

	// CAST TO A*
	A* a1 = dynamic_cast<A*>(a);	// -- 
	A* a2 = dynamic_cast<A*>(b);	// rzutowanie w gore
	A* a3 = dynamic_cast<A*>(c);	// rzutowanie w gore
	print(a1, a2, a3);

	// CAST TO B*
	B* b1 = dynamic_cast<B*>(a);	// rzutowanie w dol
	B* b2 = dynamic_cast<B*>(b);	// --
	B* b3 = dynamic_cast<B*>(c);	// rzutowanie na boki
	print(b1, b2, b3);
	
	// CAST TO C*
	C* c1 = dynamic_cast<C*>(a);	// rzutowanie w dol
	C* c2 = dynamic_cast<C*>(b);	// rzutowanie na bok
	C* c3 = dynamic_cast<C*>(c);	// --
	print(c1, c2, c3);


	// REFERENCE
	A& ra = *new A;
	B& rb = *new B;
	C& rc = *new C;

	// CAST TO A&
	A& ra1 = dynamic_cast<A&>(ra);
	A& ra2 = dynamic_cast<A&>(rb);
	A& ra3 = dynamic_cast<A&>(rc);

	// CAST TO B&
	//B& rb1 = dynamic_cast<B&>(ra);	// throw bad_cast
	B& rb2 = dynamic_cast<B&>(rb);
	//B& rb3 = dynamic_cast<B&>(rc);	// throw bad_cast

	// CAST TO C&
	//C& rc1 = dynamic_cast<C&>(ra);	// throw bad_cast
	//C& rc2 = dynamic_cast<C&>(rb);	// throw bad_cast
	C& rc3 = dynamic_cast<C&>(rc);


	// CHANGE CV QUALIFIERS IN POINTERS
	A* p1 = new A;
	const A* p2 = new A;
	//p1 = dynamic_cast<A*>(p2);
	//p1 = dynamic_cast<const A*>(p2);
	p2 = dynamic_cast<A*>(p1);
	p2 = dynamic_cast<const A*>(p1);


	// CHANGE CV QUALIFIERS IN REFERENCES
	A& r1 = *new A;
	const A& r2 = *new A;
	//A& r11 = dynamic_cast<A&>(r2);
	//A& r12 = dynamic_cast<const A&>(r2);
	const A& r21 = dynamic_cast<A&>(r1);
	const A& r22 = dynamic_cast<const A&>(r1);


	//TODO dynamic_cast<void*>(ptr)

	//T* t = new T();
	//U* u = new U();
	//void* p1;
	//void* p2;

	//p1 = dynamic_cast<void*>(t);
	//((T*)p1)->foo();

	return 0;
}