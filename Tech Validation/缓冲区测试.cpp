#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream> 
#include <stdlib.h>
#include <windows.h>

using namespace std;

char outbuf[BUFSIZ];//必须是BUFSIZ，否则存在缓冲溢出可能
int main(void)
{
	/* 将outbuf与stdout输出流相连接 */
	setbuf(stdout, outbuf);
	/* 向stdout中放入一些字符串 */
	puts("This is a test of buffered output.");//体现stdout的行缓冲性质
	fprintf(stdout, "hello world.");
	/*刷新流*/
	fflush(stdout);
	/* 以下是outbuf中的内容 */
	//puts(outbuf);
	system("pause");
	return 0;
}

int main()
{
	ofstream outfile("test.txt");
	for (int n = 0; n<4096; n++)
	{
		outfile << 'a';//缓冲区默认大小为4096字节，文件使用全缓冲，此时test.txt为空
	}
	system("PAUSE");
	outfile << 'b';//写入b时缓冲区已满，执行刷新，a写入文件，b停留在缓冲区
	system("PAUSE");
	return 0;//文件关闭时刷新缓冲区，此时b写入文件
}