#include<iostream>
#include "ctime"
#include "cstdlib"
#include"Player.h"
#include"Unitfight.h"
#include"Witch.h"
#include"Knight.h"
#include"Godzilla.h"
#include"Lose.h"
#include"winner.h"
#include<iomanip>

int main(){
	
	Player hero(20,20,20,0,0);
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));
	int i = rand()%3;
	if(i==0){
		Monster mons("Knight");
		mons.showstatus();
		knight(50);
		hero.showstatus();
			
		int turn_count = 1;
		char player_action = '\0',monster_action = '\0';
		int p = 0, m = 0;
		while(true){
			mons.newTurn();	
			hero.newTurn();
			Monster mons("Knight");
			mons.showstatus();
			knight(50);
			hero.showstatus();				
			cout << "[A] Attack [G] Guard";
			cout << "\n[Turn " << turn_count << "] Enter your action: ";
			cin >> player_action;
			player_action = toupper(player_action);
		
			int temp = rand()%2;
			if(temp == 0) monster_action = 'A';
			else if(temp == 1) monster_action = 'G';
		
			if(player_action == 'G') hero.guard();
			if(monster_action == 'G') mons.guard();
		
			//if(player_action == 'A') p = hero.attack(mons); 
			//if(monster_action == 'A') m = mons.attack(hero); 
		
			if(hero.isDead()){
				lose();
				break; 
			}else if(mons.isDead()){
				winner();
				break; 
			}
			turn_count++;
		}
	}else if(i==1){
		Monster mons("Witch");
		mons.showstatus();
		witch(50);
			
		int turn_count = 1;
		char player_action = '\0',monster_action = '\0';
		int p = 0, m = 0;
		while(true){
			mons.newTurn();	
			hero.newTurn();
			Monster mons("Witch");
			mons.showstatus();
			witch(50);
			hero.showstatus();				
			cout << "[A] Attack [G] Guard";
			cout << "\n[Turn " << turn_count << "] Enter your action: ";
			cin >> player_action;
			player_action = toupper(player_action);
		
			int temp = rand()%2;
			if(temp == 0) monster_action = 'A';
			else if(temp == 1) monster_action = 'G';
		
			if(player_action == 'G') hero.guard();
			if(monster_action == 'G') mons.guard();
		
			//if(player_action == 'A') p = hero.attack(mons); 
			//if(monster_action == 'A') m = mons.attack(hero); 
		
			if(hero.isDead()){
				lose();
				break; 
			}else if(mons.isDead()){
				winner();
				break; 
			}
			turn_count++;
		}
	}else if(i==2){
		Monster mons("Godzilla");
		mons.showstatus();
		godzilla(50);
				
		int turn_count = 1;
		char player_action = '\0',monster_action = '\0';
		int p = 0, m = 0;
		while(true){
			mons.newTurn();	
			hero.newTurn();
			Monster mons("Godzilla");
			mons.showstatus();
			godzilla(50);
			hero.showstatus();				
			cout << "[A] Attack [G] Guard";
			cout << "\n[Turn " << turn_count << "] Enter your action: ";
			cin >> player_action;
			player_action = toupper(player_action);
		
			int temp = rand()%2;
			if(temp == 0) monster_action = 'A';
			else if(temp == 1) monster_action = 'G';
		
			if(player_action == 'G') hero.guard();
			if(monster_action == 'G') mons.guard();
		
			//if(player_action == 'A') p = hero.attack(mons); 
			if(monster_action == 'A') m = mons.attack(hero); 
		
			if(hero.isDead()){
				lose();
				break; 
			}else if(mons.isDead()){
				winner();
				break; 
			}
			turn_count++;
		}
	}
		
	return 0;
}
