#include "Postac.h"
#pragma once

class Przeciwnik : public Postac
{
public:
	Przeciwnik() : Postac() {};
	// konstruktur z lista inicjalizacyjna, w ktorej wywolujemy konstruktor klasy bazowej
	Przeciwnik(string nazwa, Statystyki statystyki)
		: Postac(nazwa,  statystyki){};


	virtual int atak()
	{
		return statystyki.pobierz_sila() + modyfikator_obrazen();
	}
};