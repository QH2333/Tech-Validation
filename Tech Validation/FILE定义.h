#pragma once

//��׼C�е�FILE
#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 //һ�δ򿪵�����ļ���

//����FILE�ṹ��
typedef struct _iobuf {
	int cnt; //ʣ����ַ�����������뻺��������ô�ͱ�ʾ�������л��ж��ٸ��ַ�δ����ȡ
	char *ptr; //��һ��Ҫ����ȡ���ַ��ĵ�ַ
	char *base; //����������ַ
	int flag; //��д״̬��־λ
	int fd; //�ļ�������
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0]) // stdin ���ļ�������Ϊ0
#define stdout (&_iob[1]) // stdout ���ļ�������Ϊ1
#define stderr (&_iob[2]) // stdout ���ļ�������Ϊ2

enum _flags {
	_READ = 01, //���ļ�
	_WRITE = 02, //д�ļ�
	_UNBUF = 04, //�޻���
	_EOF = 010, //�ļ���βEOF
	_ERR = 020 //����
};

int _fillbuf(FILE *); //������������仺����
int _flushbuf(int, FILE *); //����������ˢ�»�����

#define feof(p) ((p)->flag & _EOF) != 0)
#define ferror(p) ((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)
#define getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x),p))
#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)