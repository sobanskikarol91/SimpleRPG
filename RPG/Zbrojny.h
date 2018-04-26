#pragma once
#include "Przeciwnik.h"

class Zbrojny : public Przeciwnik
{
public:
	Zbrojny() : Przeciwnik() {};
	Zbrojny(string nazwa, int zycie, int sila, int zrecznosc, int obrazenia, int poziom)
		: Przeciwnik(nazwa, zycie, sila, zrecznosc, obrazenia, poziom) {};
};

