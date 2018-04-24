#include<iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

struct Pos{
	int x;
	int y;
};
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

#include "Monster.h"
#include "Player.h"
//#include "Item.h"

int main(){
	srand(time(0));
	//fixed row-col
	int length_x, length_y;
	cout<<"Set Scale **Odd number** (x, y): ";cin>>length_x>>length_y;
	
	//creat map aray
	int **data_map=new int *[length_y];
	for(int i=0;i<length_y;i++) data_map[i]=new int [length_x];
	for(int i=0;i<length_y;i++){
		for(int j=0;j<length_x;j++){
			data_map[i][j]=1;
		}
	}

	//rand start delete
	int oi=rand()%(length_y/2-1)*2+1;
	int oj=rand()%(length_x/2-1)*2+1;
	int irand=oi;
	int jrand=oj;
	
	bool break_flag=true;
	vector<int> posX;
	vector<int> posY;
	int count_map=0;
	
	data_map[irand][jrand]=0;
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
		
		if(data_map[irand][jrand]!=0){
			data_map[irand][jrand]=0;
			data_map[(irand+cpyirand)/2][(jrand+cpyjrand)/2]=0;
			posX.push_back(irand);
			posY.push_back(jrand);
			++count_map;
		}else if(data_map[cpyirand][cpyjrand-2>0?cpyjrand-2:cpyjrand]==0&&data_map[cpyirand-2>0?cpyirand-2:cpyirand][cpyjrand]==0
		&&data_map[cpyirand][cpyjrand+2<length_x-1?cpyjrand+2:cpyjrand]==0&&data_map[cpyirand+2<length_y-1?cpyirand+2:cpyirand][cpyjrand]==0){
		//	if(irand<length_y && irand>0 && jrand<length_x && jrand>0) data_map[(irand+cpyirand)/2][(jrand+cpyjrand)/2]=0;
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
	Pos start, exit;
	{
		int poss=rand()%4;
		if(poss==0){
			start.y=0;
			exit.y=length_y-1;
			do{
				start.x=rand()%(length_x-2)+1;
				exit.x=rand()%(length_x-2)+1;
			}while(data_map[start.y+1][start.x]==1 || data_map[exit.y-1][exit.x]==1);
		}else if(poss==1){
			start.x=length_x-1;
			exit.x=0;
			do{
				start.y=rand()%(length_y-2)+1;
				exit.y=rand()%(length_y-2)+1;
			}while(data_map[start.y][start.x-1]==1 || data_map[exit.y][exit.x+1]==1);
		}else if(poss==2){
			start.y=length_y-1;
			exit.y=0;
			do{
				start.x=rand()%(length_x-2)+1;
				exit.x=rand()%(length_x-2)+1;
			}while(data_map[start.y-1][start.x]==1 || data_map[exit.y+1][exit.x]==1);
		}else{
			start.x=0;
			exit.x=length_x-1;
			do{
				start.y=rand()%(length_y-2)+1;
				exit.y=rand()%(length_y-2)+1;
			}while(data_map[start.y][start.x+1]==1 || data_map[exit.y][exit.x-1]==1);
		}
		data_map[start.y][start.x]=8;
		data_map[exit.y][exit.x]=9;
	}
	Player player(0, 0, 0, start, exit);
	Monster aa("555",data_map,length_x,length_y);
	system("CLS");
	hideCursor(0,0);
	bool kk=1;
	for(int i=0;i<length_y;i++){
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
				}else if(data_map[i][j]==8){
					cout<<"A ";//start
				}else if(data_map[i][j]==9){
					cout<<"Z ";//exit
				}
			}cout<<endl;
		}
	while(kk){
		if(GetAsyncKeyState(VK_ESCAPE)) kk=0;
//		gotoLine(0,0);
		player.walk(data_map);
		aa.findPlayer(data_map,player);
		Sleep(200);
	}
	
	for(int i=0;i<length_y;i++) delete [] data_map[i];
	delete [] data_map;
	hideCursor(1,10);
	return 0;
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
