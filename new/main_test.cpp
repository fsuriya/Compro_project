#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <stdio.h> 
#include <iomanip>
using namespace std;

//Count
int count_time;
int time_max;
int delay_time=4;

class Pos{
	public:
		int x;
		int y;
		int a;
		int b;
		void check();
};
void Pos::check(){
	if(a<0){
		x--;
		a=5;
	}else if(a>5){
		x++;
		a=0;
	}else if(b<0){
		y--;
		b=5;
	}else if(b>5){
		y++;
		b=0;
	}
}
void operator+(Pos &a, int i){
	if(i==1){
		a.a++;
		if(a.a>5){
			a.x++;
			a.a=0;
		}
	}else{
		a.b++;
		if(a.b>5){
			a.y++;
			a.b=0;
		}
	}
}
void operator-(Pos &a, int i){
	if(i==1){
		a.a--;
		if(a.a<0){
			a.x--;
			a.a=5;
		}
	}else{
		a.b--;
		if(a.b<0){
			a.y--;
			a.b=5;
		}
	}
}
bool operator+=(const Pos &a, const Pos &b){
	if(a.x==b.x && a.y==b.y && a.a==b.a && a.b==b.b) return true;
	return false;
}
bool operator-=(const Pos &a, const Pos &b){
	if(a.x==b.x && a.y==b.y && a.a==b.a && a.b==b.b) return false;
	return true;
}
bool operator==(const Pos &a, const Pos &b){
	if(a.x==b.x && a.y==b.y) return true;
	return false;
}
bool operator!=(const Pos &a, const Pos &b){
	if(a.x==b.x && a.y==b.y) return false;
	return true;
}
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPos;

void gotoLine(int, int);
void hideCursor(bool, DWORD);
void showTime();

#include "Monster.h"
#include "Player.h"

int main(){
	srand(time(0));
	//Set row-col
	int length_x, length_y;
	cout<<"Set Scale **Odd number** (x, y): ";cin>>length_x>>length_y;
	
	time_max=length_x*length_y*10;
	count_time=time_max;
	//creat map aray
	int ****data_map=new int ***[length_y];
	for(int i=0;i<length_y;i++){
		data_map[i]=new int **[length_x];
		for(int j=0;j<length_x;j++){
			data_map[i][j]=new int *[6];
			for(int k=0;k<6;k++) data_map[i][j][k]=new int [6];
		}
	}
	//All to 1
	for(int i=0;i<length_y;i++){
		for(int j=0;j<length_x;j++){
			for(int k=0;k<6;k++){
				for(int l=0;l<6;l++){
					data_map[i][j][k][l]=1;
				}
			}
			
		}
	}

	//rand start delete
	int oi=rand()%(length_y/2)*2+1;
	int oj=rand()%(length_x/2)*2+1;
	int irand=oi;
	int jrand=oj;
	
	bool break_flag=true;
	vector<int> posX;
	vector<int> posY;
	int count_map=0;
	
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			data_map[irand][jrand][i][j]=(rand()%30==0 ? 7 : rand()%80==0 ? 3 : rand()%90==0 ? 2 : 0);
		}
	}
	posX.push_back(irand);
	posY.push_back(jrand);
	//cout<<irand<<" : "<<jrand<<endl;
	while(break_flag){
		int cpyirand=irand;
		int cpyjrand=jrand;
		
		int poss=rand()%4;
		if(poss==0&&jrand>2){
			jrand-=2;
		}else if(poss==1&&irand>2){
			irand-=2;
		}else if(poss==2&&jrand<length_x-3){
			jrand+=2;
		}else if(poss==3&&irand<length_y-3){
			irand+=2;
		}
		
		if(data_map[irand][jrand][0][0]==1){
			for(int i=0;i<6;i++){
				for(int j=0;j<6;j++){
					data_map[irand][jrand][i][j]=(rand()%30==0 ? 7 : rand()%80==0 ? 3 : rand()%90==0 ? 2 : 0);
				}
			}
			for(int i=0;i<6;i++){
				for(int j=0;j<6;j++){
					data_map[(irand+cpyirand)/2][(jrand+cpyjrand)/2][i][j]=(rand()%30==0 ? 7 : rand()%80==0 ? 3 : rand()%90==0 ? 2 : 0);
				}
			}	
			posX.push_back(irand);
			posY.push_back(jrand);
			++count_map;
		}else if(data_map[cpyirand][cpyjrand-2>0?cpyjrand-2:cpyjrand][0][0]!=1&&data_map[cpyirand-2>0?cpyirand-2:cpyirand][cpyjrand][0][0]!=1
		&&data_map[cpyirand][cpyjrand+2<length_x-1?cpyjrand+2:cpyjrand][0][0]!=1&&data_map[cpyirand+2<length_y-1?cpyirand+2:cpyirand][cpyjrand][0][0]!=1){
			posX.pop_back();
			posY.pop_back();
			--count_map;
			irand=posX[count_map];
			jrand=posY[count_map];
		}else{
			irand=cpyirand;
			jrand=cpyjrand;
		}
		//cout<<irand<<" : "<<jrand<<endl;
		if(oi==irand&&oj==jrand&&count_map==0){
			break_flag=false;
		}
	}
	
	//Create start, exit
	Pos start, exit;
	{
		int poss=rand()%4;
		if(poss==0){
			start.y=0;
			exit.y=length_y-1;
			do{
				start.x=rand()%(length_x-2)+1;
				exit.x=rand()%(length_x-2)+1;
			}while(data_map[start.y+1][start.x][0][0]==1 || data_map[exit.y-1][exit.x][0][0]==1);
		}else if(poss==1){
			start.x=length_x-1;
			exit.x=0;
			do{
				start.y=rand()%(length_y-2)+1;
				exit.y=rand()%(length_y-2)+1;
			}while(data_map[start.y][start.x-1][0][0]==1 || data_map[exit.y][exit.x+1][0][0]==1);
		}else if(poss==2){
			start.y=length_y-1;
			exit.y=0;
			do{
				start.x=rand()%(length_x-2)+1;
				exit.x=rand()%(length_x-2)+1;
			}while(data_map[start.y-1][start.x][0][0]==1 || data_map[exit.y+1][exit.x][0][0]==1);
		}else{
			start.x=0;
			exit.x=length_x-1;
			do{
				start.y=rand()%(length_y-2)+1;
				exit.y=rand()%(length_y-2)+1;
			}while(data_map[start.y][start.x+1][0][0]==1 || data_map[exit.y][exit.x-1][0][0]==1);
		}
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				data_map[start.y][start.x][i][j]=8;
			}
		}
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				data_map[exit.y][exit.x][i][j]=9;
			}
		}
	}

	//Create character
	Player player("gg", start, exit);
	Monster aa("555",data_map,length_x,length_y);
	Monster bb("555",data_map,length_x,length_y);
	Monster cc("555",data_map,length_x,length_y);
	Monster dd("555",data_map,length_x,length_y);
	
	//Set Minimap
	player.mnmap=new int*[length_y];
	for(int i=0;i<length_y;i++) player.mnmap[i]=new int [length_x];
	for(int i=0;i<length_y;i++){
		for(int j=0;j<length_x;j++) player.mnmap[i][j]=1;
	}
	player.mnmap[start.y][start.x]=0;
	
	//Display Maze
	system("CLS");
	hideCursor(0,0);
	bool kk=1;
/*	for(int i=0;i<length_y;i++){
		for(int j=0;j<length_x;j++){
			if(data_map[i][j]==0||data_map[i][j]==2){
				cout<<"  ";//empty,trap
			}else if(data_map[i][j]==1){
				cout<<"00";//wall
			}else if(data_map[i][j]==3){
				cout<<"@ ";//item
			}else if(data_map[i][j]==4){
				cout<<"* ";//player
			}else if(data_map[i][j]==5){
				cout<<"& ";//monter
			}else if(data_map[i][j]==7){
				cout<<"00";//rock
			}else if(data_map[i][j]==8){
				cout<<"A ";//start
			}else if(data_map[i][j]==9){
				cout<<"Z ";//exit
			}
		}cout<<endl;
	}*/
	player.displayZoom(data_map,length_x,length_y);
	
	//Action	
	while(kk){
		showTime();
		if(delay_time<1){
			delay_time=4;
			count_time--;
		}
		if(GetAsyncKeyState(VK_ESCAPE)) kk=0;
		player.walk(data_map);
		aa.findPlayer(data_map,player);
		bb.findPlayer(data_map,player);
		cc.findPlayer(data_map,player);
		dd.findPlayer(data_map,player);
		player.updateZoom(data_map,length_x,length_y);
		if(GetAsyncKeyState(0x4D)){
			player.minimap(length_x,length_y);
			system("CLS");
			player.displayZoom(data_map,length_x,length_y);
		}
		Sleep(200);
		delay_time--;
	}
	
	//Delete Dinatic
	for(int i=0;i<length_y;i++){
		for(int j=0;j<length_x;j++){
			for(int k=0;k<6;k++){
				delete [] data_map[i][j][k];
			}
			delete [] data_map[i][j];
		}
		delete [] data_map[i], player.mnmap[i];
	}
	delete [] data_map, player.mnmap;
	player.deleteZoom();
	
	hideCursor(1,10);
	return 0;
}

//Function
void showTime(){
	gotoLine(0,0); cout<<setw(5)<<count_time;
}

void gotoLine(int xx, int yy){
	cursorPos.X=xx;
	cursorPos.Y=yy;
	SetConsoleCursorPosition(console,cursorPos); 
}
void hideCursor(bool on, DWORD size){
	if(size == 0) size = 20;
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = on;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
