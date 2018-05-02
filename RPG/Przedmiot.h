#pragma once
#include <iostream>
#include <string>
#include "Statystyki.h"
#include "Kolorowanie.h"
#include "IPlik.h"

using namespace std;

class Przedmiot
{
private:
	string nazwa;
	bool wyposazony; // czy gracz aktualnie wykorzystuje przedmiot
	Statystyki statystyki;

public:
	Przedmiot() :nazwa("Brak"), wyposazony(false) {}
	Przedmiot(string nazwa, Statystyki statystyki) : nazwa(nazwa), statystyki(statystyki), wyposazony(false) {}
	bool sprawdz_czy_wyposazony() { return wyposazony; }
	void ustaw_wyposazony(bool stan) { wyposazony = stan; }
	Statystyki pobierz_statystyki() { return statystyki; }


	void informacja(bool wyposazony_informacja = true)
	{
		cout << nazwa << "  ";

		if (wyposazony_informacja)
		{
			if (wyposazony)	koloruj_txt(" (Wyposazony)", ZIELONY);
			else	koloruj_txt(" (Nie wyposazony)", CZERWONY);
		}
		statystyki.informacja();
	}

	string pobierz_nazwa() { return nazwa; }

	virtual void zapisz_dane(string nazwa_pliku)
	{
		fstream plik;
		string nazwa_laczona = nazwa_pliku + "_" + nazwa;
		plik.open(nazwa_laczona + ".txt", ios::out);

		if (plik.good() == true)
		{
			plik << nazwa << " " << wyposazony;
			statystyki.zapisz_dane(nazwa_laczona);
		}

		plik.close();
	}

	virtual void wczytaj_dane(string nazwa_pliku)
	{
		fstream plik;
		string nazwa_laczona = nazwa_pliku;
		plik.open(nazwa_laczona + ".txt", ios::in);

		if (plik.good() == true)
		{
			plik >> nazwa_pliku >> wyposazony;
			cout << "nazwa: " << nazwa << " Wyposazony: " << wyposazony << endl;
			statystyki.wczytaj_dane(nazwa_laczona);
		}
		else
			cout << "blad pliku: " + nazwa_pliku << endl;

		plik.close();
	}
};


