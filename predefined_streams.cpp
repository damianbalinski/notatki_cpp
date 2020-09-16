#include <iostream>
#include <ostream>
#include <fstream>

/*
 * PREDEFINIOWANE STRUMIENIE
 * nazwa / klasa / typ_strumienia / typ_danych / czy_buforowany
 */

using namespace std;

int main()
{
	cin;		// istream		IN		char		BUF
	wcin;		// wistream		IN		wchar_t		BUF

	cout;		// ostream		OUT		char		BUF
	wcout;		// wostream		OUT		wchar_t		BUF

	cerr;		// ostream		ERR		char		NOT_BUF
	wcerr;		// wostream		ERR		wchar_t		NOT_BUF

	clog;		// ostream		ERR		char		BUF
	wclog;		// wostream		ERR		wchar_t		BUF

	/*
	 * IN - standardowy strumien wejsciowy
	 * OUT - standartowy strumien wyjsciowy
	 * ERR - standardowy strumien bledow
	 *
	 * BUF - buforowany
	 * NOT_BUF - nie buforowany
	 */

	return 0;
}