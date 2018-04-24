#include<iostream>
#include"Player.h"
#include"Monster.h"
#include"character.h"
#include"Witch.h"
#include<iomanip>

int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,12);
	cout << "\n";
	cout << setw(100) << "-----------------------------------\n";
	//infor mon
	cout << "\n\n";
	cout << setw(100) << "-----------------------------------\n";
	cout << "\n\n";
	character(15);
	//witch(50);
	cout << "\n";
	SetConsoleTextAttribute(hConsole,10);
	cout << setw(40) << "-----------------------------------\n";
	cout << "\n\n";
	cout << setw(40) << "-----------------------------------\n";
	SetConsoleTextAttribute(hConsole,15);
	
	return 0;
}
