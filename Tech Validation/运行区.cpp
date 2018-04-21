#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE _hd = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 1; i <= 255; i++)
    {
        SetConsoleTextAttribute(_hd, i);
        cout << i << "Hello world!" << endl;
    }
    system("pause");
    return 0;
}