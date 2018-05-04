#pragma once
#include <iostream>
#include "Przeciwnik.h"
#include "Przedmiot.h"
#include "Stan.h"
#include "Gracz.h"
#include "Dodatki.h"    // przydadza sie funkcje wyboru
#include "Kolorowanie.h" // kolorowanie skladni
#include "IPlik.h"

class Lokalizacja : IPlik
{
	Przeciwnik przeciwnik;
	Przedmiot przedmiot;
	string nazwa, opis;

public:
	Lokalizacja();
	Lokalizacja(string nazwa, string opis, Przeciwnik przeciwnik, Przedmiot przedmiot);

	void informacja();
	STAN wejdz_do_lokalizacji(Gracz * gracz);
	Przedmiot przeszukanie();
	bool proba_ucieczki(Gracz * gracz);
	STAN walka(Gracz * gracz);
	string pobierz_nazwa() { return nazwa; }
	STAN menu_wyboru_walki(Gracz * gracz);
	virtual void zapisz_dane(string nazwa_pliku);
	virtual void wczytaj_dane(string nazwa_pliku);
};

