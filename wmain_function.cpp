#include <iostream>

using namespace std;

//int wmain()
//{
//	cout << "wmain 1" << endl;
//	return 0;
//}

//int wmain(int argc, wchar_t* argv[])
//{
//	cout << "wmain 2A" << endl;
//	for (int i = 0; i < argc; i++)
//		printf("%ls\n", argv[i]);
//	return 0;
//}

//int wmain(int argc, wchar_t** argv)
//{
//	cout << "main 2B" << endl;
//	while (*argv != NULL)
//		printf("%ls\n", *argv++);
//	return 0;
//}

//int wmain(int argc, wchar_t* argv[], wchar_t* envp[])
//{
//	cout << "main 3A" << endl;
//	while (*envp != NULL)
//		printf("%ls\n", *envp++);
//	return 0;
//}

int wmain(int argc, wchar_t** argv, wchar_t** envp)
{
	cout << "main 3B" << endl;
	while (*envp != NULL)
		printf("%ls\n", *envp++);
	return 0;
}
