#include <iostream>
#include <Windows.h>
#include "All_char.h"
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESCAPE 27
using namespace std;

void cout_howtoplay(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//cout header
	SetConsoleTextAttribute(hConsole,10);
	cout<<"\n\n";
	cout<<"\t\t\t\t\t\t@  @             @@@@@        @@@@ @      @   @  @\n";
	SetConsoleTextAttribute(hConsole,11);
	cout<<"\t\t\t\t\t\t@  @               @          @  @ @     @ @  @  @\n";
	SetConsoleTextAttribute(hConsole,12);
	cout<<"\t\t\t\t\t\t@@@@ @@@@ @ @ @    @   @@@@   @@@@ @    @   @  @@ \n";
	SetConsoleTextAttribute(hConsole,13);
	cout<<"\t\t\t\t\t\t@  @ @  @ @@@@@    @   @  @   @    @    @@@@@  @@ \n";
	SetConsoleTextAttribute(hConsole,14);
	cout<<"\t\t\t\t\t\t@  @ @@@@  @ @     @   @@@@   @    @@@@ @   @  @@ \n\n\n";
	SetConsoleTextAttribute(hConsole,15);
}

void slidetoknow(int page_howto){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,10);
	if(page_howto==0){
		cout<<"First thing you should your character and status before game is starting.";
	}else if(page_howto==1){
		cout<<"Secondly you are start in edge of the maze so you can win the gmae if you can go to exit door.";
	}else if(page_howto==2){
		cout<<"Finally if receive weapon potion and trap you get buff or debuff.";
	}else if(page_howto==3){
		cout<<"GG EZ ^^";
	}
	SetConsoleTextAttribute(hConsole,15);
}

int Display_howtoplay(){
	
	bool braek_cout=true;

	//cout header
	cout_howtoplay();
	
	gotoxy(0,16);	
	Witch(110);
	
	int page_howto=0,cpy_page_howto=1;
	while(braek_cout){
		//cout slidetoknow
		if(cpy_page_howto!=page_howto){
			clearline(10);
			gotoxy(40,10);
			slidetoknow(page_howto);
			cpy_page_howto=page_howto;
		}
		
		if(GetAsyncKeyState(VK_LEFT)){
			PlaySound(TEXT("click_buttom.wav"),NULL,SND_SYNC);
			--page_howto;
			if(page_howto<0) page_howto=0;
		}else if(GetAsyncKeyState(VK_RIGHT)){
			PlaySound(TEXT("click_buttom.wav"),NULL,SND_SYNC);
			++page_howto;
			if(page_howto>3) page_howto=3;
		}else if(GetAsyncKeyState(KEY_ESCAPE)){
			braek_cout=false;
			PlaySound(TEXT("enter_click.wav"),NULL,SND_SYNC);
		}
	}
	system("CLS");
	return -1;
}
