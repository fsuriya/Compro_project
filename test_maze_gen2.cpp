#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

int main(){
	srand(time(0));
	//fixed row-col
	int n=37;
	
	//creat map aray
	int data_map[n][n][2];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			data_map[i][j][0]=1;
			data_map[i][j][1]=1;
		}
	}
	
	for(int i=0;i<n;i++){
		data_map[0][i][1]=0;
		data_map[n-1][i][1]=0;
		data_map[i][0][1]=0;
		data_map[i][n-1][1]=0;
	}
	
	//rand start delete
	int ToRandXY=n/2-1;
	int oi=rand()%ToRandXY*2+2;
	int oj=rand()%ToRandXY*2+2;
	int irand=oi;
	int jrand=oj;
	
	bool break_flag=true;
	vector<int> posX;
	vector<int> posY;
	int count_map=0;
	
	data_map[irand][jrand][1]=0;
	posX.push_back(irand);
	posY.push_back(jrand);
	//cout<<irand<<" : "<<jrand<<endl;
	while(break_flag){
		int cpyirand=irand;
		int cpyjrand=jrand;
		
		int poss=rand()%4;
		if(poss==0&&jrand>3){
			jrand-=2;
		}else if(poss==1&&irand>3){
			irand-=2;
		}else if(poss==2&&jrand<n-4){
			jrand+=2;
		}else if(poss==3&&irand<n-4){
			irand+=2;
		}
		
		if(data_map[irand][jrand][1]!=0){
			data_map[irand][jrand][1]=0;
			data_map[(irand+cpyirand)/2][(jrand+cpyjrand)/2][1]=0;
			posX.push_back(irand);
			posY.push_back(jrand);
			++count_map;
		}else if(data_map[irand][jrand-2][1]==0&&data_map[irand-2][jrand][1]==0&&data_map[irand][jrand+2][1]==0&&data_map[irand+2][jrand][1]==0){
			posX.pop_back();
			posY.pop_back();
			--count_map;
			irand=posX[count_map];
			jrand=posY[count_map];
		}else if(irand==posX[count_map-1]&&jrand==posY[count_map-1]){
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
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(data_map[i][j][0]==1){ //show
				if(data_map[i][j][1]==0||data_map[i][j][1]==2){
					cout<<"  ";//empty,trap
				}if(data_map[i][j][1]==1){
					cout<<"0 ";//wall
				}if(data_map[i][j][1]==3){
					cout<<"@ ";//item
				}if(data_map[i][j][1]==4){
					cout<<"* ";//playyer
				}if(data_map[i][j][1]==5){
					cout<<"& ";//monter
				}
			}if(data_map[i][j][0]==0){ //unshow
				cout<<" ";
			}
		}cout<<endl;
	}
	
	return 0;
}
