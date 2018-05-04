#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "IPlik.h"
#include "Kolorowanie.h"

using namespace std;

class Statystyki
{
	int zycie, sila, zrecznosc, obrona, poziom;

public:
	// domyslny konstruktor ustawia wszystkie wartosci nazero
	Statystyki();
	Statystyki(int zycie, int sila, int zrecznosc, int obrona, int poziom);

	void informacja();
	// gettery
	int pobierz_zycie() { return zycie; }
	int pobierz_sila() { return sila; }
	int pobierz_zrecznosc() { return zrecznosc; }
	int pobierz_obrona() { return obrona; }
	int pobierz_poziom() { return poziom; }

	// settery
	void dodaj_zycie(int wartosc) { zycie += wartosc; }
	void dodaj_sila(int wartosc) { sila += wartosc; }
	void dodaj_zrecznosc(int wartosc) { zrecznosc += wartosc; }
	void dodaj_obrona(int wartosc) { obrona += wartosc; }
	// poziom zwiekszamy zawsze o jeden
	void dodaj_poziom() { poziom++; }
	// operator +=, definiuje jak mamy dodac do jednego skladnika drugi
	Statystyki& operator+= (Statystyki const& s);

	// operator dodawania opisuje jak mamy dodawac dwa skladniki
	Statystyki operator+ (Statystyki const& s);
	virtual void zapisz_dane(string nazwa_pliku);
	virtual void wczytaj_dane(string nazwa_pliku);
};
