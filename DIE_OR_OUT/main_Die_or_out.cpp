#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "Display_startgame.h"
#include "Display_howtoplay.h"
#include "Display_AboutUS.h"

using namespace std;

int main() {
	//setwindow output
	setwindow(155,80);
	
	int turn=-1;
	bool break_flage=true;	
	//to turn system
	while(break_flage){
		if(turn==-1){
			turn=Display_startgame();
		}else if(turn==0){
			//turn=Display_gameplay();
		}else if(turn==1){
			turn=Display_howtoplay();
		}else if(turn==2){
			turn=Display_credit();
		}else if(turn==3){
			//turn=Display_exit();
			if(turn==69){
				break_flage=false;
			}else{
				turn=-1;
			}
		}
	}
	
	//PlaySound(TEXT("ILLUMINATI.wav"),NULL,SND_SYNC);
	
	return 0;
}