#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream> 
#include <stdlib.h>
#include <windows.h>

using namespace std;

char outbuf[BUFSIZ];//������BUFSIZ��������ڻ����������
int main(void)
{
	/* ��outbuf��stdout����������� */
	setbuf(stdout, outbuf);
	/* ��stdout�з���һЩ�ַ��� */
	puts("This is a test of buffered output.");//����stdout���л�������
	fprintf(stdout, "hello world.");
	/*ˢ����*/
	fflush(stdout);
	/* ������outbuf�е����� */
	//puts(outbuf);
	system("pause");
	return 0;
}

int main()
{
	ofstream outfile("test.txt");
	for (int n = 0; n<4096; n++)
	{
		outfile << 'a';//������Ĭ�ϴ�СΪ4096�ֽڣ��ļ�ʹ��ȫ���壬��ʱtest.txtΪ��
	}
	system("PAUSE");
	outfile << 'b';//д��bʱ������������ִ��ˢ�£�aд���ļ���bͣ���ڻ�����
	system("PAUSE");
	return 0;//�ļ��ر�ʱˢ�»���������ʱbд���ļ�
}