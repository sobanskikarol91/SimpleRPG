#pragma once
#include <iostream>
#include "Przedmiot.h"
#include "Bron.h"
#include <vector>    // dynamiczny pojemnik gdzie przechowujemy przedmioty
#include "Menu.h"
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
			for (int i = 0; i < przedmioty.size(); i++)
			{
				cout << i << ") ";
				cout << przedmioty[i].informacja();
				if (przedmioty[i].sprawdz_czy_wyposazony())
					cout << " Wyposazony" << endl;
				else
					cout << " Nie wyposazony" << endl;
			}
		}
	}

	// przesylamy wskaznik na przedmiot
	void dodaj_przedmiot(Przedmiot  nowyPrzedmiot)
	{
		przedmioty.push_back(nowyPrzedmiot);
		cout << "Dodano: " << (nowyPrzedmiot).informacja() << endl;
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

	void menu()
	{
		przegladaj();

		cout << przedmioty.size() << ") Exit" << endl;
		cout << "Wybierz numer przedmiotu: ";

		// + 1 dlatego ze jeszcze opcja exit
		int wybor_przedmiotu = wybierz_opcje(przedmioty.size());
		// jezeli wybral ostatnia opcje to znaczy ze jest to exit
		cout << wybor_przedmiotu << " " << przedmioty.size();
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

		int wybor_menu = wybierz_opcje(3, 0);
	}
};

