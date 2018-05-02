#pragma once
#include <iostream>
#include <sstream> // do pracy ze strumieniem
#include <string>
#include <fstream>
#include "IPlik.h"

using namespace std;

class Statystyki
{
	int zycie, sila, zrecznosc, obrona, poziom;

public:
	// domyslny konstruktor ustawia wszystkie wartosci nazero
	Statystyki() : zycie(0), sila(0), zrecznosc(0), obrona(0), poziom(0) {};
	Statystyki(int zycie, int sila, int zrecznosc, int obrona, int poziom)
		: zycie(zycie), sila(sila), zrecznosc(zrecznosc), obrona(obrona), poziom(poziom) {};

	void informacja()
	{
		cout << "Poziom: " << poziom << "   ";
		cout << "HP: " << zycie << "   ";
		cout << "Sila: " << sila << "   ";
		cout << "Obrona: " << obrona << "   ";
		cout << "Zrecznosc: " << zrecznosc << "   " << endl;
	}

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
	Statystyki& operator+= (Statystyki const& s)
	{
		// dodajemy poszczegolne skladowe statystyk do siebie i zwracamy rezultat jako nowy obiekt
		zycie += s.zycie;
		sila += s.sila;
		zrecznosc += s.zrecznosc;
		obrona += s.obrona;
		// poziomu nie dodajemy
		return *this;
	}

	// operator dodawania opisuje jak mamy dodawac dwa skladniki
	Statystyki operator+ (Statystyki const& s)
	{
		return Statystyki(zycie + s.zycie, sila + s.sila, zrecznosc + s.zrecznosc, obrona + s.obrona, 0); // poziomu nie dodajemy
	}

	virtual void zapisz_dane(string nazwa_pliku) 
	{
		fstream plik;
		plik.open(nazwa_pliku +  "_statystyki" + ".txt", ios::out);

		if (plik.good() == true)
			plik << zycie << " " << sila << " " << zrecznosc << " " << obrona << " " << poziom;

		plik.close();
	}

	virtual void wczytaj_dane(string nazwa_pliku)
	{
		fstream plik;
		plik.open(nazwa_pliku + "_statystyki" + ".txt", ios::in);

		if (plik.good() == true)
		{
			plik >> zycie >> sila >> zrecznosc >> obrona >> poziom;
		}
		else
			cout << "blad pliku: " + nazwa_pliku << endl;

		plik.close();
	}
};
