#pragma once
#include <iostream>
#include <string>
#include "Kostka.h"
#include "Statystyki.h"
using namespace std;


class Postac
{
protected:
	string nazwa;
	Statystyki statystyki;

public:
	Postac();
	// konstruktor z lista inicjalizacyjna sluzacy do tworzenia postaci 
	Postac(string nazwa, Statystyki statystyki);

	// Gracz i przeciwnik beda implementowac inaczej ta metode, dlatego jest czysto wirtualna przez co klasa jest abstrakcyjna
	virtual int atak() = 0;
	Statystyki pobierz_statystyki() { return statystyki; }
	string pobierz_nazwa() { return nazwa; }
	void informacje();
	void ustaw_statystyki(Statystyki wartosc) { statystyki = wartosc; }

protected: // protected bo metoda ta bedzie uzywana jedynie w klasie Przeciwnika i Gracza
	int modyfikator_obrazen();
};