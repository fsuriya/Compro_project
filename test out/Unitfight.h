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
		void guard();
		void newTurn();
		bool isDead();
		int beAttacked(int);
		void showstatus(); 
};

Monster::Monster(string n){
	name = n; 
	srand(time(0));
	if(name == "Witch"){
		hpmax=120;
		atk=30;
		def=10;
		hp=hpmax;
	}else if(name=="Knight"){
		hpmax=150;
		atk=20;
		def=20;
		hp=hpmax;
	}else if(name=="Godzilla"){
		hpmax=200;
		atk=40;
		def=30;
		hp=hpmax;
	}
}

int Monster::beAttacked(int oppatk){
	int dmg;
	if(oppatk > def){
		dmg = oppatk-def;	
		if(guard_on) dmg = dmg/3;
	}	
	hp -= dmg;
	if(hp <= 0){hp = 0;}
	
	return dmg;	
}

void Monster::newTurn(){
	guard_on = false;
}

void Monster::guard(){
	guard_on = true;
}

bool Monster::isDead(){
	if(hp <= 0) return true;
	else return false;
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

