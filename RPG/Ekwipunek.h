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
	void przegladaj();
	// zwracamy tylko te przedmioty ktore sa aktywne
	vector<Przedmiot> spis_aktywnych_przedmiotow();
	void dodaj_przedmiot(Przedmiot nowyPrzedmiot);
	// metoda oblciza wszystkie bonusy wynikajace z aktywnych przedmiotow, zwraca sume wszystkich statystyk
	Statystyki oblicz_bonusy_przedmiotow();
	void menu();

	virtual void zapisz_dane(string nazwa_pliku);
	virtual void wczytaj_dane(string nazwa_pliku);
};

