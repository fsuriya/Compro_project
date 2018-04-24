class Equipment;
class Item;
class Trap;

class Player{
	string name;
	int hpmax;
	int atk;
	int def;
	int hp;
	Pos pos, first, end;
	Equipment *equip;
	Item *item[];
	public:
		Player(int,int,int,Pos,Pos);
		void wear(Equipment *);
		void get(Item *);
		void useItem(int);
		void walk(int **);
		void beTrapped();
		friend void Monster::findPlayer(int **, const Player &);
};
Player::Player(int hhp, int aatk, int ddef, Pos start, Pos exit){
	hpmax=hhp;
	atk=aatk;
	def=ddef;
	hp=hpmax;
	pos=start;
	first=start;
	end=exit;
}

void Monster::findPlayer(int **map, const Player &player){
	Pos copy=pos;
	map[pos.y][pos.x]=0;
	if(pow(player.pos.x-pos.x,2)+pow(player.pos.y-pos.y,2)<=pow(vision,2)){
		if(find.size()==0){
			find.push_back(pos);
			Pos old,now,temp[4],miss={-1,-1};
			while(1){
				now=find.back();
				old=(find.size()>=2?find[find.size()-2]:(Pos){-1,-1});
				if(map[now.y][now.x]==4) break;
				temp[0]=(Pos){now.x,now.y-1}; temp[1]=(Pos){now.x+1,now.y}; temp[2]=(Pos){now.x,now.y+1}; temp[3]=(Pos){now.x-1,now.y};
				if(map[temp[3].y][temp[3].x]!=1 && map[temp[3].y][temp[3].x]<8 && temp[0]!=miss && temp[1]!=miss && temp[2]!=miss && temp[3]!=miss && temp[3]!=old){
					find.push_back(temp[3]);
				}else if(map[temp[2].y][temp[2].x]!=1 && map[temp[2].y][temp[2].x]<8 && temp[0]!=miss && temp[1]!=miss && temp[2]!=miss && temp[2]!=old){
					find.push_back(temp[2]);
				}else if(map[temp[1].y][temp[1].x]!=1 && map[temp[1].y][temp[1].x]<8 && temp[0]!=miss && temp[1]!=miss && temp[1]!=old){
					find.push_back(temp[1]);
				}else if(map[temp[0].y][temp[0].x]!=1 && map[temp[0].y][temp[0].x]<8 && temp[0]!=miss && temp[0]!=old){
					find.push_back(temp[0]);
				}else{
					miss=now;
					find.pop_back();
				}
			}
		}else{
			Pos now=find.back();
			
			if(map[find[find.size()-2].y][find[find.size()-2].x]==4) find.pop_back();
			else if(map[now.y-1][now.x]==4){
				now.y--;
				find.push_back(now);
			} 
			else if(map[now.y][now.x+1]==4){
				now.x++;
				find.push_back(now);
			}
			else if(map[now.y+1][now.x]==4){
				now.y++;
				find.push_back(now);
			}
			else if(map[now.y][now.x-1]==4){
				now.x--;
				find.push_back(now);
			}
		}
		pos=find[1];
		find.erase(find.begin());
	}else{
		if(find.size()!=0){
			pos=find[1];
			find.erase(find.begin());
			if(pos==find.back()) find.clear();
		}else{
			int poss=rand()%4;
			if(poss==0 && map[pos.y-1][pos.x]!=1 && map[pos.y-1][pos.x]<8) pos.y--;
			else if(poss==1 && map[pos.y][pos.x+1]!=1 && map[pos.y][pos.x+1]<8) pos.x++;
			else if(poss==2 && map[pos.y+1][pos.x]!=1 && map[pos.y+1][pos.x]<8) pos.y++;
			else if(map[pos.y][pos.x-1]!=1 && map[pos.y][pos.x-1]<8) pos.x--;	
		}
	}
	map[pos.y][pos.x]=5;
	gotoLine(copy.x*2,copy.y); cout<<"  ";
	gotoLine(pos.x*2,pos.y); cout<<"& ";
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
void Player::beTrapped(){
	srand(time(0));
	const int i=rand()%11;
	if(i<3){
		hp-=hpmax*(rand()%6+5)/100;
	}else if(i<6){
		for(int i=0;i<1e7;i++);
	}else if(i<8){
		
	}else{
		def-=def*(rand()%5+5)*100;
	}	
}
void Player::walk(int **map){
	Pos copy=pos;
	map[pos.y][pos.x]=(pos==first?8:pos==end?9:0);
	if(GetAsyncKeyState(0x57) && map[pos.y-1][pos.x]!=1){
		pos.y--;
	}else if(GetAsyncKeyState(0x53) && map[pos.y+1][pos.x]!=1){
		pos.y++;
	}else if(GetAsyncKeyState(0x41) && map[pos.y][pos.x-1]!=1){
		pos.x--;
	}else if(GetAsyncKeyState(0x44) && map[pos.y][pos.x+1]!=1){
		pos.x++;
	}
	map[pos.y][pos.x]=4;
	gotoLine(copy.x*2,copy.y); cout<<"  ";
	gotoLine(pos.x*2,pos.y); cout<<"* ";

/*	if(map[y][x]==2) get()
	else if(map[y][x]==3) beTrapped();*/
}







