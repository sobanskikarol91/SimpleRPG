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

	// metoda ta bierze pod uwage rowniez bonusy z ekwipunku
	virtual int atak()
	{
		// TODO bonusy;
		return statystyki.pobierz_sila() + modyfikator_obrazen();
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
			zmien_kolor_txt(ZIELONY);
			statystyki.informacja();
			zmien_kolor_txt(ZOLTY);
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

