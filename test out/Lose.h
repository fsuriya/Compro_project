#include "Display.h"

void lose(){
	
	ifstream fin;
	fin.open("LOSE.txt");
	string text;
	vector<string> YOULOSE;
	while(getline(fin,text)){
		YOULOSE.push_back(text);	
	}
	
	bool break_out=true;
	while(break_out){

		cout << "\n\n";
		for(int i=0;i<YOULOSE.size();i++){
			int a=12;
			if(i&1) a=15;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
			cout << "\t\t" << YOULOSE[i] << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout << "\t\t=========================================================================";
		delay(15);
		system("CLS");
		if(GetAsyncKeyState(VK_ESCAPE)){
			break_out=false;
		}
	}	
}
