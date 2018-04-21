#include <iostream>
#include <cstdio>
#include <windows.h>

using namespace std;

void colorfulHelloWorld();
void discreteHelloWorld();
void advancedHelloworld();
void writeSomething();
void drawButton();

bool gotoxy(int x, int y);

int main()
{
    drawButton();
    
    system("pause");
    return 0;
}

void colorfulHelloWorld()
{
    HANDLE _hd = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 1; i <= 255; i++)
    {
        SetConsoleTextAttribute(_hd, i);
        //gotoxy(0, 0);
        cout << i << "Hello world!" << endl;
    }
}

bool gotoxy(int x, int y)
{
    COORD pos = { x,y };
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void discreteHelloWorld()
{
    for (int i = 0; i <= 200; i++)
    {
        gotoxy(rand() % 60, rand() % 20);
        printf("Hello world!");
        Sleep(20);
    }
}

void writeSomething()
{
    for (int i = 1; i <= 300; i++)
    {
        printf("Some text here!");
    }
}

void advancedHelloworld()
{
    HWND hWnd = GetConsoleWindow();
    HDC hdc = GetDC(hWnd);

    HFONT font = CreateFont(
        64, // nHeight
        0, // nWidth
        -50, // nEscapement
        20, // nOrientation
        FW_BOLD, // nWeight
        TRUE, // bItalic
        TRUE, // bUnderline
        0, // cStrikeOut
        ANSI_CHARSET, // nCharSet
        OUT_DEFAULT_PRECIS, // nOutPrecision
        CLIP_DEFAULT_PRECIS, // nClipPrecision
        DEFAULT_QUALITY, // nQuality
        DEFAULT_PITCH | FF_SWISS,
        (LPCSTR)L"Arial" // nPitchAndFamily Arial
    );
    SelectObject(hdc, font);

    SetBkColor(hdc, 0x000000);
    SetTextColor(hdc, RGB(100, 149, 237));
    TextOut(hdc, 30, 30, (LPCSTR)L"Hello, world!", 13);

    ValidateRect(hWnd, 0);
}

void drawButton()
{
    HWND hWnd = GetConsoleWindow();
    HFONT font = CreateFont(
    20, // nHeight
    0, // nWidth
    0, // nEscapement
    0, // nOrientation
    FW_NORMAL, // nWeight
    FALSE, // bItalic
    FALSE, // bUnderline
    0, // cStrikeOut
    ANSI_CHARSET, // nCharSet
    OUT_DEFAULT_PRECIS, // nOutPrecision
    CLIP_DEFAULT_PRECIS, // nClipPrecision
    DEFAULT_QUALITY, // nQuality
    DEFAULT_PITCH | FF_SWISS,
    (LPCSTR)L"新宋体" // nPitchAndFamily Arial
);



HWND b1 = CreateWindow(
    (LPCSTR)L"BUTTON",   // predefined class
    (LPCSTR)L"确定",       // button text
    WS_VISIBLE | WS_CHILD,  //values for buttons.
    100,         // starting x position
    100,         // starting y position
    100,        // button width
    40,        // button height
    hWnd,       // parent window
    0,       // No menu
    (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
    NULL);

HWND b2 = CreateWindow(
    (LPCSTR)L"BUTTON",   // predefined class
    (LPCSTR)L"取消",       // button text
    WS_VISIBLE | WS_CHILD,  //values for buttons.
    240,         // starting x position
    100,         // starting y position
    100,        // button width
    40,        // button height
    hWnd,       // parent window
    0,       // No menu
    (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
    NULL);

SendMessage(b1, WM_SETFONT, (WPARAM)font, 1);
SendMessage(b2, WM_SETFONT, (WPARAM)font, 1);


MSG msg;
while (GetMessage(&msg, 0, 0, 0)) {

    TranslateMessage(&msg);
    DispatchMessage(&msg);

    if (msg.hwnd == b1 && msg.message == WM_LBUTTONDOWN) {
        MessageBox(hWnd, (LPCSTR)L"点击了确定按钮", (LPCSTR)L"Hello", MB_ICONINFORMATION);
    }

    if (msg.hwnd == b2 && msg.message == WM_LBUTTONDOWN) {
        MessageBox(hWnd, (LPCSTR)L"点击了取消按钮", (LPCSTR)L"Hello", MB_ICONINFORMATION);
    }
}

}