#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"winmm.lib")//timeGetTime()��Ҫ����winnn.lib
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

void timeFuncTest();
void clockFunTest();
void timeGetTimeTest();
void queryTimeTest();

int main()
{
	//timeFuncTest();
	//clockFunTest();
	queryTimeTest();
	system("pause");
	return 0;
}

void timeFuncTest()//time()���ش�1970-1-1�����ڵ�����
{
	time_t cTime1;
	time(&cTime1);
	cout << "time(&time_t):" << cTime1 << endl;

	time_t cTime3;
	double dTime;
	time(&cTime3);
	dTime = difftime(cTime3, cTime1);
	cout << "difftime():" << dTime << endl;

	time_t cTime4;
	cTime4 = time(0);
	cout << "time(0):" << cTime4 << endl;
}

void clockFunTest()//clock()���ؽ������������ڵĺ�����
{
	clock_t cClock1 = clock();
	cout << "clock():" << cClock1 << endl;
	clock_t cClock2 = clock();
	cout << "clock():" << cClock2 << endl;
}

void timeGetTimeTest()//timeGetTime()���ش�ϵͳ���������ڵĺ�����
{
	DWORD cTime2;
	cTime2 = timeGetTime();
	cout << "timeGetTime():" << cTime2 << endl;
}

void queryTimeTest()//����api���Ի�ø���ȷ�ļ�ʱ
{
	LARGE_INTEGER qTime1;
	LARGE_INTEGER qTime2;
	LARGE_INTEGER qFreq;
	QueryPerformanceFrequency(&qFreq);//��ѯʱ��Ƶ��
	QueryPerformanceCounter(&qTime1);//��ѯʼ�ռ�������ֵ
	Sleep(500);
	QueryPerformanceCounter(&qTime2);
	cout << ((double)qTime2.QuadPart - (double)qTime1.QuadPart) / (double)qFreq.QuadPart << endl;
}