#pragma once
#include "Przeciwnik.h"
class Bandyta : public Przeciwnik
{
public:
	Bandyta() : Przeciwnik() {};
	Bandyta(string nazwa, Statystyki statystyki)
		: Przeciwnik(nazwa, statystyki) {};
};

