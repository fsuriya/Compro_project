#include "iostream"
#include "ctime"
#include "cstdlib"
#include "Windows.h"
using namespace std;

class Monster{
		string name;		
		int hp;
		int hpmax;
		int atk;
		int def;
	public:
		int pos_x,pos_y;			
		Monster(string);
		void getstatus();
		void showstatus(); 
};

Monster::Monster(string n){
	name = n; 
}

void Monster::getstatus(){
	srand(time(0));
	if(name=="Witch"){
		hpmax=rand()%20+120;
		atk=rand()%5+50;
		def=rand()%5+10;
		hp=hpmax;
	}else if(name=="Knight"){
		hpmax=rand()%20+150;
		atk=rand()%5+30;
		def=rand()%5+20;
		hp=hpmax;
	}else if(name=="Godzilla"){
		hpmax=rand()%20+200;
		atk=rand()%5+40;
		def=rand()%5+30;
		hp=hpmax;
	}
}

void Monster::showstatus(){

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout << "-------------------------------------------"  << endl;
	cout << "\t" << "\t"<<  name << endl; 
	cout << "-------------------------------------------"  << endl;
	cout << "\t" << "MAX_HP = " << hpmax << endl;
	cout << "\t" << "ATK = " << atk << endl;
	cout << "\t" << "DEF = " << def << endl; 
	cout << "\t" << "Position [X][Y] = " << pos_x << "," << pos_y << endl;
	cout << "-------------------------------------------"  << endl;
	cout << endl;
	
}

// Test map;
void print_Display_move(int sizemap,int pos_monster_x,int pos_monster_y,int pos_player_x,int pos_player_y){
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "\t";
	cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
	
	for(int i=0;i<sizemap;i++){
		cout << "\t" << i << " ";
		for(int j=0;j<sizemap;j++){
			if(i==pos_player_x && j==pos_player_y){
				if(pos_player_x==pos_monster_x && pos_monster_y==pos_player_y){
					cout << "M " ;
					continue;
				}
				cout << "P ";
				continue;	
			}
			if(i==pos_monster_x && j==pos_monster_y){
				cout << "M ";
				continue;	
			}
			cout << "| ";
			
		}
		cout << "\n";
	}
	cout << "\t" << "position = (" << pos_monster_x << "," << pos_monster_y << ")" << endl << endl; 
	
}


// Function Monster --> Player *******
int monster_move_x(int pos_player_x ,int now_mons_x){
	int move_x;
	do{
		if(pos_player_x < now_mons_x){
			//if(pos_player_x == now_mons_x-1) return now_mons_x;
			move_x = now_mons_x + (rand()%2-1);
		}
		else if(pos_player_x > now_mons_x){
			//if(pos_player_x == now_mons_x+1) return now_mons_x;
			move_x = now_mons_x + (rand()%2);
		}
		else{
			move_x = now_mons_x;
		}
	}while(move_x >=10 || move_x <0);
	
	return move_x;
}

int monster_move_y(int pos_player_y ,int now_mons_y){
	int move_y;
	do{
		if(pos_player_y < now_mons_y){
			//if(pos_player_y == now_mons_y-1) return now_mons_y;
			move_y = now_mons_y + (rand()%2-1);
		}
		else if(pos_player_y > now_mons_y){
			//if(pos_player_y == now_mons_y+1) return now_mons_y;
			move_y = now_mons_y + (rand()%2);
		}
		else{
			move_y = now_mons_y;
		}
	}while(move_y >=10 || move_y <0);
	
	return move_y;
}



/*int main(){
	srand(time(0));
	
	Monster Mons_1();
	Mons_1.getstatus();
	
	int size_map=10;
	int monster_spawn_x,monster_spawn_y,pos_player_x,pos_player_y;
	

	//random position player & monster;
	monster_spawn_x=rand()%10,monster_spawn_y=rand()%10;
	pos_player_x=rand()%10 , pos_player_y=rand()%10;
	
	
	Mons_1.pos_x = monster_spawn_x;
	Mons_1.pos_y = monster_spawn_y;
	
	int X,Y;
	print_Display_move(size_map,monster_spawn_x,monster_spawn_y,pos_player_x,pos_player_y);
	Mons_1.showstatus();
	
	while(true){
		X = monster_move_x(pos_player_x ,Mons_1.pos_x);
		Y = monster_move_y(pos_player_y ,Mons_1.pos_y);
		if(X == Mons_1.pos_x && Y == Mons_1.pos_y) continue;
		cin.ignore();
		system("cls");
		Mons_1.pos_x = X;
		Mons_1.pos_y = Y;
		
		print_Display_move(size_map,X,Y,pos_player_x,pos_player_y);
		Mons_1.showstatus();
		if(X == pos_player_x && Y == pos_player_y){
			cout << "YOU LOSE!!";
			break;
		}
	}

}*/
