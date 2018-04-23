class Player;

class Monster{
		string name;		
		int hp;
		int hpmax;
		int atk;
		int def;
		int vision;
		Pos pos;
		vector<Pos> find;
	public:			
		Monster(string, int **, int, int);
		void getstatus();
		void showstatus(); 
		void beTrapped();
		void findPlayer(int **, const Player &);
};

Monster::Monster(string n, int **map, int xx, int yy){
	name = n;
	do{
		pos.y=rand()%(yy-2)+1;
		pos.x=rand()%(xx-2)+1;
	}while(map[pos.y][pos.x]!=0);
	map[pos.y][pos.x]=5;
	getstatus();
}

void Monster::getstatus(){
	hpmax=rand()%20+100;
	atk=rand()%5+8;
	def=rand()%3+4;
	hp=hpmax;
	vision=rand()%4+4;
}
/*
void Monster::findPlayer(int **map, const Player &player){
	if(pow(player.pos.x-pos.x,2)+pow(player.pos.y-pos.y,2)<=pow(vision,2)){
		if(find.size()==0) find.push_back(pos);
		Pos old,now,temp[4],miss={-1,-1};
		map[pos.y][pos.x]=0;
		while(1){
			now=find.back();
			old=(find.size()>=2?find[find.size()-2]:(Pos){-1,-1});
			if(map[now.y][now.x]==4) break;
			temp[0]=(Pos){now.x,now.y-1}; temp[1]=(Pos){now.x+1,now.y}; temp[2]=(Pos){now.x,now.y+1}; temp[3]=(Pos){now.x-1,now.y-1};
			if(map[pos.y][pos.x-1]!=1 && map[pos.y][pos.x-1]<8 && temp[0]!=miss && temp[1]!=miss && temp[2]!=miss && temp[3]!=miss && temp[3]!=old){
				find.push_back(temp[3]);
			}else if(map[pos.y+1][pos.x]!=1 && map[pos.y+1][pos.x]<8 && temp[0]!=miss && temp[1]!=miss && temp[2]!=miss && temp[2]!=old){
				find.push_back(temp[2]);
			}else if(map[pos.y][pos.x+1]!=1 && map[pos.y][pos.x+1]<8 && temp[0]!=miss && temp[1]!=miss && temp[1]!=old){
				find.push_back(temp[1]);
			}else if(map[pos.y-1][pos.x]!=1 && map[pos.y-1][pos.x]<8 && temp[0]!=miss && temp[0]!=old){
				find.push_back(temp[0]);
			}else{
				miss=now;
				find.pop_back();
				continue;
			}
			miss=(Pos){-1,-1};
		}
		pos=find[1];
		find.erase(find.begin());
		map[pos.y][pos.x]=5;
	}else{
		if(find.size()!=0) find.clear();
		map[pos.y][pos.x]=0;
			int poss=rand()%4;
			if(poss==0 && map[pos.y-1][pos.x]!=1 && map[pos.y-1][pos.x]<8) pos.y--;
			else if(poss==1 && map[pos.y][pos.x+1]!=1 && map[pos.y][pos.x+1]<8) pos.x++;
			else if(poss==2 && map[pos.y+1][pos.x]!=1 && map[pos.y+1][pos.x]<8) pos.y++;
			else if(map[pos.y][pos.x-1]!=1 && map[pos.y][pos.x-1]<8) pos.x--;
		map[pos.y][pos.x]=5;
	}
}*/


/*
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
	
}*/

/*
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
*/


/*int main(){
	srand(time(0));
	
	Monster Mons_1("Hachimoto");
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
