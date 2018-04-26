#pragma once
#include "Przeciwnik.h"
class Bandyta : public Przeciwnik
{
public:
	Bandyta() : Przeciwnik() {};
	Bandyta(string nazwa, int zycie, int sila, int zrecznosc, int obrazenia, int poziom)
		: Przeciwnik(nazwa, zycie, sila, zrecznosc, obrazenia, poziom) {};
};

