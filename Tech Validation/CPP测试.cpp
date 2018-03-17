#include <iostream>
#include <windows.h>

using namespace std;

int main6()//main6
{
	int score;
	cin >> score;

	cout << (score > 60 ? "Pass" : "Fail") << endl;
	cin >> score;

	cout << (score > 60 ? "Pass" : "Fail") << endl;
	//cout << (char)getchar() << endl;
	system("pause");
	return 0;
}