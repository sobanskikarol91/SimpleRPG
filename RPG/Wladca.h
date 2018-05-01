#pragma once
#include "Przeciwnik.h"
class Wladca :public Przeciwnik
{
public:
	Wladca() : Przeciwnik() {};
	Wladca(string nazwa, Statystyki statystyki)
		: Przeciwnik(nazwa, statystyki) {};
};

