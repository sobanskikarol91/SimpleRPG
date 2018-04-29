#include <iostream>
#include "Przeciwnik.h"
#include "Przedmiot.h"
#include "Stan.h"
#include "Gracz.h"
#include "Dodatki.h"    // przydadza sie funkcje wyboru
#include "windows.h"    // kolorowanie skladni


#pragma once
class Lokalizacja
{
	Przeciwnik przeciwnik;
	Przedmiot przedmiot;
	string nazwa;
	string opis;
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
		
		wybor = wybierz_opcje(3,1);

		switch (wybor)
		{
		case 1:
		{
			Przedmiot  znalezisko = przeszukanie();
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
	Przedmiot przeszukanie()
	{
		cout << "Przeszukujac lokalizacje natrafiasz na przedmiot jest to: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // koloruj  
		cout << przedmiot.informacja() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		return przedmiot;
	}

	bool proba_ucieczki(Gracz * gracz)
	{
		int zrecznosc_potwora = przeciwnik.pobierz_zrecznosc();

		// gracz jest wskaznikiem wiec na obiekt klasy Gracz, wykorzystujemy '->' aby dostac sie do pola klasy
		int zrecznosc_gracza = gracz->pobierz_zrecznosc();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // koloruj na seledynowy
		cout << "==============================================================" << endl;
		cout << "Zrecznosc potwora: " << zrecznosc_potwora << endl;
		cout << "Zrecznosc gracza:  " << zrecznosc_gracza << endl;
		cout << "==============================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

		// gdy gracz ma wiecej zrecznosci zwracamy true
		return zrecznosc_gracza > zrecznosc_potwora;
	}

	STAN walka(Gracz * gracz)
	{
		int sila_potwory = przeciwnik.atak();
		int sila_gracza = gracz->atak();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // koloruj na seledynowy
		cout << "==============================================================" << endl;
		cout << "Sila potwora: " << sila_potwory << endl;
		cout << "Sila gracza:  " << sila_gracza << endl;
		cout << "==============================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

		if (sila_potwory >= sila_gracza)
			return STAN::PORAZKA;
		else
			return STAN::WYGRANA; // udalo sie wygrac wiec zwracamy taki stan
	}

	STAN menu_wyboru_walki(Gracz * gracz)
	{
		cout << "Na Twojej drodze staje: " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // koloruj na zolty
		przeciwnik.statystyki();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "1) (Walka) Zrobie Ci z lba popielniczke AGRRR!! " << endl;
		cout << "2) (Ucieczka) Strasznie napakowany ten kolo, chyba wroce pozniej..." << endl;

		int wybor = wybierz_opcje(2,1);
		switch (wybor)
		{
		case 1:
		{
			cout << "Postanowiles stanac do walki" << endl;
			walka(gracz);
		}
			break;
		case 2:
		{
			if (proba_ucieczki(gracz))
			{
				return STAN::UCIECZKA;
			}
			else
			{
				cout << "Nie udalo Ci sie uciec, musisz stanac do walki " << endl;
				walka(gracz);
			}
		}
		}
	}
};

