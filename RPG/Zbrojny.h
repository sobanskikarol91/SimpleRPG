#pragma once
#include "Przeciwnik.h"

class Zbrojny : public Przeciwnik
{
public:
	Zbrojny() : Przeciwnik() {};
	Zbrojny(string nazwa, int zycie, int sila, int zrecznosc, int poziom)
		: Przeciwnik(nazwa, zycie, sila, zrecznosc, poziom) {};
};

