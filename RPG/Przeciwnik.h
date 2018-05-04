#include "Postac.h"
#pragma once
#include "IPlik.h"
#include "Okno.h"

class Przeciwnik : public Postac, IPlik
{
	Okno okno; // okno w ktorym bedize sie wyswietlac podobizna wroga

public:
	Przeciwnik();
	// konstruktur z lista inicjalizacyjna, w ktorej wywolujemy konstruktor klasy bazowej
	Przeciwnik(string nazwa, Statystyki statystyki);

	Okno pobierz_okno() { return okno; }

	virtual int atak();
	virtual void zapisz_dane(string nazwa_pliku);
	virtual void wczytaj_dane(string nazwa_pliku);
};