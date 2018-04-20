#include<iostream>
#include <windows.h>
using namespace std;

int main(){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,0);
	cout << "   ";
	SetConsoleTextAttribute(hConsole,67);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << "             \n";
	cout << "    ----------   \n";
	cout << "   ------------  \n";
	cout << "   ------------  \n";
	cout << "   -----------   \n";
	cout << "    ----------   \n";
	cout << "     -------    \n";
	cout << "   -----------    \n";
	cout << "   ----- -----   \n";
	cout << "     --   --     \n";
	
	return 0;
}
