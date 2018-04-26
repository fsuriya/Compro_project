//#include "Display.h"
#include "fstream"
#include "char_playyer.h"
#include "iomanip"
#include "vector"
#define KEY_ENTER 13
//string name;

void show_select_plyer(const vector<string> G,int stage,int &MAX_HP,int &DEF,int &ATK,string name){

	int A=10,B=10,C=10;
//	int MAX_HP,DEF,ATK;

	//EX. Hero(HP_MAX,DEF,ATK)
	//stage  0 ==> TANK(110,50,40) , stage 1 ==> Warrior(100,45,55) , stage 2 ==> magician(85,40,65);
	
	if( stage == 0){
		B=12 , C=14 , MAX_HP=110,DEF=50,ATK=40;
	}
	else if(stage == 1){
		A=14 , C=14 , B=14 , MAX_HP=100,DEF=50,ATK=50;
	}
	else if(stage == 2){
		A=14 , C= 12 , MAX_HP=85,DEF=40,ATK=65;
	}
	
	
	for(int i=0;i<G.size();i++){
		int a=13;
		if(i&1) a=11;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
		cout << "\t\t" << G[i] << endl; 	
	}
	
	cout << "\n\n" ;;
	character_player(70);
	cout << "\n\n";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	cout << setw(78) << "Your Name : " ;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout << name;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	cout << endl << endl <<setw(86) << "======================" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout << setw(86)<< "<       STATUS       >" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	cout << setw(86)<< "======================" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),A);
	cout << setw(79)<< "     MAX HP :  " << MAX_HP  <<endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),B);
	cout << setw(79)<< "     ATK    :  " << ATK <<endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),C);
	cout << setw(79)<< "     DEF    :  " << DEF << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);

}

vector<int> select_status(string &name){
	
	ifstream fin;
	fin.open("select_player.txt");
	vector<string> print_select;
	string text;
	while(getline(fin,text)) print_select.push_back(text);
	
	int U=0,C=0;
	bool break_choose=true;
	
	while(true){
		
		for(int i=0;i<print_select.size();i++){
			int a=13;
			if(i&1) a=11;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
			cout << "\t\t" << print_select[i] << endl; 	
		}
		
		cout << "\n\n" ;;
		character_player(70);
		cout << "\n\n";
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		cout << setw(78) << "Your Name : " ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		cin >> name;
		if(name.size()>8){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			cout << endl << setw(100) << "Please enter name of 8 characters or less";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			system("PAUSE");
			system("CLS");
			continue;		
		}else break;
	
	}
	system("CLS");
	
	int MAX_HP,DEF,ATK;
	while(break_choose){
		show_select_plyer(print_select,U,MAX_HP,DEF,ATK,name);	
		system("PAUSE");
		if(GetAsyncKeyState(VK_RIGHT)){
			++U;
			if(U==3) U=0; 
		}
		else if(GetAsyncKeyState(VK_LEFT)){ 
			--U;
			if(U==-1) U=2; 
		}
		else if(GetAsyncKeyState(KEY_ENTER)){
			break_choose=false;
		}
		system("CLS");
		
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	vector<int> GG;
	GG.push_back(MAX_HP);
	GG.push_back(DEF);
	GG.push_back(ATK);
	return GG;
}
