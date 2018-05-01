#pragma once
#include "Przeciwnik.h"

class Wilk : public Przeciwnik
{
public:
	Wilk() : Przeciwnik() {};
	Wilk(string nazwa, Statystyki statystyki)
		: Przeciwnik(nazwa, statystyki) {};
};

