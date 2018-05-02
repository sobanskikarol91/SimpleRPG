#pragma once
#include "Postac.h"
#include "Ekwipunek.h"
#include "Kolorowanie.h" // kolorowanie skladni
#include "Menu.h"
#include "Dodatki.h"

class Gracz : public Postac, public Menu
{
	Ekwipunek ekwipunek;

public:
	// domyslny konstruktor wywolujemy rowniez na liscie inicjalizacyjej konstruktor klasy bazowej
	Gracz() : Postac() {};

	// konstruktor z lista inicjalizacyjna sluzacy do tworzenia postaci gracza
	Gracz(string nazwa, Statystyki statystyki, Ekwipunek ekwipunek)
		: Postac(nazwa, statystyki), ekwipunek(ekwipunek) {};

	void otrzymuje_przedmiot(Przedmiot  przedmiot)
	{
		ekwipunek.dodaj_przedmiot(przedmiot);
	}

	// ustawiamy domyslne wartosci, jezeli nie podamy argumentow to zostana przeslane domyslne
	void zwieksz_poziom(int sila = 1, int zrecznosc = 1, int zycie = 10)
	{
		zmien_kolor_txt(ZIELONY);
		cout << "********************************************" << endl;
		cout << "NOWY POZIOM!" << endl;
		cout << "sila  +" << sila << "   zrecznosc  +" << zrecznosc << "   zycie  +" << zycie << endl;
		cout << "********************************************" << endl;
		zmien_kolor_txt(ZOLTY);

		statystyki.dodaj_zrecznosc(zrecznosc);
		statystyki.dodaj_sila(sila);
		statystyki.dodaj_zycie(zycie);
		statystyki.dodaj_poziom();
	}

	// metoda ta bierze pod uwage rowniez bonusy wszystkich przedmiotow w ekwipunku a dokladnie ich atrybutu sily
	virtual int atak()
	{
		return statystyki.pobierz_sila() + modyfikator_obrazen() + ekwipunek.oblicz_bonusy_przedmiotow().pobierz_sila();
	}

	// wypisujemy wszystkie informacje o graczu
	virtual void informacje()
	{
		zmien_kolor_txt(ZIELONY);
		Postac::informacje();   // informacje z klasy bazowej
		zmien_kolor_txt(ZOLTY);

		vector<Przedmiot> aktywne_przedmioty = ekwipunek.spis_aktywnych_przedmiotow();

		// jezeli sa jakies aktywne przedmioty
		if (aktywne_przedmioty.size())
		{
			// to wypisujemy o nich informacje
			for (unsigned int i = 0; i < aktywne_przedmioty.size(); i++)
			{
				cout << "=======================================================================================================================" << endl;
				aktywne_przedmioty[i].informacja();
			}
			Statystyki statystyki_gracza_przedmiotow = ekwipunek.oblicz_bonusy_przedmiotow() + statystyki;

			cout << "=======================================================================================================================" << endl;
			cout << endl << "Statystyki gracza wraz z bonusem przedmiotow " << endl;
			zmien_kolor_txt(KOLOR::SELEDYNOWY);
			statystyki_gracza_przedmiotow.informacja();
			zmien_kolor_txt(KOLOR::ZOLTY);
		}
		else // jezeli nie ma aktywnych przedmiotow to  wypisujemy informacje na czerwono
			koloruj_txt("Brak  aktywnych przedmiotow", CZERWONY);

	}

	void menu()
	{
		cout << "1) Statystyki gracza" << endl;
		cout << "2) Przegladaj ekwipunek" << endl;
		cout << "3) Powrot" << endl;

		int wybor = wybierz_opcje(3, 1);

		switch (wybor)
		{
		case 1:
		{
			informacje();
			nacisnij_klawisz();
		}
		break;
		case 2:
			ekwipunek.menu();
			break;
		case 3:
			break;
		}
	}
};

