#include <iostream>

class MyException {};

void foo()
{
	// OBJECT
	//MyException obj = MyException();
	//printf("obj(1) %p\n", &obj);
	//throw obj;

	// POINTER
	//MyException* ptr = new MyException();
	//printf("ptr(1) %p\n", ptr);
	//throw ptr;

	// REFERENCE
	MyException obj = MyException();
	printf("ref(1) %p\n", &obj);
	throw obj;
}

int main()
{
	try {
		throw 10.0L;
		/*foo();*/
	}
	catch (int) {

	}
	catch (double val) {

	}
	//catch (MyException obj) {
	//	printf("obj(2) %p\n", &obj);
	//}
	catch (MyException* ptr) {
		printf("ptr(2) %p\n", ptr);
	}
	catch (MyException& ref) {
		printf("ref(2) %p\n", &ref);
	}
	catch (...) {
		printf("else...\n");
	}

	return 0;
}