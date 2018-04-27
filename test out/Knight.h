#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;


void knight(int t){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "      " << setw(t) << "         ";
	SetConsoleTextAttribute(hConsole,85);
	cout << "-----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	cout << "   " << setw(t) << "      ";
	SetConsoleTextAttribute(hConsole,119);
	cout << "-----";
	SetConsoleTextAttribute(hConsole,85);
	cout << "----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	cout << " " << setw(t) << "    ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "----";
	SetConsoleTextAttribute(hConsole,119);
	cout << "----";
	SetConsoleTextAttribute(hConsole,136);
	cout << "-";
	SetConsoleTextAttribute(hConsole,85);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	cout << setw(t) << "   ";
	SetConsoleTextAttribute(hConsole,119);
	cout << "-----";
	SetConsoleTextAttribute(hConsole,136);
	cout << "-";
	SetConsoleTextAttribute(hConsole,119);
	cout << "--";
	SetConsoleTextAttribute(hConsole,136);
	cout << "--";
	SetConsoleTextAttribute(hConsole,85);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	cout << setw(t) << "   ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "-";
	SetConsoleTextAttribute(hConsole,119);
	cout << "-";
	SetConsoleTextAttribute(hConsole,136);
	cout << "-";
	SetConsoleTextAttribute(hConsole,119);
	cout << "-";
	SetConsoleTextAttribute(hConsole,136);
	cout << "-";
	SetConsoleTextAttribute(hConsole,119);
	cout << "-";
	SetConsoleTextAttribute(hConsole,136);
	cout << "----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "    \n";
	cout << setw(t) << "   ";
	SetConsoleTextAttribute(hConsole,119);
	cout << "------";
	SetConsoleTextAttribute(hConsole,136);
	cout << "----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "    \n";
	cout << "  " << setw(t) << "     ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "-------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	cout << " " << setw(t) << "    ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "--";
	SetConsoleTextAttribute(hConsole,119);
	cout << "----";
	SetConsoleTextAttribute(hConsole,136);
	cout << "---";
	SetConsoleTextAttribute(hConsole,0);
	cout << "    \n";
	cout << "   " << setw(t) << "      ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	cout << "   " << setw(t) << "      ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	
}
