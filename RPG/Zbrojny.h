#pragma once
#include "Przeciwnik.h"

class Zbrojny : public Przeciwnik
{
public:
	Zbrojny() : Przeciwnik() {};
	Zbrojny(string nazwa, Statystyki statystyki)
		: Przeciwnik(nazwa, statystyki) {};
};

