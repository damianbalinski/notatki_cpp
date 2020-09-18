#include <iostream>
#include <fstream>

/*
 * METODY PLIKOWE
 */

using namespace std;

int main()
{
	// dane
	const char* filepath = "test.txt";
	ios_base::openmode mode = 1;
	string str_filepath = "test.txt";
	//filesystem::path filesystem_filepath{};

	// strumienie
	ofstream fout("test.txt");

	fout << "test__1" << endl;

	fout.open(filepath);		// [baisc_filebuf&] otwiera plik, dla wejscia domyslnie in, dla wyjscia domyslnie out | trunc
	fout.open(filepath, mode);
	fout.open(str_filepath);
	fout.open(str_filepath, mode);
	//fout.open(filesystem_filepath);
	//fout.open(filesystem_filepath, mode);

	fout.close();			// zamyka plik, nie usuwa strumienia

	fout.is_open();			// sprawdza, czy pstrumien jest polaczony z plikiem

	return 0;
}