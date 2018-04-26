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

void cout_ABU(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout<<"\n\n";
	SetConsoleTextAttribute(hConsole,10);
	cout<<"\t\t\t\t\t\t\t  @   @                @     @  @ @@@@\n";
	SetConsoleTextAttribute(hConsole,11);
	cout<<"\t\t\t\t\t\t\t @ @  @              @@@@@   @  @ @   \n";
	SetConsoleTextAttribute(hConsole,12);
	cout<<"\t\t\t\t\t\t\t@   @ @@@@ @@@@ @  @   @     @  @ @@@@\n";
	SetConsoleTextAttribute(hConsole,13);
	cout<<"\t\t\t\t\t\t\t@@@@@ @  @ @  @ @  @   @     @  @    @\n";
	SetConsoleTextAttribute(hConsole,14);
	cout<<"\t\t\t\t\t\t\t@   @ @@@@ @@@@ @@@@   @     @@@@ @@@@\n";
	SetConsoleTextAttribute(hConsole,15);
	cout<<"\n\n";
}

void show_us(int page_us){
	//claer before data
	for(int c_page=10;c_page<40;c_page++){
		clearline(c_page);
	}
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if(page_us==0){
		gotoxy(30,10);
		cout<<"Sirin0786";
		gotoxy(0,18);	
		Witch(110);
	}else if(page_us==1){
		gotoxy(30,10);
		cout<<"pannawit2541";
		gotoxy(0,18);	
		character_player(110);
	}else if(page_us==2){
		gotoxy(30,10);
		cout<<"ravichahashi";
		gotoxy(0,18);	
		knight(110);
	}else if(page_us==3){
		gotoxy(30,10);
		cout<<"fsuriya";
		gotoxy(0,18);	
		Godzilla(110);
	}
	SetConsoleTextAttribute(hConsole,15);
}

int Display_credit(){
	
	bool braek_cout=true;
	int page_us=0,cpy_page_us=1;
	//cout header
	cout_ABU();
	while(braek_cout){	
		//cout slidetoknow
		//clearline(10);
		if(cpy_page_us!=page_us){
			show_us(page_us);
			cpy_page_us=page_us;
		}
		
		if(GetAsyncKeyState(VK_LEFT)){
			PlaySound(TEXT("click_buttom.wav"),NULL,SND_SYNC);
			--page_us;
			if(page_us<0) page_us=0;
		}else if(GetAsyncKeyState(VK_RIGHT)){
			PlaySound(TEXT("click_buttom.wav"),NULL,SND_SYNC);
			++page_us;
			if(page_us>3) page_us=3;
		}else if(GetAsyncKeyState(KEY_ESCAPE)){
			braek_cout=false;
			PlaySound(TEXT("enter_click.wav"),NULL,SND_SYNC);
		}
	}
	system("CLS");
	return -1;
}
