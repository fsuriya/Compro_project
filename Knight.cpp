#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

int main(){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "         ";
	SetConsoleTextAttribute(hConsole,85);
	cout << "-----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	cout << "      ";
	SetConsoleTextAttribute(hConsole,119);
	cout << "-----";
	SetConsoleTextAttribute(hConsole,85);
	cout << "----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	cout << "     ";
	SetConsoleTextAttribute(hConsole,119);
	cout << "-------";
	SetConsoleTextAttribute(hConsole,85);
	cout <<"---";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	cout << "    ";
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
	cout << "   ";
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
	cout << "   ";
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
	cout << "   ";
	SetConsoleTextAttribute(hConsole,119);
	cout << "------";
	SetConsoleTextAttribute(hConsole,136);
	cout << "----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "    \n";
	cout << "     ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "-------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	cout << "    ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "--";
	SetConsoleTextAttribute(hConsole,119);
	cout << "----";
	SetConsoleTextAttribute(hConsole,136);
	cout << "---";
	SetConsoleTextAttribute(hConsole,0);
	cout << "    \n";
	cout << "      ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	cout << "      ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	
	return 0;
}