#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int main()
{
    int *int_arr = new int[5];
    int *i = new int;
    delete[] int_arr;
    delete i;
    return 0;
}