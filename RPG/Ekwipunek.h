#pragma once
#include <iostream>
#include "Przedmiot.h"
#include "Bron.h"
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

	// przesylamy wskaznik na przedmiot
	void dodaj_przedmiot(Przedmiot * nowyPrzedmiot)
	{
		przedmioty.push_back(*nowyPrzedmiot);
		cout << "Dodano: " << (*nowyPrzedmiot).informacja() << endl;
	}

	void usun_przedmiot(int pozycja)
	{
		// usuwamy z ekwipunku przedmiot na danej pozycji, wykorzystujemy do tego metode erase z klasy Vector
		cout << "Usunieto:" << przedmioty[pozycja].informacja();
		przedmioty.erase(przedmioty.begin() + pozycja);
	}

	int oblicz_bonusy_obrazen()
	{
		//int bonus_obrazen = 0;

		//for (int i = 0; i < przedmioty.size(); i++)
		//{
		//	if (dynamic_cast<Bron*>(&przedmioty[i]))
		//		bonus_obrazen+= przedmioty
		//}
	}

	void menu_ekwipunku()
	{
		cout << "Co chcesz zrobic?" << endl;
		cout << "1) Zaloz przedmiot" << endl;
		cout << "2) Usun przedmiot" << endl;
		cout << "3) Exit" << endl;
	}
};

