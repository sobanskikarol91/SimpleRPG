#include "Postac.h"
#pragma once
#include "IPlik.h"

class Przeciwnik : public Postac, IPlik
{
public:
	Przeciwnik() : Postac() {};
	// konstruktur z lista inicjalizacyjna, w ktorej wywolujemy konstruktor klasy bazowej
	Przeciwnik(string nazwa, Statystyki statystyki)
		: Postac(nazwa,  statystyki){};


	virtual int atak()
	{
		return statystyki.pobierz_sila() + modyfikator_obrazen();
	}

	virtual void zapisz_dane(string nazwa_pliku)
	{
		fstream plik;
		string nazwa_laczona = nazwa_pliku + "_" + nazwa;
		plik.open(nazwa_laczona + ".txt", ios::out);

		if (plik.good() == true)
		{
			plik << nazwa;
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
			plik >> nazwa;
			statystyki.wczytaj_dane(nazwa_laczona);
		}
		else
			cout << "Przeciwnik blad pliku: " + nazwa_pliku << endl;

		plik.close();
	}
};