#pragma once
#include <iostream>
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
	void dodaj_poziom() { poziom++; }

	// operator +=, definiuje jak mamy dodawac do jednego obiektu Statystyka drugi obiekt Statystyka
	Statystyki operator+= (Statystyki const& s)
	{
		// dodajemy poszczegolne skladowe statystyk do siebie i zwracamy rezultat jako nowy obiekt
		return Statystyki(zycie + s.zycie, sila + s.sila, zrecznosc + s.zrecznosc, obrona + s.obrona, poziom + s.poziom);
	}
};

