#pragma once
#include "Postac.h"
#include "Ekwipunek.h"
#include "Kolorowanie.h" // kolorowanie skladni
#include "Menu.h"
#include "Dodatki.h"

class Gracz : public Postac, public Menu, public IPlik
{
	Ekwipunek ekwipunek;

public:
	// domyslny konstruktor wywolujemy rowniez na liscie inicjalizacyjej konstruktor klasy bazowej
	Gracz();
	// konstruktor z lista inicjalizacyjna sluzacy do tworzenia postaci gracza
	Gracz(string nazwa, Statystyki statystyki, Ekwipunek ekwipunek);

	void otrzymuje_przedmiot(Przedmiot  przedmiot);
	// ustawiamy domyslne wartosci, jezeli nie podamy argumentow to zostana przeslane domyslne
	void zwieksz_poziom(int sila = 1, int zrecznosc = 1, int zycie = 10);
	virtual int atak();
	virtual void informacje();
	void menu();

	virtual void zapisz_dane(string nazwa_pliku);
	virtual void wczytaj_dane(string nazwa_pliku);
};

