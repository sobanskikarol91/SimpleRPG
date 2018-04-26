#pragma once
#include "Przeciwnik.h"
class Wladca :public Przeciwnik
{
public:
	Wladca() : Przeciwnik() {};
	Wladca(string nazwa, int zycie, int sila, int zrecznosc, int obrazenia, int poziom)
		: Przeciwnik(nazwa, zycie, sila, zrecznosc, obrazenia, poziom) {};
};

