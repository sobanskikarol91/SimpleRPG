#pragma once
#include "Przeciwnik.h"

class Wilk : public Przeciwnik
{
public:
	Wilk() : Przeciwnik() {};
	Wilk(string nazwa, int zycie, int sila, int zrecznosc, int obrazenia, int poziom)
		: Przeciwnik(nazwa, zycie, sila, zrecznosc, obrazenia, poziom) {};
};
