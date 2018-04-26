#include<iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

void Godzilla(int t){
	
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

void knight(int t){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout<<setw(t);
	cout << "         ";
	SetConsoleTextAttribute(hConsole,85);
	cout << "-----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	
	cout<<setw(t);
	cout << "      ";
	SetConsoleTextAttribute(hConsole,119);
	cout << "-----";
	SetConsoleTextAttribute(hConsole,85);
	cout << "----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	
	cout<<setw(t);
	cout << "     ";
	SetConsoleTextAttribute(hConsole,119);
	cout << "-------";
	SetConsoleTextAttribute(hConsole,85);
	cout <<"---";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	
	cout<<setw(t);
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
	
	cout<<setw(t);
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
	
	cout<<setw(t);
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
	
	cout<<setw(t);
	cout << "   ";
	SetConsoleTextAttribute(hConsole,119);
	cout << "------";
	SetConsoleTextAttribute(hConsole,136);
	cout << "----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "    \n";
	
	cout<<setw(t);
	cout << "     ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "-------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	
	cout<<setw(t);
	cout << "    ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "--";
	SetConsoleTextAttribute(hConsole,119);
	cout << "----";
	SetConsoleTextAttribute(hConsole,136);
	cout << "---";
	SetConsoleTextAttribute(hConsole,0);
	cout << "    \n";
	
	cout<<setw(t);
	cout << "      ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	
	cout<<setw(t);
	cout << "      ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  ";
	SetConsoleTextAttribute(hConsole,136);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
}

int Witch(int t){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,0);
	cout << "       " << setw(t) << "        ";
	SetConsoleTextAttribute(hConsole,17);
	cout << "----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "    \n";
	cout << "     " << setw(t) << "      ";
	SetConsoleTextAttribute(hConsole,17);
	cout << "-------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	cout << "   " << setw(t) << "    ";
	SetConsoleTextAttribute(hConsole,17);
	cout << "---------";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	cout << "" << setw(t) << " ";
	SetConsoleTextAttribute(hConsole,17);
	cout << "----------";
	SetConsoleTextAttribute(hConsole,0);
	cout << " ";
	SetConsoleTextAttribute(hConsole,17);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	cout << " " << setw(t) << "  ";
	//line
	SetConsoleTextAttribute(hConsole,17);
	cout << "-";
	SetConsoleTextAttribute(hConsole,85);
	cout << "-";
	SetConsoleTextAttribute(hConsole,255);
	cout << "--";
	SetConsoleTextAttribute(hConsole,85);
	cout << "--";
	//line
	SetConsoleTextAttribute(hConsole,17);
	cout << "---";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	cout << "  " << setw(t) << "   ";
	//line
	SetConsoleTextAttribute(hConsole,17);
	cout << "-";
	//eye
	SetConsoleTextAttribute(hConsole,238);
	cout << "-";
	SetConsoleTextAttribute(hConsole,255);
	cout << "--";
	//eye
	SetConsoleTextAttribute(hConsole,238);
	cout << "-";
	SetConsoleTextAttribute(hConsole,85);
	cout << "--";
	//line
	SetConsoleTextAttribute(hConsole,17);
	cout << "---";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   \n";
	cout << "  " << setw(t) << "   ";
	//line
	SetConsoleTextAttribute(hConsole,17);
	cout << "-";
	//body
	SetConsoleTextAttribute(hConsole,255);
	cout << "-";
	SetConsoleTextAttribute(hConsole,252);
	cout << "  ";
	SetConsoleTextAttribute(hConsole,255);
	cout << "--";
	//hair
	SetConsoleTextAttribute(hConsole,85);
	cout << "-";
	//line
	SetConsoleTextAttribute(hConsole,17);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	cout << "   " << setw(t) << "    ";
	//dress
	SetConsoleTextAttribute(hConsole,17);
	cout << "-----";
	//hair
	SetConsoleTextAttribute(hConsole,85);
	cout << "-";
	//line
	SetConsoleTextAttribute(hConsole,17);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     \n";
	cout << "  " << setw(t) << "   ";
	//dress
	SetConsoleTextAttribute(hConsole,255);
	cout << "--";
	SetConsoleTextAttribute(hConsole,17);
	cout << "-----";
	SetConsoleTextAttribute(hConsole,0);
	cout << "   ";
	//broom
	SetConsoleTextAttribute(hConsole,102);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "  \n";
	cout << " " << setw(t) << "  ";
	//broom
	SetConsoleTextAttribute(hConsole,136);
	cout << "---";
	//dress
	SetConsoleTextAttribute(hConsole,17);
	cout << "------";
	//broom
	SetConsoleTextAttribute(hConsole,136);
	cout << "--";
	SetConsoleTextAttribute(hConsole,102);
	cout << "---";
	SetConsoleTextAttribute(hConsole,0);
	cout << " \n";
	cout << "     " << setw(t) << "      ";
	//dress
	SetConsoleTextAttribute(hConsole,17);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << " ";
	//dress
	SetConsoleTextAttribute(hConsole,17);
	cout << "--";
	SetConsoleTextAttribute(hConsole,0);
	cout << "     ";
	SetConsoleTextAttribute(hConsole,102);
	cout << "-";
	SetConsoleTextAttribute(hConsole,0);
	cout << " \n";	
}

void character_player(int t){
	
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
}
