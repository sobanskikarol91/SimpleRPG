#pragma once
#include "Przeciwnik.h"

class Szkielet : public Przeciwnik
{
public:
	Szkielet() : Przeciwnik() {};
	Szkielet(string nazwa, Statystyki statystyki)
		: Przeciwnik(nazwa, statystyki) {};
};