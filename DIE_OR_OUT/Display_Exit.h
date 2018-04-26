#include <iostream>
#include <Windows.h>
//#include "command.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_BACKSPACE 8
#define KEY_ESCAPE 27
using namespace std;

void cout_logoask(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole,10);
	cout<<"\n\n"
		<<"\t\t\t\t                                                                   @@@@            \n"
		<<"\t\t\t\t@@@                                             @       @          @        @   @  \n"
		<<"\t\t\t\t@  @ @@@@   @  @ @@@@ @  @   @ @ @ @@@@  @@@@ @@@@@   @@@@@ @@@@   @@@@ @ @   @@@@@\n"
		<<"\t\t\t\t@  @ @  @   @@@@ @  @ @  @   @@@@@ @  @  @  @   @       @   @  @   @     @  @   @  \n"
		<<"\t\t\t\t@@@  @@@@     @  @@@@ @@@@    @ @  @@@@@ @  @   @       @   @@@@   @@@@ @ @ @   @  \n"
		<<"\t\t\t\t             @                                                                     \n"
		<<"\n\n\n";
}

void cout_asktoout(int pos_exitmenu, int &C){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int C1=15,C2=15;
	if(pos_exitmenu==0){
		C1=C;
		C2=15;
	}SetConsoleTextAttribute(hConsole,C1);
		cout<<"\t\t\t\t\t\t\t\t\tNO\n\n";
	if(pos_exitmenu==69){
		C1=15;
		C2=C;
	}SetConsoleTextAttribute(hConsole,C2);	
		cout<<"\t\t\t\t\t\t\t\t\tYES\n\n";
	
	Change_CL(C);
	delay(5);
}

void cout_yes(){
	//bye
}

void cout_no(){
	//smile
}

int Display_Exit(){
	int C=0;
	int pos_exitmenu=0;
	bool flage_exit=true;
	cout_logoask();
	
	gotoxy(0,16);
	Godzilla(110);
	
	while(flage_exit){
		gotoxy(0,9);
		cout_asktoout(pos_exitmenu, C);
		if(GetAsyncKeyState(VK_UP)){
			pos_exitmenu=0;
			PlaySound(TEXT("click_buttom.wav"),NULL,SND_SYNC);
		}else if(GetAsyncKeyState(VK_DOWN)){
			pos_exitmenu=69;
			PlaySound(TEXT("click_buttom.wav"),NULL,SND_SYNC);
		}else if(GetAsyncKeyState(KEY_ENTER)){
			flage_exit=false;
			PlaySound(TEXT("enter_click.wav"),NULL,SND_SYNC);
			system("CLS");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			return pos_exitmenu;
		}
		delay();
	}
}
