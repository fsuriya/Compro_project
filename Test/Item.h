#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#include "Player.h"
#include "Monster.h"

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
	//	vector<int> getstat();
		friend void Player::wear(Equipment *);
};

/*class Unit{
		string med;
		int hp;
		int hpmax;
		int atk;
		int def;
		Equipment *equipment;
		
	public:
		int heal(string);
		void equip(Equipment *);
		
};*/

Equipment::Equipment(int a,int b,int c){
	
	hpmax = a;
	atk = b;
	def = c;
	
}

/*vector<int> Equipment::getstat(){
	
	vector<int> x;
	x.push_back(hpmax);
	x.push_back(atk);
	x.push_back(def);
	return x;
	
}*/

/*void Unit::equip(Equipment *x){
	if(equipment == NULL){
		
		vector<int> stat = x->getstat();
		hpmax += stat[0];
		atk += stat[1];
		def += stat[2];
		equipment =x;
		
	}else{
		
		vector<int> stat_before = equipment->getstat();
		hpmax -= stat_before[0];
		atk -= stat_before[1];
		def -= stat_before[2];
		if(hp>hpmax) hp = hpmax;
		
		vector<int> stat = x->getstat();
		hpmax += stat[0];
		atk += stat[1];
		def += stat[2];
		equipment =x;
		
	}
	
}*/
	
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
	
void Trap(Unit &player){
	srand(time(0));
	int i=rand()%11;
	
	switch (i){
		case i<3 :
			// -HP ==> 5-10%
			break;
		case i<6 :
			// Stop moving ==> 2-3 s.
			break;
		case i<8 :
			// Fight Monster
			break;
		case i<=10:
			// -Def ==> 6-10%
	}
	
}

