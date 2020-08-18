#include <iostream>
#include <cstdio>

/*
 * CONST CAST - COMPILE-TIME
 * const_cast<Type*>(ptr)
 * zmiana etykiet const/volatile, 
 
 * typy obiektow moga sie roznic jedynie obecnoscia lub brakiem 
 * kwalifikatorow const / volatile
 * modyfikowanie wartosci zadeklarowanej pierwotnie jako const/volatile 
 * jest niezdefiniowane
 * nie konwertuje wskaznikow do funkcji oraz wskaznikow do metod
 * bezpieczny dla wskaznikow zerowych
 */
void print(int a1, int a2, int a3, int a4)
{
	printf("(%d,%d,%d,%d)\n", a1, a2, a3, a4);
}

int main()
{
	int a1				  = 0;
	const int a2		  = 0;
	volatile int a3		  = 0;
	const volatile int a4 = 0;

	int* p1;
	const int* p2;
	volatile int* p3;
	const volatile int* p4;

	// NOTHING DONE
	print(a1,a2,a3,a4);

	// CAST TO INT
	p1 = const_cast<int*>(&a1);	*p1 = 10;
	p1 = const_cast<int*>(&a2);	*p1 = 10;
	p1 = const_cast<int*>(&a3);	*p1 = 10;
	p1 = const_cast<int*>(&a4);	*p1 = 10;
	print(a1, a2, a3, a4);

	// CAST TO CONST INT
	p2 = const_cast<const int*>(&a1); /**p2 = 20;*/
	p2 = const_cast<const int*>(&a2); /**p2 = 20;*/
	p2 = const_cast<const int*>(&a3); /**p2 = 20;*/
	p2 = const_cast<const int*>(&a4); /**p2 = 20;*/
	print(a1, a2, a3, a4);

	// CAST TO VOLATILE INT
	p3 = const_cast<volatile int*>(&a1); *p3 = 30;
	p3 = const_cast<volatile int*>(&a2); *p3 = 30;
	p3 = const_cast<volatile int*>(&a3); *p3 = 30;
	p3 = const_cast<volatile int*>(&a4); *p3 = 30;
	print(a1, a2, a3, a4);

	// CAST TO VOLATILE CONST INT
	p4 = const_cast<volatile const int*>(&a1); /**p4 = 40;*/
	p4 = const_cast<volatile const int*>(&a2); /**p4 = 40;*/
	p4 = const_cast<volatile const int*>(&a3); /**p4 = 40;*/
	p4 = const_cast<volatile const int*>(&a4); /**p4 = 40;*/
	print(a1, a2, a3, a4);

	// NULL POINTER
	void* null = nullptr;
	void* temp = const_cast<void*>(null);
	printf("(%p,%p)\n", null, temp);

	return 0;
}