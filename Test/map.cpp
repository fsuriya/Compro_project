#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

int main(){
	srand(time(0));
	//fixed row-col
	int n=35;
	
	//creat map aray
	int data_map[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			data_map[i][j]=1;
		}
	}

	//rand start delete
	int ToRandXY=n/2-1;
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
		}else if(poss==2&&jrand<n-3){
			jrand+=2;
		}else if(poss==3&&irand<n-3){
			irand+=2;
		}
		
		if(data_map[irand][jrand]!=0){
			data_map[irand][jrand]=0;
			data_map[(irand+cpyirand)/2][(jrand+cpyjrand)/2]=0;
			posX.push_back(irand);
			posY.push_back(jrand);
			++count_map;
		}else if(data_map[cpyirand][cpyjrand-2>0?cpyjrand-2:cpyjrand]==0&&data_map[cpyirand-2>0?cpyirand-2:cpyirand][cpyjrand]==0
		&&data_map[cpyirand][cpyjrand+2<n-1?cpyjrand+2:cpyjrand]==0&&data_map[cpyirand+2<n-1?cpyirand+2:cpyirand][cpyjrand]==0){
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
	
	//show map
	//0==empty //1==wall //2==trap //3==item //4==playyer //5==monter
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
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
	
	return 0;
}
