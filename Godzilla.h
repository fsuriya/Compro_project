#include<iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

int t=50;
void godzilla(){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,0);
	cout << "    " << setw(t) << "       ";
	SetConsoleTextAttribute(hConsole,34);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "      \n";
	cout << "   " << setw(t) << "      ";
	//line
	SetConsoleTextAttribute(hConsole,34);
	cout << "-";
	SetConsoleTextAttribute(hConsole,170);
	cout << "--";
	//ine
	SetConsoleTextAttribute(hConsole,34);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	cout << "  " << setw(t) << "     ";
	SetConsoleTextAttribute(hConsole,34);
	cout << "-------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	cout << " " << setw(t) << "    ";
	SetConsoleTextAttribute(hConsole,34);
	cout << "--------";
	SetConsoleTextAttribute(hConsole,170);
	cout << "-";
	SetConsoleTextAttribute(hConsole,34);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << " \n";
	cout << setw(t) << "   ";
	SetConsoleTextAttribute(hConsole,34);
	cout << "-";
	//eye
	SetConsoleTextAttribute(hConsole,0);
	cout << "-";
	SetConsoleTextAttribute(hConsole,34);
	cout << "---";
	//eye
	SetConsoleTextAttribute(hConsole,0);
	cout << "-";
	SetConsoleTextAttribute(hConsole,34);
	cout << "----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	cout << setw(t) << "   ";
	SetConsoleTextAttribute(hConsole,34);
	cout << "---";
	//mouth
	SetConsoleTextAttribute(hConsole,34);
	cout << ".";
	SetConsoleTextAttribute(hConsole,34);
	cout << "------";
	SetConsoleTextAttribute(hConsole,170);
	cout << "-";
	SetConsoleTextAttribute(hConsole,34);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << "\n";
	cout << " " << setw(t) << "    ";
	SetConsoleTextAttribute(hConsole,34);
	cout << "----------";
	SetConsoleTextAttribute(hConsole,0);
	cout << " \n";
	cout << "  " << setw(t) << "     ";
	//arm
	SetConsoleTextAttribute(hConsole,34);
	cout << "-";
	SetConsoleTextAttribute(hConsole,170);
	cout << "--";
	SetConsoleTextAttribute(hConsole,34);
	cout << "--";
	SetConsoleTextAttribute(hConsole,34);
	cout << "-";
	SetConsoleTextAttribute(hConsole,34);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "\n";
	cout << "  " << setw(t) << "     ";
	SetConsoleTextAttribute(hConsole,34);
	cout << "-";
	SetConsoleTextAttribute(hConsole,238);
	cout << "--";
	SetConsoleTextAttribute(hConsole,170);
	cout << "-";
	SetConsoleTextAttribute(hConsole,34);
	cout << "----";
	SetConsoleTextAttribute(hConsole,170);
	cout << "-";
	SetConsoleTextAttribute(hConsole,34);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << " \n";
	cout << "   " << setw(t) << "      ";
	SetConsoleTextAttribute(hConsole,34);
	cout << "--------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	cout << "   " << setw(t) << "      ";
	SetConsoleTextAttribute(hConsole,34);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  ";
	SetConsoleTextAttribute(hConsole,34);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	
}
