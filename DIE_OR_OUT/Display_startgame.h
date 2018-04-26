#include "iostream"
#include "fstream"
#include "string"
#include "vector"
#include "Windows.h"
#include "command.h"
#include <mmsystem.h>
#define KEY_UP 72
#define KEY_DOWN 80

using namespace std;

void print(vector<string> P,int C_P=15,int t=0,int D=0){
	for(int i =0 ; i<P.size() ; i++){
		// -69 is Chang color follow i (size vector);
		if(C_P == -69) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),C_P);
		delay(D);
		for(int j=0;j<t;j++) cout << "\t\t\t\t";
		cout <<  P[i] << endl;
	}
}

void Show_Display(const vector<string> Logo,int &C,int &Stage){
		//print(Logo,-69,1);
	if(Stage != -1){
		int B1=15,B2=15,B3=15, B4=15;
		if(Stage == 0){
			B1 = C;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),B1);
		cout << "\t\t\t\t\t\t\t\t" << "       START       " << endl << endl;
		if(Stage == 1){
			B1=15,B2=C;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),B2);
		cout << "\t\t\t\t\t\t\t\t" << "    HOW TO PLAY    " << endl << endl;
		if(Stage == 2){
			B1=15,B2=15,B3=C;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),B3);
		cout << "\t\t\t\t\t\t\t\t" << "       CREDIT      " << endl << endl;
		//comment by f.sun
		if(Stage == 3){
			B1=B2=B3=15,B4=C;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),B4);
		cout << "\t\t\t\t\t\t\t\t" << "        EXIT       " << endl << endl;				
	}		


	delay(5);
	//system("CLS");
	Change_CL(C);	
}

int Display_startgame(){
	
	// --- Decare variable for read file ---
	ifstream fin;
	fin.open("DIEorOUT.txt");
	string text;
	vector<string> Logo;
	
	// --- Read text from DIEorOUT.txt  & Input text to vector_Logo ---
	while(getline(fin,text)) Logo.push_back(text);
	fin.close();
	
	// --- Show Logo to start game ---
	print(Logo,-69,1,7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	//system("CLS");
	
	// --- Choose Menu do something ---
	int U=0,C=0;
	bool break_Display_startgame=true;
	
	while(break_Display_startgame){
		gotoxy(0,13);
		Show_Display(Logo,C,U);
		if(GetAsyncKeyState(VK_DOWN)){
			++U;
			PlaySound(TEXT("click_buttom.wav"),NULL,SND_SYNC);
			if(U==4) U=3; 
		}
		else if(GetAsyncKeyState(VK_UP)){ 
			U--;
			PlaySound(TEXT("click_buttom.wav"),NULL,SND_SYNC);
			if(U==-1) U=0; 
		}
		else if(GetAsyncKeyState(VK_RETURN)){
			break_Display_startgame=false;
			PlaySound(TEXT("enter_click.wav"),NULL,SND_SYNC);
		}
	}
		
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	return U;
}
