#pragma once
#include <iostream>
#include <vector>    // dynamiczny pojemnik gdzie przechowujemy przedmioty
#include "Przedmiot.h"
#include "Menu.h"
#include "Kolorowanie.h"
#include "Statystyki.h"

using namespace std;

class Ekwipunek : public Menu
{
	// spis wszystkich przedmiotow w ekwipunku
	vector<Przedmiot> przedmioty;

public:
	void przegladaj()
	{
		cout << "*******************************************" << endl;
		cout << "EKWIPUNEK" << endl;
		cout << "*******************************************" << endl;
		// gdy nie mamy przedmiotow w ekwipunku
		if (przedmioty.size() == 0)
			cout << "Ekwipunek jest pusty!" << endl;
		else
		{
			// wypisujemy informacje o kazdym przedmiocie w ekwpiunku gdy jakies sa
			for (unsigned int i = 0; i < przedmioty.size(); i++)
			{
				cout << i << ") ";
				cout << przedmioty[i].informacja();
				if (przedmioty[i].sprawdz_czy_wyposazony())
					koloruj_txt(" (Wyposazony)", ZIELONY);
				else
					koloruj_txt(" (Nie wyposazony)", CZERWONY);
			}
		}
	}

	// przesylamy wskaznik na przedmiot
	void dodaj_przedmiot(Przedmiot nowyPrzedmiot)
	{
		przedmioty.push_back(nowyPrzedmiot);
	}

	// metoda oblciza wszystkie bonusy wynikajace z przedmiotow, zwraca sume wszystkich statystyk
	Statystyki oblicz_bonusy_przedmiotow()
	{
		Statystyki bonus;

		for (unsigned int i = 0; i < przedmioty.size(); i++)
			bonus += przedmioty[i].pobierz_statystyki();

		return bonus;
	}

	void menu()
	{
		przegladaj();

		cout << przedmioty.size() << ") Exit" << endl;
		cout << "Wybierz numer przedmiotu: ";

		// + 1 dlatego ze jeszcze opcja exit
		int wybor_przedmiotu = wybierz_opcje(przedmioty.size());
		// jezeli wybral ostatnia opcje to znaczy ze jest to exit
		if (wybor_przedmiotu == przedmioty.size())
			return;
		else
		{
			cout << "Co chcesz zrobic?" << endl;
			cout << "1) Zaloz przedmiot" << endl;
			cout << "2) Zdejmij przedmiot" << endl;
			cout << "3) Exit" << endl;

			switch (wybierz_opcje(3))
			{
			case 1:
			{
				przedmioty[wybor_przedmiotu].ustaw_wyposazony(true);
				cout << "Przedmiot zalozony!" << endl;
				break;
			}

			case 2:
			{
				przedmioty[wybor_przedmiotu].ustaw_wyposazony(false);
				cout << "Przedmiot zdjety!" << endl;
				break;
			}
			case 3:
				return;
			}
		}
		nacisnij_klawisz();
		menu();
	}
};

