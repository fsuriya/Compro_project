#include<iostream>
#include"Player.h"
#include"Unitfight.h"
#include"Witch.h"
#include<iomanip>

int main(){
	/*Monster mons("Witch");
	
	int turn_count = 1;
	char player_action = '\0',monster_action = '\0';
	int p = 0, m = 0;
	while(true){
		mons.newTurn();	
		hero.newTurn();			
		mons.showStatus();
		drawScene(player_action,p,monster_action,m);
		hero.showStatus();	
		cout << "[A] Attack [H] Heal [G] Guard [D] Dodge [C] Change Equipment [E] Exit";
		cout << "\n[Turn " << turn_count << "] Enter your action: ";
		cin >> player_action;
		player_action = toupper(player_action);
		if(player_action == 'E') break;
		
		int temp = rand()%5;
		if(temp <= 1) monster_action = 'A';
		else if(temp == 2) monster_action = 'G';
		else if(temp == 3) monster_action = 'D';
		else if(temp == 4) monster_action = 'U';
		
		if(player_action == 'G') hero.guard();
		if(monster_action == 'G') mons.guard();
		
		if(player_action == 'A') p = hero.attack(mons); 
		if(monster_action == 'A') m = mons.attack(hero); 
		
		if(hero.isDead()){
			drawScene(player_action,p,monster_action,m);
			playerLose();
			break; 
		}
		
		if(mons.isDead()){
			drawScene(player_action,p,monster_action,m);
			playerWin();
			break; 
		}
		
		turn_count++;
	}*/
	
	
	Monster mons("Witch");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,12);
	cout << "\n";
	cout << setw(100) << "-----------------------------------\n\n";
	mons.showstatus();
	cout << "\n\n";
	cout << setw(100) << "-----------------------------------\n";
	cout << "\n\n";
	witch(50);
	cout << "\n\n\n";
	SetConsoleTextAttribute(hConsole,10);
	cout << setw(40) << "-----------------------------------\n";
	Player showStatus();
	cout << setw(40) << "-----------------------------------\n";
	SetConsoleTextAttribute(hConsole,15);
	
	return 0;
}
