#include "Display.h"

int main(){
	
	ifstream fin;
	fin.open("LOSE.txt");
	string text;
	vector<string> YOULOSE;
	while(getline(fin,text)){
		YOULOSE.push_back(text);	
	}
	
	bool break_out=true;
	int i=0,Red_White;
	while(break_out){
		if(i&1) Red_White = 12; 
		else Red_White=15;
		cout << "\n\n";
		print(YOULOSE,Red_White,2);
		cout << "\t\t=========================================================================";
		delay(15);
		system("CLS");
		i++;
		if(GetAsyncKeyState(VK_ESCAPE)){
			break_out=false;
		}
	}

	
	
}
