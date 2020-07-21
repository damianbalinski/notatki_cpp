#include <iostream>

using namespace std;

//int main()
//{
//	cout << "main 1" << endl;
//	return 0;
//}

//int main(int argc, char* argv[])
//{
//	cout << "main 2A" << endl;
//	for (int i = 0; i < argc; i++)
//		cout << argv[i];
//	return 0;
//}

//int main(int argc, char** argv)
//{
//	cout << "main 2B" << endl;
//	while (*argv != NULL)
//		cout << *argv++ << endl;
//	return 0;
//}

//int main(int argc, char* argv[], char* envp[])
//{
//	cout << "main 3A" << endl;
//	while (*envp != NULL)
//		cout << *envp++ << endl;
//	return 0;
//}

int main(int argc, char** argv, char** envp)
{
	cout << "main 3B" << endl;
	while (*envp != NULL)
		cout << *envp++ << endl;
	return 0;
}
