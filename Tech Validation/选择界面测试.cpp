#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	printf("Input your choice(1-9), 0 to exit\n");
	char ch = getchar();
	int bExit = 0;
	while (!bExit)
	{
		if (ch == '\n' || ch == 'r')
		{
			ch = getchar();
			continue;
		}
		else if (ch >= '0' && ch <= '9')
		{
			printf("Valid choice received:%d\n", ch - '0');
			if (ch == '0') bExit = 1;
			while (getchar() != '\n');
		}
		else
		{
			printf("Invalid choice received, try again!\n");
			while (getchar() != '\n');
		}
		if (!bExit) ch = getchar();
	}
	system("pause");
	return 0;
}