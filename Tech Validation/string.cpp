#include <iostream>
#include <string.h>
#include <windows.h>

int main3()//main3
{
	char str1[20] = "Hello";
	char str2[10] = "World";
	char str3[10];
	strcat_s(str3, 10, "World");
	puts(str1);
	system("pause");
	return 0;
}