#include "iostream"
#include "fstream"
#include "string"
#include "vector"
#include "Windows.h"
#include "conio.h"

#define KEY_UP 72
#define KEY_DOWN 80

using namespace std;

// --- This function for Delay Display --- 
void delay(int N=1){
	for(int i=0 ; i<N*10e6 ; i++);
}

int Change_CL(int &C){
	C++;
	if(C>15) C=0;
}

void Show_Display(const vector<string> Logo,int &C,int &Stage){
	for(int i=0 ; i<Logo.size() ; i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
		cout << "\t" << Logo[i] << endl;
	}
	
	if(Stage != -1){
		int B1=7,B2=7,B3=7, B4=7;
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		cout << endl <<  endl 
			 << "\t\t\t\t\t" << "         ^         " << endl
			 << "\t\t\t\t\t" << "         |         " << endl << endl<< endl;
		
		if(Stage == 0){
			B1 = C;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),B1);
		cout << "\t\t\t\t\t" << "       START       " << endl << endl;
		if(Stage == 1){
			B1=7,B2=C;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),B2);
		cout << "\t\t\t\t\t" << "    HOW TO PLAY    " << endl << endl;
		if(Stage == 2){
			B1=7,B2=7,B3=C;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),B3);
		cout << "\t\t\t\t\t" << "       CREDIT      " << endl << endl;
		//comment by f.sun
		if(Stage == 3){
			B1=B2=B3=7,B4=C;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),B4);
		cout << "\t\t\t\t\t" << "        EXIT       " << endl << endl;
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		cout << endl 
			 << "\t\t\t\t\t" << "         |         " << endl
			 <<	"\t\t\t\t\t" << "         v         " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);				
	}		


	delay(5);
	system("CLS");
	Change_CL(C);	
}

int Display(){
	
	// --- Decare variable for read file ---
	ifstream fin;
	fin.open("DIEorOUT.txt");
	string text;
	vector<string> Logo;
	
	// --- Read text from DIEorOUT.txt  & Input text to vector_Logo ---
	while(getline(fin,text)) Logo.push_back(text);
	fin.close();
	
	// --- Show Logo to start game ---
	for(int i=0 ; i<Logo.size() ; i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
		cout << "\t" << Logo[i] << endl;
		delay(10);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//cout << "\t\t\t\t\t" << "     CREDIT    " << endl << endl;

	
	
	// --- Choose Menu do something ---
	int U=0,C=0;
	bool braek_start=true;
	
	while(braek_start){
		Show_Display(Logo,C,U);
		if(GetAsyncKeyState(VK_DOWN)){
			++U;
			if(U==4) U=3; 
		}
		else if(GetAsyncKeyState(VK_UP)){ 
			U--;
			if(U==-1) U=0; 
		}
		else if(GetAsyncKeyState(VK_RETURN)){
			braek_start=false;
			return U;
		}
	}
		
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
