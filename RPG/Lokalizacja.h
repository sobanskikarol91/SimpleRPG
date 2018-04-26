#include <iostream>
#include "Przeciwnik.h"

#pragma once
class Lokalizacja
{
	Przeciwnik przeciwnik;
	string nazwa;
	string opis;
public:
	Lokalizacja() {};
	Lokalizacja(string nazwa, string opis, Przeciwnik przeciwnik) 
		: nazwa(nazwa), opis(opis), przeciwnik(przeciwnik) {}
};

