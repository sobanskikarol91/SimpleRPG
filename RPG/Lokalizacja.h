#include <iostream>
#include "Przeciwnik.h"
#include "Przedmiot.h"
#include "Stan.h"
#include "Gracz.h"
#include "Dodatki.h"    // przydadza sie funkcje wyboru
#include "Kolorowanie.h" // kolorowanie skladni

#pragma once
class Lokalizacja
{
	Przeciwnik przeciwnik;
	Przedmiot przedmiot;
	string nazwa, opis;

public:
	Lokalizacja() {};
	Lokalizacja(string nazwa, string opis, Przeciwnik przeciwnik, Przedmiot przedmiot)
		: nazwa(nazwa), opis(opis), przeciwnik(przeciwnik), przedmiot(przedmiot) {}

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

		wybor = wybierz_opcje(3, 1);

		switch (wybor)
		{
		case 1:
		{
			Przedmiot  znalezisko = przeszukanie();
			gracz->otrzymuje_przedmiot(znalezisko);
			cout << "Dodajesz przedmiot do ekwipunku." << endl;
			cout << "Twoje odglosy, zbudzily straznika! " << endl << endl;
			return menu_wyboru_walki(gracz);
		}
		case 2:
			return 	menu_wyboru_walki(gracz);
		default:
			return STAN::UCIECZKA;
		}
	}

	// zwracamy wskaznik na adres przedmiotu
	Przedmiot przeszukanie()
	{
		cout << "Przeszukujac lokalizacje natrafiasz na przedmiot jest to: " << endl;
		zmien_kolor_txt(ZIELONY);
		przedmiot.informacja(false); // nie chcey informacjo tym czyejst wyposazony wiec false
		zmien_kolor_txt(ZOLTY);
		return przedmiot;
	}

	bool proba_ucieczki(Gracz * gracz)
	{
		int zrecznosc_potwora = przeciwnik.pobierz_statystyki().pobierz_zrecznosc();

		// gracz jest wskaznikiem wiec na obiekt klasy Gracz, wykorzystujemy '->' aby dostac sie do pola klasy
		int zrecznosc_gracza = gracz->pobierz_statystyki().pobierz_zrecznosc();

		cout << "==============================================================" << endl;
		zmien_kolor_txt(CZERWONY);
		cout << "Zrecznosc potwora: " << zrecznosc_potwora << endl;

		zmien_kolor_txt(ZIELONY);
		cout << "Zrecznosc gracza:  " << zrecznosc_gracza << endl;
		zmien_kolor_txt(ZOLTY);
		cout << "==============================================================" << endl;


		// gdy gracz ma wiecej zrecznosci zwracamy true
		return zrecznosc_gracza > zrecznosc_potwora;
	}

	STAN walka(Gracz * gracz)
	{
		int sila_potwory = przeciwnik.atak();
		int sila_gracza = gracz->atak();

		cout << "==============================================================" << endl;
		zmien_kolor_txt(CZERWONY);
		cout << "Sila potwora: " << sila_potwory << endl;

		zmien_kolor_txt(ZIELONY);
		cout << "Sila gracza:  " << sila_gracza << endl;
		zmien_kolor_txt(ZOLTY);
		cout << "==============================================================" << endl;


		if (sila_potwory >= sila_gracza)
			return STAN::PORAZKA;
		else
			return STAN::WYGRANA; // udalo sie wygrac wiec zwracamy taki stan
	}

	STAN menu_wyboru_walki(Gracz * gracz)
	{
		cout << "Na Twojej drodze staje: " << endl;

		zmien_kolor_txt(CZERWONY);
		przeciwnik.pobierz_statystyki();
		zmien_kolor_txt(ZOLTY);

		cout << "1) (Walka) Zrobie Ci z lba popielniczke AGRRR!! " << endl;
		cout << "2) (Ucieczka) Strasznie napakowany ten kolo, chyba wroce pozniej..." << endl;

		int wybor = wybierz_opcje(2, 1);
		switch (wybor)
		{
		case 1:
		{
			cout << "Postanowiles stanac do walki" << endl;
			return walka(gracz); // zwracamy rezultat walki
		}
		break;
		default:
		{
			if (proba_ucieczki(gracz))
				return STAN::UCIECZKA;
			else
			{
				cout << "Nie udalo Ci sie uciec, musisz stanac do walki " << endl;
				nacisnij_klawisz();
				return	walka(gracz);  // zwracamy rezultat walki
			}
		}
		}
	}
};

