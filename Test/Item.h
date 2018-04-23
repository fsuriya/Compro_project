#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

//Weapon - Axe Sword Spear Graves Hammer [Excaliber(rare)]

//Armo - 1.leather 2.Iron [Diamond(rare)]

//Medicine - 1.Bread +10 HP 2.Red Potion +20 HP [Feather(rare) reborn in thisplace.]

//Potion - 1.Light Potion(more light) 2.White Potion(delete curse) 3.Blue Potion(up speed)

//Trap - 1.Lock Leg (2s) 2.Down HP 3.Remove Weapon 

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
	
int Unit::heal(string m){
	med = m;
	int temp = hp;
	
	if(med == "Bread"){
		hp += 20;	
	}else if(med == "Red_Potion"){
		hp += 40;
	}
	
	if(hp > hpmax)  hp = hpmax;
	return hp-temp;
	
}
	
