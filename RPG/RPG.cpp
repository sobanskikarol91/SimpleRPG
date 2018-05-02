#pragma once
#include <iostream>
#include "Gra.h"
#include <ctime> // do pseudolosowych liczb
using namespace std;

// do testu wywalic 
#include "Ekwipunek.h" 
#include "Przedmiot.h"
#include "Statystyki.h"
#include "Gracz.h"
#include "Lokalizacja.h"
#include "Przeciwnik.h"

int main()
{
	/*
	Ekwipunek s;
	s.dodaj_przedmiot(Przedmiot("Miecz", Statystyki(1, 2, 3, 4, 5)));
	s.dodaj_przedmiot(Przedmiot("Topor", Statystyki(10, 20, 30, 40, 50)));
	Gracz g = Gracz("a", Statystyki(2, 2, 2, 2, 2), s);

	Lokalizacja l = Lokalizacja("Krypta",
		"Na samym srodku sciezki, dostrzegasz schody prowadzace w dol. Wyczuwasz potezna, mroczna, aure bijaca z czelusci tej sciezki. Krzewy i drzewa zdaja sie byc obumarle, a w zasiegu wzroku gesto scieli sie truchlo martwych zwierzat i rozsypane kosci",
		Szkielet("Szkielet", Statystyki(10, 2, 2, 2, 1)),
		Przedmiot("Helm", Statystyki(0, 0, 0, 1, 0)));

	l.zapisz_dane("zapisy/lok");
	l.wczytaj_dane("zapisy/lok");
	*/

	//g.zapisz_dane("zapisy/gracz");
	//g.wczytaj_dane("zapisy/gracz");

	Gra gra;
	gra.rozpocznij_gre();
	//srand(time(NULL));	// pozwala na losowanie psueudolosowych liczb, przyda sie przy  rzucie kostka
	//gra.rozpocznij_gre();

	system("pause");

	return 0;
}