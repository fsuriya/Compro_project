#include "iostream"
#include "iomanip"
#include "Windows.h"
#include "string"
using namespace std;

int main(){
	int U=1;
	if(U==0){
		cout << "\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout << setw(100)<< "@@@  @@@   @@@@@@   @@    @@  @@         @@@@@@    @@@@@@@   @@@@@@@" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		cout << setw(100)<< "@@@  @@@  @@@@@@@@  @@    @@  @@        @@@@@@@@  @@@@@@@@  @@@@@@@@" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout << setw(100)<< "@@@  @@@  @@    @@  @@    @@  @@        @@    @@  @@@       @@      " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		cout << setw(100)<< " @@@@@@   @@    @@  @@    @@  @@        @@    @@   @@@@@    @@@@@@@ " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout << setw(100)<< "   @@     @@    @@  @@    @@  @@        @@    @@    @@@@@   @@@@@@@ " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		cout << setw(100)<< "   @@     @@    @@  @@    @@  @@        @@    @@       @@@  @@      " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout << setw(100)<< "   @@     @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		cout << setw(100)<< "   @@      @@@@@@   @@@@@@@@  @@@@@@@@   @@@@@@   @@@@@@@    @@@@@@@" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout << setw(101) <<"=====================================================================";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);		
	}else if(U==1){
		cout << "\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		cout << setw(100)<< "@@ @@ @@  @@@@@@@@  @@@  @@@  @@@  @@@   @@@@@@@  @@@@@@@ " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
		cout << setw(100)<< "@@ @@ @@  @@@@@@@@  @@@  @@@  @@@  @@@  @@@@@@@@  @@@@@@@@" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		cout << setw(100)<< "@@ @@ @@     @@     @@@@ @@@  @@@@ @@@  @@        @@   @@@" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		cout << setw(100)<< "@@ @@ @@     @@     @@@@@@@@  @@@@@@@@  @@@@@@@   @@   @@ " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout << setw(100)<< "@@ @@ @@     @@     @@@@@@@@  @@@@@@@@  @@@@@@@   @@@@@@  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout << setw(100)<< "@@ @@ @@     @@     @@@ @@@@  @@@ @@@@  @@        @@@@@@  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		cout << setw(100)<< "@@@@@@@@  @@@@@@@@  @@@  @@@  @@@  @@@  @@@@@@@@  @@   @@ " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout << setw(100)<< " @@@@@@   @@@@@@@@  @@@  @@@  @@@  @@@   @@@@@@@  @@   @@@" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		cout << setw(105) <<"=====================================================================";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);		
	}


	
	
}
