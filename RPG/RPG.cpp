#include <iostream>
#include "Gra.h"
#include <ctime> // do pseudolosowych liczb
using namespace std;


void menu_glowne()
{
	cout << "1) Nowa gra" << endl;
	cout << "2) Wczytaj grê" << endl;
	cout << "3) Exit" << endl;

	int wybor;
	cin >> wybor;

}

void rozpocznij_gre()
{
	// TODO Sleep
}

void sprawdzenie_ekwipunku()
{
}

void wybor_drogi_txt()
{
	int wybor =0;

	cout << "Dotarles do rozwidlenia 5 sciezek, gdzie tym razem poprowadzi Cie przeznaczenie? " << endl;


}

int main()
{
	wybor_drogi_txt();
	Gra  gra_rpg;
	gra_rpg.stworz_postac();

	srand(time(NULL));	// pozwala na losowanie psueudolosowych liczb, przyda sie przy  rzucie kostka
	system("pause");
	return 0;
}