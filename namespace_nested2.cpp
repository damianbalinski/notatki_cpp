#include <iostream>
#include <cstdio>

namespace X
{
	void funcX();
	void funcY();
	void funcZ();

	namespace Y
	{
		void funcX();
		void funcY();
		void funcZ();

		namespace Z
		{
			void funcX();
			void funcY();
			void funcZ();
		}
	}
}

void X::funcX() { printf("X->funcX\n"); }
void X::funcY() { printf("X->funcY\n"); }
void X::funcZ() { printf("X->funcZ\n"); }

void X::Y::funcX() { printf("Y->funcX\n"); }
void X::Y::funcY() { printf("Y->funcY\n"); }
void X::Y::funcZ() { printf("Y->funcZ\n"); }

void X::Y::Z::funcX() { printf("Z->funcX\n"); }
void X::Y::Z::funcY() { printf("Z->funcY\n"); }
void X::Y::Z::funcZ() { printf("Z->funcZ\n"); }

int main()
{
	X::funcX();
	X::funcX();
	X::funcZ();
	putchar('\n');

	X::Y::funcX();
	X::Y::funcX();
	X::Y::funcZ();
	putchar('\n');

	X::Y::Z::funcX();
	X::Y::Z::funcX();
	X::Y::Z::funcZ();
	putchar('\n');

	return 0;
}