#include "iostream"
#include "ctime"
#include "cstdlib"
#include "Windows.h"
#include <iomanip>
using namespace std;

class Monster{
		string name;		
		int hp;
		int hpmax;
		int atk;
		int def;
		bool guard_on;
	public:			
		Monster(string);
		void newTurn();
		void showstatus(); 
};

Monster::Monster(string n){
	name = n; 
	srand(time(0));
	if(name == "Witch"){
		hpmax=rand()%20+120;
		atk=rand()%5+30;
		def=rand()%5+10;
		hp=hpmax;
	}else if(name=="Knight"){
		hpmax=rand()%20+150;
		atk=rand()%5+20;
		def=rand()%5+20;
		hp=hpmax;
	}else if(name=="Godzilla"){
		hpmax=rand()%20+200;
		atk=rand()%5+40;
		def=rand()%5+30;
		hp=hpmax;
	}
}

void Monster::newTurn(){
	guard_on = false;
}

void Monster::showstatus(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,12);
	cout << "\n";
	cout << setw(100) << "-----------------------------------\n\n";
	cout << "   " << setw(70) << name << "\n\n";
	cout << setw(70) << "HP: " << hp << "/" << hpmax << "   " << "ATK: " << atk << "   " << "DEF: "<< def;
	cout << "\n\n";
	cout << setw(100) << "-----------------------------------\n";
	cout << "\n\n";
}

