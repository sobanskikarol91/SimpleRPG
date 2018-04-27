#include <iostream>
#include "Gra.h"
#include <ctime> // do pseudolosowych liczb
#include "windows.h"    // kolorowanie skladni
using namespace std;


void menu_glowne()
{
	cout << "1) Nowa gra" << endl;
	cout << "2) Wczytaj grê" << endl;
	cout << "3) Exit" << endl;

	int wybor;
	cin >> wybor;

}

int main()
{
	Gra  gra;
	//gra_rpg.stworz_postac();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // koloruj  text
	gra.wybierz_droge();
	srand(time(NULL));	// pozwala na losowanie psueudolosowych liczb, przyda sie przy  rzucie kostka
	system("pause");
	return 0;
}