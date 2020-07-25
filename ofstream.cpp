#include <fstream>

int main()
{
	using namespace std;

	// open file
	ofstream out_file;
	out_file.open("test.txt");

	// save data into file
	out_file << "test1" << endl;
	out_file << "test2" << endl;
	out_file << "test3" << endl;

	// close file
	out_file.close();

	return 0;
}