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

void cout_asktoout(int pos_exitmenu, int C){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole,10);
	cout<<"\n\n\n\n"
		<<DO you want to exit?";
		<<
		<<
	if(pos_exitmenu==0){
		SetConsoleTextAttribute(hConsole,C);
		cout<<"\t\t\tNO"
	}
	

}

void cout_yes(){
	//bye
}

void cout_no(){
	//smile
}

int main(){
	int C=0;
	int pos_exitmenu=0;
	bool flage_exit=true;
	
	while(flage_exit){
		cout_asktoout(pos_exitmenu, C);
		
		if(GetAsyncKeyState(KEY_LEFT)){
			pos_exitmenu=0;
		}else if(GetAsyncKeyState(KEY_RIGHT)){
			pos_exitmenu=69;
		}else if(GetAsyncKeyState(KEY_ENTER)){
			flage_exit=false;
			return pos_exitmenu;
		}
	}
}
