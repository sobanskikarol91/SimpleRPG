#include "Przedmiot.h"
#pragma once
class Pancerz : public Przedmiot
{
	int obrona;

public:
	Pancerz() :Przedmiot(){};
	Pancerz(string nazwa, int obrona) : Przedmiot(nazwa), obrona(obrona) {};
};

