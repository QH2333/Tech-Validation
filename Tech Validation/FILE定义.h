#pragma once

//标准C中的FILE
#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 //一次打开的最大文件数

//定义FILE结构体
typedef struct _iobuf {
	int cnt; //剩余的字符，如果是输入缓冲区，那么就表示缓冲区中还有多少个字符未被读取
	char *ptr; //下一个要被读取的字符的地址
	char *base; //缓冲区基地址
	int flag; //读写状态标志位
	int fd; //文件描述符
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0]) // stdin 的文件描述符为0
#define stdout (&_iob[1]) // stdout 的文件描述符为1
#define stderr (&_iob[2]) // stdout 的文件描述符为2

enum _flags {
	_READ = 01, //读文件
	_WRITE = 02, //写文件
	_UNBUF = 04, //无缓冲
	_EOF = 010, //文件结尾EOF
	_ERR = 020 //出错
};

int _fillbuf(FILE *); //函数声明，填充缓冲区
int _flushbuf(int, FILE *); //函数声明，刷新缓冲区

#define feof(p) ((p)->flag & _EOF) != 0)
#define ferror(p) ((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)
#define getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x),p))
#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)