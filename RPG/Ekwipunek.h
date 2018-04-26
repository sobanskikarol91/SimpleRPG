#pragma once
#include <iostream>
#include "Przedmiot.h"
#include <vector>    // dynamiczny pojemnik gdzie przechowujemy przedmioty

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
		cout << "Dodano: " << nowyPrzedmiot.informacja();
	}

	void usunPrzedmiot(int pozycja)
	{
		// usuwamy z ekwipunku przedmiot na danej pozycji, wykorzystujemy do tego metode erase z klasy Vector
		cout << "Usunieto:" << przedmioty[pozycja].informacja();
		przedmioty.erase(przedmioty.begin() + pozycja);
	}
};

