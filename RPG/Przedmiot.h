#pragma once
#include <iostream>
#include <string>
#include "Statystyki.h"
#include "Kolorowanie.h"

using namespace std;

class Przedmiot
{
private:
	string nazwa;
	bool wyposazony; // czy gracz aktualnie wykorzystuje przedmiot
	Statystyki statystyki;

public:
	Przedmiot() :wyposazony(false) {}
	Przedmiot(string nazwa, Statystyki statystyki) : nazwa(nazwa), statystyki(statystyki), wyposazony(false) {}
	bool sprawdz_czy_wyposazony() { return wyposazony; }
	void ustaw_wyposazony(bool stan) { wyposazony = stan; }
	Statystyki pobierz_statystyki() { return statystyki; }


	void informacja(bool wyposazony_informacja = true)
	{
		cout << nazwa << "  ";

		if (wyposazony_informacja)
		{
			if (wyposazony)	koloruj_txt(" (Wyposazony)", ZIELONY);
			else	koloruj_txt(" (Nie wyposazony)", CZERWONY);
		}
		statystyki.informacja();
	}
};


