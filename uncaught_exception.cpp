#include <iostream>
#include <cstdio>

// WYJATEK NIEPRZECHWYCONY

void handler()
{
	printf("uncaught\n");
}

int main()
{
	std::set_terminate(handler);

	try {
		throw 10.0;
	}
	catch (int) {

	}

	return 0;
}