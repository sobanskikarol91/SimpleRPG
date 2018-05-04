#pragma once
#include <iostream>
#include <vector>    // dynamiczny pojemnik gdzie przechowujemy przedmioty
#include "Przedmiot.h"
#include "Menu.h"
#include "Statystyki.h"

using namespace std;

class Ekwipunek : public Menu, public IPlik
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
				cout << "=======================================================================================================================" << endl;
				cout << i << ")  " << endl;

				przedmioty[i].informacja();
				cout << "=======================================================================================================================" << endl;
			}
		}
	}

	// zwracamy tylko te przedmioty ktore sa aktywne
	vector<Przedmiot> spis_aktywnych_przedmiotow()
	{
		vector<Przedmiot> aktywne;

		for (unsigned int i = 0; i < przedmioty.size(); i++)
		{
			// jezeli nie wyposazony przedmiot to nie wykonuj dalszej czesci bloku
			if (przedmioty[i].sprawdz_czy_wyposazony() == false) continue;
			aktywne.push_back(przedmioty[i]); // dodaj aktywny przedmiot
		}

		return aktywne;
	}

	void dodaj_przedmiot(Przedmiot nowyPrzedmiot)
	{
		przedmioty.push_back(nowyPrzedmiot);
	}

	// metoda oblciza wszystkie bonusy wynikajace z aktywnych przedmiotow, zwraca sume wszystkich statystyk
	Statystyki oblicz_bonusy_przedmiotow()
	{
		Statystyki suma;
		vector< Przedmiot> aktywne_przedmioty = spis_aktywnych_przedmiotow();

		for (unsigned int i = 0; i < aktywne_przedmioty.size(); i++)
			suma += przedmioty[i].pobierz_statystyki();

		return suma;
	}

	void menu()
	{
		przegladaj(); 

		cout << przedmioty.size() << ") Exit" << endl;
		cout << "Wybierz numer przedmiotu: ";

		int wybor_przedmiotu = wybierz_opcje(przedmioty.size());

		// jezeli wybral ostatnia opcje to znaczy ze jest to exit
		if (wybor_przedmiotu == przedmioty.size())
			return;
		else
		{
			cout << "Co chcesz zrobic?" << endl;
			cout << "1) Zaloz przedmiot" << endl;
			cout << "2) Zdejmij przedmiot" << endl;
			cout << "3) Zamknij ekwipunek" << endl;

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

	virtual void zapisz_dane(string nazwa_pliku)
	{
		fstream plik;
		string nazwa_laczona = nazwa_pliku + "_ekwipunek";
		plik.open(nazwa_laczona + ".txt", ios::out);

		if (plik.good() == true)
		{		
			for (int i = 0; i < przedmioty.size(); i++)
			{
				// przechowujemy nazwy przedmiotow w ekwipunku;
				plik << przedmioty[i].pobierz_nazwa() << " ";
				przedmioty[i].zapisz_dane(nazwa_laczona);
			}
		}

		plik.close();
	}

	virtual void wczytaj_dane(string nazwa_pliku)
	{
		fstream plik;
		string nazwa_laczona = nazwa_pliku + "_ekwipunek";
		plik.open(nazwa_laczona + ".txt", ios::in);

		przedmioty.clear();
		if (plik.good() == true)
		{
			while (true) // niekonczaca sie petla
			{
				string nazwa_przedmiotu;
				plik >> nazwa_przedmiotu;
				if (plik.fail()) // gdy skoncza sie dane wychodzimy z petli
					break;
				Przedmiot nowy;
				nowy.wczytaj_dane(nazwa_laczona + "_" + nazwa_przedmiotu);

				przedmioty.push_back(nowy);
			}
		}
		else
			cout << "blad pliku: " + nazwa_laczona << endl;

		plik.close();
	}
};

