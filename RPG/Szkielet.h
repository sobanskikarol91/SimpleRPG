#include "Przeciwnik.h"
#pragma once

class Szkielet : public Przeciwnik
{
public:
	Szkielet() : Przeciwnik() {};
	Szkielet(string nazwa, Statystyki statystyki)
		: Przeciwnik(nazwa, statystyki) {};
};