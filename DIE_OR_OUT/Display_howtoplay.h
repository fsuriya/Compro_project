#include <iostream>
#include <Windows.h>
//#include "command.h"
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
	cout<<"\t\t\t\t\t\t@  @ @@@@  @ @     @   @@@@   @    @@@@ @   @  @@ \n";
	SetConsoleTextAttribute(hConsole,15);
}

void slidetoknow(){
	
}

int Display_howtoplay(){
	
	bool braek_cout=true;
	while(braek_cout){
		//cout header
		cout_howtoplay();
		
		//cout slidetoknow
		slidetoknow();
	
		delay();
		system("CLS");
		if(GetAsyncKeyState(KEY_ESCAPE)){
			braek_cout=false;
		}
	}
	
	return -1;
}
