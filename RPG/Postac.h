#include <iostream>
#include <string>
#include "Kostka.h"
using namespace std;

#pragma once
class Postac
{
protected:
	string nazwa;
	int zycie, sila, zrecznosc, obrazenia, poziom;

public:
	Postac() {};
	// konstruktor z lista inicjalizacyjna sluzacy do tworzenia postaci 
	Postac(string nazwa, int zycie, int sila, int zrecznosc, int obrazenia, int poziom) :
		nazwa(nazwa), zycie(zycie), sila(sila), zrecznosc(zrecznosc), obrazenia(obrazenia), poziom(poziom) {}

	void informacja()
	{
		cout << "=======================================================================================================================" << endl;
		cout << nazwa << "   ";
		cout << "Poziom: " << poziom << "   ";
		cout << "HP: " << zycie << "   ";
		cout << "Sila: " << sila << "   ";
		cout << "Zrecznosc: " << zrecznosc << "   ";
		cout << "Obrazenia: " << obrazenia << "   " << endl;
		cout << "=======================================================================================================================" << endl;
	}

	void przyznaj_obrazenia(int obrazenia) { zycie -= obrazenia; }
	bool czy_zyje() { return zycie > 0; }
	bool pobierz_zrecznosc() { return zrecznosc; }

	// Gracz i przeciwnik beda implementowac inaczej ta metode, dlatego ejst czysto wirtualna przez co klasa jest abstrakcyjna
	virtual int atak() = 0;

protected: // protected bo metoda ta bedzie uzywana jedynie w klasie Przeciwnika i Gracza
	int modyfikator_obrazen()
	{
		Kostka kostka;
		return kostka.losuj();
	}
};