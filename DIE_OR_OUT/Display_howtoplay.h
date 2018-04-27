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
		cout<<"First,you can input the name of your character and select your character status before game is starting.";
	}else if(page_howto==1){
		cout<<"Secondly, you must find a way out of the maze within the time limit.";
	}else if(page_howto==2){
		cout<<"If you exit before time runs out.You will WIN.";
	}else if(page_howto==3){
		cout<<"But if time runs out before you exit.You will LOSE.";
	}else if(page_howto==4){
		cout<<"And in the game,there are still obstacles.";
	}else if(page_howto==5){
		cout<<"If you keep the items in game.Your time will increase";
	}else if(page_howto==6){
		cout<<"But if you smash the monsters in game.Your time will decrease.";
	}else if(page_howto==7){
		cout<<"We hope that our game isn't too difficult for you.:)";
	}else if(page_howto==8){
		cout<<"Thank you very much,we hope you will enjoy with our game.:)";
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
			if(page_howto>8) page_howto=8;
		}else if(GetAsyncKeyState(KEY_ESCAPE)){
			braek_cout=false;
			PlaySound(TEXT("enter_click.wav"),NULL,SND_SYNC);
		}
	}
	system("CLS");
	return -1;
}
