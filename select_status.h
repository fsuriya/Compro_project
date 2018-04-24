#include "Display.h"

#include "character.h"

//#include "iomanip"



void show_select_plyer(const vector<string> G,int stage){



	for(int i=0;i<G.size();i++){

		int a=13;

		if(i&1) a=11;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);

		cout << "\t\t" << G[i] << endl; 	

	}

	

	cout << "\n\n" ;;

	//print_character();

	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);

	int A=10,B=10,C=10;

	int MAX_HP,DEF,ATK;

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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);

	cout << "\t\t======================" << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

	cout << "\t\t        STATUS        " << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);

	cout << "\t\t======================" << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),A);

	cout << "\n\t\t     MAX HP :  " << MAX_HP  <<endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),B);

	cout << "\n\t\t     ATK    :  " << ATK <<endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),C);

	cout << "\n\t\t     DEF    :  " << DEF << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);

	system("pause");

}



/*int main(){

	

	ifstream fin;

	fin.open("select_player.txt");

	vector<string> print_select;

	string text;

	while(getline(fin,text)) print_select.push_back(text);

	

	int U=0,C=0;

	bool break_choose=true;

	

	show_select_plyer(print_select,U);

	if(GetAsyncKeyState(VK_DOWN)){

		++U;

		if(U==3) U=2; 

	}

	else if(GetAsyncKeyState(VK_UP)){ 

		U--;

		if(U==-1) U=0; 

	}

	else if(GetAsyncKeyState(VK_RETURN)){

		break_choose=false;

	}

	

/*

	while(break_choose){

		show_select_plyer(print_select,C,U);

		if(GetAsyncKeyState(VK_DOWN)){

			++U;

			if(U==3) U=2; 

		}

		else if(GetAsyncKeyState(VK_UP)){ 

			U--;

			if(U==-1) U=0; 

		}

		else if(GetAsyncKeyState(VK_RETURN)){

			break_choose=false;

		}

	}

	*/

	/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);

}*/
