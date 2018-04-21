#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 | 128);
    //cout << "Hello world!" << endl;
    system("pause");
    return 0;
}