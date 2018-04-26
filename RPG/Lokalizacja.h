#include <iostream>
#include "Przeciwnik.h"
#include "Przedmiot.h"
#include "Stan.h"
#include "Gracz.h"

#pragma once
class Lokalizacja
{
	bool czy_zdobyta;  // przyda sie do sprawdzenia czy gracz juz zdobyl ta lokalizacje aby nie wchodzi tu ponownie
	Przeciwnik przeciwnik;
	Przedmiot przedmiot;
	string nazwa;
	string opis;
public:
	Lokalizacja() {};
	Lokalizacja(string nazwa, string opis, Przeciwnik przeciwnik, Przedmiot przedmiot)
		: nazwa(nazwa), opis(opis), przeciwnik(przeciwnik), przedmiot(przedmiot), czy_zdobyta(false) {}

	// wypisujemy nazwe i opis danej lokalizacji
	void informacja()
	{
		cout << nazwa << endl;
		cout << "==========================" << endl;
		cout << opis << endl;
	}

	// w zaleznosci od podjetego wyboru gracza zwracamy jego decyzje aby pozniej na jej podstawie
	// przejsc do innego etapu gry
	STAN wejdz_do_lokalizacji(Gracz * gracz)
	{
		int wybor;
		cout << "Co chcesz zrobic?" << endl;
		cout << "1) Przeszukaj lokalizacje" << endl;
		cout << "2) Walcz " << endl;
		cout << "3) Zawroc " << endl;

		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			Przedmiot * znalezisko = przeszukanie();
			gracz->otrzymuje_przedmiot(znalezisko);
			cout << "Przeszukujac lokalizacje, zbudziles jego straznika! " << endl;
			return menu_wyboru_walki(gracz);
		}
		case 2:
			return 	menu_wyboru_walki(gracz);
		case 3:
			return STAN::UCIECZKA;
		}
	}

	// zwracamy wskaznik na adres przedmiotu
	Przedmiot* przeszukanie()
	{
		cout << "Przeszukujac lokalizacje natrafiasz na przedmiot jest to: " << endl;
		przedmiot.informacja();
		return &przedmiot;
	}

	bool proba_ucieczki(Gracz * gracz)
	{
		int zrecznosc_potwora = przeciwnik.pobierz_zrecznosc();

		// gracz jest wskaznikiem wiec na obiekt klasy Gracz, wykorzystujemy '->' aby dostac sie do pola klasy
		int zrecznosc_gracza = gracz->pobierz_zrecznosc();

		cout << "Zrecznosc potwora: " << zrecznosc_potwora << endl;
		cout << "Zrecznosc gracza:  " << zrecznosc_gracza << endl;
		// gdy gracz ma wiecej zrecznosci zwracamy true
		return zrecznosc_gracza > zrecznosc_potwora;
	}

	STAN walka(Gracz * gracz)
	{
		int silaPotwora = przeciwnik.atak();
		int silaGracza = gracz->atak();

		if (silaPotwora >= silaGracza)
			return STAN::PORAZKA;
		else
		{
			czy_zdobyta = true;
			return STAN::WYGRANA; // udalo sie wygrac wiec zwracamy taki stan
		}
	}

	STAN menu_wyboru_walki(Gracz * gracz)
	{
		cout << "Na Twojej drodze staje: " << endl;
		przeciwnik.informacja();

		cout << "1) (Walka) Zrobie Ci z lba popielniczke AGRRR!! " << endl;
		cout << "2) (Ucieczka) Strasznie napakowany ten kolo, chyba wroce pozniej..." << endl;

		int wybor;

		cin >> wybor;

		switch (wybor)
		{
		case 1:
			walka(gracz);
			break;
		case 2:
		{
			if (proba_ucieczki(gracz))
				return STAN::UCIECZKA;
			else walka(gracz);
		}
		}
	}

};

