#pragma once
#include <iostream>
#include <string>
#include "Statystyki.h"
#include "Kolorowanie.h"
#include "IPlik.h"

#include "Okno.h"
using namespace std;


class Przedmiot
{
private:
	string nazwa;
	bool wyposazony; // czy gracz aktualnie wykorzystuje przedmiot
	Statystyki statystyki;
	Okno okno;

public:
	Przedmiot() :nazwa("Brak"), wyposazony(false) {};

	Przedmiot(string nazwa, Statystyki statystyki) : okno(Okno(nazwa)), nazwa(nazwa), statystyki(statystyki), wyposazony(false){}


	bool sprawdz_czy_wyposazony() { return wyposazony; }
	void ustaw_wyposazony(bool stan) { wyposazony = stan; }
	Statystyki pobierz_statystyki() { return statystyki; }
	Okno pobierz_okno() { return okno; }

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
			plik >> nazwa >> wyposazony;
			statystyki.wczytaj_dane(nazwa_laczona);
			okno = Okno(nazwa); // tworzymy nowy obiekt okno ze sciezka;
		}
		else
			cout << "Przedmiot blad pliku: " + nazwa_laczona << endl;

		plik.close();
	}
};


