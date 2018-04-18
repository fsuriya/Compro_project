#include<iostream>
#include<Windows.h>
#include "Display.h"
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

int main(){
	int turn=0;	
	
	//setwindow output
	setwindow(100,44);
	
	//to turn system
	if(turn==0){
		turn=Display();
	}
	
	cout<<turn;
	
	return 0;
}
