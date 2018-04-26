#pragma once
#include <iostream>
#include "Przedmiot.h"
#include <vector>
using namespace std;


class Ekwipunek
{
	// spis wszystkich przedmiotow w ekwipunku
	vector<Przedmiot> przedmioty;

public:
	void przegladaj()
	{
		// gdy nie mamy przedmiotow w ekwipunku
		if (przedmioty.size() == 0) 
			cout << "Ekwipunek jest pusty!" << endl;
		else
		{
			// wypisujemy informacje o kazdym przedmiocie w ekwpiunku gdy jakies sa
			for (int i = 0; i < przedmioty.size(); i++)
			{
				przedmioty[i].informacja();
				cout << "============" << endl;
			}
		}
	}

	void dodajPrzedmiot(Przedmiot nowyPrzedmiot)
	{
		przedmioty.push_back(nowyPrzedmiot);
	}

	void usunPrzedmiot(Przedmiot nowyPrzedmiot)
	{
		przedmioty.pop_back();
	}
};

