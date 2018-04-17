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


int main(){
	// --- Decare variable for read file ---
	ifstream fin;
	fin.open("DIEorOUT.txt");
	string text;
	vector<string> Logo;
	
	// --- Decare variable for get key on keyborad ---
	char key;
	int ascii_key;
	
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
	int U=0;
	
	while(U != -1){
		switch(U){
			case 0:
				
				for(int i=0 ; i<Logo.size() ; i++){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
					cout << "\t" << Logo[i] << endl;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				cout << "\t\t\t\t\t" << ">      START      <" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				cout << "\t\t\t\t\t" << "    HOW TO PLAY    " << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				cout << "\t\t\t\t\t" << "       CREDIT      " << endl << endl;
				delay(5);
				ascii_key = getch();
				system("CLS");	
				if(ascii_key == 80) U++;
				else if(ascii_key == 13) U=-1;
				break;
				
			case 1:
				
				for(int i=0 ; i<Logo.size() ; i++){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
					cout << "\t" << Logo[i] << endl;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				cout << "\t\t\t\t\t" << "       START       " << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				cout << "\t\t\t\t\t" << ">   HOW TO PLAY   <" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				cout << "\t\t\t\t\t" << "       CREDIT      " << endl << endl;
				delay(5);
				ascii_key = getch();
				system("CLS");	
				if(ascii_key == 80) U++;
				else if(ascii_key == 72) U--;
				else if(ascii_key == 13) U=-1;
				break;
				
			case 2:
				
				for(int i=0 ; i<Logo.size() ; i++){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
					cout << "\t" << Logo[i] << endl;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				cout << "\t\t\t\t\t" << "       START       " << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				cout << "\t\t\t\t\t" << "    HOW TO PLAY    " << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				cout << "\t\t\t\t\t" << ">      CREDIT     <" << endl << endl;
				delay(5);
				ascii_key = getch();
				system("CLS");	
				if(ascii_key == 72) U--;
				else if(ascii_key == 13) U=-1;
		}	 
	}
	
	


	
	
	
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
