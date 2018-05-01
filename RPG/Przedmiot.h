#pragma once
#include <iostream>
#include <string>
#include "Statystyki.h"
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
	string informacja() { return nazwa; }
	bool sprawdz_czy_wyposazony() { return wyposazony; }
	void ustaw_wyposazony(bool stan) { wyposazony = stan; }
};


