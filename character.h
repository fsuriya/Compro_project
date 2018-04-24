#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;


int character_player(int t){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,0);
	cout << setw(t) << "   ";
	SetConsoleTextAttribute(hConsole,68);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << "             \n";
	cout << " " << setw(t) << "    ";
	SetConsoleTextAttribute(hConsole,68);
	cout << "----------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	cout << setw(t) << "   ";
	SetConsoleTextAttribute(hConsole,68);
	cout << "------------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	cout << setw(t) << "   ";
	//hair
	SetConsoleTextAttribute(hConsole,68);
	cout << "---";
	//body
	SetConsoleTextAttribute(hConsole,255);
	cout << "----";
	//hair
	SetConsoleTextAttribute(hConsole,68);
	cout << "---";
	//body
	SetConsoleTextAttribute(hConsole,255);
	cout << "-";
	//hair
	SetConsoleTextAttribute(hConsole,68);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	cout << setw(t) << "   ";
	//hair
	SetConsoleTextAttribute(hConsole,68);
	cout << "-";
	//body
	SetConsoleTextAttribute(hConsole,255);
	cout << "-";
	//hair
	SetConsoleTextAttribute(hConsole,68);
	cout << "-";
	//body
	SetConsoleTextAttribute(hConsole,255);
	cout << "-";
	//eye
	SetConsoleTextAttribute(hConsole,119);
	cout << "--";
	//body
	SetConsoleTextAttribute(hConsole,255);
	cout << "---";
	//eye
	SetConsoleTextAttribute(hConsole,119);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	cout << " " << setw(t) << "    ";
	//hair
	SetConsoleTextAttribute(hConsole,68);
	cout << "-";
	//body
	SetConsoleTextAttribute(hConsole,255);
	cout << "-----";
	SetConsoleTextAttribute(hConsole,240);
	cout << "--";
	SetConsoleTextAttribute(hConsole,255);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	cout << "  " << setw(t) << "     ";
	//shirt blue
	SetConsoleTextAttribute(hConsole,153);
	cout << "-";
	//shirt red
	SetConsoleTextAttribute(hConsole,204);
	cout << "------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "    \n";
	cout << " " << setw(t) << "    ";
	//shirt blue
	SetConsoleTextAttribute(hConsole,153);
	cout << "-";
	//shirt red
	SetConsoleTextAttribute(hConsole,204);
	cout << "-------";
	//shirt blue
	SetConsoleTextAttribute(hConsole,153);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	cout << setw(t) << "   ";
	//arm
	SetConsoleTextAttribute(hConsole,255);
	cout << "--";
	SetConsoleTextAttribute(hConsole,136);
	cout << "---";
	SetConsoleTextAttribute(hConsole,0);
	cout << " ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "---";
	//arm
	SetConsoleTextAttribute(hConsole,255);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	cout << "  " << setw(t) << "     ";
	SetConsoleTextAttribute(hConsole,102);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   ";
	SetConsoleTextAttribute(hConsole,102);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	
	return 0;
}
