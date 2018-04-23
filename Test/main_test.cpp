#include<iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
#include "Monster.h"
#include "Player.h"
//#include "Item.h"


int main(){
	srand(time(0));
	//fixed row-col
	int length_x, length_y;
	cout<<"Scale (x, y): ";cin>>length_x>>length_y;
	
	//creat map aray
	int **data_map=new int *[length_y];
	for(int i=0;i<length_y;i++) data_map[i]=new int [length_x];
	for(int i=0;i<length_y;i++){
		for(int j=0;j<length_x;j++){
			data_map[i][j]=1;
		}
	}

	//rand start delete
	int ToRandXY=length_x/2-1;
	int oi=rand()%ToRandXY*2+1;
	int oj=rand()%ToRandXY*2+1;
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
	Player player(0, 0, 0, jrand, irand);
	
	while(1){
		system("CLS");
		player.walk(data_map);
		for(int i=0;i<length_y;i++){
			for(int j=0;j<length_x;j++){
				if(data_map[i][j]==0||data_map[i][j]==2){
					cout<<"  ";//empty,trap
				}else if(data_map[i][j]==1){
					cout<<"00";//wall
				}else if(data_map[i][j]==3){
					cout<<"@ ";//item
				}else if(data_map[i][j]==4){
					cout<<"* ";//playyer
				}else if(data_map[i][j]==5){
					cout<<"& ";//monter
				}
			}cout<<endl;
		}
	}
	
	for(int i=0;i<length_y;i++) delete [] data_map[i];
	delete [] data_map;
	
	return 0;
}
