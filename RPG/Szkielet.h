#include "Przeciwnik.h"
#pragma once

class Szkielet : public Przeciwnik
{
public:
	Szkielet(string nazwa, int zycie, int sila, int zrecznosc, int obrazenia, int poziom)
		: Przeciwnik(nazwa, zycie, sila, zrecznosc, obrazenia, poziom) {};
};