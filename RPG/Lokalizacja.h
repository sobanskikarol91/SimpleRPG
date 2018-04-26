#include <iostream>
#include "Przeciwnik.h"
#include "Przedmiot.h"

#pragma once
class Lokalizacja
{
	Przeciwnik przeciwnik;
	Przedmiot przedmiot;
	string nazwa;
	string opis;
public:
	Lokalizacja() {};
	Lokalizacja(string nazwa, string opis, Przeciwnik przeciwnik, Przedmiot przedmiot)
		: nazwa(nazwa), opis(opis), przeciwnik(przeciwnik), przedmiot(przedmiot) {}

	// wypisujemy nazwe i opis danej lokalizacji
	void informacja()
	{
		cout << nazwa << endl;
		cout << "==========================" << endl;
		cout << opis << endl;
	}

	Przedmiot przeszukaj()
	{
		cout << "Przeszukujac lokalizacje natrafiasz na przedmiot jest to: " << endl;
		przedmiot.informacja();
	}

	void walcz()
	{

	}
};

