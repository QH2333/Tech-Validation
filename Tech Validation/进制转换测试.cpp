#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//Define the characters needed
const char* BASE = "0123456789ABCDEF";
//Main convertion function
char* generalConverter(int sourceRadix, int targetRadix, char *sourceArr);
//An auxlilary function returning the index, i.e. the actual value of <curChar>
int getIndex(char curChar);
void reverseStr(char* str);


int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	int sourRad, tarRad;
	char sourArr[100];
	cout << "Input the radix(s) of your source number and target number:" << endl;
	cin >> sourRad >> tarRad;
	cout << "Input your sourct number:" << endl;
	cin >> sourArr;
	cout << generalConverter(sourRad, tarRad, sourArr);
	system("pause");
	return 0;
}

char* generalConverter(int sourceRadix, int targetRadix, char *sourceArr)
{
	int sourceLength = strlen(sourceArr);//The length of the source number in source radix
	long sourceNum = 0;//The actual value of the source number
	for (int i = sourceLength - 1; i >= 0; i--)
	{
		sourceNum += getIndex(sourceArr[i]) * (long)pow(sourceRadix, sourceLength - i - 1);
	}
	char* targetArr = (char*)malloc(100 * sizeof(char));//DANGEROUS! FIX IT SOMETIME IN THE FUTURE!
	int targetLength = 0;
	while (sourceNum != 0)
	{
		targetArr[targetLength] = BASE[sourceNum % targetRadix];
		sourceNum /= targetRadix;
		targetLength++;
	}
	targetArr[targetLength] = '\0';
	reverseStr(targetArr);
	return targetArr;
}

int getIndex(char curChar)
{
	int i = 0;
	while (BASE[i] != curChar) i++;
	return i;
}

void reverseStr(char* str)
{
	int length = strlen(str);
	int i = 0;
	int j = length - 1;
	char temp;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}