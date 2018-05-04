#pragma once
#include <iostream>
#include <string>
#include "Statystyki.h"
#include "Kolorowanie.h"
#include "IPlik.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
using namespace std;


class Przedmiot  // dziedziczymy po interfejsie rysowania
{
private:
	string nazwa;
	bool wyposazony; // czy gracz aktualnie wykorzystuje przedmiot
	Statystyki statystyki;
	Texture texture;
	Sprite sprite;

public:
	Przedmiot() :nazwa("Brak"), wyposazony(false) {}
	Przedmiot(string nazwa, Statystyki statystyki) : nazwa(nazwa), statystyki(statystyki), wyposazony(false)
	{
		// konstruktor ustawia teksture przedmiotu
		if (!texture.loadFromFile("grafika/" + nazwa)) // wczytaj teksture o danej nazwie z folderu grafika
			cout << "Nie udalo sie wczytac tekstury " << nazwa;

		sprite.setTexture(texture);
	}

	bool sprawdz_czy_wyposazony() { return wyposazony; }
	void ustaw_wyposazony(bool stan) { wyposazony = stan; }
	Statystyki pobierz_statystyki() { return statystyki; }
	void draw(RenderTarget & target, RenderStates state) const
	{
		target.draw(sprite, state);
	}



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
		}
		else
			cout << "Przedmiot blad pliku: " + nazwa_laczona << endl;

		plik.close();
	}
};


