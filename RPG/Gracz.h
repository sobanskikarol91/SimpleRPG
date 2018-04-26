#pragma once
#include "Postac.h"
#include "Ekwipunek.h"

class Gracz : public Postac
{
	Ekwipunek ekwipunek;
public:
	// domyslny konstruktor wywolujemy rowniez na liscie inicjalizacyjej konstruktor klasy bazowej
	Gracz() : Postac() {};	
	// konstruktor z lista inicjalizacyjna sluzacy do tworzenia postaci gracza
	Gracz(string nazwa, int zycie, int sila, int zrecznosc, int obrazenia, int poziom)
		: Postac(nazwa, zycie, sila, zrecznosc, obrazenia, poziom) {};
};

