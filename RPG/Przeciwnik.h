#include "Postac.h"
#pragma once

class Przeciwnik : public Postac
{
public:
	Przeciwnik() : Postac() {};
	// konstruktur z lista inicjalizacyjna, w ktorej wywolujemy konstruktor klasy bazowej
	Przeciwnik(string nazwa, int zycie, int sila, int zrecznosc, int obrazenia, int poziom)
		: Postac(nazwa, zycie, sila, zrecznosc, obrazenia, poziom) {};


	virtual int atak()
	{
		return sila + modyfikator_obrazen();
	}
};