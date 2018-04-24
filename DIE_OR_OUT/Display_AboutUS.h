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

void show_us(){
	
}

int Display_credit(){
	
	bool braek_cout=true;
	while(braek_cout){
		//cout header
		cout_ABU();
		
		//cout slidetoknow
		show_us();
		
		delay();
		system("CLS");
		if(GetAsyncKeyState(KEY_ESCAPE)){
			braek_cout=false;
		}
	}
	
	return -1;
}
