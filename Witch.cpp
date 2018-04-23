#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

int t=50;
int main(){
	
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
	
	return 0;	
}
