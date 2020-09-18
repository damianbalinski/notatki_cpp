#include <iostream>

/*
 * STALE ZDARZEN
 * ios_base::event
 */

using namespace std;

int main()
{
	ios_base::erase_event;		// rzucany przed wywolaniem ~ios_base() lub copyfmt()
	ios_base::imbue_event;		// rzucany przed wywolaniem imbue()
	ios_base::copyfmt_event;	// rzucany przed wywolaniem copyfmt()

	return 0;
}