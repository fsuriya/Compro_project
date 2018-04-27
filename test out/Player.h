#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include"Windows.h"
#include <iomanip>

using namespace std;

class Equipment;
class Item;
class Trap;

struct Pos{
	int x;
	int y;
};

class Player{
	string name;
	int hpmax;
	int atk;
	int def;
	int hp;
	Pos pos;
	Equipment *equip;
	Item *item[];
	bool guard_on;
	public:
		Player(int, int, int, int, int);
		void wear(Equipment *);
		void get(Item *);
		void useItem(int);
		void walk(int,int **);
		void beTrapped();
		void newTurn();
		void guard();
		int beAttacked(int);
		bool isDead();
		void showstatus();
};
Player::Player(int hhp, int aatk, int ddef, int xx, int yy){
	hpmax=hhp;
	atk=aatk;
	def=ddef;
	hp=hpmax;
	pos.x=xx;
	pos.y=yy;
}

class Equipment{
		int hpmax;
		int atk;
		int def;
	public:	
		Equipment(int,int,int);
		friend void Player::wear(Equipment *);
};
Equipment::Equipment(int a,int b,int c){
	hpmax = a;
	atk = b;
	def = c;
	
}

void Player::wear(Equipment *select){
	if(equip!=0){
		hpmax-=equip->hpmax;
		atk-=equip->atk;
		def-=equip->def;
		if(hp>hpmax) hp = hpmax;
	}
	equip=select;
	hpmax+=equip->hpmax;
	atk+=equip->atk;
	def+=equip->def;
}
void Player::get(Item *obj){

}
/*void Player::useItem(int num){
	int temp = hp;
	if(m == "Bread"){
		hp += 20;	
	}else if(m == "Red_Potion"){
		hp += 40;
	}
	if(hp > hpmax)  hp = hpmax;
	return hp-temp;	
}*/

void Player::walk(int trap,int **map){
	map[pos.y][pos.x]=0;
	if(trap==1){
		Sleep(2000);
	}else{
		if(GetAsyncKeyState(0x57) && map[pos.y-1][pos.x]!=1){
		pos.y--;
	}else if(GetAsyncKeyState(0x53) && map[pos.y-1][pos.x]!=1){
		pos.y++;
	}else if(GetAsyncKeyState(0x41) && map[pos.y][pos.x-1]!=1){
		pos.x--;
	}else if(GetAsyncKeyState(0x44) && map[pos.y][pos.x+1]!=1){
		pos.x++;
	}
	}
	map[pos.y][pos.x]=4;
/*	if(map[y][x]==2) get()
	else if(map[y][x]==3) beTrapped();*/
}

void Player::beTrapped(){
	srand(time(0));
	const int i=rand()%11;
	if(i<3){
		hp-=rand()%11+10;
	}else if(i<6){
		for(int i=0;i<2;i++){
			walk(1,0);
		}
	}else if(i<8){
		//show fight();
	}else{
		def-=rand()%11+10;
	}	
}

void Player::newTurn(){
	guard_on = false;
}

void Player::guard(){
	guard_on = true;
}

int Player::beAttacked(int oppatk){
	int dmg;
	if(oppatk > def){
		dmg = oppatk-def;	
		if(guard_on) dmg = dmg/3;
	}	
	hp -= dmg;
	if(hp <= 0){hp = 0;}
	
	return dmg;	
}

bool Player::isDead(){
	if(hp <= 0) return true;
	else return false;
}

void Player::showstatus(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n\n\n";
	SetConsoleTextAttribute(hConsole,10);
	cout << setw(50) << "-----------------------------------\n";
	cout << "   " << setw(70) << name << "\n\n";
	cout << setw(20) << "HP: " << hp << "/" << hpmax << "   " << "ATK: " << atk << "   " << "DEF: "<< def;
	cout << "\n\n";
	cout << setw(50) << "-----------------------------------\n";
	SetConsoleTextAttribute(hConsole,15);
}


