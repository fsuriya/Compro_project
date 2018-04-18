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
	bool SM;
	int C=0;
	while(U != -1){
		SM=true;
		switch(U){
			case 0:
				while(SM == true){
					for(int i=0 ; i<Logo.size() ; i++){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
						cout << "\t" << Logo[i] << endl;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),C);
					cout << "\t\t\t\t\t" << ">      START      <" << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					cout << "\t\t\t\t\t" << "    HOW TO PLAY    " << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					cout << "\t\t\t\t\t" << "       CREDIT      " << endl << endl;
					delay(5);
					system("CLS");
					Change_CL(C);
					if(GetAsyncKeyState(VK_DOWN)){
						U++;
						SM = false;
					}
					else if(GetAsyncKeyState(VK_RETURN)){
						U=-1;
						SM = false;
					}	
				}
				break;
				
			case 1:
				while(SM == true){
					for(int i=0 ; i<Logo.size() ; i++){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
						cout << "\t" << Logo[i] << endl;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					cout << "\t\t\t\t\t" << "       START       " << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),C);
					cout << "\t\t\t\t\t" << ">   HOW TO PLAY   <" << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					cout << "\t\t\t\t\t" << "       CREDIT      " << endl << endl;
					delay(5);
					system("CLS");
					Change_CL(C);	
					if(GetAsyncKeyState(VK_DOWN)){
						U++;
						SM = false;
					}
					else if(GetAsyncKeyState(VK_UP)){
						U--;
						SM = false;
					}
					else if(GetAsyncKeyState(VK_RETURN)){
						U=-1;
						SM = false;
					}	
				}
				break;
				
			case 2:
				while(SM == true){
					for(int i=0 ; i<Logo.size() ; i++){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
						cout << "\t" << Logo[i] << endl;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					cout << "\t\t\t\t\t" << "       START       " << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					cout << "\t\t\t\t\t" << "    HOW TO PLAY    " << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),C);
					cout << "\t\t\t\t\t" << ">      CREDIT     <" << endl << endl;
					delay(5);
					system("CLS");
					Change_CL(C);
					if(GetAsyncKeyState(VK_UP)){
						U--;
						SM = false;
					}
					else if(GetAsyncKeyState(VK_RETURN)){
						U=-1;
						SM = false;
					}	
				}	
		}	 
	}
	
	


	
	
	
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
