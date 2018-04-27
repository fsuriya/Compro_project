class Item;
class Trap;

class Player{
	string name;
	int vision;
	int **zoom;
	int old_p;
	Pos pos, first, end;
	public:
		int **mnmap;
		Player(string,Pos,Pos);
		void get();
		void walk(int ****);
		void beTrapped();
		friend void Monster::findPlayer(int ****, const Player &);
		void displayZoom(int ****,int,int);
		void deleteZoom();
		void updateZoom(int ****,int,int);
		void minimap(int,int);
};
Player::Player(string n, Pos start, Pos exit){
	name=n;
	vision=12;
	old_p=0;
	zoom=new int *[vision*2+1];
	for(int i=0;i<vision*2+1;i++) zoom[i]=new int [vision*2+1];
	pos=start; pos.a=3; pos.b=3;
	first=pos;
	end=exit;
}
/*
void Player::displayZoom(int ****map, int length_x, int length_y){
	int ff=vision/6, mm=vision%6;
	Pos set0={pos.x-ff,pos.y-ff,pos.a-mm,pos.b-mm}, read;
	for(int i=0;i<vision*2+1;i++){
		for(int j=0;j<vision*2+1;j++){
			if(pow(i-vision,2)+pow(j-vision,2)<=pow(vision,2)){
				read=(Pos){set0.x+(j/6),set0.y+(i/6),set0.a+(j%6),set0.b+(i%6)};
				if(read.y<0 || read.x<0 || read.y>length_y-1 || read.x>length_x-1) cout<<". ";
				else if(map[read.y][read.x][read.b][read.a]==0) cout<<"  ";
				else if(map[read.y][read.x][read.b][read.a]==1) cout<<"**";
				else if(map[read.y][read.x][read.b][read.a]==4) cout<<"CD";
				else if(map[read.y][read.x][read.b][read.a]==5) cout<<"EB";
				else if(map[read.y][read.x][read.b][read.a]==7) cout<<"oo";
				else if(map[read.y][read.x][read.b][read.a]==8) cout<<"A ";
				else if(map[read.y][read.x][read.b][read.a]==9) cout<<"Z ";
			}else{
				cout<<"::";
			}
		}
		cout<<endl;
	}
}*/
void Player::displayZoom(int ****map, int length_x, int length_y){
	map[pos.y][pos.x][pos.b][pos.a]=4;
	int ff=vision/6, mm=vision%6;
	Pos set0={pos.x-ff,pos.y-ff,pos.a-mm,pos.b-mm}, read=set0;
	for(int i=0;i<vision*2+1;i++){
		read.x=set0.x; read.a=set0.a;
		for(int j=0;j<vision*2+1;j++){
			if(pow(i-vision,2)+pow(j-vision,2)<=pow(vision,2)){
				if(read.y<0 || read.x<0 || read.y>length_y-1 || read.x>length_x-1){
					cout<<"  ";
					zoom[i][j]=99;
				}else if(map[read.y][read.x][read.b][read.a]==0){
					cout<<"||"; //Way
					zoom[i][j]=0;
				}else if(map[read.y][read.x][read.b][read.a]==1){
					cout<<"**"; //Block
					zoom[i][j]=1;
				}else if(map[read.y][read.x][read.b][read.a]==2){
					cout<<"||"; //Trap
					zoom[i][j]=2;
				}else if(map[read.y][read.x][read.b][read.a]==3){
					cout<<"NP"; //Item
					zoom[i][j]=3;
				}else if(map[read.y][read.x][read.b][read.a]==4){
					cout<<"CD"; //Player
					zoom[i][j]=4;
				}else if(map[read.y][read.x][read.b][read.a]==5){
					cout<<"EB"; //Monster
					zoom[i][j]=5;
				}else if(map[read.y][read.x][read.b][read.a]==7){
					cout<<"oo"; //Rock
					zoom[i][j]=7;
				}else if(map[read.y][read.x][read.b][read.a]==8){
					cout<<"A "; //Start
					zoom[i][j]=8;
				}else if(map[read.y][read.x][read.b][read.a]==9){
					cout<<"Z "; //End
					zoom[i][j]=9;
				}
			}else{
				cout<<"  ";
				zoom[i][j]=69;
			}
			read+1;
		}
		read+2;
		cout<<endl;
	}
}
void Player::updateZoom(int ****map,int length_x,int length_y){
	int ff=vision/6, mm=vision%6;
	Pos set0={pos.x-ff,pos.y-ff,pos.a-mm,pos.b-mm}, read=set0;
	for(int i=0;i<vision*2+1;i++){
		read.x=set0.x; read.a=set0.a;
		for(int j=0;j<vision*2+1;j++){
			if(pow(i-vision,2)+pow(j-vision,2)<=pow(vision,2)){
				if(read.y<0 || read.x<0 || read.y>length_y-1 || read.x>length_x-1){
					if(zoom[i][j]!=99){
						zoom[i][j]=99;
						gotoLine(j*2,i); cout<<"  ";
					}
				}else if(map[read.y][read.x][read.b][read.a]==0){
					if(zoom[i][j]!=0){
						zoom[i][j]=0;
						gotoLine(j*2,i); cout<<"||";
					}
				}else if(map[read.y][read.x][read.b][read.a]==1){
					if(zoom[i][j]!=1){
						zoom[i][j]=1;
						gotoLine(j*2,i); cout<<"**";
					}
				}else if(map[read.y][read.x][read.b][read.a]==2){
					if(zoom[i][j]!=2){
						zoom[i][j]=2;
						gotoLine(j*2,i); cout<<"||";
					}
				}else if(map[read.y][read.x][read.b][read.a]==3){
					if(zoom[i][j]!=3){
						zoom[i][j]=3;
						gotoLine(j*2,i); cout<<"NP";
					}
				}else if(map[read.y][read.x][read.b][read.a]==4){
					if(zoom[i][j]!=4){
						zoom[i][j]=4;
						gotoLine(j*2,i); cout<<"CD";
					}
				}else if(map[read.y][read.x][read.b][read.a]==5){
					if(zoom[i][j]!=5){
						zoom[i][j]=5;
						gotoLine(j*2,i); cout<<"EB";
					}
				}else if(map[read.y][read.x][read.b][read.a]==7){
					if(zoom[i][j]!=7){
						zoom[i][j]=7;
						gotoLine(j*2,i); cout<<"oo";
					}
				}else if(map[read.y][read.x][read.b][read.a]==8){
					if(zoom[i][j]!=8){
						zoom[i][j]=8;
						gotoLine(j*2,i); cout<<"A ";
					}
				}else if(map[read.y][read.x][read.b][read.a]==9){
					if(zoom[i][j]!=9){
						zoom[i][j]=9;
						gotoLine(j*2,i); cout<<"Z ";
					}
				}
			}else{
				if(zoom[i][j]!=69){
					zoom[i][j]=69;
					gotoLine(j*2,i); cout<<"  ";
				}
			}
			read+1;
		}
		read+2;
	}
}
void Player::deleteZoom(){
	for(int i=0;i<vision*2+1;i++) delete [] zoom[i];
	delete [] zoom;
}
void Player::minimap(int length_x, int length_y){
	system("CLS");
	for(int i=0;i<length_y;i++){
		for(int j=0;j<length_x;j++){
			if(mnmap[i][j]==0) cout<<"  ";
			else cout<<"? ";
		}
		cout<<endl;
	}
	cout<<endl;
	system("pause");
}
void Monster::findPlayer(int ****map, const Player &player){
	if(player.pos!=player.first && player.pos!=player.end){
		if(delay_stop=0){
			if(pos-=player.pos){
				Pos copy=pos;
				map[pos.y][pos.x][pos.b][pos.a]=0;
				Pos ap=pos, a2p=pos, an=pos, a2n=pos, bp=pos, b2p=pos, bn=pos, b2n=pos;
				ap+1;
				a2p+1; a2p+1;
				an-1;
				a2n-1; a2n-1;
				bp+2;
				b2p+2; b2p+2;
				bn-2;
				b2n-2; b2n-2;
				int apm, a2pm, anm, a2nm, bpm, b2pm, bnm, b2nm;
				apm=map[ap.y][ap.x][ap.b][ap.a];
				a2pm=map[a2p.y][a2p.x][a2p.b][a2p.a];
				anm=map[an.y][an.x][an.b][an.a];
				a2nm=map[a2n.y][a2n.x][a2n.b][a2n.a];
				bpm=map[bp.y][bp.x][bp.b][bp.a];
				b2pm=map[b2p.y][b2p.x][b2p.b][b2p.a];
				bnm=map[bn.y][bn.x][bn.b][bn.a];
				b2nm=map[b2n.y][b2n.x][b2n.b][b2n.a];
				if(chest.size()!=0){
					pos=chest[0];
					chest.erase(chest.begin());
					goto change;
				}
				if(pow(player.pos.x*6+player.pos.a-pos.x*6-pos.a,2)+pow(player.pos.y*6+player.pos.b-pos.y*6-pos.b,2)<=pow(vision,2)){
					if(pos!=player.pos){
						if(find.size()==0){
							Pos now,temp[4];
							find.push_back(pos);
							Pos old,miss={-1,-1};
							while(1){
								now=find.back();
								old=(find.size()>=2?find[find.size()-2]:(Pos){-1,-1});
								if(now==player.pos) break;
								temp[0]=(Pos){now.x,now.y-1}; temp[1]=(Pos){now.x+1,now.y};
								temp[2]=(Pos){now.x,now.y+1}; temp[3]=(Pos){now.x-1,now.y};
								if(map[temp[3].y][temp[3].x][0][0]!=1 && map[temp[3].y][temp[3].x][0][0]<8 && temp[0]!=miss && temp[1]!=miss && temp[2]!=miss && temp[3]!=miss && temp[3]!=old){
									find.push_back(temp[3]);
								}else if(map[temp[2].y][temp[2].x][0][0]!=1 && map[temp[2].y][temp[2].x][0][0]<8 && temp[0]!=miss && temp[1]!=miss && temp[2]!=miss && temp[2]!=old){
									find.push_back(temp[2]);
								}else if(map[temp[1].y][temp[1].x][0][0]!=1 && map[temp[1].y][temp[1].x][0][0]<8 && temp[0]!=miss && temp[1]!=miss && temp[1]!=old){
									find.push_back(temp[1]);
								}else if(map[temp[0].y][temp[0].x][0][0]!=1 && map[temp[0].y][temp[0].x][0][0]<8 && temp[0]!=miss && temp[0]!=old){
									find.push_back(temp[0]);
								}else{
									miss=now;
									find.pop_back();
								}
							}
						}else{
							if(find[find.size()-2]==player.pos) find.pop_back();
							else if(find.back()!=player.pos) find.push_back(player.pos);
						}
					}	
				}else if(find.size()==0){
					if(delay_walk==0){
						poss_walk=rand()%4;
					}
					if(poss_walk==0 && bnm!=1 && bnm<7 && bnm!=5) pos=bn;
					else if(poss_walk==1 && apm!=1 && apm<7 && apm!=5) pos=ap;
					else if(poss_walk==2 && bpm!=1 && bpm<7 && bpm!=5) pos=bp;
					else if(anm!=1 && anm<7 && anm!=5) pos=an;
					delay_walk++;
					if(delay_walk>1) delay_walk=0;
					goto change;
				}
				if(find.size()!=0){
					if(find[1].x-pos.x==1){
						if(apm!=7 && apm!=5 && (a2pm!=7 || (map[bp.y][bp.x][bp.b][bp.a+1]!=7 && map[bp.y][bp.x][bp.b][bp.a+1]!=1)
						|| (map[bn.y][bn.x][bn.b][bn.a+1]!=7 && map[bn.y][bn.x][bn.b][bn.a+1]!=1)))
							pos=ap;
						else{
							int rposs=rand()%2, count=(rposs?0:11);
							do{
								if(count<6 && bpm!=7 && bpm!=1 && bpm!=5){
									pos+2;
									ap+2;
									a2p+2;
									chest.push_back(pos);
								}
								else if(bnm!=7 && bnm!=1 && bnm!=5){
									pos-2;
									ap-2;
									a2p-2;
									chest.push_back(pos);
								}
								bpm=map[pos.y][pos.x][pos.b+1][pos.a];
								bnm=map[pos.y][pos.x][pos.b-1][pos.a];
								rposs?count++:count--;
								if(chest.back()+=copy) chest.clear();
							}while(map[ap.y][ap.x][ap.b][ap.a]==7 || map[a2p.y][a2p.x][a2p.b][a2p.a]==7); //bug
							pos=chest[0];
							chest.erase(chest.begin());
						}
					}else if(find[1].x-pos.x==-1){
						if(anm!=7 && anm!=5 && (a2nm!=7 || (map[bp.y][bp.x][bp.b][bp.a-1]!=7 && map[bp.y][bp.x][bp.b][bp.a-1]!=1)
						|| (map[bn.y][bn.x][bn.b][bn.a-1]!=7 && map[bn.y][bn.x][bn.b][bn.a-1]!=1)))
							pos=an;
						else{
							int rposs=rand()%2, count=(rposs?0:11);
							do{
								if(count<6 && bpm!=7 && bpm!=1 && bpm!=5){
									pos+2;
									an+2;
									a2n+2;
									chest.push_back(pos);
								}
								else if(bnm!=7 && bnm!=1 && bnm!=5){
									pos-2;
									an-2;
									a2n-2;
									chest.push_back(pos);
								}
								bpm=map[pos.y][pos.x][pos.b+1][pos.a];
								bnm=map[pos.y][pos.x][pos.b-1][pos.a];
								rposs?count++:count--;
								if(chest.back()+=copy) chest.clear();
							}while(map[an.y][an.x][an.b][an.a]==7 || map[a2n.y][a2n.x][a2n.b][a2n.a]==7);
							pos=chest[0];
							chest.erase(chest.begin());
						}
					}else if(find[1].y-pos.y==1){
						if(bpm!=7 && bpm!=5 && (b2pm!=7 || (map[ap.y][ap.x][ap.b+1][ap.a]!=7 && map[ap.y][ap.x][ap.b+1][ap.a]!=1)
						|| (map[an.y][an.x][an.b+1][an.a]!=7 && map[an.y][an.x][an.b+1][an.a]!=1)))
							pos=bp;
						else{
							int rposs=rand()%2, count=(rposs?0:11);
							do{
								if(count<6 && apm!=7 && apm!=1 && apm!=5){
									pos+1;
									bp+1;
									b2p+1;
									chest.push_back(pos);
								}
								else if(anm!=7 && anm!=1 && anm!=5){
									pos-1;
									bp-1;
									b2p-1;
									chest.push_back(pos);
								}
								apm=map[pos.y][pos.x][pos.b][pos.a+1];
								anm=map[pos.y][pos.x][pos.b][pos.a-1];
								rposs?count++:count--;
								if(chest.back()+=copy) chest.clear();
							}while(map[bp.y][bp.x][bp.b][bp.a]==7 || map[b2p.y][b2p.x][b2p.b][b2p.a]==7);
							pos=chest[0];
							chest.erase(chest.begin());
						}
					}else if(find[1].y-pos.y==-1){
						if(bnm!=7 && bnm!=5 && (b2nm!=7 || (map[ap.y][ap.x][ap.b-1][ap.a]!=7 && map[ap.y][ap.x][ap.b-1][ap.a]!=1)
						|| (map[an.y][an.x][an.b-1][an.a]!=7 && map[an.y][an.x][an.b-1][an.a]!=1)))
							pos=bn;
						else{
							int rposs=rand()%2, count=(rposs?0:11);
							do{
								if(count<6 && apm!=7 && apm!=1 && apm!=5){
									pos+1;
									bn+1;
									b2n+1;
									chest.push_back(pos);
								}
								else if(anm!=7 && anm!=1 && anm!=5){
									pos-1;
									bn-1;
									b2n-1;
									chest.push_back(pos);
								}
								apm=map[pos.y][pos.x][pos.b][pos.a+1];
								anm=map[pos.y][pos.x][pos.b][pos.a-1];
								rposs?count++:count--;
								if(chest.back()+=copy) chest.clear();
							}while(map[bn.y][bn.x][bn.b][bn.a]==7 || map[b2n.y][b2n.x][b2n.b][b2n.a]==7);
							pos=chest[0];
							chest.erase(chest.begin());
						}
					}
					if(pos==find[1]) find.erase(find.begin());
					if(pos==find.back()) find.clear();
				}else{
					int rposs=2;
					if(pos.a!=player.pos.a && pos.b!=player.pos.b) rposs=rand()%2;
					if(rposs!=0){
						if(pos.a<player.pos.a){
							if(apm!=7 && apm!=5 && (a2pm!=7 || (map[bp.y][bp.x][bp.b][bp.a+1]!=7 && map[bp.y][bp.x][bp.b][bp.a+1]!=1)
							|| (map[bn.y][bn.x][bn.b][bn.a+1]!=7 && map[bn.y][bn.x][bn.b][bn.a+1]!=1)))
								pos=ap;
							else{
								if(apm==7 || apm==5){
									if(pos.b<player.pos.b && (bpm==7 || bpm==1 || bpm==5)) pos=bn;
									else pos=bp;	//bug
								}else{
									if(bpm==7 || bpm==1 || bpm==5 || b2pm==7 || b2pm==1){
										b2p=b2n;
										bp=bn;
									}else if(bnm==7 || bnm==1 || bnm==5 || b2nm==7 || b2nm==1){
										b2n=b2p;
										bn=bp;
									}
									if(pos.b<player.pos.b){
										pos=bp;
										chest.push_back(b2p);
									}else if(pos.b>player.pos.b){
										pos=bn;
										chest.push_back(b2n);
									}else{
										if(rand()%2){
											pos=bp;
											chest.push_back(b2p);
										}else{
											pos=bn;
											chest.push_back(b2n);
										}
									}
								}
							}
						}else if(pos.a>player.pos.a){
							if(anm!=7 && anm!=5 && (a2nm!=7 || (map[bp.y][bp.x][bp.b][bp.a-1]!=7 && map[bp.y][bp.x][bp.b][bp.a-1]!=1)
							|| (map[bn.y][bn.x][bn.b][bn.a-1]!=7 && map[bn.y][bn.x][bn.b][bn.a-1]!=1)))
								pos=an;
							else{
								if(anm==7 || anm==5){
									if(pos.b<player.pos.b && (bpm==7 || bpm==1 || bpm==5)) pos=bn;
									else pos=bp;
								}else{
									if(bpm==7 || bpm==1 || bpm==5 || b2pm==7 || b2pm==1){
										b2p=b2n;
										bp=bn;
									}else if(bnm==7 || bnm==1 || bnm==5 || b2nm==7 || b2nm==1){
										b2n=b2p;
										bn=bp;
									} 
									if(pos.b<player.pos.b){
										pos=bp;
										chest.push_back(b2p);
									}else if(pos.b>player.pos.b){
										pos=bn;
										chest.push_back(b2n);
									}else{
										if(rand()%2){
											pos=bp;
											chest.push_back(b2p);
										}else{
											pos=bn;
											chest.push_back(b2n);
										}
									}
								}
							}
						}
					}
					if(rposs!=1){
						if(pos.b<player.pos.b){
							if(bpm!=7 && bpm!=5 && (b2pm!=7 || (map[ap.y][ap.x][ap.b+1][ap.a]!=7 && map[ap.y][ap.x][ap.b+1][ap.a]!=1)
							|| (map[an.y][an.x][an.b+1][an.a]!=7 && map[an.y][an.x][an.b+1][an.a]!=1)))
								pos=bp;
							else{
								if(bpm==7 || bpm==5){
									if(pos.a<player.pos.a && (apm==7 || apm==1 || apm==5)) pos=an;
									else pos=ap;
								}else{
									if(apm==7 || apm==1 || apm==5 || a2pm==7 || a2pm==1){
										a2p=a2n;
										ap=an;
									}else if(anm==7 || anm==1 || anm==5 || a2nm==7 || a2nm==1){
										a2n=a2p;
										an=ap;
									} 
									if(pos.a<player.pos.a){
										pos=ap;
										chest.push_back(a2p);
									}else if(pos.a>player.pos.a){
										pos=an;
										chest.push_back(a2n);
									}else{
										if(rand()%2){
											pos=ap;
											chest.push_back(a2p);
										}else{
											pos=an;
											chest.push_back(a2n);
										}
									}
								}
							}
						}else if(pos.b>player.pos.b){
							if(bnm!=7 && bnm!=5 && (b2nm!=7 || (map[ap.y][ap.x][ap.b-1][ap.a]!=7 && map[ap.y][ap.x][ap.b-1][ap.a]!=1)
							|| (map[an.y][an.x][an.b-1][an.a]!=7 && map[an.y][an.x][an.b-1][an.a]!=1)))
								pos=bn;
							else{
								if(bnm==7 || bnm==5){
									if(pos.a<player.pos.a && (apm==7 || apm==1 || apm==5)) pos=an;
									else pos=ap;
								}else{
									if(apm==7 || apm==1 || apm==5 || a2pm==7 || a2pm==1){
										a2p=a2n;
										ap=an;
									}else if(anm==7 || anm==1 || anm==5 || a2nm==7 || a2nm==1){
										a2n=a2p;
										an=ap;
									} 
									if(pos.a<player.pos.a){
										pos=ap;
										chest.push_back(a2p);
									}else if(pos.a>player.pos.a){
										pos=an;
										chest.push_back(a2n);
									}else{
										if(rand()%2){
											pos=ap;
											chest.push_back(a2p);
										}else{
											pos=an;
											chest.push_back(a2n);
										}
									}
								}
							}
						}
					}
				}
			}
			if(pos+=player.pos){
				count_time-=10;
				delay_stop=12;
			}
			
			change:
			map[pos.y][pos.x][pos.b][pos.a]=5;
		}else delay_stop--;
		
	}
		
}

void Player::get(){
	count_time+=5;
	
}
void Player::beTrapped(){
	count_time-=3;	
}
void Player::walk(int ****map){
		Pos copy=pos;
		map[pos.y][pos.x][pos.b][pos.a]=(pos==first?8:pos==end?9:old_p);
		if(GetAsyncKeyState(0x57)) pos-2;
		else if(GetAsyncKeyState(0x53)) pos+2;
		else if(GetAsyncKeyState(0x41)) pos-1;
		else if(GetAsyncKeyState(0x44)) pos+1;
		int pmap=map[pos.y][pos.x][pos.b][pos.a];
		old_p=0;
		if(pmap==1 || pmap==7){
			pos=copy;
			pmap=map[pos.y][pos.x][pos.b][pos.a];
		}
		if(pmap==3){
			if(GetAsyncKeyState(0x46)) get();
			else old_p=3;
		}else if(pmap==2) beTrapped();
		map[pos.y][pos.x][pos.b][pos.a]=4;
		mnmap[pos.y][pos.x]=0;
	
}
