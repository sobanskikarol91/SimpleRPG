#include <iostream>
#include <string>
#include "Kostka.h"
#include "Statystyki.h"
using namespace std;

#pragma once
class Postac
{
protected:
	string nazwa;
	Statystyki statystyki;

public:
	Postac() {};
	// konstruktor z lista inicjalizacyjna sluzacy do tworzenia postaci 
	Postac(string nazwa, Statystyki statystyki) :
		nazwa(nazwa), statystyki(statystyki) {}


	// Gracz i przeciwnik beda implementowac inaczej ta metode, dlatego jest czysto wirtualna przez co klasa jest abstrakcyjna
	virtual int atak() = 0;
	Statystyki pobierz_statystyki() { return statystyki; }
	void informacje()
	{
		cout << nazwa << endl;
		statystyki.informacja();
	}
	void ustaw_statystyki(Statystyki wartosc) { statystyki = wartosc; }

protected: // protected bo metoda ta bedzie uzywana jedynie w klasie Przeciwnika i Gracza
	int modyfikator_obrazen()
	{
		Kostka kostka(1, 3);
		return kostka.losuj();
	}

	// Przeciazenie operatorow zapisu do pliku
	friend ostream & operator<<(ostream & plik, const Postac & s)
	{
		return	plik << s.nazwa << " " << s.statystyki;
	}

	// Przeciazenie operatorow odczytu z pliku
	friend istream & operator>>(istream & plik, Postac & s)
	{
		string linia;
		while (getline(plik, linia));
		return plik;
	}
};