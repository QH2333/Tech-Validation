#include <stdio.h>
#include <windows.h>

void draw(int);

int main()
{
	int i;
	float s = 0, v = 5, a = -0.1;
	for (i = 1; v + a * i >= 0; i++)
	{
		s = (int)(v*i + 0.5*a*i*i);
		system("cls");
		draw(s);
		Sleep(10);
	}
	system("pause");
}

void draw(int count)
{
	int i;
	for (i = 0; i <= count; i++)
	{
		printf(" ");
	}
	printf("*");
}