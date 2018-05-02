#include <iostream>
#include "Gra.h"
#include <ctime> // do pseudolosowych liczb
using namespace std;

// do testu wywalic 
#include "Ekwipunek.h" 
#include "Przedmiot.h"
#include "Statystyki.h"
int main()
{
	Ekwipunek s;
	s.dodaj_przedmiot(Przedmiot("Miecz", Statystyki(1,2,3,4,5)));
	s.dodaj_przedmiot(Przedmiot("Topor", Statystyki(10, 20, 30, 40, 50)));
	s.zapisz_dane("zapisy/a");
	s.wczytaj_dane("zapisy/a");
	//Gra gra;
	//srand(time(NULL));	// pozwala na losowanie psueudolosowych liczb, przyda sie przy  rzucie kostka
	//gra.rozpocznij_gre();

	system("pause");

	return 0;
}