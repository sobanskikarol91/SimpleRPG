#pragma once
#include <iostream>
#include <string>
#include "Statystyki.h"
#include "Kolorowanie.h"
#include "IPlik.h"
#include "Okno.h"
using namespace std;

class Przedmiot
{
private:
	string nazwa;
	bool wyposazony; // czy gracz aktualnie wykorzystuje przedmiot
	Statystyki statystyki;
	Okno okno;

public:
	Przedmiot();
	Przedmiot(string nazwa, Statystyki statystyki);

	bool sprawdz_czy_wyposazony() { return wyposazony; }
	void ustaw_wyposazony(bool stan) { wyposazony = stan; }
	Statystyki pobierz_statystyki() { return statystyki; }
	Okno pobierz_okno() { return okno; }
	void informacja(bool wyposazony_informacja = true);
	string pobierz_nazwa() { return nazwa; }

	virtual void zapisz_dane(string nazwa_pliku);
	virtual void wczytaj_dane(string nazwa_pliku);
};


