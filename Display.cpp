#include "iostream"
#include "string"
#include "fstream"
#include "vector"
#include "Windows.h"
using namespace std;

void pause(int N){
	for(int i=0;i<N*10e5;i++);
}




int main(){
	
	vector<string> Display_1,Display_2;
	ifstream Display;
	Display.open("Display_1.txt");
	string textline;

	while(getline(Display,textline)){
		Display_1.push_back(textline);
	}
	Display.close();
	
	Display.open("Display_2.txt");
	while(getline(Display,textline)){
		Display_2.push_back(textline);
	}
	Display.close();
	

	for(int i=0;i<Display_1.size();i++){
		system("COLOR 4");
		cout << "\t" << Display_1[i] << endl;
		pause(50);
	}
	system("CLS");


	for(int i=0 ; i<5 ; i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5+i);
		for(int j=0;j<Display_2.size();j++ ) cout << "\t" << Display_2[j] << endl;
		pause(50);
		system("CLS");
		pause(30);
	}
	

	for(int i=0;i<Display_1.size();i++ ){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
		for(int j=0;j<Display_1.size();j++) cout << "\t" << Display_1[j] << endl;
		pause(20);
		system("CLS");
		pause(50);
	}
	
	system("CLS");
	for(int j=0;j<Display_1.size();j++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),j);
		cout << "\t" << Display_1[j] << endl;
	}


}
