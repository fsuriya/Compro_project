//Weapon - Axe Sword Spear Graves Hammer [Excaliber(rare)]

//Armo - 1.leather 2.Iron [Diamond(rare)]

//Medicine - 1.Bread +10 HP 2.Red Potion +20 HP [Feather(rare) reborn in thisplace.]

//Potion - 1.Light Potion(more light) 2.White Potion(delete curse) 3.Blue Potion(up speed)

//Trap - 1.Lock Leg (2s) 2.Down HP 3.Remove Weapon 

class Equipment{
	string name;
	int hpmax;
	int atk;
	int def;
	Pos pos;
	public:	
		Equipment(string,int,int,int,int ****,int,int);
		friend void Player::wear(vector<Equipment> &);
};
Equipment::Equipment(string nn,int a,int b,int c,int ****map,int xx,int yy){
	name=nn;
	hpmax = a;
	atk = b;
	def = c;
	do{
		pos.y=rand()%(yy-2)+1;
		pos.x=rand()%(xx-2)+1;
	}while(map[pos.y][pos.x][0][0]==1);
	do{
		pos.a=rand()%6;
		pos.b=rand()%6;
	}while(map[pos.y][pos.x][pos.b][pos.a]!=0);
	map[pos.y][pos.x][pos.b][pos.a]=6;
	
}
	
void Player::wear(vector<Equipment> &eq){
	if(equip!=NULL){
		hpmax-=equip->hpmax;
		atk-=equip->atk;
		def-=equip->def;
	}
	for(int i=0;i<7;i++){
		if(pos+=eq[i].pos){
			if(equip!=NULL) swap(eq[i].pos,equip->pos);
			equip=&eq[i];
			break;
		}
	}
	hpmax+=equip->hpmax;
	atk+=equip->atk;
	def+=equip->def;
}

