#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream> // do operacji na plikach
#include "Gracz.h"
#include "Lokalizacja.h"
#include "Szkielet.h"
#include "Wilk.h"
#include "Wladca.h"
#include "Zbrojny.h"
#include "Bandyta.h" 
#include "Przedmiot.h"
#include "Stan.h" // pozwala na przeslanie wiadomosci zwrotnej, wyboru gracza z lokalizacji
#include "Dodatki.h"
#include "Statystyki.h"
#include "IPlik.h"
using namespace std;

class Gra : IPlik
{
	Gracz gracz;
	// spis wszystkich lokalizacji w grze
	vector <Lokalizacja> lokalizacje;

public:
	void stworz_gracza();
	void stworz_lokalizacje();
	void wybierz_droge();
	void wybierz_dzialanie_wyniku(STAN wynik, int wybor);
	void sprawdz_warunki_ukonczenia_gry();
	void menu_glowne();
	void rozpocznij_gre();
	void wyjscie();

	virtual void zapisz_dane(string nazwa_pliku);
	virtual void wczytaj_dane(string nazwa_pliku);
};
