#include "Przedmiot.h"

#pragma once
class Bron : public Przedmiot
{
	int obrazenia;
public:
	Bron() : Przedmiot() {};
	Bron(string nazwa, int obrazenia) : Przedmiot(nazwa), obrazenia(obrazenia) {};
};

