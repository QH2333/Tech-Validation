#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"winmm.lib")//timeGetTime()需要导入winnn.lib
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

void timeFuncTest()//time()返回从1970-1-1到现在的秒数
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

void clockFunTest()//clock()返回进程启动到现在的毫秒数
{
	clock_t cClock1 = clock();
	cout << "clock():" << cClock1 << endl;
	clock_t cClock2 = clock();
	cout << "clock():" << cClock2 << endl;
}

void timeGetTimeTest()//timeGetTime()返回从系统启动到现在的毫秒数
{
	DWORD cTime2;
	cTime2 = timeGetTime();
	cout << "timeGetTime():" << cTime2 << endl;
}

void queryTimeTest()//调用api可以获得更精确的计时
{
	LARGE_INTEGER qTime1;
	LARGE_INTEGER qTime2;
	LARGE_INTEGER qFreq;
	QueryPerformanceFrequency(&qFreq);//查询时钟频率
	QueryPerformanceCounter(&qTime1);//查询始终计数器的值
	Sleep(500);
	QueryPerformanceCounter(&qTime2);
	cout << ((double)qTime2.QuadPart - (double)qTime1.QuadPart) / (double)qFreq.QuadPart << endl;
}