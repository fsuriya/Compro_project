#include<iostream>
#include<Windows.h>
using namespace std;

void setwindow(int Width, int Height){
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

// --- This function for Delay Display --- 
void delay(int N=1){
	for(int i=0 ; i<N*10e6 ; i++);
}

int Change_CL(int &C){
	C++;
	if(C>15) C=0;
}

