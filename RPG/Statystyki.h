#pragma once
#include <iostream>
using namespace std;

class Statystyki
{
	int zycie, sila, zrecznosc, obrona, poziom;

public:
	Statystyki() {};
	Statystyki(int zycie, int sila, int zrecznosc, int obrona, int poziom)
		: zycie(zycie), sila(sila), zrecznosc(zrecznosc), obrona(obrona), poziom(poziom) {};

	void informacja()
	{
		cout << "=======================================================================================================================" << endl;
		cout << "Poziom: " << poziom << "   ";
		cout << "HP: " << zycie << "   ";
		cout << "Sila: " << sila << "   ";
		cout << "Obrona: " << obrona << "   ";
		cout << "Zrecznosc: " << zrecznosc << "   " << endl;
		cout << "=======================================================================================================================" << endl;
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
	void dodaj_poziom() { poziom ++;}
};

