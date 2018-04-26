#pragma once
#include "Przedmiot.h"

class Amulet : public Przedmiot
{
	int bonus;
public:
	Amulet() : Przedmiot() {};
	// gdy nie podamy parametru bonus ba on domyslna wartosc zero
	Amulet(string nazwa, int bonus = 0) : Przedmiot(nazwa), bonus(bonus) {};
};

