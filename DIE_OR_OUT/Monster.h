class Player;

class Monster{
		string name;		
		int vision;
		int delay_walk;
		int delay_stop;
		int poss_walk;
		Pos pos;
		vector<Pos> find, chest;
	public:			
		Monster(string, int ****, int, int);
		void getstatus();
		void showstatus(); 
		void beTrapped();
		void findPlayer(int ****, const Player &);
};

Monster::Monster(string n, int ****map, int xx, int yy){
	name = n;
	do{
		pos.y=rand()%(yy-2)+1;
		pos.x=rand()%(xx-2)+1;
	}while(map[pos.y][pos.x][0][0]==1);
	do{
		pos.a=rand()%6;
		pos.b=rand()%6;
	}while(map[pos.y][pos.x][pos.b][pos.a]!=0);
	map[pos.y][pos.x][pos.b][pos.a]=5;
	delay_stop=0;
	getstatus();
}

void Monster::getstatus(){
	vision=rand()%4+10;
	delay_walk=0;
}
