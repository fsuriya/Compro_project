#include <iostream>
#include <string>
#include <conio.h>
#include "Monster.h"
//#include "Item.h"
using namespace std;

struct Stat{
	int hpmax;
	int atk;
	int def;
	int hp;
};
struct Posi{
	int x;
	int y;
};

class Player{
	string name;
	Stat stat;
	Posi posi;
//	Equipment *equip;
//	Item *item[];
	public:
		Player(Stat &,int ,int);
//		void wear(Equipment *);
//		void get(Item *);
//		void useItem(int);
		void walk(int [][37][2]);
//		void beTrapped(Trap *)
};

Player::Player(Stat &select,int xx,int yy){
	stat=select;
	posi.x=xx;
	posi.y=yy;
}
/*void Player::wear(Equipment *select){
	if(equip!=0){
		hpmax-=equip->hpmax;
		atk-=equip->atk;
		def-=equip->def;
	}
	equip=select;
	hpmax+=equip->hpmax;
	atk+=equip->atk;
	def+=equip->def;
}*/
/*void Player::get(Item *obj){
	
}
void Player::useItem(int num){
	
}
void Player::beTrapped(Trap *trap){
	
}*/
void Player::walk(int map[][37][2]){
	char des=getch();
	des=toupper(des);
	map[posi.y][posi.x][1]=0;
	if(des=='W'&&map[posi.y-1][posi.x][1]!=1){
		posi.y--;
	}else if(des=='S'&&map[posi.y+1][posi.x][1]!=1){
		posi.y++;
	}else if(des=='A'&&map[posi.y][posi.x-1][1]!=1){
		posi.x--;
	}else if(des=='D'&&map[posi.y][posi.x+1][1]!=1){
		posi.x++;
	}
	map[posi.y][posi.x][1]=4;
/*	if(map[y][x]==2) get()
	else if(map[y][x]==3) beTrapped();*/
}







