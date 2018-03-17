#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
	int i = 1;
	char ch;
	while (i)
	{
		printf("getchar:%d\n", getchar());
		//printf("getch:%d\n", _getch());
	}

	system("pause");
	return 0;
}