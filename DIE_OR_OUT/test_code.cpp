#include <iostream>
#include <Windows.h>
#include "select_status.h"
using namespace std;

int main(){
	string name;
	vector<int> data_playyer=select_status(name);
	
	cout<<name<<endl
		<<data_playyer[0]<<endl
		<<data_playyer[1]<<endl
		<<data_playyer[2]<<endl;
		
	return 0;
}
